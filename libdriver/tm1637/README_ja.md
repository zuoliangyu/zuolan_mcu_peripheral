[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver TM1637

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/tm1637/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

TM1637 は、キーボード スキャン インターフェイスを備えた LED (発光ダイオード ディスプレイ) 駆動制御特殊回路の一種で、MCU デジタル インターフェイス、データ ラッチ、LED 高圧ドライブ、キーボード スキャンが内部で統合されています。 本製品は、優れた性能と高品質を備えたDIP20/SOP20パッケージタイプで、主に電磁調理器や電子レンジ、小型家電製品の表示駆動に使用されます。

LibDriver TM1637 は、LibDriver によって起動される TM1637 の全機能ドライバーです。 LibDriver TM1637 は、デジタル チューブ ディスプレイ、キーパッド スキャン、その他の機能を提供します。 LibDriver は MISRA に準拠しています。

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

/ srcディレクトリには、LibDriver TM1637のソースファイルが含まれています。

/ interfaceディレクトリには、LibDriver TM1637用のプラットフォームに依存しないIICバステンプレートが含まれています。

/ testディレクトリには、チップの必要な機能を簡単にテストできるLibDriver TM1637ドライバーテストプログラムが含まれています。

/ exampleディレクトリには、LibDriver TM1637プログラミング例が含まれています。

/ docディレクトリには、LibDriver TM1637オフラインドキュメントが含まれています。

/ datasheetディレクトリには、TM1637データシートが含まれています。

/ projectディレクトリには、一般的に使用されるLinuxおよびマイクロコントローラー開発ボードのプロジェクトサンプルが含まれています。 すべてのプロジェクトは、デバッグ方法としてシェルスクリプトを使用しています。詳細については、各プロジェクトのREADME.mdを参照してください。

/ misraはLibDriver misraコードスキャン結果を含む。

### インストール

/ interfaceディレクトリにあるプラットフォームに依存しないIICバステンプレートを参照して、指定したプラットフォームのIICバスドライバを完成させます。

/src ディレクトリ、プラットフォームのインターフェイス ドライバー、および独自のドライバーをプロジェクトに追加します。デフォルトのサンプル ドライバーを使用する場合は、/example ディレクトリをプロジェクトに追加します。

### 使用

/example ディレクトリ内のサンプルを参照して、独自のドライバーを完成させることができます。 デフォルトのプログラミング例を使用したい場合の使用方法は次のとおりです。

#### example basic

```C
#include "driver_tm1637_basic.h"

uint8_t res;
uint8_t seg;
uint8_t k;
uint8_t number[] = {TM1637_NUMBER_0, TM1637_NUMBER_1, TM1637_NUMBER_2,
                    TM1637_NUMBER_3, TM1637_NUMBER_4, TM1637_NUMBER_5,
                    TM1637_NUMBER_6, TM1637_NUMBER_7, TM1637_NUMBER_8, TM1637_NUMBER_9};

/* init */
res = tm1637_basic_init();
if (res != 0)
{
    return 1;
}

...
    
/* write */
res = tm1637_basic_write(0, &number[0], 6);
if (res != 0)
{
    (void)tm1637_basic_deinit();
    
    return 1;
}

...
    
/* read */
res = tm1637_basic_read(&seg, &k);
if (res != 0)
{
    (void)tm1637_basic_deinit();
    
    return 1;
}

/* output */
tm1637_interface_debug_print("tm1637: seg: 0x%02X.\n", seg);
tm1637_interface_debug_print("tm1637: k: 0x%02X.\n", k);

...
    
/* on */
res = tm1637_basic_display_on();
if (res != 0)
{
    (void)tm1637_basic_deinit();
    
    return 1;
}

...
    
/* off */
res = tm1637_basic_display_off();
if (res != 0)
{
    (void)tm1637_basic_deinit();
    
    return 1;
}

...
    
/* deinit */
(void)tm1637_basic_deinit();

return 0;
```

### ドキュメント

オンラインドキュメント: [https://www.libdriver.com/docs/tm1637/index.html](https://www.libdriver.com/docs/tm1637/index.html)。

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