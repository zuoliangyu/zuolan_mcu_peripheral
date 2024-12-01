### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

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
find_package(adxl362 REQUIRED)
```

### 3. ADXL362

#### 3.1 Command Instruction

1. Show adxl362 chip and driver information.

   ```shell
   adxl362 (-i | --information)
   ```

2. Show adxl362 help.

   ```shell
   adxl362 (-h | --help)
   ```

3. Show adxl362 pin connections of the current board.

   ```shell
   adxl362 (-p | --port)
   ```

4. Run adxl362 register test.

   ```shell
   adxl362 (-t reg | --test=reg)
   ```

5. Run adxl362 read test, num means the test times.

   ```shell
   adxl362 (-t read | --test=read) [--times=<num>]
   ```

6. Run adxl362 fifo test, num means the test times.

   ```shell
   adxl362 (-t fifo | --test=fifo) [--times=<num>]
   ```

7. Run adxl362 motion test, num means the test times.

   ```shell
   adxl362 (-t motion | --test=motion) [--times=<num>]
   ```

8. Run adxl362 basic function, num is the read times.

   ```shell
   adxl362 (-e basic | --example=basic) [--times=<num>]
   ```

9. Run adxl362 fifo function, num is the read times.

   ```shell
   adxl362 (-e fifo | --example=fifo) [--times=<num>]
   ```

10. Run adxl362 motion function, num is the read times.

    ```shell
    adxl362 (-e motion | --example=motion) [--times=<num>]
    ```

#### 3.2 Command Example

```shell
./adxl362 -i

adxl362: chip is Analog Devices ADXL362.
adxl362: manufacturer is Analog Devices.
adxl362: interface is SPI.
adxl362: driver version is 1.0.
adxl362: min supply voltage is 1.6V.
adxl362: max supply voltage is 3.5V.
adxl362: max current is 0.01mA.
adxl362: max temperature is 85.0C.
adxl362: min temperature is -40.0C.
```

```shell
./adxl362 -p

adxl362: SPI interface SCK connected to GPIO11(BCM).
adxl362: SPI interface MISO connected to GPIO9(BCM).
adxl362: SPI interface MOSI connected to GPIO10(BCM).
adxl362: SPI interface CS connected to GPIO8(BCM).
adxl362: INT connected to GPIO17(BCM).
```

```shell
./adxl362 -t reg

