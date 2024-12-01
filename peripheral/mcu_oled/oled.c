#include "OLED.h" 
#include "oledfont.h"
#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

extern I2C_HandleTypeDef hi2c1;

uint8_t OLED_GRAM[128][8];
uint8_t OLED_GRAM_TEMP[8][128];
uint8_t OLED_GRAMbuf[8][128];
uint8_t OLED_CMDbuf[8][4] = {0};
uint8_t I2C1_MemTxFinshFlag = 1;
uint8_t CountFlag = 0; 
uint8_t BufFinshFlag = 0; 



/**
  * @brief    HAL_I2C_Master_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
              uint16_t Size)完成回调函数
  * 					保证DMA传输完成后，开启下次DMA
  */
	
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if(BufFinshFlag)
	{
		HAL_I2C_Mem_Write_DMA(&hi2c1,0x78,0x40,I2C_MEMADD_SIZE_8BIT,OLED_GRAMbuf[CountFlag],128);
	}
}


/**
  * @brief    HAL_I2C_Mem_Write_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress,
              uint16_t MemAddSize, uint8_t *pData, uint16_t Size)完成回调函数
  * 					保证DMA传输完成后，开启下次DMA
  */
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if(CountFlag == 7)
	{
		BufFinshFlag = 0;
		CountFlag = 0;
	}
	if(BufFinshFlag)
	{
		CountFlag ++;
		HAL_I2C_Master_Transmit_DMA(&hi2c1,0x78,OLED_CMDbuf[CountFlag],4);
	}
}

uint32_t oled_pow(uint8_t m, uint8_t n)
{
  uint32_t result = 1;

  while (n--)
    result *= m;

  return result;
}

uint8_t check_num_len(uint32_t num)
{
  uint32_t tmp;
	uint8_t i;
  for(i = 1; i < 10; i++)
  {
    tmp = oled_pow(10, i);
    if(num < tmp)
    {
      return i;
    }
  }
	return 0;
}

/**
  * @brief          initialize the oled device
  * @param[in]      none
  * @retval         none
  */
/**
  * @brief          初始化OLED模块，
  * @param[in]      none
  * @retval         none
  */
uint8_t OLED_Init_CMD[]={
0xAE, 0x00, 0x10, 0x40, 0xB0, 0x81, 0xFF, 0xA1, 0xA6, 0xA8, 0x3F,
					
0xC0, 0xD3, 0x00, 0xD5, 0x80, 0xD8, 0x05, 0xD9, 0xF1, 0xDA, 0x12,
					
0xDB, 0x30, 0x8D, 0x14, 0xAF,0x20,0x00};

void OLED_init(void)
{
	HAL_I2C_Mem_Write_DMA(&hi2c1, OLED_I2C_ADDRESS, 0x00, I2C_MEMADD_SIZE_8BIT, OLED_Init_CMD, 29);
}

/**
  * @brief          operate the graphic ram(size: 128*8 char)
  * @param[in]      pen: the type of operate.
                    PEN_CLEAR: set ram to 0x00
                    PEN_WRITE: set ram to 0xff
                    PEN_INVERSION: bit inversion 
  * @retval         none
  */
/**
  * @brief          操作GRAM内存(128*8char数组)
  * @param[in]      pen: 操作类型.
                    PEN_CLEAR: 设置为0x00
                    PEN_WRITE: 设置为0xff
  * @retval         none
  */
void OLED_operate_gram(pen_typedef pen)
{
	if (pen == PEN_WRITE)
	{
			memset(OLED_GRAM,0xff,sizeof(OLED_GRAM));
	}
	else if(pen == PEN_CLEAR)
	{
			memset(OLED_GRAM,0x00,sizeof(OLED_GRAM));
	}
	
}

/**
  * @brief          cursor set to (x,y) point
  * @param[in]      x:X-axis, from 0 to 127
  * @param[in]      y:Y-axis, from 0 to 7
  * @retval         none
  */
/**
  * @brief          设置光标起点(x,y)
  * @param[in]      x:x轴, 从 0 到 127
  * @param[in]      y:y轴, 从 0 到 7
  * @retval         none
  */
void OLED_set_pos(uint8_t x, uint8_t y)
{
	OLED_CMDbuf[y][0] = 0x00;
	OLED_CMDbuf[y][1] = 0xb0 + y;
	OLED_CMDbuf[y][2] = 0x10;
	OLED_CMDbuf[y][3] = 0x00;
	
}


/**
  * @brief          draw one bit of graphic raw, operate one point of screan(128*64)
  * @param[in]      x: x-axis, [0, X_WIDTH-1]
  * @param[in]      y: y-axis, [0, Y_WIDTH-1]
  * @param[in]      pen: type of operation,
                        PEN_CLEAR: set (x,y) to 0
                        PEN_WRITE: set (x,y) to 1
                        PEN_INVERSION: (x,y) value inversion 
  * @retval         none
  */
