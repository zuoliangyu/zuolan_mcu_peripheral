[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver BMP388

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/bmp388/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

BMP388是一款成熟的帶有壓力和溫度測量的數字傳感器。傳感器1Hz、3.4uA的測量模式可以使其工作在諸多電池驅動的設備，例如手機、GPS或者手錶。 BMP388可被用在飛行玩具、無人機、手機平板GPS、導航系統、便攜式健康設備、室內監測和手錶等。

LibDriver BMP388是LibDriver推出的BMP388全功能驅動，該驅動提供壓強溫度連續讀取、壓強溫度單次讀取、中斷讀取和FIFO採集等功能並且它符合MISRA標準。

### 目錄

  - [說明](#說明)
  - [安裝](#安裝)
  - [使用](#使用)
    - [example basic](#example-basic)
    - [example shot](#example-shot)
    - [example interrupt](#example-interrupt)
    - [example fifo](#example-fifo)
  - [文檔](#文檔)
  - [貢獻](#貢獻)
  - [版權](#版權)
  - [聯繫我們](#聯繫我們)

### 說明

/src目錄包含了LibDriver BMP388的源文件。

/interface目錄包含了LibDriver BMP388與平台無關的IIC、SPI總線模板。

/test目錄包含了LibDriver BMP388驅動測試程序，該程序可以簡單的測試芯片必要功能。

/example目錄包含了LibDriver BMP388編程範例。

/doc目錄包含了LibDriver BMP388離線文檔。

/datasheet目錄包含了BMP388數據手冊。

/project目錄包含了常用Linux與單片機開發板的工程樣例。所有工程均採用shell腳本作為調試方法，詳細內容可參考每個工程裡面的README.md。

/misra目錄包含了LibDriver MISRA程式碼掃描結果。

### 安裝

參考/interface目錄下與平台無關的IIC、SPI總線模板，完成指定平台的IIC、SPI總線驅動。

將/src目錄，您使用平臺的介面驅動和您開發的驅動加入工程，如果您想要使用默認的範例驅動，可以將/example目錄加入您的工程。

### 使用

您可以參考/example目錄下的程式設計範例完成適合您的驅動，如果您想要使用默認的程式設計範例，以下是它們的使用方法。

#### example basic

```C
#include "driver_bmp388_basic.h"

uint8_t res;
uint8_t i;
float temperature_c;
float pressure_pa;

res = bmp388_basic_init(BMP388_INTERFACE_IIC, BMP388_ADDRESS_ADO_LOW);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    bmp388_interface_delay_ms(1000);
    res = bmp388_basic_read((float *)&temperature_c, (float *)&pressure_pa);
    if (res != 0)
    {
        (void)bmp388_basic_deinit();

        return 1;
    }
    bmp388_interface_debug_print("bmp388: temperature is %0.2fC.\n", temperature_c);
    bmp388_interface_debug_print("bmp388: pressure is %0.2fPa.\n", pressure_pa);

    ...
        
}

...

(void)bmp388_basic_deinit();

return 0;
```

#### example shot

```C
#include "driver_bmp388_shot.h"

uint8_t res;
uint8_t i;
float temperature_c;
float pressure_pa;

res = bmp388_shot_init(BMP388_INTERFACE_IIC, BMP388_ADDRESS_ADO_LOW);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    bmp388_interface_delay_ms(1000);
    res = bmp388_shot_read((float *)&temperature_c, (float *)&pressure_pa);
    if (res != 0)
    {
        (void)bmp388_shot_deinit();

        return 1;
    }
    bmp388_interface_debug_print("bmp388: temperature is %0.2fC.\n", temperature_c);
    bmp388_interface_debug_print("bmp388: pressure is %0.2fPa.\n", pressure_pa);
    
    ...
    
}

...

(void)bmp388_shot_deinit();

return 0;
```

#### example interrupt

```C
#include "driver_bmp388_interrupt.h"

uint8_t res;
uint16_t i, timeout;
uint8_t gs_data_ready_flag;
float gs_temperature_c;
float gs_pressure_pa;

void bmp388_interrupt_receive_callback(uint8_t type)
{
    switch (type)
    {
        case BMP388_INTERRUPT_STATUS_FIFO_WATERMARK :
        {
            break;
        }
        case BMP388_INTERRUPT_STATUS_FIFO_FULL :
        {
            break;
        }
        case BMP388_INTERRUPT_STATUS_DATA_READY :
        {
            /* read temperature pressure */
            if (bmp388_interrupt_read((float *)&gs_temperature_c, (float *)&gs_pressure_pa) != 0)
            {
                bmp388_interface_debug_print("bmp388: read temperature and pressure failed.\n");
           
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
res = bmp388_interrupt_init(BMP388_INTERFACE_IIC, BMP388_ADDRESS_ADO_LOW, bmp388_interrupt_receive_callback);
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
        bmp388_interface_delay_ms(100);
        timeout--;
        if (gs_data_ready_flag != 0)
        {
            break;
        }
        if (timeout == 0)
        {
            (void)gpio_interrupt_deinit();
            (void)bmp388_interrupt_deinit();

            return 1;
        }
    }
    gs_data_ready_flag = 0;
    timeout = 5000;
    bmp388_interface_debug_print("bmp388: temperature is %0.2fC.\n", gs_temperature_c);
    bmp388_interface_debug_print("bmp388: pressure is %0.2fPa.\n", gs_pressure_pa);
    
    ...
    
}

...

(void)gpio_interrupt_deinit();
(void)bmp388_interrupt_deinit();

return 0;
```

#### example fifo

```C
#include "driver_bmp388_fifo.h"

uint8_t gs_fifo_full_flag;
uint8_t gs_fifo_watermark_flag;
uint16_t i, timeout;
uint8_t gs_buf[512];
bmp388_frame_t gs_frame[256];

void bmp388_fifo_receive_callback(uint8_t type)
{
    switch (type)
    {
        case BMP388_INTERRUPT_STATUS_FIFO_WATERMARK :
        {
            uint8_t res;
            uint16_t len;
            uint16_t i, frame_len;
            
            len = 512;
            frame_len = 256;
            res = bmp388_fifo_read(gs_buf, len, (bmp388_frame_t *)gs_frame, (uint16_t *)&frame_len);
            if (res != 0)
            {
                bmp388_interface_debug_print("bmp388: fifo read failed.\n");
                
                return;
            }
            for (i = 0; i < frame_len; i++)
            {
                if (gs_frame[i].type == BMP388_FRAME_TYPE_TEMPERATURE)
                {
                    bmp388_interface_debug_print("bmp388: fifo %d/%d.\n", i+1, frame_len);
                    bmp388_interface_debug_print("bmp388: temperature is %0.2fC.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP388_FRAME_TYPE_PRESSURE)
                {
                    bmp388_interface_debug_print("bmp388: fifo %d/%d.\n", i+1, frame_len);
                    bmp388_interface_debug_print("bmp388: pressure is %0.2fPa.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP388_FRAME_TYPE_SENSORTIME)
                {
                    bmp388_interface_debug_print("bmp388: fifo %d/%d.\n", i+1, frame_len);
                    bmp388_interface_debug_print("bmp388: sensortime is %d.\n", gs_frame[i].raw);
                }
                else
                {
                    bmp388_interface_debug_print("bmp388: fifo %d/%d.\n", i+1, frame_len);
                    bmp388_interface_debug_print("bmp388: unknow type.\n");
                }
            }
            gs_fifo_watermark_flag = 1;
            
            break;
        }
        case BMP388_INTERRUPT_STATUS_FIFO_FULL :
        {
            uint8_t res;
            uint16_t len;
            uint16_t i, frame_len;
            
            len = 512;
            frame_len = 256;
            res = bmp388_fifo_read(gs_buf, len, (bmp388_frame_t *)gs_frame, (uint16_t *)&frame_len);
            if (res != 0)
            {
                bmp388_interface_debug_print("bmp388: fifo read failed.\n");
                
                return;
            }
            for (i = 0; i < frame_len; i++)
            {
                if (gs_frame[i].type == BMP388_FRAME_TYPE_TEMPERATURE)
                {
                    bmp388_interface_debug_print("bmp388: fifo %d/%d.\n", i+1, frame_len);
                    bmp388_interface_debug_print("bmp388: temperature is %0.2fC.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP388_FRAME_TYPE_PRESSURE)
                {
                    bmp388_interface_debug_print("bmp388: fifo %d/%d.\n", i+1, frame_len);
                    bmp388_interface_debug_print("bmp388: pressure is %0.2fPa.\n", gs_frame[i].data);
                }
                else if (gs_frame[i].type == BMP388_FRAME_TYPE_SENSORTIME)
                {
                    bmp388_interface_debug_print("bmp388: fifo %d/%d.\n", i+1, frame_len);
                    bmp388_interface_debug_print("bmp388: sensortime is %d.\n", gs_frame[i].raw);
                }
                else
                {
                    bmp388_interface_debug_print("bmp388: fifo %d/%d.\n", i+1, frame_len);
                    bmp388_interface_debug_print("bmp388: unknow type.\n");
                }
            }
            gs_fifo_full_flag = 1;
            
            break;
        }
        case BMP388_INTERRUPT_STATUS_DATA_READY :
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
res = bmp388_fifo_init(BMP388_INTERFACE_IIC, BMP388_ADDRESS_ADO_LOW, bmp388_fifo_receive_callback);
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
        bmp388_interface_delay_ms(100);
        timeout--;
        if ((gs_fifo_watermark_flag != 0) || (gs_fifo_full_flag != 0))
        {
            break;
        }
        if (timeout == 0)
        {
            (void)gpio_interrupt_deinit();
            (void)bmp388_fifo_deinit();

            return 1;
        }
    }
    gs_fifo_watermark_flag = 0;
    gs_fifo_full_flag = 0;
    timeout = 5000;
    
    ...
    
}
(void)gpio_interrupt_deinit();
(void)bmp388_fifo_deinit();

...

return 0;
```

### 文檔

在線文檔: [https://www.libdriver.com/docs/bmp388/index.html](https://www.libdriver.com/docs/bmp388/index.html)。

離線文檔: /doc/html/index.html。

### 貢獻

請參攷CONTRIBUTING.md。

### 版權

版權 (c) 2015 - 現在 LibDriver 版權所有

MIT 許可證（MIT）

特此免費授予任何獲得本軟件副本和相關文檔文件（下稱“軟件”）的人不受限制地處置該軟件的權利，包括不受限制地使用、複製、修改、合併、發布、分發、轉授許可和/或出售該軟件副本，以及再授權被配發了本軟件的人如上的權利，須在下列條件下：

上述版權聲明和本許可聲明應包含在該軟件的所有副本或實質成分中。

本軟件是“如此”提供的，沒有任何形式的明示或暗示的保證，包括但不限於對適銷性、特定用途的適用性和不侵權的保證。在任何情況下，作者或版權持有人都不對任何索賠、損害或其他責任負責，無論這些追責來自合同、侵權或其它行為中，還是產生於、源於或有關於本軟件以及本軟件的使用或其它處置。

### 聯繫我們

請聯繫lishifenging@outlook.com。
