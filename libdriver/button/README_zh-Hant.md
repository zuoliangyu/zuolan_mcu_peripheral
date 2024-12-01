[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver BUTTON

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/button/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

按鈕是一種簡單的開關機制用於控制機器或過程的某些方面。 按鈕通常由硬質資料製成，通常是塑膠或金屬。 表面通常是平坦的或形狀適合人的手指或手以便容易地被壓下或推動。 按鈕通常是偏置開關，儘管許多非偏置按鈕（由於其物理性質）仍然需要彈簧才能返回到未按下的狀態。

LibDriver BUTTON是LibDriver推出的BUTTON全功能驅動，該驅動提供按壓檢測、釋放檢測、按一下檢測、按兩下檢測、三擊檢測、重複按鍵檢測、短按檢測、長按檢測等功能並且它符合MISRA標準。

LibDriver BUTTON支持單按鈕檢測，可以以更高效的方法運行，如果您需要多按鍵或者矩陣按鍵檢測，請參攷[https://github.com/libdriver/multi_button](https://github.com/libdriver/multi_button)。

### 目錄

  - [說明](#說明)
  - [安裝](#安裝)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文檔](#文檔)
  - [貢獻](#貢獻)
  - [版權](#版權)
  - [聯繫我們](#聯繫我們)

### 說明

/src目錄包含了LibDriver BUTTON的源文件。

/interface目錄包含了LibDriver BUTTON與平台無關的GPIO總線模板。

/test目錄包含了LibDriver BUTTON驅動測試程序，該程序可以簡單的測試芯片必要功能。

/example目錄包含了LibDriver BUTTON編程範例。

/doc目錄包含了LibDriver BUTTON離線文檔。

/datasheet目錄包含了BUTTON數據手冊。

/project目錄包含了常用Linux與單片機開發板的工程樣例。所有工程均採用shell腳本作為調試方法，詳細內容可參考每個工程裡面的README.md。

/misra目錄包含了LibDriver MISRA程式碼掃描結果。

### 安裝

參考/interface目錄下與平台無關的GPIO總線模板，完成指定平台的GPIO總線驅動。

將/src目錄，您使用平臺的介面驅動和您開發的驅動加入工程，如果您想要使用默認的範例驅動，可以將/example目錄加入您的工程。

### 使用

您可以參考/example目錄下的程式設計範例完成適合您的驅動，如果您想要使用默認的程式設計範例，以下是它們的使用方法。

#### example basic

```C
#include "driver_button_basic.h"

uint8_t res;
uint8_t (*g_gpio_irq)(uint8_t) = NULL;
uint8_t (*g_period_irq)(void) = NULL;

static void a_receive_callback(button_t *data)
{
    switch (data->status)
    {
        case BUTTON_STATUS_PRESS :
        {
            break;
        }
        case BUTTON_STATUS_RELEASE :
        {
            break;
        }
        case BUTTON_STATUS_SINGLE_CLICK :
        {
            button_interface_debug_print("button: irq single click.\n");

            break;
        }
        case BUTTON_STATUS_DOUBLE_CLICK :
        {
            button_interface_debug_print("button: irq double click.\n");

            break;
        }
        case BUTTON_STATUS_TRIPLE_CLICK :
        {
            button_interface_debug_print("button: irq triple click.\n");

            break;
        }
        case BUTTON_STATUS_REPEAT_CLICK :
        {
            button_interface_debug_print("button: irq repeat click with %d times.\n", data->times);

            break;
        }
        case BUTTON_STATUS_SHORT_PRESS_START :
        {
            button_interface_debug_print("button: irq short press start.\n");

            break;
        }
        case BUTTON_STATUS_SHORT_PRESS_END :
        {
            button_interface_debug_print("button: irq short press end.\n");

            break;
        }
        case BUTTON_STATUS_LONG_PRESS_START :
        {
            button_interface_debug_print("button: irq long press start.\n");

            break;
        }
        case BUTTON_STATUS_LONG_PRESS_HOLD :
        {
            button_interface_debug_print("button: irq long press hold.\n");

            break;
        }
        case BUTTON_STATUS_LONG_PRESS_END :
        {
            button_interface_debug_print("button: irq long press end.\n");

            break;
        }
        default :
        {
            button_interface_debug_print("button: irq unknown status.\n");

            break;
        }
    }
}

/* gpio init */
res = gpio_interrupt_init();
if (res != 0)
{
    return 1;
}

/* set the irq */
g_gpio_irq = button_basic_irq_handler;
g_period_irq = button_basic_period_handler;

/* basic init */
res = button_basic_init(a_receive_callback);
if (res != 0)
{
    (void)gpio_interrupt_deinit();
    g_gpio_irq = NULL;
    g_period_irq = NULL;
}

...
    
while (1)
{
    ...
}

...

/* basic deinit */
(void)button_basic_deinit();

/* gpio deinit */
(void)gpio_interrupt_deinit();
g_gpio_irq = NULL;
g_period_irq = NULL;

return 0;
```

### 文檔

在線文檔: [https://www.libdriver.com/docs/button/index.html](https://www.libdriver.com/docs/button/index.html)。

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