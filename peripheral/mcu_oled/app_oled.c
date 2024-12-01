#include "app_oled.h"

extern double rms1;
extern double rms2;
extern volatile float pwm_output_channel_1;
extern bool Pwm_Pid_Ctrl;
extern uint16_t data;
extern double avg1;
extern double avg2;
uint16_t buffer[128];

uint32_t count = 0;

bool oled_disp_mode;

void OLED_Proc(void)
{
    count++; if(count > 8888) count = 0;
    OLED_operate_gram(PEN_CLEAR);
    
    if(oled_disp_mode == false)
    {
        LcdSprintf(COLUMN0, LINE0, "sys_count:%d", count);
        LcdSprintf(COLUMN0, LINE1, "adc_1 : %lu", adc_original_buffer[0]);
		LcdSprintf(COLUMN0, LINE2, "avg_1:%.3f", avg1);
        LcdSprintf(COLUMN0, LINE3, "rms_1:%.3f", rms1);
        LcdSprintf(COLUMN0, LINE4, "data:%d", data);
				
    }
    else
    {
        OLED_Draw_Line(buffer);
    }
    
    OLED_refresh_gram();
}