adxl362: chip is Analog Devices ADXL362.
adxl362: manufacturer is Analog Devices.
adxl362: interface is SPI.
adxl362: driver version is 1.0.
adxl362: min supply voltage is 1.6V.
adxl362: max supply voltage is 3.5V.
adxl362: max current is 0.01mA.
adxl362: max temperature is 85.0C.
adxl362: min temperature is -40.0C.
adxl362: start register test.
adxl362: adxl362_get_revision test.
adxl362: revision is 0x02.
adxl362: adxl362_get_status test.
adxl362: status is 0xC0.
adxl362: adxl362_get_fifo_counter test.
adxl362: fifo counter 0.
adxl362: adxl362_soft_reset test.
adxl362: check reset ok.
adxl362: adxl362_set_fifo_temperature/adxl362_get_fifo_temperature test.
adxl362: enable fifo temperature.
adxl362: check fifo temperature ok.
adxl362: disable fifo temperature.
adxl362: check fifo temperature ok.
adxl362: adxl362_set_fifo_temperature/adxl362_get_fifo_temperature test.
adxl362: set fifo triggered mode.
adxl362: check fifo mode ok.
adxl362: set fifo stream mode.
adxl362: check fifo mode ok.
adxl362: set oldest saved mode.
adxl362: check fifo mode ok.
adxl362: set disable mode.
adxl362: check fifo mode ok.
adxl362: adxl362_set_fifo_sample/adxl362_get_fifo_sample test.
adxl362: set fifo sample 359.
adxl362: check fifo sample error.
adxl362: adxl362_set_interrupt_pin1_active_level/adxl362_get_interrupt_pin1_active_level test.
adxl362: set interrupt pin1 active level high.
adxl362: check interrupt pin1 active level ok.
adxl362: set interrupt pin1 active level low.
adxl362: check interrupt pin1 active level ok.
adxl362: adxl362_set_interrupt_pin1_map/adxl362_get_interrupt_pin1_map test.
adxl362: set interrupt pin1 map awake enable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map awake disable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map inact enable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map inact disable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map act enable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map act disable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map fifo overrun enable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map fifo overrun disable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map fifo watermark enable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map fifo watermark disable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map fifo ready enable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map fifo ready disable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map data ready enable.
adxl362: check interrupt pin1 map ok.
adxl362: set interrupt pin1 map data ready disable.
adxl362: check interrupt pin1 map ok.
adxl362: adxl362_set_interrupt_pin2_map/adxl362_get_interrupt_pin2_map test.
adxl362: set interrupt pin2 map awake enable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map awake disable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map inact enable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map inact disable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map act enable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map act disable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map fifo overrun enable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map fifo overrun disable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map fifo watermark enable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map fifo watermark disable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map fifo ready enable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map fifo ready disable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map data ready enable.
adxl362: check interrupt pin2 map ok.
adxl362: set interrupt pin2 map data ready disable.
adxl362: check interrupt pin2 map ok.
adxl362: adxl362_set_range/adxl362_get_range test.
adxl362: set range 2g.
adxl362: check range ok.
adxl362: set range 4g.
adxl362: check range ok.
adxl362: set range 8g.
adxl362: check range ok.
adxl362: adxl362_set_bandwidth/adxl362_get_bandwidth test.
adxl362: set bandwidth 1/2 odr.
adxl362: check bandwidth ok.
adxl362: set bandwidth 1/4 odr.
adxl362: check bandwidth ok.
adxl362: adxl362_set_interrupt_pin2_as_external_sampling_trigger/adxl362_get_interrupt_pin2_as_external_sampling_trigger test.
adxl362: set interrupt pin2 as external sampling trigger enable.
adxl362: check interrupt pin2 as external sampling trigger ok.
adxl362: set interrupt pin2 as external sampling trigger disable.
adxl362: check interrupt pin2 as external sampling trigger ok.
adxl362: adxl362_set_odr/adxl362_get_odr test.
adxl362: set odr 12.5Hz.
adxl362: check odr ok.
adxl362: set odr 25Hz.
adxl362: check odr ok.
adxl362: set odr 50Hz.
adxl362: check odr ok.
adxl362: set odr 100Hz.
adxl362: check odr ok.
adxl362: set odr 200Hz.
adxl362: check odr ok.
adxl362: set odr 400Hz.
adxl362: check odr ok.
adxl362: adxl362_set_interrupt_pin1_as_external_clock/adxl362_get_interrupt_pin1_as_external_clock test.
adxl362: set interrupt pin1 as external clock enable.
adxl362: check interrupt pin1 as external clock ok.
adxl362: set interrupt pin1 as external clock disable.
adxl362: check interrupt pin1 as external clock ok.
adxl362: adxl362_set_noise_mode/adxl362_get_noise_mode test.
adxl362: set noise mode normal.
adxl362: check noise mode ok.
adxl362: set noise mode low noise.
adxl362: check noise mode ok.
adxl362: set noise mode ultra low noise.
adxl362: check noise mode ok.
adxl362: adxl362_set_wake_up/adxl362_get_wake_up test.
adxl362: set wake up enable.
adxl362: check wake up ok.
adxl362: set wake up disable.
adxl362: check wake up ok.
adxl362: adxl362_set_auto_sleep/adxl362_get_auto_sleep test.
adxl362: set auto sleep enable.
adxl362: check sleep ok.
adxl362: set auto sleep disable.
adxl362: check sleep ok.
adxl362: adxl362_set_mode/adxl362_get_mode test.
adxl362: set mode measurement.
adxl362: check mode ok.
adxl362: set mode standby.
adxl362: check mode ok.
adxl362: adxl362_set_activity_threshold/adxl362_get_activity_threshold test.
adxl362: set activity threshold 0x03F4.
adxl362: check activity threshold ok.
adxl362: adxl362_activity_threshold_convert_to_register/adxl362_activity_threshold_convert_to_data test.
adxl362: activity threshold convert to register 0.08g.
adxl362: check activity threshold 0.08g.
adxl362: adxl362_set_activity_time/adxl362_get_activity_time test.
adxl362: set activity time 0x73.
adxl362: check activity time ok.
adxl362: adxl362_activity_time_convert_to_register/adxl362_activity_time_convert_to_data test.
adxl362: activity time convert to register 79.30ms.
adxl362: check activity time 77.50ms.
adxl362: adxl362_set_inactivity_threshold/adxl362_get_inactivity_threshold test.
adxl362: set inactivity threshold 0x00EB.
adxl362: check inactivity threshold ok.
adxl362: adxl362_inactivity_threshold_convert_to_register/adxl362_inactivity_threshold_convert_to_data test.
adxl362: inactivity threshold convert to register 0.09g.
adxl362: check inactivity threshold 0.09g.
adxl362: adxl362_set_inactivity_time/adxl362_get_inactivity_time test.
adxl362: set inactivity time 0xBB41.
adxl362: check inactivity time ok.
adxl362: adxl362_inactivity_time_convert_to_register/adxl362_inactivity_time_convert_to_data test.
adxl362: inactivity time convert to register 664.90ms.
adxl362: check inactivity time 662.50ms.
adxl362: adxl362_set_detect_mode/adxl362_get_detect_mode test.
adxl362: set detect mode both.
adxl362: check detect mode ok.
adxl362: set detect mode link.
adxl362: check detect mode ok.
adxl362: set detect mode loop.
adxl362: check detect mode ok.
adxl362: adxl362_set_inactivity_detect_trigger/adxl362_get_inactivity_detect_trigger test.
adxl362: set inactivity detect trigger absolute mode.
adxl362: check inactivity detect trigger ok.
adxl362: set inactivity detect trigger referenced mode.
adxl362: check inactivity detect trigger ok.
adxl362: adxl362_set_activity_detect_trigger/adxl362_get_activity_detect_trigger test.
adxl362: set activity detect trigger absolute mode.
adxl362: check activity detect trigger ok.
adxl362: set activity detect trigger referenced mode.
adxl362: check activity detect trigger ok.
adxl362: adxl362_set_inactivity/adxl362_get_inactivity test.
adxl362: set inactivity disable.
adxl362: check inactivity ok.
adxl362: set inactivity enable.
adxl362: check inactivity ok.
adxl362: adxl362_set_activity/adxl362_get_activity test.
adxl362: set activity disable.
adxl362: check activity ok.
adxl362: set activity enable.
adxl362: check activity ok.
adxl362: adxl362_set_self_test/adxl362_get_self_test test.
adxl362: set self test enable.
adxl362: check self test ok.
adxl362: set self test disable.
adxl362: check self test ok.
adxl362: finish register test.
```

```shell
./adxl362 -t read --times=3

