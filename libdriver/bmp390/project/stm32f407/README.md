### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

SPI Pin: SCK/MISO/MOSI/CS  PA5/PA6/PA7/PA4.

GPIO Pin: INT PB0.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. BMP390

#### 3.1 Command Instruction

1. Show bmp390 chip and driver information.

   ```shell
   bmp390 (-i | --information)
   ```

2. Show bmp390 help.

   ```shell
   bmp390 (-h | --help)
   ```

3. Show bmp390 pin connections of the current board.

   ```shell
   bmp390 (-p | --port)
   ```

4. Run bmp390 register test.

   ```shell
   bmp390 (-t reg | --test=reg) [--addr=<0 | 1>] [--interface=<iic | spi>]
   ```

5. Run bmp390 read test, num means the test times.

   ```shell
   bmp390 (-t read | --test=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

6. Run bmp390 interrupt test, num means the test times.

   ```shell
   bmp390 (-t int | --test=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

7. Run bmp390 fifo test, num means the test times. 

   ```shell
   bmp390 (-t fifo | --test=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

8. Run bmp390 read function, num means the read times.

   ```shell
   bmp390 (-e read | --example=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

9. Run bmp390 shot function, num means the read times.

   ```shell
   bmp390 (-e shot | --example=shot) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

10. Run bmp390 interrupt function, num means the read times. 

    ```shell
    bmp390 (-e int | --example=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
    ```

11. Run bmp390 fifo function, num means the read times.

    ```shell
    bmp390 (-e fifo | --example=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>] 
    ```

#### 3.2 Command Example

```shell
bmp390 -i

bmp390: chip is Bosch BMP390.
bmp390: manufacturer is Bosch.
bmp390: interface is IIC SPI.
bmp390: driver version is 1.0.
bmp390: min supply voltage is 1.6V.
bmp390: max supply voltage is 3.6V.
bmp390: max current is 0.73mA.
bmp390: max temperature is 85.0C.
bmp390: min temperature is -40.0C.
```

```shell
bmp390 -p

bmp390: SPI interface SCK connected to GPIOA PIN5.
bmp390: SPI interface MISO connected to GPIOA PIN6.
bmp390: SPI interface MOSI connected to GPIOA PIN7.
bmp390: SPI interface CS connected to GPIOA PIN4.
bmp390: IIC interface SCL connected to GPIOB PIN8.
bmp390: IIC interface SDA connected to GPIOB PIN9.
bmp390: INT connected to GPIOB PIN0.
```

```shell
bmp390 -t reg --addr=0 --interface=iic

bmp390: chip is Bosch BMP390.
bmp390: manufacturer is Bosch.
bmp390: interface is IIC SPI.
bmp390: driver version is 1.0.
bmp390: min supply voltage is 1.6V.
bmp390: max supply voltage is 3.6V.
bmp390: max current is 0.73mA.
bmp390: max temperature is 85.0C.
bmp390: min temperature is -40.0C.
bmp390: start register test.
bmp390: bmp390_set_interface/bmp390_get_interface test.
bmp390: set interface iic.
bmp390: check interface ok.
bmp390: set interface spi.
bmp390: check interface ok.
bmp390: bmp390_set_addr_pin/bmp390_get_addr_pin test.
bmp390: set addr pin low.
bmp390: check addr pin ok.
bmp390: set addr pin high.
bmp390: check addr pin ok.
bmp390: bmp390_set_fifo_watermark/bmp390_get_fifo_watermark test.
bmp390: set fifo watermark 432.
bmp390: check fifo watermark ok.
bmp390: bmp390_set_fifo/bmp390_get_fifo test.
bmp390: set fifo enable.
bmp390: check fifo ok.
bmp390: set fifo disable.
bmp390: check fifo ok.
bmp390: bmp390_set_fifo_stop_on_full/bmp390_get_fifo_stop_on_full test.
bmp390: set fifo stop on full enable.
bmp390: check fifo stop on full ok.
bmp390: set fifo stop on full disable.
bmp390: check fifo stop on full ok.
bmp390: bmp390_set_fifo_sensortime_on/bmp390_get_fifo_sensortime_on test.
bmp390: set fifo sensortime on enable.
bmp390: check fifo sensortime on ok.
bmp390: set fifo sensortime on disable.
bmp390: check fifo sensortime on ok.
bmp390: bmp390_set_fifo_pressure_on/bmp390_get_fifo_pressure_on test.
bmp390: set fifo pressure on enable.
bmp390: check fifo pressure on ok.
bmp390: set fifo pressure on disable.
bmp390: check fifo pressure on ok.
bmp390: bmp390_set_fifo_temperature_on/bmp390_get_fifo_temperature_on test.
bmp390: set fifo temperature on enable.
bmp390: check fifo temperature on ok.
bmp390: set fifo temperature on disable.
bmp390: check fifo temperature on ok.
bmp390: bmp390_set_fifo_subsampling/bmp390_get_fifo_subsampling test.
bmp390: set fifo subsampling 4.
bmp390: check fifo subsampling on ok.
bmp390: bmp390_set_fifo_data_source/bmp390_get_fifo_data_source test.
bmp390: set fifo data source unfiltered.
bmp390: check fifo data source ok.
bmp390: set fifo data source filtered.
bmp390: check fifo data source ok.
bmp390: bmp390_set_interrupt_pin_type/bmp390_get_interrupt_pin_type test.
bmp390: set interrupt pin type push pull.
bmp390: check interrupt pin type ok.
bmp390: set interrupt pin type open drain.
bmp390: check interrupt pin type ok.
bmp390: bmp390_set_interrupt_active_level/bmp390_get_interrupt_active_level test.
bmp390: set interrupt active level lower.
bmp390: check interrupt active level ok.
bmp390: set interrupt active level higher.
bmp390: check interrupt active level ok.
bmp390: bmp390_set_latch_interrupt_pin_and_interrupt_status/bmp390_get_latch_interrupt_pin_and_interrupt_status test.
bmp390: set latch interrupt pin and interrupt status enable.
bmp390: check latch interrupt pin and interrupt status ok.
bmp390: set latch interrupt pin and interrupt status disable.
bmp390: check latch interrupt pin and interrupt status ok.
bmp390: bmp390_set_interrupt_fifo_watermark/bmp390_get_interrupt_fifo_watermark test.
bmp390: set interrupt fifo watermark enable.
bmp390: check interrupt fifo watermark ok.
bmp390: set interrupt fifo watermark disable.
bmp390: check interrupt fifo watermark ok.
bmp390: bmp390_set_interrupt_fifo_full/bmp390_get_interrupt_fifo_full test.
bmp390: set interrupt fifo full enable.
bmp390: check interrupt fifo full ok.
bmp390: set interrupt fifo full disable.
bmp390: check interrupt fifo full ok.
bmp390: bmp390_set_interrupt_data_ready/bmp390_get_interrupt_fifo_data_ready test.
bmp390: set interrupt data ready enable.
bmp390: check interrupt data ready ok.
bmp390: set interrupt data ready disable.
bmp390: check interrupt data ready ok.
bmp390: bmp390_set_spi_wire/bmp390_get_spi_wire test.
bmp390: set spi 4 wire.
bmp390: check spi wire ok.
bmp390: set spi 3 wire.
bmp390: check spi wire ok.
bmp390: bmp390_set_iic_watchdog_timer/bmp390_get_iic_watchdog_timer test.
bmp390: set iic watchdog timer enable.
bmp390: check iic watchdog timer ok.
bmp390: set iic watchdog timer disable.
bmp390: check iic watchdog timer ok.
bmp390: bmp390_set_iic_watchdog_period/bmp390_get_iic_watchdog_period test.
bmp390: set iic watchdog period 1.25ms.
bmp390: check iic watchdog period ok.
bmp390: set iic watchdog period 40ms.
bmp390: check iic watchdog period ok.
bmp390: bmp390_set_pressure/bmp390_get_pressure test.
bmp390: set pressure disable.
bmp390: check pressure ok.
bmp390: set pressure enable.
bmp390: check pressure ok.
bmp390: bmp390_set_temperature/bmp390_get_temperature test.
bmp390: set temperature disable.
bmp390: check temperature ok.
bmp390: set temperature enable.
bmp390: check temperature ok.
bmp390: bmp390_set_mode/bmp390_get_mode test.
bmp390: set mode sleep.
bmp390: check mode ok.
bmp390: set mode normal mode.
bmp390: check mode ok.
bmp390: set mode forced mode.
bmp390: check mode ok.
bmp390: bmp390_set_pressure_oversampling/bmp390_get_pressure_oversampling test.
bmp390: set pressure oversampling x1.
bmp390: check pressure oversampling ok.
bmp390: set pressure oversampling x2.
bmp390: check pressure oversampling ok.
bmp390: set pressure oversampling x4.
bmp390: check pressure oversampling ok.
bmp390: set pressure oversampling x8.
bmp390: check pressure oversampling ok.
bmp390: set pressure oversampling x16.
bmp390: check pressure oversampling ok.
bmp390: set pressure oversampling x32.
bmp390: check pressure oversampling ok.
bmp390: bmp390_set_temperature_oversampling/bmp390_get_temperature_oversampling test.
bmp390: set temperature oversampling x1.
bmp390: check temperature oversampling ok.
bmp390: set temperature oversampling x2.
bmp390: check temperature oversampling ok.
bmp390: set temperature oversampling x4.
bmp390: check temperature oversampling ok.
bmp390: set temperature oversampling x8.
bmp390: check temperature oversampling ok.
bmp390: set temperature oversampling x16.
bmp390: check temperature oversampling ok.
bmp390: set temperature oversampling x32.
bmp390: check temperature oversampling ok.
bmp390: bmp390_set_odr/bmp390_get_odr test.
bmp390: set odr 200Hz.
bmp390: check odr ok.
bmp390: set odr 100Hz.
bmp390: check odr ok.
bmp390: set odr 50Hz.
bmp390: check odr ok.
bmp390: set odr 25Hz.
bmp390: check odr ok.
bmp390: set odr 12.5Hz.
bmp390: check odr ok.
bmp390: set odr 6.25Hz.
bmp390: check odr ok.
bmp390: set odr 3.1Hz.
bmp390: check odr ok.
bmp390: set odr 1.5Hz.
bmp390: check odr ok.
bmp390: set odr 0.78Hz.
bmp390: check odr ok.
bmp390: set odr 0.39Hz.
bmp390: check odr ok.
bmp390: set odr 0.2Hz.
bmp390: check odr ok.
bmp390: set odr 0.1Hz.
bmp390: check odr ok.
bmp390: set odr 0.05Hz.
bmp390: check odr ok.
bmp390: set odr 0.02Hz.
bmp390: check odr ok.
bmp390: set odr 0.01Hz.
bmp390: check odr ok.
bmp390: set odr 0.006Hz.
bmp390: check odr ok.
bmp390: set odr 0.003Hz.
bmp390: check odr ok.
bmp390: set odr 0.0015Hz.
bmp390: check odr ok.
bmp390: bmp390_set_filter_coefficient/bmp390_get_filter_coefficient test.
bmp390: set filter coefficient 0.
bmp390: check filter coefficient ok.
bmp390: set filter coefficient 1.
bmp390: check filter coefficient ok.
bmp390: set filter coefficient 3.
bmp390: check filter coefficient ok.
bmp390: set filter coefficient 7.
bmp390: check filter coefficient ok.
bmp390: set filter coefficient 15.
bmp390: check filter coefficient ok.
bmp390: set filter coefficient 31.
bmp390: check filter coefficient ok.
bmp390: set filter coefficient 63.
bmp390: check filter coefficient ok.
bmp390: set filter coefficient 127.
bmp390: check filter coefficient ok.
bmp390: bmp390_get_error.
bmp390: err is 0x00.
bmp390: bmp390_get_status.
bmp390: status is 0x70.
bmp390: bmp390_get_sensortime.
bmp390: sensortime is 0x002B2D.
bmp390: bmp390_get_event.
bmp390: event is power up or softrest.
bmp390: bmp390_get_interrupt_status.
bmp390: interrupt status is 0x08.
bmp390: bmp390_get_fifo_length.
bmp390: get fifo length is 0x0000.
bmp390: bmp390_get_fifo_data.
bmp390: get fifo data is 0x0080.
bmp390: bmp390_flush_fifo.
bmp390: flush fifo ok.
bmp390: bmp390_get_revision_id.
bmp390: revision id is 0x01.
bmp390: bmp390_softreset.
bmp390: softreset ok.
bmp390: finish register test.
```

```shell
bmp390 -t read --addr=0 --interface=iic --times=3

bmp390: chip is Bosch BMP390.
bmp390: manufacturer is Bosch.
bmp390: interface is IIC SPI.
bmp390: driver version is 1.0.
bmp390: min supply voltage is 1.6V.
bmp390: max supply voltage is 3.6V.
bmp390: max current is 0.73mA.
bmp390: max temperature is 85.0C.
bmp390: min temperature is -40.0C.
bmp390: start read test.
bmp390: forced mode read test.
bmp390: temperature is 26.06C.
bmp390: pressure is 102666.82Pa.
bmp390: temperature is 26.05C.
bmp390: pressure is 102666.68Pa.
bmp390: temperature is 26.05C.
bmp390: pressure is 102666.59Pa.
bmp390: normal mode read test.
bmp390: temperature is 26.14C.
bmp390: pressure is 102655.02Pa.
bmp390: temperature is 26.24C.
bmp390: pressure is 102649.76Pa.
bmp390: temperature is 26.28C.
bmp390: pressure is 102647.24Pa.
bmp390: finish read test.
```

```shell
bmp390 -t int --addr=0 --interface=iic --times=3

bmp390: chip is Bosch BMP390.
bmp390: manufacturer is Bosch.
bmp390: interface is IIC SPI.
bmp390: driver version is 1.0.
bmp390: min supply voltage is 1.6V.
bmp390: max supply voltage is 3.6V.
bmp390: max current is 0.73mA.
bmp390: max temperature is 85.0C.
bmp390: min temperature is -40.0C.
bmp390: start interrupt test.
bmp390: temperature is 26.03C.
bmp390: pressure is 102656.98Pa.
bmp390: temperature is 26.20C.
bmp390: pressure is 102646.88Pa.
bmp390: temperature is 26.27C.
bmp390: pressure is 102645.23Pa.
bmp390: finish interrupt test.
```

```shell
bmp390 -t fifo --addr=0 --interface=iic --times=3

bmp390: chip is Bosch BMP390.
bmp390: manufacturer is Bosch.
bmp390: interface is IIC SPI.
bmp390: driver version is 1.0.
bmp390: min supply voltage is 1.6V.
bmp390: max supply voltage is 3.6V.
bmp390: max current is 0.73mA.
bmp390: max temperature is 85.0C.
bmp390: min temperature is -40.0C.
bmp390: start fifo test.
bmp390: fifo watermark test.
bmp390: read fifo with length 265.
bmp390: read fifo with length 263.
bmp390: read fifo with length 263.
bmp390: fifo full test.
bmp390: clear fifo with length 508.
bmp390: fifo parse success and total frame is 145.
bmp390: clear fifo with length 508.
bmp390: fifo parse success and total frame is 145.
bmp390: clear fifo with length 508.
bmp390: fifo parse success and total frame is 145.
bmp390: finish fifo test.
```

```shell
bmp390 -e read --addr=0 --interface=iic --times=3

bmp390: 1/3.
bmp390: temperature is 25.95C.
bmp390: pressure is 102653.25Pa.
bmp390: 2/3.
bmp390: temperature is 26.04C.
bmp390: pressure is 102647.65Pa.
bmp390: 3/3.
bmp390: temperature is 26.09C.
bmp390: pressure is 102645.28Pa.
```

```shell
bmp390 -e shot --addr=0 --interface=iic --times=3

bmp390: 1/3.
bmp390: temperature is 25.79C.
bmp390: pressure is 102671.04Pa.
bmp390: 2/3.
bmp390: temperature is 25.79C.
bmp390: pressure is 102671.03Pa.
bmp390: 3/3.
bmp390: temperature is 25.79C.
bmp390: pressure is 102670.87Pa.
```

```shell
bmp390 -e int --addr=0 --interface=iic --times=3

bmp390: 1/3.
bmp390: temperature is 25.65C.
bmp390: pressure is 102666.16Pa.
bmp390: 2/3.
bmp390: temperature is 25.65C.
bmp390: pressure is 102665.57Pa.
bmp390: 3/3.
bmp390: temperature is 25.67C.
bmp390: pressure is 102663.83Pa.
```

```shell
bmp390 -e fifo --addr=0 --interface=iic --times=3

bmp390: fifo 1/1.
bmp390: sensortime is 74187.
bmp390: fifo 1/75.
bmp390: temperature is 25.85C.
bmp390: fifo 2/75.
bmp390: pressure is 102650.23Pa.
bmp390: fifo 3/75.
bmp390: temperature is 25.85C.
bmp390: fifo 4/75.
bmp390: pressure is 102649.93Pa.
bmp390: fifo 5/75.
bmp390: temperature is 25.86C.
bmp390: fifo 6/75.
bmp390: pressure is 102649.73Pa.
bmp390: fifo 7/75.
bmp390: temperature is 25.86C.
bmp390: fifo 8/75.
bmp390: pressure is 102649.66Pa.
bmp390: fifo 9/75.
bmp390: temperature is 25.86C.
bmp390: fifo 10/75.
bmp390: pressure is 102649.59Pa.
bmp390: fifo 11/75.
bmp390: temperature is 25.86C.
bmp390: fifo 12/75.
bmp390: pressure is 102649.53Pa.
bmp390: fifo 13/75.
bmp390: temperature is 25.87C.
bmp390: fifo 14/75.
bmp390: pressure is 102649.39Pa.
bmp390: fifo 15/75.
bmp390: temperature is 25.87C.
bmp390: fifo 16/75.
bmp390: pressure is 102649.25Pa.
bmp390: fifo 17/75.
bmp390: temperature is 25.87C.
bmp390: fifo 18/75.
bmp390: pressure is 102649.03Pa.
bmp390: fifo 19/75.
bmp390: temperature is 25.87C.
bmp390: fifo 20/75.
bmp390: pressure is 102648.95Pa.
bmp390: fifo 21/75.
bmp390: temperature is 25.87C.
bmp390: fifo 22/75.
bmp390: pressure is 102648.87Pa.
bmp390: fifo 23/75.
bmp390: temperature is 25.87C.
bmp390: fifo 24/75.
bmp390: pressure is 102648.82Pa.
bmp390: fifo 25/75.
bmp390: temperature is 25.88C.
bmp390: fifo 26/75.
bmp390: pressure is 102648.72Pa.
bmp390: fifo 27/75.
bmp390: temperature is 25.88C.
bmp390: fifo 28/75.
bmp390: pressure is 102648.55Pa.
bmp390: fifo 29/75.
bmp390: temperature is 25.88C.
bmp390: fifo 30/75.
bmp390: pressure is 102648.48Pa.
bmp390: fifo 31/75.
bmp390: temperature is 25.88C.
bmp390: fifo 32/75.
bmp390: pressure is 102648.38Pa.
bmp390: fifo 33/75.
bmp390: temperature is 25.88C.
bmp390: fifo 34/75.
bmp390: pressure is 102648.45Pa.
bmp390: fifo 35/75.
bmp390: temperature is 25.88C.
bmp390: fifo 36/75.
bmp390: pressure is 102648.48Pa.
bmp390: fifo 37/75.
bmp390: temperature is 25.89C.
bmp390: fifo 38/75.
bmp390: pressure is 102648.40Pa.
bmp390: fifo 39/75.
bmp390: temperature is 25.89C.
bmp390: fifo 40/75.
bmp390: pressure is 102648.34Pa.
bmp390: fifo 41/75.
bmp390: temperature is 25.89C.
bmp390: fifo 42/75.
bmp390: pressure is 102648.29Pa.
bmp390: fifo 43/75.
bmp390: temperature is 25.89C.
bmp390: fifo 44/75.
bmp390: pressure is 102648.21Pa.
bmp390: fifo 45/75.
bmp390: temperature is 25.89C.
bmp390: fifo 46/75.
bmp390: pressure is 102648.16Pa.
bmp390: fifo 47/75.
bmp390: temperature is 25.89C.
bmp390: fifo 48/75.
bmp390: pressure is 102648.13Pa.
bmp390: fifo 49/75.
bmp390: temperature is 25.89C.
bmp390: fifo 50/75.
bmp390: pressure is 102648.05Pa.
bmp390: fifo 51/75.
bmp390: temperature is 25.89C.
bmp390: fifo 52/75.
bmp390: pressure is 102647.96Pa.
bmp390: fifo 53/75.
bmp390: temperature is 25.90C.
bmp390: fifo 54/75.
bmp390: pressure is 102647.93Pa.
bmp390: fifo 55/75.
bmp390: temperature is 25.90C.
bmp390: fifo 56/75.
bmp390: pressure is 102647.86Pa.
bmp390: fifo 57/75.
bmp390: temperature is 25.90C.
bmp390: fifo 58/75.
bmp390: pressure is 102647.97Pa.
bmp390: fifo 59/75.
bmp390: temperature is 25.90C.
bmp390: fifo 60/75.
bmp390: pressure is 102647.93Pa.
bmp390: fifo 61/75.
bmp390: temperature is 25.90C.
bmp390: fifo 62/75.
bmp390: pressure is 102647.94Pa.
bmp390: fifo 63/75.
bmp390: temperature is 25.90C.
bmp390: fifo 64/75.
bmp390: pressure is 102647.92Pa.
bmp390: fifo 65/75.
bmp390: temperature is 25.91C.
bmp390: fifo 66/75.
bmp390: pressure is 102647.83Pa.
bmp390: fifo 67/75.
bmp390: temperature is 25.91C.
bmp390: fifo 68/75.
bmp390: pressure is 102647.76Pa.
bmp390: fifo 69/75.
bmp390: temperature is 25.91C.
bmp390: fifo 70/75.
bmp390: pressure is 102647.70Pa.
bmp390: fifo 71/75.
bmp390: temperature is 25.91C.
bmp390: fifo 72/75.
bmp390: pressure is 102647.70Pa.
bmp390: fifo 73/75.
bmp390: temperature is 25.91C.
bmp390: fifo 74/75.
bmp390: pressure is 102647.71Pa.
bmp390: fifo 75/75.
bmp390: sensortime is 149750.
bmp390: fifo 1/11.
bmp390: temperature is 25.91C.
bmp390: fifo 2/11.
bmp390: pressure is 102647.75Pa.
bmp390: fifo 3/11.
bmp390: temperature is 25.91C.
bmp390: fifo 4/11.
bmp390: pressure is 102647.77Pa.
bmp390: fifo 5/11.
bmp390: temperature is 25.92C.
bmp390: fifo 6/11.
bmp390: pressure is 102647.75Pa.
bmp390: fifo 7/11.
bmp390: temperature is 25.92C.
bmp390: fifo 8/11.
bmp390: pressure is 102647.78Pa.
bmp390: fifo 9/11.
bmp390: temperature is 25.92C.
bmp390: fifo 10/11.
bmp390: pressure is 102647.85Pa.
bmp390: fifo 11/11.
bmp390: sensortime is 161426.
bmp390: fifo 1/75.
bmp390: temperature is 25.92C.
bmp390: fifo 2/75.
bmp390: pressure is 102647.83Pa.
bmp390: fifo 3/75.
bmp390: temperature is 25.92C.
bmp390: fifo 4/75.
bmp390: pressure is 102647.86Pa.
bmp390: fifo 5/75.
bmp390: temperature is 25.92C.
bmp390: fifo 6/75.
bmp390: pressure is 102647.87Pa.
bmp390: fifo 7/75.
bmp390: temperature is 25.92C.
bmp390: fifo 8/75.
bmp390: pressure is 102647.83Pa.
bmp390: fifo 9/75.
bmp390: temperature is 25.93C.
bmp390: fifo 10/75.
bmp390: pressure is 102647.76Pa.
bmp390: fifo 11/75.
bmp390: temperature is 25.93C.
bmp390: fifo 12/75.
bmp390: pressure is 102647.73Pa.
bmp390: fifo 13/75.
bmp390: temperature is 25.93C.
bmp390: fifo 14/75.
bmp390: pressure is 102647.68Pa.
bmp390: fifo 15/75.
bmp390: temperature is 25.93C.
bmp390: fifo 16/75.
bmp390: pressure is 102647.62Pa.
bmp390: fifo 17/75.
bmp390: temperature is 25.93C.
bmp390: fifo 18/75.
bmp390: pressure is 102647.59Pa.
bmp390: fifo 19/75.
bmp390: temperature is 25.93C.
bmp390: fifo 20/75.
bmp390: pressure is 102647.56Pa.
bmp390: fifo 21/75.
bmp390: temperature is 25.93C.
bmp390: fifo 22/75.
bmp390: pressure is 102647.55Pa.
bmp390: fifo 23/75.
bmp390: temperature is 25.93C.
bmp390: fifo 24/75.
bmp390: pressure is 102647.40Pa.
bmp390: fifo 25/75.
bmp390: temperature is 25.93C.
bmp390: fifo 26/75.
bmp390: pressure is 102647.29Pa.
bmp390: fifo 27/75.
bmp390: temperature is 25.93C.
bmp390: fifo 28/75.
bmp390: pressure is 102647.20Pa.
bmp390: fifo 29/75.
bmp390: temperature is 25.94C.
bmp390: fifo 30/75.
bmp390: pressure is 102647.21Pa.
bmp390: fifo 31/75.
bmp390: temperature is 25.94C.
bmp390: fifo 32/75.
bmp390: pressure is 102647.16Pa.
bmp390: fifo 33/75.
bmp390: temperature is 25.94C.
bmp390: fifo 34/75.
bmp390: pressure is 102647.16Pa.
bmp390: fifo 35/75.
bmp390: temperature is 25.94C.
bmp390: fifo 36/75.
bmp390: pressure is 102647.09Pa.
bmp390: fifo 37/75.
bmp390: temperature is 25.94C.
bmp390: fifo 38/75.
bmp390: pressure is 102647.05Pa.
bmp390: fifo 39/75.
bmp390: temperature is 25.94C.
bmp390: fifo 40/75.
bmp390: pressure is 102646.95Pa.
bmp390: fifo 41/75.
bmp390: temperature is 25.94C.
bmp390: fifo 42/75.
bmp390: pressure is 102646.81Pa.
bmp390: fifo 43/75.
bmp390: temperature is 25.94C.
bmp390: fifo 44/75.
bmp390: pressure is 102646.73Pa.
bmp390: fifo 45/75.
bmp390: temperature is 25.94C.
bmp390: fifo 46/75.
bmp390: pressure is 102646.63Pa.
bmp390: fifo 47/75.
bmp390: temperature is 25.94C.
bmp390: fifo 48/75.
bmp390: pressure is 102646.53Pa.
bmp390: fifo 49/75.
bmp390: temperature is 25.94C.
bmp390: fifo 50/75.
bmp390: pressure is 102646.48Pa.
bmp390: fifo 51/75.
bmp390: temperature is 25.94C.
bmp390: fifo 52/75.
bmp390: pressure is 102646.35Pa.
bmp390: fifo 53/75.
bmp390: temperature is 25.94C.
bmp390: fifo 54/75.
bmp390: pressure is 102646.20Pa.
bmp390: fifo 55/75.
bmp390: temperature is 25.94C.
bmp390: fifo 56/75.
bmp390: pressure is 102646.21Pa.
bmp390: fifo 57/75.
bmp390: temperature is 25.95C.
bmp390: fifo 58/75.
bmp390: pressure is 102646.24Pa.
bmp390: fifo 59/75.
bmp390: temperature is 25.95C.
bmp390: fifo 60/75.
bmp390: pressure is 102646.20Pa.
bmp390: fifo 61/75.
bmp390: temperature is 25.95C.
bmp390: fifo 62/75.
bmp390: pressure is 102646.19Pa.
bmp390: fifo 63/75.
bmp390: temperature is 25.95C.
bmp390: fifo 64/75.
bmp390: pressure is 102646.15Pa.
bmp390: fifo 65/75.
bmp390: temperature is 25.95C.
bmp390: fifo 66/75.
bmp390: pressure is 102646.06Pa.
bmp390: fifo 67/75.
bmp390: temperature is 25.95C.
bmp390: fifo 68/75.
bmp390: pressure is 102645.99Pa.
bmp390: fifo 69/75.
bmp390: temperature is 25.95C.
bmp390: fifo 70/75.
bmp390: pressure is 102645.87Pa.
bmp390: fifo 71/75.
bmp390: temperature is 25.95C.
bmp390: fifo 72/75.
bmp390: pressure is 102645.80Pa.
bmp390: fifo 73/75.
bmp390: temperature is 25.95C.
bmp390: fifo 74/75.
bmp390: pressure is 102645.73Pa.
bmp390: fifo 75/75.
bmp390: sensortime is 235766.
bmp390: fifo 1/11.
bmp390: temperature is 25.95C.
bmp390: fifo 2/11.
bmp390: pressure is 102645.58Pa.
bmp390: fifo 3/11.
bmp390: temperature is 25.95C.
bmp390: fifo 4/11.
bmp390: pressure is 102645.44Pa.
bmp390: fifo 5/11.
bmp390: temperature is 25.95C.
bmp390: fifo 6/11.
bmp390: pressure is 102645.31Pa.
bmp390: fifo 7/11.
bmp390: temperature is 25.95C.
bmp390: fifo 8/11.
bmp390: pressure is 102645.16Pa.
bmp390: fifo 9/11.
bmp390: temperature is 25.96C.
bmp390: fifo 10/11.
bmp390: pressure is 102645.00Pa.
bmp390: fifo 11/11.
bmp390: sensortime is 247482.
bmp390: finish fifo read.
```

```shell
bmp390 -h

Usage:
  bmp390 (-i | --information)
  bmp390 (-h | --help)
  bmp390 (-p | --port)
  bmp390 (-t reg | --test=reg) [--addr=<0 | 1>] [--interface=<iic | spi>]
  bmp390 (-t read | --test=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp390 (-t int | --test=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp390 (-t fifo | --test=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp390 (-e read | --example=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp390 (-e shot | --example=shot) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp390 (-e int | --example=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp390 (-e fifo | --example=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]

Options:
      --addr=<0 | 1>                 Set the chip iic address.([default: 0])
  -e <read | shot | int | fifo>, --example=<read | shot | int | fifo>
                                     Run the driver example.
  -h, --help                         Show the help.
  -i, --information                  Show the chip information.
      --interface=<iic | spi>        Set the chip interface.([default: iic])
  -p, --port                         Display the pin connections of the current board.
  -t <reg | read | int | fifo>, --test=<reg | read | int | fifo>
                                     Run the driver test.
      --times=<num>                  Set the running times.([default: 3])
```