/**
  * @brief          操作GRAM中的一个位，相当于操作屏幕的一个点
  * @param[in]      x:x轴,  [0,X_WIDTH-1]
  * @param[in]      y:y轴,  [0,Y_WIDTH-1]
  * @param[in]      pen: 操作类型,
                        PEN_CLEAR: 设置 (x,y) 点为 0
                        PEN_WRITE: 设置 (x,y) 点为 1
                        PEN_INVERSION: (x,y) 值反转
  * @retval         none
  */
void OLED_draw_point(int8_t x, int8_t y, pen_typedef pen)
{
    uint8_t page = 0, row = 0;

    /* check the corrdinate */
    if ((x < 0) || (x > (X_WIDTH - 1)) || (y < 0) || (y > (Y_WIDTH - 1)))
    {
        return;
    }
    page = y / 8;
    row = y % 8;

    if (pen == PEN_WRITE)
    {
        OLED_GRAM[x][page] |= 1 << row;
    }
    else if (pen == PEN_INVERSION)
    {
        OLED_GRAM[x][page] ^= 1 << row;
    }
    else
    {
        OLED_GRAM[x][page] &= ~(1 << row);
    }
}




/**
  * @brief          draw a line from (x1, y1) to (x2, y2)
  * @param[in]      x1: the start point of line
  * @param[in]      y1: the start point of line
  * @param[in]      x2: the end point of line
  * @param[in]      y2: the end point of line
  * @param[in]      pen: type of operation,PEN_CLEAR,PEN_WRITE,PEN_INVERSION.
  * @retval         none
  */
/**
  * @brief          画一条直线，从(x1,y1)到(x2,y2)
  * @param[in]      x1: 起点
  * @param[in]      y1: 起点
  * @param[in]      x2: 终点
  * @param[in]      y2: 终点
  * @param[in]      pen: 操作类型,PEN_CLEAR,PEN_WRITE,PEN_INVERSION.
  * @retval         none
  */
  
void OLED_draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, pen_typedef pen)
{
    uint8_t col = 0, row = 0;
    uint8_t x_st = 0, x_ed = 0, y_st = 0, y_ed = 0;
    float k = 0.0f, b = 0.0f;

    if (y1 == y2)
    {
        (x1 <= x2) ? (x_st = x1):(x_st = x2);
        (x1 <= x2) ? (x_ed = x2):(x_ed = x1);

        for (col = x_st; col <= x_ed; col++)
        {
            OLED_draw_point(col, y1, pen);
        }
    }
    else if (x1 == x2)
    {
        (y1 <= y2) ? (y_st = y1):(y_st = y2);
        (y1 <= y2) ? (y_ed = y2):(y_ed = y1);

        for (row = y_st; row <= y_ed; row++)
        {
            OLED_draw_point(x1, row, pen);
        }
    }
    else
    {
        k = ((float)(y2 - y1)) / (x2 - x1);
        b = (float)y1 - k * x1;

        (x1 <= x2) ? (x_st = x1):(x_st = x2);
        (x1 <= x2) ? (x_ed = x2):(x_ed = x2);

        for (col = x_st; col <= x_ed; col++)
        {
            OLED_draw_point(col, (uint8_t)(col * k + b), pen);
        }
    }
}



/**
  * @brief          send the data of gram to oled sreen
  * @param[in]      none
  * @retval         none
  */
/**
  * @brief          发送数据到OLED的GRAM
  * @param[in]      none
  * @retval         none
  */
void OLED_refresh_gram(void)
{	
	uint8_t i;
	uint16_t j;
		
	if(BufFinshFlag == 0)
	{
		for(i = 0; i < 8; i ++ )
		{
			OLED_set_pos(0, i);
			for(j = 0;j < 128; j ++)
			{
					OLED_GRAMbuf[i][j] = OLED_GRAM[j][i];  //OLED_GRAM[128][8]

			}
		}
		BufFinshFlag = 1;
		HAL_I2C_Master_Transmit_DMA(&hi2c1,0x78,OLED_CMDbuf[0],4);
	}
}

/**************************************************************************
Function: Screen clear function, clear the screen, the entire screen is black, and did not light up the same
Input   : none
Output  : none
函数功能：清屏函数,清完屏,整个屏幕是黑色的，和没点亮一样
入口参数：无		  
返回  值：无
**************************************************************************/  	  
void OLED_Clear(void)  
{  
	uint8_t i,n;  
	for(i=0;i<8;i++)for(n=0;n<128;n++)OLED_GRAM[n][i]=0X00;  
	OLED_refresh_gram();//更新显示
}
/**************************************************************************
Function: Draw point
Input   : x,y: starting coordinate;T :1, fill,0, empty
Output  : none
函数功能：画点 
入口参数：x,y :起点坐标; t:1,填充,0,清空			  
返回  值：无
**************************************************************************/ 			   				   
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t)
{
	uint8_t pos,bx,temp=0;
	if(x>127||y>63)return;//超出范围了.
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)  OLED_GRAM[x][pos]|=temp;
	else   OLED_GRAM[x][pos]&=~temp;	    
}

