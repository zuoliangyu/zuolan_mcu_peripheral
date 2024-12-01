#include "icm20608.h"
#include "main.h"
#include "usart.h"

I2C_HandleTypeDef *_icm20608_ui2c;

/**
 * @brief	ICM20608��ʼ������
 *
 * @param   void
 *
 * @return  uint8_t		0,�ɹ�������,ʧ��
 */
uint8_t ICM20608_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t res;
    
    _icm20608_ui2c = hi2c;
    
    MPU_Write_Byte(MPU_PWR_MGMT1_REG, 0X80);	//��λICM20608
    HAL_Delay(100);
    MPU_Write_Byte(MPU_PWR_MGMT1_REG, 0X00);	//����ICM20608
    MPU_Set_Gyro_Fsr(3);					//�����Ǵ�����,��2000dps
    MPU_Set_Accel_Fsr(0);					//���ٶȴ�����,��2g
    MPU_Set_Rate(50);						//���ò�����50Hz
    MPU_Write_Byte(MPU_INT_EN_REG, 0X00);	//�ر������ж�
    MPU_Write_Byte(MPU_USER_CTRL_REG, 0X00);	//I2C��ģʽ�ر�
    MPU_Write_Byte(MPU_FIFO_EN_REG, 0X00);	//�ر�FIFO
    MPU_Write_Byte(MPU_INTBP_CFG_REG, 0X80);	//INT���ŵ͵�ƽ��Ч

    MPU_Write_Byte(0x1D, 1);	//INT���ŵ͵�ƽ��Ч

    res = MPU_Read_Byte(MPU_DEVICE_ID_REG);

    if(res == 0XAF) //����ID��ȷ
    {
        MPU_Write_Byte(MPU_PWR_MGMT1_REG, 0X01);	//����CLKSEL,PLL X��Ϊ�ο�
        MPU_Write_Byte(MPU_PWR_MGMT2_REG, 0X00);	//���ٶ��������Ƕ�����
        MPU_Set_Rate(50);						//���ò�����Ϊ50Hz
    }
    else return 1;

    return 0;

}
/**
 * @brief	����ICM20608���ٶȴ����������̷�Χ
 *
 * @param   fsr		0,��250dps;1,��500dps;2,��1000dps;3,��2000dps
 *
 * @return  uint8_t		0,�ɹ�������,ʧ��
 */
uint8_t MPU_Set_Gyro_Fsr(uint8_t fsr)
{
    return MPU_Write_Byte(MPU_GYRO_CFG_REG, fsr << 3); //���������������̷�Χ
}
/**
 * @brief	����ICM20608�����Ǵ����������̷�Χ
 *
 * @param   fsr		0,��2g;1,��4g;2,��8g;3,��16g
 *
 * @return  uint8_t		0,�ɹ�������,ʧ��
 */
uint8_t MPU_Set_Accel_Fsr(uint8_t fsr)
{
    return MPU_Write_Byte(MPU_ACCEL_CFG_REG, fsr << 3); //���ü��ٶȴ����������̷�Χ
}
/**
 * @brief	����ICM20608�����ֵ�ͨ�˲���
 *
 * @param   lpf		���ֵ�ͨ�˲�Ƶ��(Hz)
 *
 * @return  uint8_t		0,�ɹ�������,ʧ��
 */
uint8_t MPU_Set_LPF(uint16_t lpf)
{
    uint8_t data = 0;

    if(lpf >= 188)data = 1;

    else if(lpf >= 98)data = 2;

    else if(lpf >= 42)data = 3;

    else if(lpf >= 20)data = 4;

    else if(lpf >= 10)data = 5;

    else data = 6;

    return MPU_Write_Byte(MPU_CFG_REG, data); //�������ֵ�ͨ�˲���
}

/**
 * @brief	����ICM20608�Ĳ�����(�ٶ�Fs=1KHz)
 *
 * @param   rate	4~1000(Hz)
 *
 * @return  uint8_t		0,�ɹ�������,ʧ��
 */
uint8_t MPU_Set_Rate(uint16_t rate)
{
    uint8_t data;

    if(rate > 1000)rate = 1000;

    if(rate < 4)rate = 4;

    data = 1000 / rate - 1;
    data = MPU_Write_Byte(MPU_SAMPLE_RATE_REG, data);	//�������ֵ�ͨ�˲���
    return MPU_Set_LPF(rate / 2);	//�Զ�����LPFΪ�����ʵ�һ��
}
/**
 * @brief	�õ��¶�ֵ
 *
 * @param   rate	4~1000(Hz)
 *
 * @return  short	�¶�ֵ(������100��)
 */
