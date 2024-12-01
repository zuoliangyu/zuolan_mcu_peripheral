[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SSD1351

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/ssd1351/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SSD1351是一个CMOS OLED/PLED驱动器，具有384个段和128个公共输出，支持高达128 x 128 RGB点阵显示。该芯片是为普通阴极型OLED/PLED设计的面板。SSD1351具有嵌入式图形显示数据RAM（GDDRAM）。它支持8、16、18位8080/6800并行接口和串行外设接口。它有256级对比度和262K色控件，在OLED面板上提供生动的彩色显示。

LibDriver SSD1351是LibDriver推出的SSD1351的全功能驱动，该驱动提供绘制单点，填充块，图片显示等功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
    - [example advance](#example-advance)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver SSD1351的源文件。

/interface目录包含了LibDriver SSD1351与平台无关的SPI总线模板。

/test目录包含了LibDriver SSD1351驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver SSD1351编程范例。

/doc目录包含了LibDriver SSD1351离线文档。

/datasheet目录包含了SSD1351数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的SPI总线模板，完成指定平台的SPI总线驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

#### example basic

```C
#include "driver_ssd1351_basic.h"

uint8_t res;

res = ssd1351_basic_init();
if (res != 0)
{
    ssd1351_interface_debug_print("ssd1351: init failed.\n");

    return 1;
}

...

res = ssd1351_basic_clear();
if (res != 0)
{
    ssd1351_interface_debug_print("ssd1351: clear screen failed.\n");
    (void)ssd1351_basic_deinit();

    return 1;
}
res = ssd1351_basic_string(0, 0, "123", 3, 0xFFFF, SSD1351_FONT_16);
if (res != 0)
{
    ssd1351_interface_debug_print("ssd1351: show string failed.\n");
    (void)ssd1351_basic_deinit();

    return 1;
}

...

res = ssd1351_basic_rect(0, 32, 32, 32, 0xFFFF);
if (res != 0)
{
    (void)ssd1351_basic_deinit();

    return 1;
}

...

(void)ssd1351_basic_deinit();

return 0;
```

#### example advance

图像提取格式如下，颜色格式是RGB565。

<div align=center>
<img src="/doc/image/image_format.svg" width="220" height="220"/>
</div>

```C
#include "driver_ssd1351_advance.h"

uint8_t res;
uint16_t image[16384];

res = ssd1351_advance_init();
if (res != 0)
{
    ssd1351_interface_debug_print("ssd1351: init failed.\n");

    return 1;
}

...

res = ssd1351_advance_clear();
if (res != 0)
{
    ssd1351_interface_debug_print("ssd1351: clear screen failed.\n");
    (void)ssd1351_advance_deinit();

    return 1;
}
res = ssd1351_advance_string(0, 0, "123", 3, 0xFFFF, SSD1351_FONT_16);
if (res != 0)
{
    ssd1351_interface_debug_print("ssd1351: show string failed.\n");
    (void)ssd1351_advance_deinit();

    return 1;
}

...

res = ssd1351_advance_write_point(56, 56, 0xFF00);
if (res != 0)
{
    (void)ssd1351_advance_deinit();

    return 1;
}

...

res = ssd1351_advance_rect(0, 32, 32, 32, 0xFFFF);
if (res != 0)
{
    (void)ssd1351_advance_deinit();

    return 1;
}

...

res = ssd1351_advance_set_scroll(1, 0, 128, SSD1351_SCROLL_MODE_NORMAL);
if (res != 0)
{
    (void)ssd1351_advance_deinit();

    return 1;
}
res = ssd1351_advance_enable_scroll();
if (res != 0)
{
    (void)ssd1351_advance_deinit();

    return 1;
}

...

res = ssd1351_advance_draw_pictrue_16bits(0, 0, 0, 0, image);
if (res != 0)
{
    (void)ssd1351_advance_deinit();

    return 1;
}

...

(void)ssd1351_advance_deinit();

return 0;
```

### 文档

在线文档: [https://www.libdriver.com/docs/ssd1351/index.html](https://www.libdriver.com/docs/ssd1351/index.html)。

离线文档: /doc/html/index.html。

### 贡献

请参考CONTRIBUTING.md。

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com。