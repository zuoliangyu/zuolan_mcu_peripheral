#include "key.h"

button btns[4];

static void Btn_0_handler(button *btn)
{
    switch (btn->btn_state) {
        case BTN_STA_IDLE:
            break;
        case BTN_STA_LONG_PRESS:
            printf("0 long press!\r\n");
            break;
        case BTN_STA_CLICK:
            printf("0 click!\r\n");
            break;
        case BTN_STA_DOUBLE_CLICK:
            printf("0 double click!\r\n");
            break;
    }
}

static void Btn_1_handler(button *btn)
{
    switch (btn->btn_state) {
        case BTN_STA_IDLE:
            break;
        case BTN_STA_LONG_PRESS:
            printf("1 long press!\r\n");
            break;
        case BTN_STA_CLICK:
            printf("1 click!\r\n");
            break;
        case BTN_STA_DOUBLE_CLICK:
            printf("1 double click!\r\n");
            break;
    }
}

static void Btn_2_handler(button *btn)
{
    switch (btn->btn_state) {
        case BTN_STA_IDLE:
            break;
        case BTN_STA_LONG_PRESS:
            printf("2 long press!\r\n");
            break;
        case BTN_STA_CLICK:
            printf("2 click!\r\n");
            break;
        case BTN_STA_DOUBLE_CLICK:
            printf("2 double click!\r\n");
            break;
    }
}

static void Btn_3_handler(button *btn)
{
    switch (btn->btn_state) {
        case BTN_STA_IDLE:
            break;
        case BTN_STA_LONG_PRESS:
            printf("3 long press!\r\n");
            break;
        case BTN_STA_CLICK:
            printf("3 click!\r\n");
            break;
        case BTN_STA_DOUBLE_CLICK:
            printf("3 double click!\r\n");
            break;
    }

    // btn - btn->id 
    if (BTN_STA_LONG_PRESS == ((btn - btn->id) + 2)->btn_state && BTN_STA_LONG_PRESS == ((btn - btn->id) + 3)->btn_state) {
        printf("btn0 state : %d\r\n", (int)((btn - btn->id) + 0)->btn_state);
        printf("btn1 state : %d\r\n", (int)((btn - btn->id) + 1)->btn_state);
        printf("btn2 state : %d\r\n", (int)((btn - btn->id) + 2)->btn_state);
        printf("btn3 state : %d\r\n", (int)((btn - btn->id) + 3)->btn_state);
        printf("btn2 & 3 long press\r\n");
    }

    if (BTN_STA_LONG_PRESS == ((btn - btn->id) + 2)->btn_state && BTN_STA_CLICK == ((btn - btn->id) + 3)->btn_state) {
        printf("btn0 state : %d\r\n", (int)((btn - btn->id) + 0)->btn_state);
        printf("btn1 state : %d\r\n", (int)((btn - btn->id) + 1)->btn_state);
        printf("btn2 state : %d\r\n", (int)((btn - btn->id) + 2)->btn_state);
        printf("btn3 state : %d\r\n", (int)((btn - btn->id) + 3)->btn_state);
        printf("btn2 long press & btn3 click\r\n");
    }

    if (BTN_STA_LONG_PRESS == ((btn - btn->id) + 2)->btn_state && BTN_STA_DOUBLE_CLICK == ((btn - btn->id) + 3)->btn_state) {
        printf("btn0 state : %d\r\n", (int)((btn - btn->id) + 0)->btn_state);
        printf("btn1 state : %d\r\n", (int)((btn - btn->id) + 1)->btn_state);
        printf("btn2 state : %d\r\n", (int)((btn - btn->id) + 2)->btn_state);
        printf("btn3 state : %d\r\n", (int)((btn - btn->id) + 3)->btn_state);
        printf("btn2 long press & btn3 double click\r\n");
    }
}

void button_handler(button *btn)
{
    uint8_t gpio_level = HAL_GPIO_ReadPin(btn->GPIOx, btn->GPIO_Pin);

    if (btn->state > 0)
        btn->ticks++;

    if (btn->level != gpio_level) {
        if (++(btn->debouce_cnt) >= 3) {
            btn->level = gpio_level;
            btn->debouce_cnt = 0;
        }
    } else {
        btn->debouce_cnt = 0;
    }

    switch (btn->state) {
        case 0:
            if (btn->level == 0) {
                btn->state = 1;
                btn->ticks = 0;
                btn->repeat = 1;
            } else {
                btn->btn_state = BTN_STA_IDLE;
            }
            break;
        case 1:
            if (btn->level != 0) {
                btn->ticks = 0;
                btn->state = 2;
            } else if (btn->ticks >= 50) {
                btn->btn_state = BTN_STA_LONG_PRESS;
                btn->button_handler(btn);
                btn->ticks = 0;
                btn->repeat = 0;
            }
            break;
        case 2:
            if (btn->ticks > 15) {
                if (btn->repeat == 1) {
                    btn->btn_state = BTN_STA_CLICK;
                    btn->button_handler(btn);
                } else if (btn->repeat == 2) {
                    btn->btn_state = BTN_STA_DOUBLE_CLICK;
                    btn->button_handler(btn);
                }
                btn->state = 0;
            } else {
                if (btn->level == 0) {
                    btn->repeat++;
                    btn->state = 1;
                    btn->ticks = 0;
                }
            }
            break;
    }
}

void Key_Proc(void)
{
    for (uint8_t i = 0; i < 4; i++) {
        button_handler(&btns[i]);
    }
}

void Key_Init(void)
{
    btns[0].GPIOx = GPIOB;
    btns[0].GPIO_Pin = GPIO_PIN_0;
    btns[0].level = 1;
    btns[0].id = 0;
    btns[0].button_handler = &Btn_0_handler;

    btns[1].GPIOx = GPIOB;
    btns[1].GPIO_Pin = GPIO_PIN_1;
    btns[1].level = 1;
    btns[1].id = 1;
    btns[1].button_handler = &Btn_1_handler;

    btns[2].GPIOx = GPIOB;
    btns[2].GPIO_Pin = GPIO_PIN_2;
    btns[2].level = 1;
    btns[2].id = 2;
    btns[2].button_handler = &Btn_2_handler;

    btns[3].GPIOx = GPIOA;
    btns[3].GPIO_Pin = GPIO_PIN_0;
    btns[3].level = 1;
    btns[3].id = 3;
    btns[3].button_handler = &Btn_3_handler;
}
