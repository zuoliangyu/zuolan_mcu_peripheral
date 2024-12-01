[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver STS4X

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sts4x/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

STS4x は、さまざまな精度クラスを提供する完全デジタル温度センサー プラットフォームです。I2C インターフェイスは、複数の事前設定された I2C アドレスを提供し、超低消費電力を実現します。コスト重視で設計されたこの 4 ピン デュアル フラット ノーリード パッケージは、表面実装技術 (SMT) 処理に適しています。

LibDriver STS4X は、LibDriver によってリリースされた STS4X のフル機能ドライバーです。温度連続モード読み取りと温度単一モード読み取りの機能を提供します。LibDriver は MISRA に準拠しています。

### 目次

  - [説明](#説明)
  - [インストール](#インストール)
  - [使用](#使用)
    - [example basic](#example-basic)
    - [example shot](#example-shot)
  - [ドキュメント](#ドキュメント)
  - [貢献](#貢献)
  - [著作権](#著作権)
  - [連絡して](#連絡して)

### 説明

/ srcディレクトリには、LibDriver STS4Xのソースファイルが含まれています。

/ interfaceディレクトリには、LibDriver STS4X用のプラットフォームに依存しないIICバステンプレートが含まれています。

/ testディレクトリには、チップの必要な機能を簡単にテストできるLibDriver STS4Xドライバーテストプログラムが含まれています。

/ exampleディレクトリには、LibDriver STS4Xプログラミング例が含まれています。

/ docディレクトリには、LibDriver STS4Xオフラインドキュメントが含まれています。

/ datasheetディレクトリには、STS4Xデータシートが含まれています。

/ projectディレクトリには、一般的に使用されるLinuxおよびマイクロコントローラー開発ボードのプロジェクトサンプルが含まれています。 すべてのプロジェクトは、デバッグ方法としてシェルスクリプトを使用しています。詳細については、各プロジェクトのREADME.mdを参照してください。

/ misraはLibDriver misraコードスキャン結果を含む。

### インストール

/ interfaceディレクトリにあるプラットフォームに依存しないIICバステンプレートを参照して、指定したプラットフォームのIICバスドライバを完成させます。

/src ディレクトリ、プラットフォームのインターフェイス ドライバー、および独自のドライバーをプロジェクトに追加します。デフォルトのサンプル ドライバーを使用する場合は、/example ディレクトリをプロジェクトに追加します。

### 使用

/example ディレクトリ内のサンプルを参照して、独自のドライバーを完成させることができます。 デフォルトのプログラミング例を使用したい場合の使用方法は次のとおりです。

#### example basic

```C
#include "driver_sts4x_basic.h"

uint8_t res;
uint8_t i;
float temperature;

res = sts4x_basic_init(STS4X_ADDRESS_0);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    sts4x_interface_delay_ms(1000);
    res = sts4x_basic_read((float *)&temperature);
    if (res != 0)
    {
        (void)sts4x_basic_deinit();

        return 1;
    }
    sts4x_interface_debug_print("sts4x: temperature is %0.2fC.\n", temperature);
    
    ...
    
}

...

(void)sts4x_basic_deinit();

return 0;
```

#### example shot

```c
#include "driver_sts4x_shot.h"

uint8_t res;
uint8_t i;
float temperature;

res = sts4x_shot_init(STS4X_ADDRESS_0);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    sts4x_interface_delay_ms(1000);
    res = sts4x_shot_read((float *)&temperature);
    if (res != 0)
    {
        (void)sts4x_shot_deinit();

        return 1;
    }
    sts4x_interface_debug_print("sts4x: temperature is %0.2fC.\n", temperature);
    
    ...
    
}

...

(void)sts4x_shot_deinit();

return 0;
```

### ドキュメント

オンラインドキュメント: [https://www.libdriver.com/docs/sts4x/index.html](https://www.libdriver.com/docs/sts4x/index.html)。

オフラインドキュメント: /doc/html/index.html。

### 貢献

CONTRIBUTING.mdを参照してください。

### 著作権

著作権（c）2015-今 LibDriver 全著作権所有

MITライセンス（MIT）

このソフトウェアおよび関連するドキュメントファイル（「ソフトウェア」）のコピーを取得した人は、無制限の使用、複製、変更、組み込み、公開、配布、サブライセンスを含む、ソフトウェアを処分する権利を制限なく付与されます。ソフトウェアのライセンスおよび/またはコピーの販売、および上記のようにソフトウェアが配布された人の権利のサブライセンスは、次の条件に従うものとします。

上記の著作権表示およびこの許可通知は、このソフトウェアのすべてのコピーまたは実体に含まれるものとします。

このソフトウェアは「現状有姿」で提供され、商品性、特定目的への適合性、および非侵害の保証を含むがこれらに限定されない、明示または黙示を問わず、いかなる種類の保証もありません。 いかなる場合も、作者または著作権所有者は、契約、不法行為、またはその他の方法で、本ソフトウェアおよび本ソフトウェアの使用またはその他の廃棄に起因または関連して、請求、損害、またはその他の責任を負わないものとします。

### 連絡して

お問い合わせくださいlishifenging@outlook.com。