adxl362: chip is Analog Devices ADXL362.
adxl362: manufacturer is Analog Devices.
adxl362: interface is SPI.
adxl362: driver version is 1.0.
adxl362: min supply voltage is 1.6V.
adxl362: max supply voltage is 3.5V.
adxl362: max current is 0.01mA.
adxl362: max temperature is 85.0C.
adxl362: min temperature is -40.0C.
adxl362: start read test.
adxl362: 2g range test.
adxl362: x is -0.38g.
adxl362: y is 0.36g.
adxl362: z is 1.05g.
adxl362: x 8msb is -0.40g.
adxl362: y 8msb is 0.35g.
adxl362: z 8msb is 1.04g.
adxl362: x is -0.39g.
adxl362: y is 0.36g.
adxl362: z is 1.05g.
adxl362: x 8msb is -0.40g.
adxl362: y 8msb is 0.35g.
adxl362: z 8msb is 1.04g.
adxl362: x is -0.38g.
adxl362: y is 0.17g.
adxl362: z is 1.08g.
adxl362: x 8msb is -0.38g.
adxl362: y 8msb is 0.16g.
adxl362: z 8msb is 1.07g.
adxl362: 4g range test.
adxl362: x is -0.14g.
adxl362: y is 0.01g.
adxl362: z is 1.15g.
adxl362: x 8msb is -0.16g.
adxl362: y 8msb is 0.00g.
adxl362: z 8msb is 1.15g.
adxl362: x is -0.15g.
adxl362: y is 0.00g.
adxl362: z is 1.15g.
adxl362: x 8msb is -0.16g.
adxl362: y 8msb is 0.00g.
adxl362: z 8msb is 1.12g.
adxl362: x is -0.13g.
adxl362: y is -0.01g.
adxl362: z is 1.16g.
adxl362: x 8msb is -0.13g.
adxl362: y 8msb is -0.03g.
adxl362: z 8msb is 1.15g.
adxl362: 8g range test.
adxl362: x is -0.11g.
adxl362: y is 0.19g.
adxl362: z is 1.28g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: x is -0.10g.
adxl362: y is 0.17g.
adxl362: z is 1.28g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: x is -0.11g.
adxl362: y is 0.19g.
adxl362: z is 1.27g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: read temperature test.
adxl362: temperature is 28.14C.
adxl362: temperature is 28.08C.
adxl362: temperature is 28.27C.
adxl362: 12.5 Hz output rate test.
adxl362: x is -0.09g.
adxl362: y is 0.17g.
adxl362: z is 1.29g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.29g.
adxl362: x is -0.10g.
adxl362: y is 0.17g.
adxl362: z is 1.29g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.29g.
adxl362: x is -0.09g.
adxl362: y is 0.17g.
adxl362: z is 1.28g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: 25Hz output rate test.
adxl362: x is -0.09g.
adxl362: y is 0.17g.
adxl362: z is 1.29g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: x is -0.09g.
adxl362: y is 0.17g.
adxl362: z is 1.29g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: x is -0.09g.
adxl362: y is 0.17g.
adxl362: z is 1.28g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: 50Hz output rate test.
adxl362: x is -0.09g.
adxl362: y is 0.17g.
adxl362: z is 1.28g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: x is -0.10g.
adxl362: y is 0.16g.
adxl362: z is 1.29g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: x is -0.09g.
adxl362: y is 0.17g.
adxl362: z is 1.29g.
adxl362: x 8msb is -0.14g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: 100Hz output rate test.
adxl362: x is -0.07g.
adxl362: y is 0.17g.
adxl362: z is 1.28g.
adxl362: x 8msb is -0.07g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: x is -0.07g.
adxl362: y is 0.17g.
adxl362: z is 1.28g.
adxl362: x 8msb is -0.07g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: x is -0.07g.
adxl362: y is 0.19g.
adxl362: z is 1.26g.
adxl362: x 8msb is -0.07g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.23g.
adxl362: 200Hz output rate test.
adxl362: x is -0.07g.
adxl362: y is 0.16g.
adxl362: z is 1.29g.
adxl362: x 8msb is -0.07g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.29g.
adxl362: x is -0.06g.
adxl362: y is 0.15g.
adxl362: z is 1.30g.
adxl362: x 8msb is -0.07g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.29g.
adxl362: x is -0.07g.
adxl362: y is 0.15g.
adxl362: z is 1.31g.
adxl362: x 8msb is -0.07g.
adxl362: y 8msb is 0.14g.
adxl362: z 8msb is 1.29g.
adxl362: 400Hz output rate test.
adxl362: x is -0.00g.
adxl362: y is 0.06g.
adxl362: z is 1.21g.
adxl362: x 8msb is -0.07g.
adxl362: y 8msb is 0.00g.
adxl362: z 8msb is 1.16g.
adxl362: x is -0.00g.
adxl362: y is 0.07g.
adxl362: z is 1.22g.
adxl362: x 8msb is -0.07g.
adxl362: y 8msb is 0.07g.
adxl362: z 8msb is 1.16g.
adxl362: x is -0.01g.
adxl362: y is 0.07g.
adxl362: z is 1.22g.
adxl362: x 8msb is -0.07g.
adxl362: y 8msb is 0.07g.
adxl362: z 8msb is 1.16g.
adxl362: finish read test.
```

```shell
./adxl362 -t fifo --times=3