/**************************************************************************
Function: Displays a character, including partial characters, at the specified position
Input   : x,y: starting coordinate;Len: The number of digits;Size: font size;Mode :0, anti-white display,1, normal display
Output  : none
函数功能：在指定位置显示一个字符,包括部分字符
入口参数：x,y :起点坐标; len :数字的位数; size:字体大小; mode:0,反白显示,1,正常显示	   
返回  值：无
**************************************************************************/
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size,uint8_t mode)
{      			    
	uint8_t temp,t,t1;
	uint8_t y0=y;
	chr=chr-' ';																//得到偏移后的值				   
    for(t=0;t<size;t++)
    {   
			if(size==12)  temp=oled_asc2_1206[chr][t];  //调用1206字体
			else          temp=oled_asc2_1608[chr][t];	//调用1608字体 	                          
			for(t1=0;t1<8;t1++)
			{
				if(temp&0x80)  OLED_DrawPoint(x,y,mode);
				else           OLED_DrawPoint(x,y,!mode);
				temp<<=1;
				y++;
				if((y-y0)==size)
				{
					y=y0;
					x++;
					break;
				}
			}  	 
    }          
}

/**************************************************************************
Function: Displays 2 numbers
Input   : x,y: starting coordinate;Len: The number of digits;Size: font size;Mode: mode, 0, fill mode, 1, overlay mode;Num: value (0 ~ 4294967295);
Output  : none
函数功能：显示2个数字
入口参数：x,y :起点坐标; len :数字的位数; size:字体大小; mode:模式, 0,填充模式, 1,叠加模式; num:数值(0~4294967295);	 
返回  值：无
**************************************************************************/		  
void OLED_ShowNumber(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size/2)*t,y,' ',size,1);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size/2)*t,y,temp+'0',size,1); 
	}
} 

/**************************************************************************
Function: Display string
Input   : x,y: starting coordinate;*p: starting address of the string
Output  : none
函数功能：显示字符串
入口参数：x,y :起点坐标; *p:字符串起始地址 
返回  值：无
**************************************************************************/
//用16字体
void OLED_ShowString(uint8_t x,uint8_t y,const uint8_t *p)
{
#define MAX_CHAR_POSX 122
#define MAX_CHAR_POSY 58          
    while(*p!='\0')
    {       
      if(x>MAX_CHAR_POSX){x=0;y+=16;}
      if(y>MAX_CHAR_POSY){y=x=0;OLED_Clear();}
      OLED_ShowChar(x,y,*p,12,1);	 
      x+=8;
      p++;
    }  
}


void OLED_show_floatnum(uint8_t x, uint8_t y, float num, uint8_t size)
{
  int32_t m, n;
  float R;
  uint8_t chartemp[6], i;
	
  R = num;
  m = R / 1;
  n = (R - m) * 1000;
  if(n < 0) n = -n;

  i = check_num_len(m);

  OLED_ShowNumber(x, y, m, i, size);

  chartemp[0] = '.';
  chartemp[1] = n / 100 + 48;
  chartemp[2] = n / 10 % 10 + 48;
  chartemp[3] = n % 10 + 48;
  chartemp[4] = ' ';
  chartemp[5] = '\0';
  OLED_ShowString(x, y + i, chartemp);
}


/**
  * @brief          formatted output in oled 128*64
  * @param[in]      row: row of character string begin, 0 <= row <= 4;
  * @param[in]      col: column of character string begin, 0 <= col <= 20;
  * @param          *fmt: the pointer to format character string
  * @note           if the character length is more than one row at a time, the extra characters will be truncated
  * @retval         none
  */
/**
  * @brief          格式输出
  * @param[in]      col: 开始行， 0 <= col <= 20;
  * @param[in]      row: 开始列，0 <= row <= 4;
  * @param[in]      *fmt:格式化输出字符串
  * @retval         none
  */
void LcdSprintf(uint8_t Colume, uint8_t Line, char *format,...)
{
    char String[128];
    va_list arg;
    va_start(arg, format);
    vsprintf(String, format, arg);
    va_end(arg);
    OLED_ShowString(Colume, Line, (uint8_t*)String);
}

void draw_axes(void)
{
    // 画x轴
    for (uint8_t x = 0; x <= 127; x++) {
        OLED_DrawPoint(x, 63, 1); // 在最底部画x轴
    }

    // 画y轴
    for (uint8_t y = 0; y <= 63; y++) {
        OLED_DrawPoint(0, y, 1); // 在最左侧画y轴
    }
}

void OLED_Draw_Line(uint16_t *Point_Buffer)
{
    uint8_t i;
    uint16_t h;
    uint16_t offset = 2; // 定义向下移动的偏移量

    draw_axes(); // 绘制坐标轴

    for(i = 0; i < 128; i++)
    {
        h = (float)Point_Buffer[i] * (64.0 / 4096); // 将采集到的值转化至屏幕尺寸（0-64）
        h = (int)h;
        h += offset; // 向下移动图像
        if (h > 64) h = 64; // 确保h值不会超过屏幕尺寸
        OLED_DrawPoint(i, 64 - h, 1); // 显示采集值，形成曲线
    }
}
