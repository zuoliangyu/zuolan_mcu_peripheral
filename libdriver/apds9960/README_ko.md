[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver APDS9960

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/apds9960/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

Broadcom APDS-9960은 단일 8핀 패키지의 디지털 RGB, 주변광, 근접 및 제스처 센서 장치입니다. 이 장치는 IR LED를 사용하여 RGBC(빨간색, 녹색, 파란색), 근접성 및 제스처 감지를 제공하는 I2C 호환 인터페이스를 갖추고 있습니다. RGB 및 주변광 감지 기능은 다양한 조명 조건과 어두운 유리를 포함한 다양한 감쇠 재료를 통해 빛의 강도를 감지합니다. 또한 통합된 UV-IR 차단 필터는 정확한 주변광 및 상관 색온도 감지를 가능하게 합니다. 근접 및 제스처 기능은 공장에서 조정되며 고객 보정 없이도 100mm 근접 감지 거리로 보정됩니다. 제스처 감지는 가시적 차단 필터와 통합된 4개의 지향성 포토다이오드를 사용하여 간단한 위-아래-오른쪽-왼쪽 제스처 또는 더 복잡한 제스처를 정확하게 감지합니다. 모듈 내에 마이크로 광학 렌즈를 추가하여 적외선 에너지의 고효율 전송 및 수신을 제공합니다. 내부 상태 기계를 사용하면 장치를 RGBC, 근접 및 제스처 측정 사이에서 저전력 상태로 전환하여 매우 낮은 전력 소비를 제공할 수 있습니다. 디스플레이 백라이트 제어, 상관 색온도 감지, 휴대 전화 터치 스크린 비활성화, 디지털에 사용할 수 있습니다. 카메라 터치 스크린 비활성화, 기계적 스위치 교체, 제스처 감지 등.

LibDriver APDS9960은 LibDriver에서 출시한 APDS9960의 전체 기능 드라이버입니다. LibDriver APDS9960은 rgbc 읽기 기능, 근접 읽기 기능, 제스처 디코딩 기능 및 기타 기능을 제공합니다. LibDriver는 MISRA를 준수합니다.

### 콘텐츠

  - [설명](#설명)
  - [설치](#설치)
  - [사용](#사용)
    - [example basic](#example-basic)
    - [example gesture](#example-gesture)
    - [example interrupt](#example-interrupt)
  - [문서](#문서)
  - [기고](#기고)
  - [저작권](#저작권)
  - [문의하기](#문의하기)

### 설명

/src 디렉토리에는 LibDriver APDS9960의 소스 파일이 포함되어 있습니다.

/interface 디렉토리에는 LibDriver APDS9960용 플랫폼 독립적인 IIC버스 템플릿이 포함되어 있습니다.

/test 디렉토리에는 LibDriver APDS9960드라이버 테스트 프로그램이 포함되어 있어 칩의 필요한 기능을 간단히 테스트할 수 있습니다.

/example 디렉토리에는 LibDriver APDS9960프로그래밍 예제가 포함되어 있습니다.

/doc 디렉토리에는 LibDriver APDS9960오프라인 문서가 포함되어 있습니다.

/datasheet 디렉토리에는 APDS9960데이터시트가 있습니다.

/project 디렉토리에는 일반적으로 사용되는 Linux 및 마이크로컨트롤러 개발 보드의 프로젝트 샘플이 포함되어 있습니다. 모든 프로젝트는 디버깅 방법으로 셸 스크립트를 사용하며, 자세한 내용은 각 프로젝트의 README.md를 참조하십시오.

/misra 에는 LibDriver misra 코드 검색 결과가 포함됩니다.

### 설치

/interface 디렉토리에서 플랫폼 독립적인IIC 버스 템플릿을 참조하여 지정된 플랫폼에 대한 IIC버스 드라이버를 완성하십시오.

/src 디렉터리, 플랫폼용 인터페이스 드라이버 및 자체 드라이버를 프로젝트에 추가합니다. 기본 예제 드라이버를 사용하려면 /example 디렉터리를 프로젝트에 추가합니다.

### 사용

/example 디렉터리의 예제를 참조하여 자신만의 드라이버를 완성할 수 있습니다. 기본 프로그래밍 예제를 사용하려는 경우 사용 방법은 다음과 같습니다.

#### example basic

```C
#include "driver_apds9960_basic.h"

uint8_t res;
uint32_t i, times;

times = 3;
res = apds9960_basic_init();
if (res != 0)
{
    return 1;
}

/* 1000 ms */
apds9960_interface_delay_ms(1000);

for (i = 0; i < times; i++)
{
    uint8_t proximity;
    uint16_t red, green, blue, clear;

    /* read rgbc */
    res = apds9960_basic_read_rgbc((uint16_t *)&red, (uint16_t *)&green, (uint16_t *)&blue, (uint16_t *)&clear);
    if (res != 0)
    {
        apds9960_interface_debug_print("apds9960: read rgbc failed.\n");
        (void)apds9960_basic_deinit();

        return 1;
    }

    /* read proximity */
    res = apds9960_basic_read_proximity((uint8_t *)&proximity);
    if (res != 0)
    {
        apds9960_interface_debug_print("apds9960: read proximity failed.\n");
        (void)apds9960_basic_deinit();

        return 1;
    }

    /* output */
    apds9960_interface_debug_print("%d/%d.\n", i + 1, times);
    apds9960_interface_debug_print("apds9960: red is 0x%04X.\n", red);
    apds9960_interface_debug_print("apds9960: green is 0x%04X.\n", green);
    apds9960_interface_debug_print("apds9960: blue is 0x%04X.\n", blue);
    apds9960_interface_debug_print("apds9960: clear is 0x%04X.\n", clear);
    apds9960_interface_debug_print("apds9960: proximity is 0x%02X.\n", proximity);

    /* 1000 ms */
    apds9960_interface_delay_ms(1000);
}

/* deinit */
(void)apds9960_basic_deinit();

return 0;
```

#### example gesture

```c
#include "driver_apds9960_gesture.h"

uint8_t (*g_gpio_irq)(void) = NULL;
static uint8_t gs_flag;
uint8_t res;
uint32_t i, times;

static void a_gesture_callback(uint8_t type)
{
    switch (type)
    {
        case APDS9960_INTERRUPT_STATUS_GESTURE_LEFT :
        {
            apds9960_interface_debug_print("apds9960: irq gesture left.\n");
            gs_flag = 1;
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GESTURE_RIGHT :
        {
            apds9960_interface_debug_print("apds9960: irq gesture right.\n");
            gs_flag = 1;
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GESTURE_UP :
        {
            apds9960_interface_debug_print("apds9960: irq gesture up.\n");
            gs_flag = 1;
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GESTURE_DOWN :
        {
            apds9960_interface_debug_print("apds9960: irq gesture down.\n");
            gs_flag = 1;
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GESTURE_NEAR :
        {
            apds9960_interface_debug_print("apds9960: irq gesture near.\n");
            gs_flag = 1;
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GESTURE_FAR :
        {
            apds9960_interface_debug_print("apds9960: irq gesture far.\n");
            gs_flag = 1;
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GFOV :
        {
            apds9960_interface_debug_print("apds9960: irq gesture fifo overflow.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GVALID :
        {
            apds9960_interface_debug_print("apds9960: irq gesture fifo data.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_CPSAT :
        {
            apds9960_interface_debug_print("apds9960: irq clear photodiode saturation.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_PGSAT :
        {
            apds9960_interface_debug_print("apds9960: irq analog saturation.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_PINT :
        {
            apds9960_interface_debug_print("apds9960: irq proximity interrupt.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_AINT :
        {
            apds9960_interface_debug_print("apds9960: irq als interrupt.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GINT :
        {
            break;
        }
        case APDS9960_INTERRUPT_STATUS_PVALID :
        {
            break;
        }
        case APDS9960_INTERRUPT_STATUS_AVALID :
        {
            apds9960_interface_debug_print("apds9960: irq als valid.\n");
            
            break;
        }
        default :
        {
            apds9960_interface_debug_print("apds9960: irq unknown.\n");
            
            break;
        }
    }
}

times = 3;

/* gpio interrupt init */
g_gpio_irq = apds9960_gesture_irq_handler;
if (gpio_interrupt_init() != 0)
{
    g_gpio_irq = NULL;
}

res = apds9960_gesture_init(a_gesture_callback);
if (res != 0)
{
    (void)gpio_interrupt_deinit();
    g_gpio_irq = NULL;

    return 1;
}

gs_flag = 0;
for (i = 0; i < times; i++)
{
    if (gs_flag != 0)
    {
        gs_flag = 0;

        /* 1000 ms */
        apds9960_interface_delay_ms(100);

        break;
    }
    else
    {
        /* 1000 ms */
        apds9960_interface_delay_ms(100); 

        continue;
    }
}

(void)apds9960_gesture_deinit();
(void)gpio_interrupt_deinit();
g_gpio_irq = NULL;

return 0;
```

#### example interrupt

```C
#include "driver_apds9960_interrupt.h"

uint8_t (*g_gpio_irq)(void) = NULL;
static uint8_t gs_flag;
uint8_t res;
uint32_t i, times;

static void a_interrupt_callback(uint8_t type)
{
    switch (type)
    {
        case APDS9960_INTERRUPT_STATUS_GESTURE_LEFT :
        {
            apds9960_interface_debug_print("apds9960: irq gesture left.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GESTURE_RIGHT :
        {
            apds9960_interface_debug_print("apds9960: irq gesture right.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GESTURE_UP :
        {
            apds9960_interface_debug_print("apds9960: irq gesture up.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GESTURE_DOWN :
        {
            apds9960_interface_debug_print("apds9960: irq gesture down.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GESTURE_NEAR :
        {
            apds9960_interface_debug_print("apds9960: irq gesture near.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GESTURE_FAR :
        {
            apds9960_interface_debug_print("apds9960: irq gesture far.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GFOV :
        {
            apds9960_interface_debug_print("apds9960: irq gesture fifo overflow.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GVALID :
        {
            apds9960_interface_debug_print("apds9960: irq gesture fifo data.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_CPSAT :
        {
            apds9960_interface_debug_print("apds9960: irq clear photodiode saturation.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_PGSAT :
        {
            apds9960_interface_debug_print("apds9960: irq analog saturation.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_PINT :
        {
            uint8_t res;
            uint8_t proximity;
            
            /* read proximity */
            res = apds9960_interrupt_read_proximity((uint8_t *)&proximity);
            if (res != 0)
            {
                apds9960_interface_debug_print("apds9960: read proximity failed.\n");
            }
            apds9960_interface_debug_print("apds9960: proximity is 0x%02X.\n", proximity);
            gs_flag = 1;
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_AINT :
        {
            uint8_t res;
            uint16_t red, green, blue, clear;
            
            /* read rgbc */
            res = apds9960_interrupt_read_rgbc((uint16_t *)&red, (uint16_t *)&green, (uint16_t *)&blue, (uint16_t *)&clear);
            if (res != 0)
            {
                apds9960_interface_debug_print("apds9960: read rgbc failed.\n");
                
                return 1;
            }
            /* output */
            apds9960_interface_debug_print("apds9960: red is 0x%04X.\n", red);
            apds9960_interface_debug_print("apds9960: green is 0x%04X.\n", green);
            apds9960_interface_debug_print("apds9960: blue is 0x%04X.\n", blue);
            apds9960_interface_debug_print("apds9960: clear is 0x%04X.\n", clear);
            gs_flag = 1;
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_GINT :
        {
            apds9960_interface_debug_print("apds9960: irq gesture interrupt.\n");
            
            break;
        }
        case APDS9960_INTERRUPT_STATUS_PVALID :
        {
            break;
        }
        case APDS9960_INTERRUPT_STATUS_AVALID :
        {
            break;
        }
        default :
        {
            apds9960_interface_debug_print("apds9960: irq unknown.\n");
            
            break;
        }
    }
}
               
times = 3;

/* gpio interrupt init */
g_gpio_irq = apds9960_interrupt_irq_handler;
if (gpio_interrupt_init() != 0)
{
    g_gpio_irq = NULL;
}

/* run interrupt function */
if (apds9960_interrupt_init(_interrupt_callback, 1,
                            2000, 1, 150) != 0)
{
    (void)gpio_interrupt_deinit();
    g_gpio_irq = NULL;

    return 1;
}

gs_flag = 0;
for (i = 0; i < times; i++)
{
    if (gs_flag != 0)
    {
        gs_flag = 0;

        /* 1000 ms */
        apds9960_interface_delay_ms(100);

        break;
    }
    else
    {
        /* 1000 ms */
        apds9960_interface_delay_ms(100); 

        continue;
    }
}

(void)apds9960_interrupt_deinit();
(void)gpio_interrupt_deinit();
g_gpio_irq = NULL;

return 0;
```

### 문서

온라인 문서: [https://www.libdriver.com/docs/apds9960/index.html](https://www.libdriver.com/docs/apds9960/index.html).

오프라인 문서: /doc/html/index.html.

### 기고

CONTRIBUTING.md 를 참조하십시오.

### 저작권

저작권 (c) 2015 - 지금 LibDriver 판권 소유

MIT 라이선스(MIT)

이 소프트웨어 및 관련 문서 파일("소프트웨어")의 사본을 얻은 모든 사람은 이에 따라 무제한 사용, 복제, 수정, 통합, 출판, 배포, 2차 라이선스를 포함하여 소프트웨어를 처분할 수 있는 권리가 부여됩니다. 소프트웨어의 사본에 대한 라이선스 및/또는 판매, 그리고 소프트웨어가 위와 같이 배포된 사람의 권리에 대한 2차 라이선스는 다음 조건에 따릅니다.

위의 저작권 표시 및 이 허가 표시는 이 소프트웨어의 모든 사본 또는 내용에 포함됩니다.

이 소프트웨어는 상품성, 특정 목적에의 적합성 및 비침해에 대한 보증을 포함하되 이에 국한되지 않는 어떠한 종류의 명시적 또는 묵시적 보증 없이 "있는 그대로" 제공됩니다. 어떤 경우에도 저자 또는 저작권 소유자는 계약, 불법 행위 또는 기타 방식에 관계없이 소프트웨어 및 기타 소프트웨어 사용으로 인해 발생하거나 이와 관련하여 발생하는 청구, 손해 또는 기타 책임에 대해 책임을 지지 않습니다.

### 문의하기

연락주세요lishifenging@outlook.com.