adxl362: chip is Analog Devices ADXL362.
adxl362: manufacturer is Analog Devices.
adxl362: interface is SPI.
adxl362: driver version is 1.0.
adxl362: min supply voltage is 1.6V.
adxl362: max supply voltage is 3.5V.
adxl362: max current is 0.01mA.
adxl362: max temperature is 85.0C.
adxl362: min temperature is -40.0C.
adxl362: start fifo test.
adxl362: irq fifo watermark with 100.
adxl362: x axis is -2.05g.
adxl362: y axis is -2.05g.
adxl362: z axis is -2.05g.
adxl362: temperature is -133.12C.
adxl362: x axis is -0.24g.
adxl362: y axis is 0.16g.
adxl362: z axis is 1.21g.
adxl362: temperature is 27.82C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.82C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.82C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 27.82C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: irq fifo watermark with 100.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.10g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.75C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: finish fifo test.
adxl362: irq fifo watermark with 100.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 27.82C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.14g.
adxl362: temperature is 27.82C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.01C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
adxl362: x axis is -0.25g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 27.95C.
adxl362: x axis is -0.26g.
adxl362: y axis is 0.09g.
adxl362: z axis is 1.13g.
adxl362: temperature is 28.08C.
```

```shell
./adxl362 -t motion --times=3

