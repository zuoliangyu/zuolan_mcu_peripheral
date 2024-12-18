[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver BMP384

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/bmp384/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

BMP384는 젤로 채워진 캐비티를 갖추고 있어 해당 통합 개념을 사용하면 물, 액체 및 기타 화학 물질에 대한 견고성이 더 높아집니다. BMP384는 수위 및 막힘 감지 애플리케이션에 완벽하게 적합합니다. 더 나은 성능, 견고성 및 안정성을 위해 BMI088을 포함한 다른 Bosch Sensortec 센서와 호환됩니다. 작은 면적을 갖춘 BMP384는 뛰어난 설계 유연성을 제공하여 스마트 홈, 산업 제품 및 웨어러블을 위한 기존 및 출시 예정인 다른 장치에 쉽게 통합할 수 있는 단일 패키지 솔루션을 제공합니다.

LibDriver BMP384은 LibDriver에서 출시한 BMP384의 전체 기능 드라이버입니다. 압력 및 온도의 지속적인 판독, 압력 및 온도의 단일 판독, 인터럽트 판독, FIFO 수집 및 기타 기능을 제공합니다. LibDriver는 MISRA를 준수합니다.

### 콘텐츠

  - [설명](#설명)
  - [설치](#설치)
  - [사용](#사용)
    - [example basic](#example-basic)
    - [example shot](#example-shot)
    - [example interrupt](#example-interrupt)
    - [example fifo](#example-fifo)
  - [문서](#문서)
  - [기고](#기고)
  - [저작권](#저작권)
  - [문의하기](#문의하기)

### 설명

/src 디렉토리에는 LibDriver BMP384의 소스 파일이 포함되어 있습니다.

/interface 디렉토리에는 LibDriver BMP384용 플랫폼 독립적인 IIC, SPI버스 템플릿이 포함되어 있습니다.

/test 디렉토리에는 LibDriver BMP384드라이버 테스트 프로그램이 포함되어 있어 칩의 필요한 기능을 간단히 테스트할 수 있습니다.

/example 디렉토리에는 LibDriver BMP384프로그래밍 예제가 포함되어 있습니다.

/doc 디렉토리에는 LibDriver BMP384오프라인 문서가 포함되어 있습니다.

/datasheet 디렉토리에는 BMP384데이터시트가 있습니다.

/project 디렉토리에는 일반적으로 사용되는 Linux 및 마이크로컨트롤러 개발 보드의 프로젝트 샘플이 포함되어 있습니다. 모든 프로젝트는 디버깅 방법으로 셸 스크립트를 사용하며, 자세한 내용은 각 프로젝트의 README.md를 참조하십시오.

/misra 에는 LibDriver misra 코드 검색 결과가 포함됩니다.

### 설치

/interface 디렉토리에서 플랫폼 독립적인 IIC, SPI버스 템플릿을 참조하여 지정된 플랫폼에 대한 IIC, SPI버스 드라이버를 완성하십시오.

/src 디렉터리, 플랫폼용 인터페이스 드라이버 및 자체 드라이버를 프로젝트에 추가합니다. 기본 예제 드라이버를 사용하려면 /example 디렉터리를 프로젝트에 추가합니다.

### 사용

/example 디렉터리의 예제를 참조하여 자신만의 드라이버를 완성할 수 있습니다. 기본 프로그래밍 예제를 사용하려는 경우 사용 방법은 다음과 같습니다.

#### example basic

```C
#include "driver_bmp384_basic.h"

uint8_t res;
uint8_t i;
float temperature_c;
float pressure_pa;

res = bmp384_basic_init(BMP384_INTERFACE_IIC, BMP384_ADDRESS_ADO_LOW);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    bmp384_interface_delay_ms(1000);
    res = bmp384_basic_read((float *)&temperature_c, (float *)&pressure_pa);
    if (res != 0)
    {
        (void)bmp384_basic_deinit();

        return 1;
    }
    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", temperature_c);
    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", pressure_pa);

    ...
        
}

...

(void)bmp384_basic_deinit();

return 0;
```

#### example shot

```C
#include "driver_bmp384_shot.h"

uint8_t res;
uint8_t i;
float temperature_c;
float pressure_pa;

res = bmp384_shot_init(BMP384_INTERFACE_IIC, BMP384_ADDRESS_ADO_LOW);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    bmp384_interface_delay_ms(1000);
    res = bmp384_shot_read((float *)&temperature_c, (float *)&pressure_pa);
    if (res != 0)
    {
        (void)bmp384_shot_deinit();

        return 1;
    }
    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", temperature_c);
    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", pressure_pa);
    
    ...
    
}

...

(void)bmp384_shot_deinit();

return 0;
```

#### example interrupt

```C
#include "driver_bmp384_interrupt.h"

uint8_t res;
uint16_t i, timeout;
uint8_t gs_data_ready_flag;
float gs_temperature_c;
float gs_pressure_pa;

void bmp384_interrupt_receive_callback(uint8_t type)
{
    switch (type)
    {
        case BMP384_INTERRUPT_STATUS_FIFO_WATERMARK :
        {
            break;
        }
        case BMP384_INTERRUPT_STATUS_FIFO_FULL :
        {
            break;
        }
        case BMP384_INTERRUPT_STATUS_DATA_READY :
        {
            /* read temperature pressure */
            if (bmp384_interrupt_read((float *)&gs_temperature_c, (float *)&gs_pressure_pa) != 0)
            {
                bmp384_interface_debug_print("bmp384: read temperature and pressure failed.\n");
           
                return;
            }
            gs_data_ready_flag  = 1;
            
            break;
        }
        default :
        {
            break;
        }
    }
}

res = gpio_interrupt_init();
if (res != 0)
{
    return 1;
}
res = bmp384_interrupt_init(BMP384_INTERFACE_IIC, BMP384_ADDRESS_ADO_LOW, bmp384_interrupt_receive_callback);
if (res != 0)
{
    (void)gpio_interrupt_deinit();

    return 1;
}

...

gs_data_ready_flag = 0;
timeout = 5000;
for (i = 0; i < 3; i++)
{
    while (timeout != 0)
    {
        bmp384_interface_delay_ms(100);
        timeout--;
        if (gs_data_ready_flag != 0)
        {
            break;
        }
        if (timeout == 0)
        {
            (void)gpio_interrupt_deinit();
            (void)bmp384_interrupt_deinit();

            return 1;
        }
    }
    gs_data_ready_flag = 0;
    timeout = 5000;
    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", gs_temperature_c);
    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", gs_pressure_pa);
    
    ...
    
}

...

(void)gpio_interrupt_deinit();
(void)bmp384_interrupt_deinit();

return 0;
```

#### example fifo

```C
#include "driver_bmp384_fifo.h"

uint8_t gs_fifo_full_flag;
uint8_t gs_fifo_watermark_flag;
uint16_t i, timeout;
uint8_t gs_buf[512];
bmp384_frame_t gs_frame[256];

void bmp384_fifo_receive_callback(uint8_t type)
{
    switch (type)
    {
        case BMP384_INTERRUPT_STATUS_FIFO_WATERMARK :
        {
            uint8_t res;
            uint16_t len;
            uint16_t i, frame_len;
            
            len = 512;
            frame_len = 256;
            res = bmp384_fifo_read(gs_buf, len, (bmp384_frame_t *)gs_frame, (uint16_t *)&frame_len);
            if (res != 0)
            {
                bmp384_interface_debug_print("bmp384: fifo read failed.\n");
                
                return;
            }
            for (i = 0; i < frame_len; i++)
            {
                if (gs_frame[i].type == BMP384_FRAME_TYPE_TEMPERATURE)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_PRESSURE)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_SENSORTIME)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: sensortime is %d.\n", gs_frame[i].raw);
                }
                else
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: unknow type.\n");
                }
            }
            gs_fifo_watermark_flag = 1;
            
            break;
        }
        case BMP384_INTERRUPT_STATUS_FIFO_FULL :
        {
            uint8_t res;
            uint16_t len;
            uint16_t i, frame_len;
            
            len = 512;
            frame_len = 256;
            res = bmp384_fifo_read(gs_buf, len, (bmp384_frame_t *)gs_frame, (uint16_t *)&frame_len);
            if (res != 0)
            {
                bmp384_interface_debug_print("bmp384: fifo read failed.\n");
                
                return;
            }
            for (i = 0; i < frame_len; i++)
            {
                if (gs_frame[i].type == BMP384_FRAME_TYPE_TEMPERATURE)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: temperature is %0.2fC.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_PRESSURE)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: pressure is %0.2fPa.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP384_FRAME_TYPE_SENSORTIME)
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: sensortime is %d.\n", gs_frame[i].raw);
                }
                else
                {
                    bmp384_interface_debug_print("bmp384: fifo %d/%d.\n", i+1, frame_len);
                    bmp384_interface_debug_print("bmp384: unknow type.\n");
                }
            }
            gs_fifo_full_flag = 1;
            
            break;
        }
        case BMP384_INTERRUPT_STATUS_DATA_READY :
        {
            break;
        }
        default :
        {
            break;
        }
    }
}

res = gpio_interrupt_init();
if (res != 0)
{
    return 1;
}
res = bmp384_fifo_init(BMP384_INTERFACE_IIC, BMP384_ADDRESS_ADO_LOW, bmp384_fifo_receive_callback);
if (res != 0)
{
    (void)gpio_interrupt_deinit();

    return 1;
}

...

gs_fifo_watermark_flag = 0;
gs_fifo_full_flag = 0;
timeout = 5000;
for (i = 0; i < 3; i++)
{
    while (timeout != 0)
    {
        bmp384_interface_delay_ms(100);
        timeout--;
        if ((gs_fifo_watermark_flag != 0) || (gs_fifo_full_flag != 0))
        {
            break;
        }
        if (timeout == 0)
        {
            (void)gpio_interrupt_deinit();
            (void)bmp384_fifo_deinit();

            return 1;
        }
    }
    gs_fifo_watermark_flag = 0;
    gs_fifo_full_flag = 0;
    timeout = 5000;
    
    ...
    
}
(void)gpio_interrupt_deinit();
(void)bmp384_fifo_deinit();

...

return 0;
```

### 문서

온라인 문서: [https://www.libdriver.com/docs/bmp384/index.html](https://www.libdriver.com/docs/bmp384/index.html).

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