### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

SPI Pin: SCLK/MOSI/MISO/CS GPIO11/GPIO10/GPIO9/GPIO8.

GPIO Pin: INT GPIO17.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(adxl345 REQUIRED)
```

### 3. ADXL345

#### 3.1 Command Instruction

1. Show adxl345 chip and driver information.

   ```shell
   adxl345 (-i | --information)
   ```

2. Show adxl345 help.

   ```shell
   adxl345 (-h | --help)
   ```

3. Show adxl345 pin connections of the current board.

   ```shell
   adxl345 (-p | --port)
   ```

4. Run adxl345 register test.

   ```shell
   adxl345 (-t reg | --test=reg) [--addr=<0 | 1>] [--interface=<iic | spi>]
   ```

5. Run adxl345 read test, num means the test times.

   ```shell
   adxl345 (-t read | --test=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

6. Run adxl345 fifo test.

   ```shell
   adxl345 (-t fifo | --test=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>]
   ```

7. Run adxl345 interrupt test.

   ```shell
   adxl345 (-t int | --test=int) [--addr=<0 | 1>] [--interface=<iic | spi>]
   ```

8. Run adxl345 basic function, num is the read times.

   ```shell
   adxl345 (-e basic | --example=basic) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

9. Run adxl345 fifo function, num is the read times.

   ```shell
   adxl345 (-e fifo | --example=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

10. Run adxl345 interrupt function, mask is the interrupt mask, bit 0 is the tap enable mask, bit 1 is the action enable mask, bit 2 is the inaction enable mask and bit 3 is the free fall enable mask.

    ```shell
    adxl345 (-e int | --example=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--mask=<msk>]
    ```

#### 3.2 Command Example

```shell
./adxl345 -i

adxl345: chip is Analog Devices ADXL345.
adxl345: manufacturer is Analog Devices.
adxl345: interface is IIC SPI.
adxl345: driver version is 2.0.
adxl345: min supply voltage is 2.0V.
adxl345: max supply voltage is 3.6V.
adxl345: max current is 0.14mA.
adxl345: max temperature is 85.0C.
adxl345: min temperature is -40.0C.
```

```shell
./adxl345 -p

adxl345: SPI interface SCK connected to GPIO11(BCM).
adxl345: SPI interface MISO connected to GPIO9(BCM).
adxl345: SPI interface MOSI connected to GPIO10(BCM).
adxl345: SPI interface CS connected to GPIO8(BCM).
adxl345: IIC interface SCL connected to GPIO3(BCM).
adxl345: IIC interface SDA connected to GPIO2(BCM).
adxl345: INT connected to GPIO17(BCM).
```

```shell
./adxl345 -t reg --interface=spi

adxl345: chip is Analog Devices ADXL345.
adxl345: manufacturer is Analog Devices.
adxl345: interface is IIC SPI.
adxl345: driver version is 2.0.
adxl345: min supply voltage is 2.0V.
adxl345: max supply voltage is 3.6V.
adxl345: max current is 0.14mA.
adxl345: max temperature is 85.0C.
adxl345: min temperature is -40.0C.
adxl345: start register test.
adxl345: adxl345_set_interface/adxl345_get_interface test.
adxl345: set interface iic.
adxl345: check interface ok.
adxl345: set interface spi.
adxl345: check interface ok.
adxl345: adxl345_set_addr_pin/adxl345_get_addr_pin test.
adxl345: set addr pin alt0.
adxl345: check addr pin ok.
adxl345: set addr pin alt1.
adxl345: check addr pin ok.
adxl345: adxl345_set_tap_threshold/adxl345_get_tap_threshold test.
adxl345: set tap threshold 0x67.
adxl345: check tap threshold ok.
adxl345: adxl345_set_offset/adxl345_get_offset test.
adxl345: set x offset 70.
adxl345: set y offset -105.
adxl345: set z offset 115.
adxl345: check x offset ok.
adxl345: check y offset ok.
adxl345: check z offset ok.
adxl345: adxl345_set_duration/adxl345_get_duration test.
adxl345: set duration 0x51.
adxl345: check duration ok.
adxl345: adxl345_set_latent/adxl345_get_latent test.
adxl345: set latent 0xFF.
adxl345: check latent ok.
adxl345: adxl345_set_window/adxl345_get_window test.
adxl345: set window 0x4A.
adxl345: check window ok.
adxl345: adxl345_set_action_threshold/adxl345_get_action_threshold test.
adxl345: set action threshold 0xEC.
adxl345: check action threshold ok.
adxl345: adxl345_set_inaction_threshold/adxl345_get_inaction_threshold test.
adxl345: set inaction threshold 0x29.
adxl345: check inaction threshold ok.
adxl345: adxl345_set_inaction_time/adxl345_get_inaction_time test.
adxl345: set inaction time 0xCD.
adxl345: check inaction time ok.
adxl345: adxl345_set_action_inaction/adxl345_get_action_inaction test.
adxl345: set action x enable.
adxl345: check action inaction ok.
adxl345: set action x disable.
adxl345: check action inaction ok.
adxl345: set action y enable.
adxl345: check action inaction ok.
adxl345: set action y disable.
adxl345: check action inaction ok.
adxl345: set action z enable.
adxl345: check action inaction ok.
adxl345: set action z disable.
adxl345: check action inaction ok.
adxl345: set inaction x enable.
adxl345: check action inaction ok.
adxl345: set inaction x disable.
adxl345: check action inaction ok.
adxl345: set inaction y enable.
adxl345: check action inaction ok.
adxl345: set inaction y disable.
adxl345: check action inaction ok.
adxl345: set inaction z enable.
adxl345: check action inaction ok.
adxl345: set inaction z disable.
adxl345: check action inaction ok.
adxl345: adxl345_set_action_coupled/adxl345_get_action_coupled test.
adxl345: set action coupled dc.
adxl345: check action coupled ok.
adxl345: set action coupled ac.
adxl345: check action coupled ok.
adxl345: adxl345_set_inaction_coupled/adxl345_get_inaction_coupled test.
adxl345: set inaction coupled dc.
adxl345: check inaction coupled ok.
adxl345: set inaction coupled ac.
adxl345: check inaction coupled ok.
adxl345: adxl345_set_free_fall_threshold/adxl345_get_free_fall_threshold test.
adxl345: set free fall threshold 0xBA.
adxl345: check free fall threshold ok.
adxl345: adxl345_set_free_fall_time/adxl345_get_free_fall_time test.
adxl345: set free fall time 0xAB.
adxl345: check free fall time ok.
adxl345: adxl345_set_tap_axis/adxl345_get_tap_axis test.
adxl345: set tap axis x enable.
adxl345: check tap axis ok.
adxl345: set tap axis x disable.
adxl345: check tap axis ok.
adxl345: set tap axis y enable.
adxl345: check tap axis ok.
adxl345: set tap axis y disable.
adxl345: check tap axis ok.
adxl345: set tap axis z enable.
adxl345: check tap axis ok.
adxl345: set tap axis z disable.
adxl345: check tap axis ok.
adxl345: adxl345_set_tap_suppress/adxl345_get_tap_suppress test.
adxl345: set tap suppress enable.
adxl345: check tap suppress ok.
adxl345: set tap suppress disable.
adxl345: check tap suppress ok.
adxl345: get tap status test.
adxl345: tap status is 0x00.
adxl345: adxl345_set_rate/adxl345_get_rate test.
adxl345: set rate 0.1Hz.
adxl345: check rate ok.
adxl345: set rate 0.2Hz.
adxl345: check rate ok.
adxl345: set rate 0.39Hz.
adxl345: check rate ok.
adxl345: set rate 0.78Hz.
adxl345: check rate ok.
adxl345: set rate 1.56Hz.
adxl345: check rate ok.
adxl345: set rate 3.13Hz.
adxl345: check rate ok.
adxl345: set rate 6.25Hz.
adxl345: check rate ok.
adxl345: set rate 12.5Hz.
adxl345: check rate ok.
adxl345: set rate 25Hz.
adxl345: check rate ok.
adxl345: set rate 50Hz.
adxl345: check rate ok.
adxl345: set rate 100Hz.
adxl345: check rate ok.
adxl345: set rate 200Hz.
adxl345: check rate ok.
adxl345: set rate 400Hz.
adxl345: check rate ok.
adxl345: set rate 800Hz.
adxl345: check rate ok.
adxl345: set rate 1600Hz.
adxl345: check rate ok.
adxl345: set rate 3200Hz.
adxl345: check rate ok.
adxl345: set rate low 12.5Hz.
adxl345: check rate ok.
adxl345: set rate low 25Hz.
adxl345: check rate ok.
adxl345: set rate low 50Hz.
adxl345: check rate ok.
adxl345: set rate low 100Hz.
adxl345: check rate ok.
adxl345: set rate low 200Hz.
adxl345: check rate ok.
adxl345: set rate low 400Hz.
adxl345: check rate ok.
adxl345: adxl345_set_interrupt/adxl345_get_interrupt test.
adxl345: set interrupt data ready enable.
adxl345: check interrupt ok.
adxl345: set interrupt data ready disable.
adxl345: check interrupt ok.
adxl345: set interrupt single enable.
adxl345: check interrupt ok.
adxl345: set interrupt single disable.
adxl345: check interrupt ok.
adxl345: set interrupt double enable.
adxl345: check interrupt ok.
adxl345: set interrupt double disable.
adxl345: check interrupt ok.
adxl345: set interrupt activity enable.
adxl345: check interrupt ok.
adxl345: set interrupt activity disable.
adxl345: check interrupt ok.
adxl345: set interrupt inactivity enable.
adxl345: check interrupt ok.
adxl345: set interrupt inactivity disable.
adxl345: check interrupt ok.
adxl345: set interrupt free fall enable.
adxl345: check interrupt ok.
adxl345: set interrupt free fall disable.
adxl345: check interrupt ok.
adxl345: set interrupt watermark enable.
adxl345: check interrupt ok.
adxl345: set interrupt watermark disable.
adxl345: check interrupt ok.
adxl345: set interrupt overrun enable.
adxl345: check interrupt ok.
adxl345: set interrupt overrun disable.
adxl345: check interrupt ok.
adxl345: adxl345_set_interrupt_map/adxl345_get_interrupt_map test.
adxl345: set interrupt map data ready pin1.
adxl345: check interrupt map ok.
adxl345: set interrupt map data ready pin2.
adxl345: check interrupt map ok.
adxl345: set interrupt map single tap pin1.
adxl345: check interrupt map ok.
adxl345: set interrupt map single pin2.
adxl345: check interrupt map ok.
adxl345: set interrupt map double tap pin1.
adxl345: check interrupt map ok.
adxl345: set interrupt map double pin2.
adxl345: check interrupt map ok.
adxl345: set interrupt map acivity pin1.
adxl345: check interrupt map ok.
adxl345: set interrupt acivity pin2.
adxl345: check interrupt map ok.
adxl345: set interrupt map inacivity pin1.
adxl345: check interrupt map ok.
adxl345: set interrupt inacivity pin2.
adxl345: check interrupt map ok.
adxl345: set interrupt map free fall pin1.
adxl345: check interrupt map ok.
adxl345: set interrupt free fall pin2.
adxl345: check interrupt map ok.
adxl345: set interrupt map watermark pin1.
adxl345: check interrupt map ok.
adxl345: set interrupt watermark pin2.
adxl345: check interrupt map ok.
adxl345: set interrupt map overrun pin1.
adxl345: check interrupt map ok.
adxl345: set interrupt overrun pin2.
adxl345: check interrupt map ok.
adxl345: adxl345_get_interrupt_source test.
adxl345: check interrupt source 0x00.
adxl345: adxl345_set_self_test/adxl345_get_self_test test.
adxl345: set self test enable.
adxl345: check self test ok.
adxl345: set self test disable.
adxl345: check self test ok.
adxl345: adxl345_set_spi_wire/adxl345_get_spi_wire test.
adxl345: set self test enable.
adxl345: check self test ok.
adxl345: set self test disable.
adxl345: check self test ok.
adxl345: adxl345_set_interrupt_active_level/adxl345_get_interrupt_active_level test.
adxl345: set interrupt active level high.
adxl345: check interrupt active level ok.
adxl345: set interrupt active level low.
adxl345: check interrupt active level ok.
adxl345: adxl345_set_full_resolution/adxl345_get_full_resolution test.
adxl345: enable full resolution.
adxl345: check full resolution ok.
adxl345: disable full resolution.
adxl345: check full resolution ok.
adxl345: adxl345_set_justify/adxl345_get_justify test.
adxl345: set justify right.
adxl345: check justify ok.
adxl345: set justify left.
adxl345: check justify ok.
adxl345: adxl345_set_range/adxl345_get_range test.
adxl345: set range 2g.
adxl345: check range ok.
adxl345: set range 4g.
adxl345: check range ok.
adxl345: set range 8g.
adxl345: check range ok.
adxl345: set range 16g.
adxl345: check range ok.
adxl345: adxl345_set_mode/adxl345_get_mode test.
adxl345: set mode bypass.
adxl345: check mode ok.
adxl345: set mode fifo.
adxl345: check mode ok.
adxl345: set mode stream.
adxl345: check mode ok.
adxl345: set mode trigger.
adxl345: check mode ok.
adxl345: adxl345_set_trigger_pin/adxl345_get_trigger_pin test.
adxl345: set trigger pin 1.
adxl345: check trigger pin ok.
adxl345: set trigger pin 2.
adxl345: check trigger pin ok.
adxl345: adxl345_set_watermark/adxl345_get_watermark test.
adxl345: set watermark 0x12.
adxl345: check watermark ok.
adxl345: adxl345_get_watermark_level test.
adxl345: watermark level is 0x00.
adxl345: adxl345_get_trigger_status test.
adxl345: trigger status is 0x00.
adxl345: adxl345_set_link_activity_inactivity/adxl345_get_link_activity_inactivity test.
adxl345: enable link activity inactivity.
adxl345: check link activity inactivity ok.
adxl345: disable link activity inactivity.
adxl345: check link activity inactivity ok.
adxl345: adxl345_set_auto_sleep/adxl345_get_auto_sleep test.
adxl345: enable auto sleep.
adxl345: check auto sleep ok.
adxl345: disable auto sleep.
adxl345: check auto sleep ok.
adxl345: adxl345_set_measure/adxl345_get_measure test.
adxl345: enable measure.
adxl345: check measure ok.
adxl345: disable measure.
adxl345: check measure ok.
adxl345: adxl345_set_sleep/adxl345_get_sleep test.
adxl345: enable sleep.
adxl345: check sleep ok.
adxl345: disable sleep.
adxl345: check sleep ok.
adxl345: adxl345_set_sleep_frequency/adxl345_get_sleep_frequency test.
adxl345: set sleep frequency 8 Hz.
adxl345: check sleep frequency ok.
adxl345: set sleep frequency 4 Hz.
adxl345: check sleep frequency ok.
adxl345: set sleep frequency 2 Hz.
adxl345: check sleep frequency ok.
adxl345: set sleep frequency 1 Hz.
adxl345: check sleep frequency ok.
adxl345: adxl345_tap_threshold_convert_to_register/adxl345_tap_threshold_convert_to_data test.
adxl345: tap threshold before is 0.5900.
adxl345: tap threshold register is 0x09.
adxl345: tap threshold convert is 0.5625.
adxl345: adxl345_offset_convert_to_register/adxl345_offset_convert_to_data test.
adxl345: offset before is 0.6300.
adxl345: offset register is 0x28.
adxl345: offset convert is 0.6240.
adxl345: adxl345_duration_convert_to_register/adxl345_duration_convert_to_data test.
adxl345: duration before is 3750.
adxl345: duration register is 0x06.
adxl345: duration convert is 3750.
adxl345: adxl345_latent_convert_to_register/adxl345_latent_convert_to_data test.
adxl345: latent before is 54.0000.
adxl345: latent register is 0x2B.
adxl345: latent convert is 53.7500.
adxl345: adxl345_window_convert_to_register/adxl345_window_convert_to_data test.
adxl345: window before is 2.2600.
adxl345: window register is 0x01.
adxl345: window convert is 1.2500.
adxl345: adxl345_action_threshold_convert_to_register/adxl345_action_threshold_convert_to_data test.
adxl345: action threshold before is 3.7200.
adxl345: action threshold register is 0x3B.
adxl345: action threshold convert is 3.6875.
adxl345: adxl345_inaction_threshold_convert_to_register/adxl345_inaction_threshold_convert_to_data test.
adxl345: inaction threshold before is 5.3600.
adxl345: inaction threshold register is 0x55.
adxl345: inaction threshold convert is 5.3125.
adxl345: adxl345_inaction_time_convert_to_register/adxl345_inaction_time_convert_to_data test.
adxl345: inaction time before is 0x1B.
adxl345: inaction time register is 0x1B.
adxl345: inaction time convert is 0x1B.
adxl345: adxl345_free_fall_threshold_convert_to_register/adxl345_free_fall_threshold_convert_to_data test.
adxl345: free fall threshold before is 1.6800.
adxl345: free fall threshold register is 0x1A.
adxl345: free fall threshold convert is 1.6250.
adxl345: adxl345_free_fall_time_convert_to_register/adxl345_free_fall_time_convert_to_data test.
adxl345: free time threshold before is 167.
adxl345: free time threshold register is 0x21.
adxl345: free time threshold convert is 165.
adxl345: finish register test.
```

```shell
./adxl345 -t read --interface=spi --times=3

adxl345: chip is Analog Devices ADXL345.
adxl345: manufacturer is Analog Devices.
adxl345: interface is IIC SPI.
adxl345: driver version is 2.0.
adxl345: min supply voltage is 2.0V.
adxl345: max supply voltage is 3.6V.
adxl345: max current is 0.14mA.
adxl345: max temperature is 85.0C.
adxl345: min temperature is -40.0C.
adxl345: start read test.
adxl345: set align right.
adxl345: set 2g range.
x is 1.03 g.
y is -0.05 g.
z is -0.08 g.
x is 1.04 g.
y is -0.04 g.
z is -0.05 g.
x is 1.03 g.
y is -0.03 g.
z is -0.06 g.
adxl345: set 4g range.
x is 1.04 g.
y is -0.03 g.
z is -0.07 g.
x is 1.04 g.
y is -0.03 g.
z is -0.05 g.
x is 1.03 g.
y is -0.02 g.
z is -0.07 g.
adxl345: set 8g range.
x is 1.03 g.
y is -0.03 g.
z is -0.06 g.
x is 1.03 g.
y is -0.05 g.
z is -0.06 g.
x is 1.03 g.
y is -0.03 g.
z is -0.08 g.
adxl345: set 16g range.
x is 1.03 g.
y is -0.03 g.
z is -0.09 g.
x is 1.03 g.
y is -0.06 g.
z is -0.06 g.
x is 1.03 g.
y is -0.03 g.
z is -0.06 g.
adxl345: set full resolution.
x is 1.04 g.
y is -0.03 g.
z is -0.06 g.
x is 1.04 g.
y is -0.03 g.
z is -0.06 g.
x is 1.04 g.
y is -0.04 g.
z is -0.07 g.
adxl345: set align left.
adxl345: set 2g range.
x is 1.53 g.
y is -0.03 g.
z is -0.07 g.
x is 1.53 g.
y is -0.03 g.
z is -0.06 g.
x is 1.03 g.
y is -0.03 g.
z is -0.08 g.
adxl345: set 4g range.
x is 1.03 g.
y is -0.03 g.
z is -0.06 g.
x is 1.04 g.
y is -0.03 g.
z is -0.06 g.
x is 1.03 g.
y is -0.03 g.
z is -0.09 g.
adxl345: set 8g range.
x is 3.00 g.
y is -0.06 g.
z is -0.06 g.
x is 3.00 g.
y is -0.06 g.
z is -0.06 g.
x is 3.00 g.
y is -0.06 g.
z is -0.06 g.
adxl345: set 16g range.
x is 1.03 g.
y is -0.09 g.
z is -0.09 g.
x is 1.03 g.
y is -0.09 g.
z is -0.09 g.
x is 1.03 g.
y is -0.09 g.
z is -0.09 g.
adxl345: set full resolution.
x is 1.03 g.
y is -0.09 g.
z is -0.12 g.
x is 1.04 g.
y is -0.09 g.
z is -0.12 g.
x is 1.04 g.
y is -0.09 g.
z is -0.12 g.
adxl345: set rate 0.1Hz.
x is 1.04 g.
y is -0.02 g.
z is -0.06 g.
x is 1.04 g.
y is -0.02 g.
z is -0.06 g.
x is 1.04 g.
y is -0.02 g.
z is -0.06 g.
adxl345: set rate 0.2Hz.
x is 1.04 g.
y is -0.02 g.
z is -0.06 g.
x is 1.04 g.
y is -0.02 g.
z is -0.06 g.
x is 1.04 g.
y is -0.02 g.
z is -0.06 g.
adxl345: set rate 0.39Hz.
x is 1.04 g.
y is -0.02 g.
z is -0.06 g.
x is 1.04 g.
y is -0.02 g.
z is -0.06 g.
x is 1.04 g.
y is -0.02 g.
z is -0.06 g.
adxl345: set rate 0.78Hz.
x is 0.97 g.
y is -0.04 g.
z is -0.06 g.
x is 0.97 g.
y is -0.04 g.
z is -0.06 g.
x is 0.97 g.
y is -0.04 g.
z is -0.06 g.
adxl345: set rate 1.56Hz.
x is 1.02 g.
y is -0.05 g.
z is -0.06 g.
x is 0.97 g.
y is -0.04 g.
z is -0.07 g.
x is 1.03 g.
y is -0.05 g.
z is -0.07 g.
adxl345: set rate 3.13Hz.
x is 1.03 g.
y is -0.04 g.
z is -0.06 g.
x is 1.02 g.
y is -0.04 g.
z is -0.07 g.
x is 1.03 g.
y is -0.05 g.
z is -0.07 g.
adxl345: set rate 6.25Hz.
x is 1.03 g.
y is -0.04 g.
z is -0.07 g.
x is 1.02 g.
y is -0.05 g.
z is -0.08 g.
x is 1.02 g.
y is -0.04 g.
z is -0.07 g.
adxl345: set rate 12.5Hz.
x is 1.03 g.
y is -0.05 g.
z is -0.07 g.
x is 1.03 g.
y is -0.05 g.
z is -0.07 g.
x is 1.03 g.
y is -0.05 g.
z is -0.07 g.
adxl345: set rate 25Hz.
x is 1.03 g.
y is -0.04 g.
z is -0.08 g.
x is 1.03 g.
y is -0.05 g.
z is -0.07 g.
x is 1.03 g.
y is -0.04 g.
z is -0.08 g.
adxl345: set rate 50Hz.
x is 1.02 g.
y is -0.05 g.
z is -0.07 g.
x is 1.02 g.
y is -0.05 g.
z is -0.08 g.
x is 1.02 g.
y is -0.05 g.
z is -0.08 g.
adxl345: set rate 100Hz.
x is 1.02 g.
y is -0.04 g.
z is -0.07 g.
x is 1.03 g.
y is -0.02 g.
z is -0.06 g.
x is 1.03 g.
y is -0.02 g.
z is -0.07 g.
adxl345: set rate 200Hz.
x is 0.97 g.
y is -0.03 g.
z is -0.05 g.
x is 1.03 g.
y is -0.02 g.
z is -0.05 g.
x is 1.03 g.
y is -0.02 g.
z is -0.05 g.
adxl345: set rate 400Hz.
x is 1.04 g.
y is -0.02 g.
z is -0.07 g.
x is 1.04 g.
y is -0.02 g.
z is -0.05 g.
x is 1.04 g.
y is -0.02 g.
z is -0.05 g.
adxl345: set rate 800Hz.
x is 1.03 g.
y is -0.02 g.
z is -0.05 g.
x is 1.04 g.
y is -0.02 g.
z is -0.06 g.
x is 1.04 g.
y is -0.03 g.
z is -0.07 g.
adxl345: set rate 1600Hz.
x is 1.01 g.
y is -0.02 g.
z is -0.06 g.
x is 1.03 g.
y is -0.05 g.
z is -0.09 g.
x is 1.02 g.
y is -0.05 g.
z is -0.08 g.
adxl345: set rate 3200Hz.
x is 1.05 g.
y is -0.03 g.
z is -0.07 g.
x is 1.06 g.
y is -0.03 g.
z is -0.04 g.
x is 1.02 g.
y is -0.03 g.
z is -0.06 g.
adxl345: set rate low power 12.5Hz.
x is 1.01 g.
y is -0.03 g.
z is -0.08 g.
x is 1.02 g.
y is -0.04 g.
z is -0.06 g.
x is 1.03 g.
y is -0.04 g.
z is -0.06 g.
adxl345: set rate low power 25Hz.
x is 1.03 g.
y is -0.05 g.
z is -0.07 g.
x is 1.03 g.
y is -0.04 g.
z is -0.07 g.
x is 1.03 g.
y is -0.05 g.
z is -0.09 g.
adxl345: set rate low power 50Hz.
x is 1.03 g.
y is -0.05 g.
z is -0.07 g.
x is 1.03 g.
y is -0.05 g.
z is -0.07 g.
x is 1.02 g.
y is -0.05 g.
z is -0.07 g.
adxl345: set rate low power 100Hz.
x is 0.90 g.
y is -0.05 g.
z is -0.06 g.
x is 1.02 g.
y is -0.04 g.
z is -0.08 g.
x is 1.02 g.
y is -0.05 g.
z is -0.07 g.
adxl345: set rate low power 200Hz.
x is 1.02 g.
y is -0.04 g.
z is -0.07 g.
x is 1.02 g.
y is -0.04 g.
z is -0.09 g.
x is 1.03 g.
y is -0.04 g.
z is -0.07 g.
adxl345: set rate low power 400Hz.
x is 1.02 g.
y is -0.04 g.
z is -0.07 g.
x is 1.02 g.
y is -0.05 g.
z is -0.08 g.
x is 1.01 g.
y is -0.05 g.
z is -0.08 g.
adxl345: finish read test.
```

```shell
./adxl345 -t fifo --interface=spi

adxl345: chip is Analog Devices ADXL345.
adxl345: manufacturer is Analog Devices.
adxl345: interface is IIC SPI.
adxl345: driver version is 2.0.
adxl345: min supply voltage is 2.0V.
adxl345: max supply voltage is 3.6V.
adxl345: max current is 0.14mA.
adxl345: max temperature is 85.0C.
adxl345: min temperature is -40.0C.
adxl345: start fifo test.
adxl345: irq water mark with 16.
adxl345: irq water mark with 16.
adxl345: irq water mark with 16.
adxl345: finish fifo test.
```

```shell
./adxl345 -t int --interface=spi

adxl345: chip is Analog Devices ADXL345.
adxl345: manufacturer is Analog Devices.
adxl345: interface is IIC SPI.
adxl345: driver version is 2.0.
adxl345: min supply voltage is 2.0V.
adxl345: max supply voltage is 3.6V.
adxl345: max current is 0.14mA.
adxl345: max temperature is 85.0C.
adxl345: min temperature is -40.0C.
adxl345: start tap action fall test.
adxl345: please single tap.
adxl345: irq single tap.
adxl345: irq double tap.
adxl345: irq activity.
adxl345: irq inactivity.
adxl345: irq free fall.
adxl345: irq single tap.
adxl345: irq free fall.
adxl345: detect single tap.
adxl345: please double tap.
adxl345: irq free fall.
adxl345: irq single tap.
adxl345: irq free fall.
adxl345: irq inactivity.
adxl345: irq free fall.
adxl345: irq activity.
adxl345: irq single tap.
adxl345: irq double tap.
adxl345: irq free fall.
adxl345: detect double tap.
adxl345: please action.
adxl345: irq free fall.
adxl345: irq single tap.
adxl345: irq inactivity.
adxl345: irq free fall.
adxl345: irq free fall.
adxl345: irq activity.
adxl345: irq single tap.
adxl345: detect action.
adxl345: please stop action.
adxl345: irq inactivity.
adxl345: detect stop.
adxl345: please free fall.
adxl345: irq free fall.
adxl345: irq free fall.
adxl345: detect free fall.
adxl345: finish tap action fall test.
```

```shell
./adxl345 -e basic --interface=spi --times=3

adxl345: x is 0.008.
adxl345: y is -0.062.
adxl345: z is 0.846.
adxl345: x is 0.016.
adxl345: y is -0.058.
adxl345: z is 0.846.
adxl345: x is 0.012.
adxl345: y is -0.066.
adxl345: z is 0.850.
```

```shell
./adxl345 -e fifo --interface=spi --times=3

adxl345: fifo read 3.
adxl345: fifo read 2.
adxl345: fifo read 1.
```

```shell
./adxl345 -e int --interface=spi --mask=15

adxl345: irq single tap.
adxl345: irq activity.
adxl345: irq inactivity.
adxl345: irq free fall.
adxl345: finish interrupt.
```

```shell
./adxl345 -h

Usage:
  adxl345 (-i | --information)
  adxl345 (-h | --help)
  adxl345 (-p | --port)
  adxl345 (-t reg | --test=reg) [--addr=<0 | 1>] [--interface=<iic | spi>]
  adxl345 (-t read | --test=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  adxl345 (-t fifo | --test=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>]
  adxl345 (-t int | --test=int) [--addr=<0 | 1>] [--interface=<iic | spi>]
  adxl345 (-e basic | --example=basic) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  adxl345 (-e fifo | --example=fifo) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  adxl345 (-e int | --example=int) [--addr=<0 | 1>] [--interface=<iic | spi>] [--mask=<msk>]

Options:
      --addr=<0 | 1>                 Set the chip address.([default: 0])
  -e <basic | fifo | int>, --example=<basic | fifo | int>
                                     Run the driver example.
  -h, --help                         Show the help.
  -i, --information                  Show the chip information.
      --interface=<iic | spi>        Set the chip interface.([default: iic])
      --mask=<msk>                   Set the interrupt mask, bit 0 is the tap enable mask,
                                     bit 1 is the action enable mask, bit 2 is the inaction enable mask,
                                     bit 3 is the free fall enable mask.([default: 15])
  -p, --port                         Display the pin connections of the current board.
  -t <reg | read | fifo | int>, --test=<reg | read | fifo | int>
                                     Run the driver test.
      --times=<num>                  Set the running times.([default: 3])
```
