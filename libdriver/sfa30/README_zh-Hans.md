[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SFA30

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue)](https://www.libdriver.com/docs/sfa30/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SFA30是一款基于电化学传感技术的甲醛检测模块，针对最低的误报率进行了优化。SFA30 HCHO传感器对乙醇具有低交叉灵敏度，并经过优化，可在低百万分之一（ppb）范围内工作，以准确检测世界卫生组织室内暴露参考值周围的低HCHO浓度。通过集成Sensirion RHT传感器和集成微处理器进行温度和湿度补偿，确保在不断变化的室内环境中具有可靠的性能。该传感器能够承受储存、搬运和运输过程中的不利环境条件。由于其先进的防干技术，该传感器的使用寿命为6年。每个SFA30都经过工厂校准，可以通过I2C或UART接口轻松集成到您的设备中。低功耗允许电池运行。这使得SFA30成为一种可靠、易于使用和高质量的HCHO和RHT组合传感解决方案。

LibDriver SFA30是LibDriver推出的SFA30的全功能驱动，该驱动提供甲醛浓度读取、温度读取、湿度读取和SN读取等功能并且它符合MISRA标准。

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

/src目录包含了LibDriver SFA30的源文件。

/interface目录包含了LibDriver SFA30与平台无关的IIC、UART总线模板。

/test目录包含了LibDriver SFA30驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver SFA30编程范例。

/doc目录包含了LibDriver SFA30离线文档。

/datasheet目录包含了SFA30数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的IIC、UART总线模板，完成指定平台的IIC、UART总线驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

#### example basic

```C
#include "driver_sfa30_basic.h"

uint8_t res;
char sn[32];
uint32_t i;

/* init */
res = sfa30_basic_init(interface);
if (res != 0)
{
    return 1;
}

/* get the sn */
res = sfa30_basic_get_device_information((char *)sn);
if (res != 0)
{
    (void)sfa30_basic_deinit();

    return 1;
}

/* print */
sfa30_interface_debug_print("sfa30: sn is %s.\n", sn);

/* delay 2000 ms */
sfa30_interface_delay_ms(2000);

/* loop */
for (i = 0; i < times; i++)
{
    sfa30_data_t data;

    /* read data */
    res = sfa30_basic_read(&data);
    if (res != 0)
    {
        (void)sfa30_basic_deinit();

        return 1;
    }

    /* print */
    sfa30_interface_debug_print("sfa30: %d/%d.\n", i + 1, times);
    sfa30_interface_debug_print("sfa30: formaldehyde is %0.2fppb.\n", data.formaldehyde);
    sfa30_interface_debug_print("sfa30: humidity is %0.2f%%.\n", data.humidity);
    sfa30_interface_debug_print("sfa30: temperature is %0.2fC.\n", data.temperature);

    /* delay 2000 ms */
    sfa30_interface_delay_ms(2000);
}

/* deinit */
(void)sfa30_basic_deinit();

return 0;
```

### 文档

在线文档: [https://www.libdriver.com/docs/sfa30/index.html](https://www.libdriver.com/docs/sfa30/index.html)。

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