adxl362: chip is Analog Devices ADXL362.
adxl362: manufacturer is Analog Devices.
adxl362: interface is SPI.
adxl362: driver version is 1.0.
adxl362: min supply voltage is 1.6V.
adxl362: max supply voltage is 3.5V.
adxl362: max current is 0.01mA.
adxl362: max temperature is 85.0C.
adxl362: min temperature is -40.0C.
adxl362: start motion test.
adxl362: irq activity.
adxl362: irq activity.
adxl362: irq activity.
adxl362: finish motion test.
```

```shell
./adxl362 -e basic --times=3

1/3
adxl362: x is -0.432g.
adxl362: y is 0.304g.
adxl362: z is 1.054g.
2/3
adxl362: x is -0.433g.
adxl362: y is 0.303g.
adxl362: z is 1.055g.
3/3
adxl362: x is -0.433g.
adxl362: y is 0.302g.
adxl362: z is 1.049g.
```

```shell
./adxl362 -e fifo --times=3

adxl362: irq fifo watermark with 129.
adxl362: x axis is -2.05g.
adxl362: y axis is -2.05g.
adxl362: z axis is -2.05g.
adxl362: x axis is -0.42g.
adxl362: y axis is 0.32g.
adxl362: z axis is 1.09g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.44g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: irq fifo watermark with 129.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: irq fifo watermark with 129.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.44g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.43g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
adxl362: x axis is -0.44g.
adxl362: y axis is 0.31g.
adxl362: z axis is 1.05g.
```

```shell
./adxl362 -e motion --times=3

adxl362: irq activity.
adxl362: motion detect 3.
adxl362: irq activity.
adxl362: motion detect 2.
adxl362: irq activity.
adxl362: motion detect 1.
```

```shell
./adxl362 -h

Usage:
  adxl362 (-i | --information)
  adxl362 (-h | --help)
  adxl362 (-p | --port)
  adxl362 (-t reg | --test=reg)
  adxl362 (-t read | --test=read) [--times=<num>]
  adxl362 (-t fifo | --test=fifo) [--times=<num>]
  adxl362 (-t motion | --test=motion) [--times=<num>]
  adxl362 (-e basic | --example=basic) [--times=<num>]
  adxl362 (-e fifo | --example=fifo) [--times=<num>]
  adxl362 (-e motion | --example=motion) [--times=<num>]

Options:
  -e <basic | fifo | motion>, --example=<basic | fifo | motion>
                       Run the driver example.
  -h, --help           Show the help.
  -i, --information    Show the chip information.
  -p, --port           Display the pin connections of the current board.
  -t <reg | read | fifo | motion>, --test=<reg | read | fifo | motion>
                       Run the driver test.
      --times=<num>    Set the running times.([default: 3])
```

#### 3.3 Command Problem

There is some unknown problem in the gpio interrupt or data reading of adxl362 on the raspberry board, motion detecting always failed.
