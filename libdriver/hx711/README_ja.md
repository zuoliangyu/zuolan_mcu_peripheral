[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver HX711

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/hx711/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

HX711は、高精度電子はかり用に特別に設計された24ビットA / Dコンバーターチップであり、Haixinテクノロジー集積回路の特許技術を採用しています。 同種の他のチップと比較して、チップセットはより安定しており、高集積化、高速応答、強力な干渉防止という利点があります。 それは電子密度を減らします。 スケールの全体的なコストは、マシン全体のパフォーマンスと信頼性を向上させます。

LibDriver HX711は、LibDiverによって起動されたHX711の全機能ドライバーであり、差分広告読み取り機能を提供します。LibDriverはMISRAに準拠しています。

### 目次

  - [説明](#説明)
  - [インストール](#インストール)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [ドキュメント](#ドキュメント)
  - [貢献](#貢献)
  - [著作権](#著作権)
  - [連絡して](#連絡して)

### 説明

/ srcディレクトリには、LibDriver HX711のソースファイルが含まれています。

/ interfaceディレクトリには、LibDriver HX711用のプラットフォームに依存しないgpioバステンプレートが含まれています。

/ testディレクトリには、チップの必要な機能を簡単にテストできるLibDriver HX711ドライバーテストプログラムが含まれています。

/ exampleディレクトリには、LibDriver HX711プログラミング例が含まれています。

/ docディレクトリには、LibDriver HX711オフラインドキュメントが含まれています。

/ datasheetディレクトリには、HX711データシートが含まれています。

/ projectディレクトリには、一般的に使用されるLinuxおよびマイクロコントローラー開発ボードのプロジェクトサンプルが含まれています。 すべてのプロジェクトは、デバッグ方法としてシェルスクリプトを使用しています。詳細については、各プロジェクトのREADME.mdを参照してください。

/ misraはLibDriver misraコードスキャン結果を含む。

### インストール

/ interfaceディレクトリにあるプラットフォームに依存しないgpioバステンプレートを参照して、指定したプラットフォームのgpioバスドライバを完成させます。

/src ディレクトリ、プラットフォームのインターフェイス ドライバー、および独自のドライバーをプロジェクトに追加します。デフォルトのサンプル ドライバーを使用する場合は、/example ディレクトリをプロジェクトに追加します。

### 使用

/example ディレクトリ内のサンプルを参照して、独自のドライバーを完成させることができます。 デフォルトのプログラミング例を使用したい場合の使用方法は次のとおりです。

#### example basic

```C
#include "driver_hx711_basic.h"

uint8_t res;
uint8_t i;
int32_t raw_voltage;
double voltage_v;

res = hx711_basic_init();
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    res = hx711_basic_read((int32_t *)&raw_voltage, (double *)&voltage_v);
    if (res != 0)
    {
        (void)hx711_basic_deinit();

        return 1;
    }
    hx711_interface_delay_ms(1000);
    hx711_interface_debug_print("hx711: raw voltage is %d.\n", raw_voltage);
    hx711_interface_debug_print("hx711: voltage is %fmV.\n", voltage_v); 

    ...
    
}

...

(void)hx711_basic_deinit();

return 0;
```

### ドキュメント

オンラインドキュメント: [https://www.libdriver.com/docs/hx711/index.html](https://www.libdriver.com/docs/hx711/index.html)。

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