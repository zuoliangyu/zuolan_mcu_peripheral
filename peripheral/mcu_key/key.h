#ifndef KEY_H
#define KEY_H

#include "main.h"

typedef enum {
    BTN_STA_IDLE,
    BTN_STA_LONG_PRESS,
    BTN_STA_CLICK,
    BTN_STA_DOUBLE_CLICK,
} button_state_t;

typedef struct btn {
    uint16_t ticks;
    uint8_t level;
    uint8_t id;
    uint8_t state;
    uint8_t repeat;
    uint8_t debouce_cnt;
    
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;

    button_state_t btn_state;
    void (*button_handler)(struct btn *btn);
} button;

void Key_Init(void);
void Key_Proc(void);

#endif
