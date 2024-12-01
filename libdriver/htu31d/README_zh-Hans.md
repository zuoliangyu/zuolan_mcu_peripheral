[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver HTU31D

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/htu31d/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

HTU31是市场上最小、最准确的湿度传感器之一。TE Connectivity精密工程和在湿度和温度组合传感器方面20多年的经验使这款新产品具有快速响应时间、精确测量、低滞后、对回流组装过程的高鲁棒性和持续性能，即使暴露在极端温度[-40°至125°C]和湿度[0%RH至100%RH]的环境中依然如此。

LibDriver HTU31D是LibDriver推出的HTU31D全功能驱动，该驱动提供温度、相对湿度读取的功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver HTU31D的源文件。

/interface目录包含了LibDriver HTU31D与平台无关的IIC总线模板。

/test目录包含了LibDriver HTU31D驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver HTU31D编程范例。

/doc目录包含了LibDriver HTU31D离线文档。

/datasheet目录包含了HTU31D数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的IIC总线模板，完成指定平台的IIC总线驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

#### example basic

```C
#include "driver_htu31d_basic.h"

uint8_t res;
uint8_t i;
float temperature;
uint8_t humidity;

res = htu31d_basic_init();
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    htu31d_interface_delay_ms(2000);
    res = htu31d_basic_read((float *)&temperature, (uint8_t *)&humidity);
    if (res != 0)
    {
        (void)htu31d_basic_deinit();

        return 1;
    }
    htu31d_interface_debug_print("htu31d: temperature is %0.2fC.\n", temperature);
    htu31d_interface_debug_print("htu31d: humidity is %d%%.\n", humidity); 
    
    ...
        
}

...

(void)htu31d_basic_deinit();

return 0;
```

### 文档

在线文档: [https://www.libdriver.com/docs/htu31d/index.html](https://www.libdriver.com/docs/htu31d/index.html)。

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