short MPU_Get_Temperature(void)
{
    uint8_t buf[2];
    short raw;
    float temp;
    MPU_Read_Len(MPU_ADDR, MPU_TEMP_OUTH_REG, 2, buf);
    raw = ((uint16_t)buf[0] << 8) | buf[1];
    temp = 25 + ((double)raw) / 326.8;
    return temp * 100;;
}

/**
 * @brief	�õ�������ֵ(ԭʼֵ)
 *
 * @param   gx,gy,gz	������x,y,z���ԭʼ����(������)
 *
 * @return  uint8_t			0,�ɹ�������,ʧ��
 */
uint8_t MPU_Get_Gyroscope(short *gx, short *gy, short *gz)
{
    uint8_t buf[6], res;
    res = MPU_Read_Len(MPU_ADDR, MPU_GYRO_XOUTH_REG, 6, buf);

    if(res == 0)
    {
        *gx = ((uint16_t)buf[0] << 8) | buf[1];
        *gy = ((uint16_t)buf[2] << 8) | buf[3];
        *gz = ((uint16_t)buf[4] << 8) | buf[5];
    }

    return res;;
}
/**
 * @brief	�õ����ٶ�ֵ(ԭʼֵ)
 *
 * @param   ax,ay,az	���ٶ�ֵx,y,z���ԭʼ����(������)
 *
 * @return  uint8_t			0,�ɹ�������,ʧ��
 */
uint8_t MPU_Get_Accelerometer(short *ax, short *ay, short *az)
{
    uint8_t buf[6], res;
    res = MPU_Read_Len(MPU_ADDR, MPU_ACCEL_XOUTH_REG, 6, buf);

    if(res == 0)
    {
        *ax = ((uint16_t)buf[0] << 8) | buf[1];
        *ay = ((uint16_t)buf[2] << 8) | buf[3];
        *az = ((uint16_t)buf[4] << 8) | buf[5];
    }

    return res;;
}

extern I2C_HandleTypeDef hi2c1; // ȷ���������ط��Ѿ���ʼ���� hi2c1

/**
 * @brief	IIC����д
 *
 * @param   addr	������ַ
 * @param   reg		�Ĵ�����ַ
 * @param   len		д�볤��
 * @param   buf		������
 *
 * @return  uint8_t			0,�ɹ�������,ʧ��
 */
uint8_t MPU_Write_Len(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf)
{
    uint8_t data[256];
    data[0] = reg;
    memcpy(&data[1], buf, len);

    if (HAL_I2C_Master_Transmit(&hi2c1, addr << 1, data, len + 1, HAL_MAX_DELAY) != HAL_OK)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief	IIC������
 *
 * @param   addr	������ַ
 * @param   reg		Ҫ��ȡ�ļĴ�����ַ
 * @param   len		Ҫ��ȡ�ĳ���
 * @param   buf		��ȡ�������ݴ洢��
 *
 * @return  uint8_t			0,�ɹ�������,ʧ��
 */
uint8_t MPU_Read_Len(uint8_t addr, uint8_t reg, uint8_t len, uint8_t *buf)
{
    if (HAL_I2C_Master_Transmit(&hi2c1, addr << 1, &reg, 1, HAL_MAX_DELAY) != HAL_OK)
    {
        return 1;
    }

    if (HAL_I2C_Master_Receive(&hi2c1, addr << 1, buf, len, HAL_MAX_DELAY) != HAL_OK)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief	IICдһ���ֽ�
 *
 * @param   reg		�Ĵ�����ַ
 * @param   data		����
 *
 * @return  uint8_t			0,�ɹ�������,ʧ��
 */
uint8_t MPU_Write_Byte(uint8_t reg, uint8_t data)
{
    uint8_t buf[2] = {reg, data};

    if (HAL_I2C_Master_Transmit(&hi2c1, MPU_ADDR << 1, buf, 2, HAL_MAX_DELAY) != HAL_OK)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief	IIC��һ���ֽ�
 *
 * @param   reg		�Ĵ�����ַ
 *
 * @return  uint8_t		����������
 */
uint8_t MPU_Read_Byte(uint8_t reg)
{
    uint8_t res;

    if (HAL_I2C_Master_Transmit(&hi2c1, MPU_ADDR << 1, &reg, 1, HAL_MAX_DELAY) != HAL_OK)
    {
        return 1;
    }

    if (HAL_I2C_Master_Receive(&hi2c1, MPU_ADDR << 1, &res, 1, HAL_MAX_DELAY) != HAL_OK)
    {
        return 1;
    }
    return res;
}

