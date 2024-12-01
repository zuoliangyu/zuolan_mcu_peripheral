### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

SPI Pin: SCLK/MOSI/MISO/CS GPIO11/GPIO10/GPIO9/GPIO8.

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
find_package(w25qxx REQUIRED)
```

### 3. W25QXX

#### 3.1 Command Instruction

1. Show w25qxx chip and driver information.

   ```shell
   w25qxx (-i | --information)
   ```

2. Show w25qxx help.

   ```shell
   w25qxx (-h | --help)
   ```

3. Show w25qxx pin connections of the current board.

   ```shell
   w25qxx (-p | --port)
   ```

4. Run w25qxx register test.

   ```shell
   w25qxx (-t reg | --test=reg) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
   ```

5. Run w25qxx read test.

   ```shell
   w25qxx (-t read | --test=read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
   ```

6. Run w25qxx basic power down function.

   ```shell
   w25qxx (-e power-down | --example=power-down) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
   ```

7. Run w25qxx basic wake up function.

   ```shell
   w25qxx (-e wake-up | --example=wake-up) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
   ```

8. Run w25qxx basic chip erase function.

   ```shell
   w25qxx (-e chip-erase | --example=chip-erase) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
   ```

9. Run w25qxx basic get id function.

   ```shell
   w25qxx (-e get-id | --example=get-id) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
   ```

10. Run w25qxx basic read function, address is the read address.

    ```shell
    w25qxx (-e read | --example=read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address>
    ```

11. Run w25qxx basic write function, address is the write address, hex is the write data.

    ```shell
    w25qxx (-e write | --example=write) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address> --data=<hex>
    ```

12. Run w25qxx advance power down function.

    ```shell
    w25qxx (-e advance-power-down | --example=advance-power-down) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

13. Run w25qxx advance wake up function.

    ```shell
    w25qxx (-e advance-wake-up | --example=advance-wake-up) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

14. Run w25qxx advance chip erase function.

    ```shell
    w25qxx (-e advance-chip-erase | --example=advance-chip-erase) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

15. Run w25qxx advance get id function.

    ```shell
    w25qxx (-e advance-get-id | --example=advance-get-id) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

16. Run w25qxx advance read function, address is the read address.

    ```shell
    w25qxx (-e advance-read | --example=advance-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address>
    ```

17. Run w25qxx advance write function, address is the write address, hex is the write data.

    ```shell
    w25qxx (-e advance-write | --example=advance-write) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address> --data=<hex>
    ```

18. Run w25qxx advance page program function, address is the program address, hex is the write data.

    ```shell
    w25qxx (-e advance-page-program | --example=advance-page-program) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address> --data=<hex>
    ```

19. Run w25qxx advance erase 4k function, address is the erase address.

    ```shell
    w25qxx (-e advance-erase-4k | --example=advance-erase-4k) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address>
    ```

20. Run w25qxx advance erase 32k function, address is the erase address.

    ```shell
    w25qxx (-e advance-erase-32k | --example=advance-erase-32k) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address>
    ```

21. Run w25qxx advance erase 64k function, address is the erase address.

    ```shell
    w25qxx (-e advance-erase-64k | --example=advance-erase-64k) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address>
    ```

22. Run w25qxx advance fast read function, address is the read address. 

    ```shell
    w25qxx (-e advance-fast-read | --example=advance-fast-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address>
    ```

23. Run w25qxx advance get status1 function.

    ```shell
    w25qxx (-e advance-get-status1 | --example=advance-get-status1) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

24. Run w25qxx advance get status2 function.

    ```shell
    w25qxx (-e advance-get-status2 | --example=advance-get-status2) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

25. Run w25qxx advance get status3 function.

    ```shell
    w25qxx (-e advance-get-status3 | --example=advance-get-status3) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

26. Run w25qxx advance set status1 function, hex is the set status.

    ```shell
    w25qxx (-e advance-set-status1 | --example=advance-set-status1) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --status=<hex>
    ```

27. Run w25qxx advance set status2 function, hex is the set status.

    ```shell
    w25qxx (-e advance-set-status2 | --example=advance-set-status2) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --status=<hex>
    ```

28. Run w25qxx advance set status3 function, hex is the set status.

    ```shell
    w25qxx (-e advance-set-status3 | --example=advance-set-status3) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --status=<hex>
    ```

29. Run w25qxx advance get jedec id function.

    ```shell
    w25qxx (-e advance-get-jedec-id | --example=advance-get-jedec-id) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

30. Run w25qxx advance global lock function.

    ```shell
    w25qxx (-e advance-global-lock | --example=advance-global-lock) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

31. Run w25qxx advance global unlock function.

    ```shell
    w25qxx (-e advance-global-unlock | --example=advance-global-unlock) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

32. Run w25qxx advance block lock function, address is the block address.

    ```shell
    w25qxx (-e advance-block-lock | --example=advance-block-lock) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address>
    ```

33. Run w25qxx advance block unlock function, address is the block address.

    ```shell
    w25qxx (-e advance-block-unlock | --example=advance-block-unlock) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address>
    ```

34. Run w25qxx advance read block function, address is the read address.

    ```shell
    w25qxx (-e advance-read-block | --example=advance-read-block) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>] --addr=<address>
    ```

35. Run w25qxx advance reset function.

    ```shell
    w25qxx (-e advance-reset | --example=advance-reset) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
    ```

36. Run w25qxx advance spi read function, address is the read address.

    ```shell
    w25qxx (-e advance-spi-read | --example=advance-spi-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --addr=<address>
    ```

37. Run w25qxx advance spi dual output read function, address is the read address.

    ```shell
    w25qxx (-e advance-spi-dual-output-read | --example=advance-spi-dual-output-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --addr=<address>
    ```

38. Run w25qxx advance spi quad output read function, address is the read address. 

    ```shell
    w25qxx (-e advance-spi-quad-output-read | --example=advance-spi-quad-output-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --addr=<address>
    ```

39. Run w25qxx advance spi dual io read function, address is the read address.  

    ```shell
    w25qxx (-e advance-spi-dual-io-read | --example=advance-spi-dual-io-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --addr=<address>
    ```

40. Run w25qxx advance spi quad io read function, address is the read address.  

    ```shell
    w25qxx (-e advance-spi-quad-io-read | --example=advance-spi-quad-io-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --addr=<address>
    ```

41. Run w25qxx advance spi word quad io read function, address is the read address. 

    ```shell
    w25qxx (-e advance-spi-word-quad-io-read | --example=advance-spi-word-quad-io-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --addr=<address>
    ```

42. Run w25qxx advance spi octal word quad io read function, address is the read address.    

    ```shell
    w25qxx (-e advance-spi-octal-word-quad-io-read | --example=advance-spi-octal-word-quad-io-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --addr=<address>
    ```

43. Run w25qxx advance page program quad input function, address is the write address, hex is the write data.   

    ```shell
    w25qxx (-e advance-spi-page-program-quad-input | --example=advance-spi-page-program-quad-input) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --addr=<address> --data=<hex>
    ```

44. Run w25qxx advance get id dual io function.

    ```shell
    w25qxx (-e advance-spi-get-id-dual-io | --example=advance-spi-get-id-dual-io) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
    ```

45. Run w25qxx advance get id quad io function.

    ```shell
    w25qxx (-e advance-spi-get-id-quad-io | --example=advance-spi-get-id-quad-io) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
    ```

46. Run w25qxx advance get sfdp function.

    ```shell
    w25qxx (-e advance-spi-get-sfdp | --example=advance-spi-get-sfdp) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
    ```

47. Run w25qxx advance write security register function, hex is the write data.    

    ```shell
    w25qxx (-e advance-spi-write-security | --example=advance-spi-write-security) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --num=<1 | 2 | 3> --data=<hex>
    ```

48. Run w25qxx advance read security register function.

    ```shell
    w25qxx (-e advance-spi-read-security | --example=advance-spi-read-security) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --num=<1 | 2 | 3>
    ```

49. Run w25qxx advance set read parameters function.

    ```shell
    w25qxx (-e advance-qspi-set-read-parameters | --example=advance-qspi-set-read-parameters) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --dummy=<DUMMY_2_33MHZ | DUMMY_4_55MHZ | DUMMY_6_80MHZ | DUMMY_8_80MHZ> --length=<8 | 16 | 32 | 64>
    ```

50. Run w25qxx advance set burst function. 

    ```shell
    w25qxx (-e advance-spi-set-burst | --example=advance-spi-set-burst) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --wrap=<WRAP_NONE | WRAP_8_BYTE | WRAP_16_BYTE | WRAP_32_BYTE | WRAP_64_BYTE>
    ```

#### 3.2 Command Example

```shell
./w25qxx -i

w25qxx: chip is Winbond W25QXX.
w25qxx: manufacturer is Winbond.
w25qxx: interface is SPI QSPI.
w25qxx: driver version is 1.0.
w25qxx: min supply voltage is 2.7V.
w25qxx: max supply voltage is 3.6V.
w25qxx: max current is 25.00mA.
w25qxx: max temperature is 85.0C.
w25qxx: min temperature is -40.0C.
```

```shell
./w25qxx -p

w25qxx: SPI interface SCK connected to GPIO11(BCM).
w25qxx: SPI interface MISO connected to GPIO9(BCM).
w25qxx: SPI interface MOSI connected to GPIO10(BCM).
w25qxx: SPI interface CS connected to GPIO8(BCM).
```

```shell
./w25qxx -t reg --type=W25Q128 --interface=spi

w25qxx: chip is Winbond W25QXX.
w25qxx: manufacturer is Winbond.
w25qxx: interface is SPI QSPI.
w25qxx: driver version is 1.0.
w25qxx: min supply voltage is 2.7V.
w25qxx: max supply voltage is 3.6V.
w25qxx: max current is 25.00mA.
w25qxx: max temperature is 85.0C.
w25qxx: min temperature is -40.0C.
w25qxx: start register test.
w25qxx: w25qxx_set_type/w25qxx_get_type test.
w25qxx: set type W25Q80.
w25qxx: check chip type ok.
w25qxx: set type W25Q16.
w25qxx: check chip type ok.
w25qxx: set type W25Q32.
w25qxx: check chip type ok.
w25qxx: set type W25Q64.
w25qxx: check chip type ok.
w25qxx: set type W25Q128.
w25qxx: check chip type ok.
w25qxx: set type W25Q256.
w25qxx: check chip type ok.
w25qxx: w25qxx_set_interface/w25qxx_get_interface test.
w25qxx: set interface SPI.
w25qxx: check chip interface ok.
w25qxx: set interface QSPI.
w25qxx: check chip interface ok.
w25qxx: w25qxx_get_manufacturer_device_id test.
w25qxx: manufacturer is 0xEF, device id is 0x17.
w25qxx: w25qxx_get_jedec_id test.
w25qxx: manufacturer is 0xEF, device id is 0x40 0x18.
w25qxx: w25qxx_get_unique_id test.
w25qxx: unique id 0xD2 0x66 0x78 0xB2 0x5F 0x26 0x2D 0x24.
w25qxx: w25qxx_set_status1/w25qxx_get_status1 test.
w25qxx: status1 is 0x00.
w25qxx: w25qxx_set_status2/w25qxx_get_status2 test.
w25qxx: status2 is 0x02.
w25qxx: w25qxx_set_status3/w25qxx_get_status3 test.
w25qxx: status3 is 0x60.
w25qxx: w25qxx_enable_write test.
w25qxx: check enable write ok.
w25qxx: w25qxx_disable_write test.
w25qxx: check disable write ok.
w25qxx: w25qxx_enable_write test.
w25qxx: check enable sr write ok.
w25qxx: w25qxx_erase_program_suspend test.
w25qxx: check erase program suspend ok.
w25qxx: w25qxx_erase_program_suspend test.
w25qxx: check erase program resume ok.
w25qxx: w25qxx_global_block_lock test.
w25qxx: check global block lock ok.
w25qxx: w25qxx_global_block_unlock test.
w25qxx: check global block unlock ok.
w25qxx: w25qxx_individual_block_lock test.
w25qxx: check individual block lock ok.
w25qxx: w25qxx_read_block_lock test.
w25qxx: check read block lock ok with 1.
w25qxx: w25qxx_individual_block_unlock test.
w25qxx: check individual block unlock ok.
w25qxx: w25qxx_set_burst_with_wrap test.
w25qxx: check set burst with wrap ok.
w25qxx: w25qxx_power_down test.
w25qxx: w25qxx_release_power_down test.
w25qxx: w25qxx_enable_reset test.
w25qxx: w25qxx_reset_device test.
w25qxx: finish register test.
```

```shell
./w25qxx -t read --type=W25Q128 --interface=spi

w25qxx: chip is Winbond W25QXX.
w25qxx: manufacturer is Winbond.
w25qxx: interface is SPI QSPI.
w25qxx: driver version is 1.0.
w25qxx: min supply voltage is 2.7V.
w25qxx: max supply voltage is 3.6V.
w25qxx: max current is 25.00mA.
w25qxx: max temperature is 85.0C.
w25qxx: min temperature is -40.0C.
w25qxx: start read test.
w25qxx: w25qxx_write/w25qxx_read test.
w25qxx: 0x00000000/0x01000000 successful.
w25qxx: 0x00100000/0x01000000 successful.
w25qxx: 0x00200000/0x01000000 successful.
w25qxx: 0x00300000/0x01000000 successful.
w25qxx: 0x00400000/0x01000000 successful.
w25qxx: 0x00500000/0x01000000 successful.
w25qxx: 0x00600000/0x01000000 successful.
w25qxx: 0x00700000/0x01000000 successful.
w25qxx: 0x00800000/0x01000000 successful.
w25qxx: 0x00900000/0x01000000 successful.
w25qxx: 0x00A00000/0x01000000 successful.
w25qxx: 0x00B00000/0x01000000 successful.
w25qxx: 0x00C00000/0x01000000 successful.
w25qxx: 0x00D00000/0x01000000 successful.
w25qxx: 0x00E00000/0x01000000 successful.
w25qxx: 0x00F00000/0x01000000 successful.
w25qxx: w25qxx_sector_erase_4k test with address 0x4000.
w25qxx: only spi read test passed.
w25qxx: fast read test passed.
w25qxx: w25qxx_block_erase_32k test with address 0x40000.
w25qxx: only spi read test passed.
w25qxx: fast read test passed.
w25qxx: w25qxx_block_erase_64k test with address 0x10000.
w25qxx: only spi read test passed.
w25qxx: fast read test passed.
w25qxx: get sfdp.
w25qxx: sdfp[0-7] is 0xE9 0x41 0xE1 0x93 0x0A 0xDA 0xC1 0xE5.
w25qxx: sdfp[8-15] is 0x66 0xE0 0xCA 0xF1 0xB8 0xD4 0x7E 0x15.
w25qxx: sdfp[16-23] is 0x9E 0xF8 0xC6 0x24 0x52 0x7F 0xE7 0x6D.
w25qxx: sdfp[24-31] is 0xDD 0xFF 0x97 0xA1 0x1B 0x44 0xC5 0x05.
w25qxx: sdfp[32-39] is 0x86 0xA6 0x98 0x90 0x80 0x59 0x75 0xE7.
w25qxx: sdfp[40-47] is 0x39 0x3F 0xD8 0xF1 0x14 0x56 0x07 0xB2.
w25qxx: sdfp[48-55] is 0x4F 0xCD 0xD6 0xA1 0x4C 0xBD 0x0E 0x29.
w25qxx: sdfp[56-63] is 0xBC 0xA5 0xCB 0xD8 0xEA 0x90 0xDD 0x70.
w25qxx: sdfp[64-71] is 0x36 0x75 0x00 0xB7 0xCE 0x75 0x9E 0x07.
w25qxx: sdfp[72-79] is 0xB5 0x76 0xF9 0xC9 0xCC 0x00 0x7B 0x1B.
w25qxx: sdfp[80-87] is 0xCD 0x51 0xBC 0x19 0x0F 0xCB 0x43 0xCB.
w25qxx: sdfp[88-95] is 0x70 0x0E 0xA3 0x5A 0x9E 0x80 0xCA 0xD4.
w25qxx: sdfp[96-103] is 0xF5 0xCA 0x8B 0xC3 0x40 0x29 0xCB 0xF5.
w25qxx: sdfp[104-111] is 0x9F 0xC4 0xBE 0x6C 0xC4 0x39 0x87 0x91.
w25qxx: sdfp[112-119] is 0x8A 0x44 0xAA 0x99 0x0F 0xED 0x65 0x7F.
w25qxx: sdfp[120-127] is 0xFB 0x08 0xDA 0x99 0x89 0xA4 0x6E 0x7E.
w25qxx: sdfp[128-135] is 0x6F 0xF9 0x42 0xAF 0x23 0x0D 0xA4 0xC2.
w25qxx: sdfp[136-143] is 0xD1 0x62 0x2E 0x95 0x9B 0xB6 0x26 0x25.
w25qxx: sdfp[144-151] is 0xFA 0xD0 0xBF 0x09 0xBE 0x24 0x88 0xB9.
w25qxx: sdfp[152-159] is 0x2C 0x62 0x53 0xB5 0x07 0xC1 0x34 0x76.
w25qxx: sdfp[160-167] is 0xBA 0x76 0x25 0xDD 0x83 0xC9 0xA0 0x54.
w25qxx: sdfp[168-175] is 0x2B 0xCE 0xE9 0xC6 0x84 0x0F 0xEB 0x7E.
w25qxx: sdfp[176-183] is 0xDF 0xAA 0x87 0x9D 0xCE 0x10 0x57 0xFB.
w25qxx: sdfp[184-191] is 0x72 0xAA 0xB0 0x79 0x6B 0xE4 0xEF 0x25.
w25qxx: sdfp[192-199] is 0x5A 0x14 0x03 0xDD 0xDD 0xA3 0x31 0x08.
w25qxx: sdfp[200-207] is 0x71 0x1A 0xCE 0xF6 0x29 0xBA 0x74 0x09.
w25qxx: sdfp[208-215] is 0x64 0xFC 0xA6 0x33 0x0C 0xFD 0x2E 0x7E.
w25qxx: sdfp[216-223] is 0xA7 0xDE 0xF8 0x12 0xC3 0xE7 0x38 0x1D.
w25qxx: sdfp[224-231] is 0xFC 0x3B 0xFB 0xD9 0xDE 0x2C 0xE2 0x4F.
w25qxx: sdfp[232-239] is 0x47 0xB0 0x45 0x70 0x6A 0xBA 0x79 0xCF.
w25qxx: sdfp[240-247] is 0xB6 0x20 0x02 0xC2 0x1D 0x30 0x40 0xC5.
w25qxx: sdfp[248-255] is 0x0E 0x38 0xD7 0xD1 0x20 0x0F 0xEF 0x1C.
w25qxx: security register1 write and read test.
w25qxx: security register1 check passed.
w25qxx: security register2 write and read test.
w25qxx: security register2 check passed.
w25qxx: security register3 write and read test.
w25qxx: security register3 check passed.
w25qxx: start chip erasing.
w25qxx: w25qxx_chip_erase test.
w25qxx: chip erase successful.
w25qxx: finish read test.
```

```shell
./w25qxx -e power-down --type=W25Q128 --interface=spi

w25qxx: power down successful.
```

```shell
./w25qxx -e wake-up --type=W25Q128 --interface=spi

w25qxx: wake up successful.
```

```shell
./w25qxx -e chip-erase --type=W25Q128 --interface=spi

w25qxx: start chip erase.
w25qxx: chip erase successful.
```

```shell
./w25qxx -e get-id --type=W25Q128 --interface=spi

w25qxx: manufacturer is 0xEF device id is 0x17.
```

```shell
./w25qxx -e read --type=W25Q128 --interface=spi --addr=0x000000

w25qxx: addr 0 is 8.
```

```shell
./w25qxx -e write --type=W25Q128 --interface=spi --addr=0x000000 --data=0x08

w25qxx: addr 0 write data 8.
```

```shell
./w25qxx -e advance-power-down --type=W25Q128 --interface=spi

w25qxx: power down successful.
```

```shell
./w25qxx -e advance-wake-up --type=W25Q128 --interface=spi

w25qxx: wake up successful.
```

```shell
./w25qxx -e advance-chip-erase --type=W25Q128 --interface=spi

w25qxx: start chip erase.
w25qxx: chip erase successful.
```

```shell
./w25qxx -e advance-get-id --type=W25Q128 --interface=spi

w25qxx: manufacturer is 0xEF device id is 0x17.
```

```shell
./w25qxx -e advance-read --type=W25Q128 --interface=spi --addr=0x000000

w25qxx: addr 0 is 2.
```

```shell
./w25qxx -e advance-write --type=W25Q128 --interface=spi --addr=0x000000 --data=0x02

w25qxx: addr 0 write data 2.
```

```shell
./w25qxx -e advance-page-program --type=W25Q128 --interface=spi --addr=0x000000 --data=0x06

w25qxx: addr 0 page program data 6.
```

```shell
./w25qxx -e advance-erase-4k --type=W25Q128 --interface=spi --addr=0x000000

w25qxx: erase 4k addr 0 successful.
```

```shell
./w25qxx -e advance-erase-32k --type=W25Q128 --interface=spi --addr=0x000000

w25qxx: erase 32k addr 0 successful.
```

```shell
./w25qxx -e advance-erase-64k --type=W25Q128 --interface=spi --addr=0x000000

w25qxx: erase 64k addr 0 successful.
```

```shell
./w25qxx -e advance-fast-read --type=W25Q128 --interface=spi --addr=0x000000

w25qxx: addr 0 is 255.
```

```shell
./w25qxx -e advance-get-status1 --type=W25Q128 --interface=spi

w25qxx: get status1 is 0x00.
```

```shell
./w25qxx -e advance-get-status2 --type=W25Q128 --interface=spi

w25qxx: get status2 is 0x00.
```

```shell
./w25qxx -e advance-get-status3 --type=W25Q128 --interface=spi

w25qxx: get status3 is 0x60.
```

```shell
./w25qxx -e advance-set-status1 --type=W25Q128 --interface=spi --status=0x00

w25qxx: set status1 0x00.
```

```shell
./w25qxx -e advance-set-status2 --type=W25Q128 --interface=spi --status=0x02

w25qxx: set status2 0x02.
```

```shell
./w25qxx -e advance-set-status3 --type=W25Q128 --interface=spi --status=0x60

w25qxx: set status3 0x60.
```

```shell
./w25qxx -e advance-get-jedec-id --type=W25Q128 --interface=spi

w25qxx: manufacturer is 0xEF device id is 0x40 0x18.
```

```shell
./w25qxx -e advance-global-lock --type=W25Q128 --interface=spi

w25qxx: global block lock successful.  
```

```shell
./w25qxx -e advance-global-unlock --type=W25Q128 --interface=spi

w25qxx: global block unlock successful.
```

```shell
./w25qxx -e advance-block-lock --type=W25Q128 --interface=spi --addr=0x000000

w25qxx: block lock addr 0.
```

```shell
./w25qxx -e advance-block-unlock --type=W25Q128 --interface=spi --addr=0x000000

w25qxx: block unlock addr 0.
```

```shell
./w25qxx -e advance-read-block --type=W25Q128 --interface=spi --addr=0x000000

w25qxx: read block addr 0 is 1.
```

```shell
./w25qxx -e advance-reset --type=W25Q128 --interface=spi

w25qxx: reset successful.
```

```shell
./w25qxx -e advance-spi-read --type=W25Q128 --addr=0x000000 --interface=spi

w25qxx: add 0 spi read is 0xFF.
```

```shell
./w25qxx -e advance-spi-dual-output-read --type=W25Q128 --addr=0x000000 --interface=spi

w25qxx: this chip can't use this function.
```

```shell
./w25qxx -e advance-spi-quad-output-read --type=W25Q128 --addr=0x000000 --interface=spi

w25qxx: this chip can't use this function.
```

```shell
./w25qxx -e advance-spi-dual-io-read --type=W25Q128 --addr=0x000000 --interface=spi

w25qxx: this chip can't use this function.
```

```shell
./w25qxx -e advance-spi-quad-io-read --type=W25Q128 --addr=0x000000 --interface=spi

w25qxx: this chip can't use this function.
```

```shell
./w25qxx -e advance-spi-word-quad-io-read --type=W25Q128 --addr=0x000000 --interface=spi

w25qxx: this chip can't use this function.
```

```shell
./w25qxx -e advance-spi-octal-word-quad-io-read --type=W25Q128 --addr=0x000000 --interface=spi

w25qxx: this chip can't use this function.
```

```shell
./w25qxx -e advance-spi-read-security --type=W25Q128 --num=1 --interface=spi

w25qxx: read 4096 security register.
w25qxx: 0xE9 0x41 0xE1 0x93 0x0A 0xDA 0xC1 0xE5.
w25qxx: 0x66 0xE0 0xCA 0xF1 0xB8 0xD4 0x7E 0x15.
w25qxx: 0x9E 0xF8 0xC6 0x24 0x52 0x7F 0xE7 0x6D.
w25qxx: 0xDD 0xFF 0x97 0xA1 0x1B 0x44 0xC5 0x05.
w25qxx: 0x86 0xA6 0x98 0x90 0x80 0x59 0x75 0xE7.
w25qxx: 0x39 0x3F 0xD8 0xF1 0x14 0x56 0x07 0xB2.
w25qxx: 0x4F 0xCD 0xD6 0xA1 0x4C 0xBD 0x0E 0x29.
w25qxx: 0xBC 0xA5 0xCB 0xD8 0xEA 0x90 0xDD 0x70.
w25qxx: 0x36 0x75 0x00 0xB7 0xCE 0x75 0x9E 0x07.
w25qxx: 0xB5 0x76 0xF9 0xC9 0xCC 0x00 0x7B 0x1B.
w25qxx: 0xCD 0x51 0xBC 0x19 0x0F 0xCB 0x43 0xCB.
w25qxx: 0x70 0x0E 0xA3 0x5A 0x9E 0x80 0xCA 0xD4.
w25qxx: 0xF5 0xCA 0x8B 0xC3 0x40 0x29 0xCB 0xF5.
w25qxx: 0x9F 0xC4 0xBE 0x6C 0xC4 0x39 0x87 0x91.
w25qxx: 0x8A 0x44 0xAA 0x99 0x0F 0xED 0x65 0x7F.
w25qxx: 0xFB 0x08 0xDA 0x99 0x89 0xA4 0x6E 0x7E.
w25qxx: 0x6F 0xF9 0x42 0xAF 0x23 0x0D 0xA4 0xC2.
w25qxx: 0xD1 0x62 0x2E 0x95 0x9B 0xB6 0x26 0x25.
w25qxx: 0xFA 0xD0 0xBF 0x09 0xBE 0x24 0x88 0xB9.
w25qxx: 0x2C 0x62 0x53 0xB5 0x07 0xC1 0x34 0x76.
w25qxx: 0xBA 0x76 0x25 0xDD 0x83 0xC9 0xA0 0x54.
w25qxx: 0x2B 0xCE 0xE9 0xC6 0x84 0x0F 0xEB 0x7E.
w25qxx: 0xDF 0xAA 0x87 0x9D 0xCE 0x10 0x57 0xFB.
w25qxx: 0x72 0xAA 0xB0 0x79 0x6B 0xE4 0xEF 0x25.
w25qxx: 0x5A 0x14 0x03 0xDD 0xDD 0xA3 0x31 0x08.
w25qxx: 0x71 0x1A 0xCE 0xF6 0x29 0xBA 0x74 0x09.
w25qxx: 0x64 0xFC 0xA6 0x33 0x0C 0xFD 0x2E 0x7E.
w25qxx: 0xA7 0xDE 0xF8 0x12 0xC3 0xE7 0x38 0x1D.
w25qxx: 0xFC 0x3B 0xFB 0xD9 0xDE 0x2C 0xE2 0x4F.
w25qxx: 0x47 0xB0 0x45 0x70 0x6A 0xBA 0x79 0xCF.
w25qxx: 0xB6 0x20 0x02 0xC2 0x1D 0x30 0x40 0xC5.
w25qxx: 0x0E 0x38 0xD7 0xD1 0x20 0x0F 0xEF 0x1C.
```

```shell
./w25qxx -e advance-spi-get-id-dual-io --type=W25Q128 --interface=spi

w25qxx: this chip can't use this function.
```

```shell
./w25qxx -e advance-spi-get-id-quad-io --type=W25Q128 --interface=spi

w25qxx: this chip can't use this function.
```

```shell
./w25qxx -e advance-spi-get-sfdp --type=W25Q128 --interface=spi

w25qxx: sdfp[0-7] is 0xE9 0x41 0xE1 0x93 0x0A 0xDA 0xC1 0xE5.
w25qxx: sdfp[8-15] is 0x66 0xE0 0xCA 0xF1 0xB8 0xD4 0x7E 0x15.
w25qxx: sdfp[16-23] is 0x9E 0xF8 0xC6 0x24 0x52 0x7F 0xE7 0x6D.
w25qxx: sdfp[24-31] is 0xDD 0xFF 0x97 0xA1 0x1B 0x44 0xC5 0x05.
w25qxx: sdfp[32-39] is 0x86 0xA6 0x98 0x90 0x80 0x59 0x75 0xE7.
w25qxx: sdfp[40-47] is 0x39 0x3F 0xD8 0xF1 0x14 0x56 0x07 0xB2.
w25qxx: sdfp[48-55] is 0x4F 0xCD 0xD6 0xA1 0x4C 0xBD 0x0E 0x29.
w25qxx: sdfp[56-63] is 0xBC 0xA5 0xCB 0xD8 0xEA 0x90 0xDD 0x70.
w25qxx: sdfp[64-71] is 0x36 0x75 0x00 0xB7 0xCE 0x75 0x9E 0x07.
w25qxx: sdfp[72-79] is 0xB5 0x76 0xF9 0xC9 0xCC 0x00 0x7B 0x1B.
w25qxx: sdfp[80-87] is 0xCD 0x51 0xBC 0x19 0x0F 0xCB 0x43 0xCB.
w25qxx: sdfp[88-95] is 0x70 0x0E 0xA3 0x5A 0x9E 0x80 0xCA 0xD4.
w25qxx: sdfp[96-103] is 0xF5 0xCA 0x8B 0xC3 0x40 0x29 0xCB 0xF5.
w25qxx: sdfp[104-111] is 0x9F 0xC4 0xBE 0x6C 0xC4 0x39 0x87 0x91.
w25qxx: sdfp[112-119] is 0x8A 0x44 0xAA 0x99 0x0F 0xED 0x65 0x7F.
w25qxx: sdfp[120-127] is 0xFB 0x08 0xDA 0x99 0x89 0xA4 0x6E 0x7E.
w25qxx: sdfp[128-135] is 0x6F 0xF9 0x42 0xAF 0x23 0x0D 0xA4 0xC2.
w25qxx: sdfp[136-143] is 0xD1 0x62 0x2E 0x95 0x9B 0xB6 0x26 0x25.
w25qxx: sdfp[144-151] is 0xFA 0xD0 0xBF 0x09 0xBE 0x24 0x88 0xB9.
w25qxx: sdfp[152-159] is 0x2C 0x62 0x53 0xB5 0x07 0xC1 0x34 0x76.
w25qxx: sdfp[160-167] is 0xBA 0x76 0x25 0xDD 0x83 0xC9 0xA0 0x54.
w25qxx: sdfp[168-175] is 0x2B 0xCE 0xE9 0xC6 0x84 0x0F 0xEB 0x7E.
w25qxx: sdfp[176-183] is 0xDF 0xAA 0x87 0x9D 0xCE 0x10 0x57 0xFB.
w25qxx: sdfp[184-191] is 0x72 0xAA 0xB0 0x79 0x6B 0xE4 0xEF 0x25.
w25qxx: sdfp[192-199] is 0x5A 0x14 0x03 0xDD 0xDD 0xA3 0x31 0x08.
w25qxx: sdfp[200-207] is 0x71 0x1A 0xCE 0xF6 0x29 0xBA 0x74 0x09.
w25qxx: sdfp[208-215] is 0x64 0xFC 0xA6 0x33 0x0C 0xFD 0x2E 0x7E.
w25qxx: sdfp[216-223] is 0xA7 0xDE 0xF8 0x12 0xC3 0xE7 0x38 0x1D.
w25qxx: sdfp[224-231] is 0xFC 0x3B 0xFB 0xD9 0xDE 0x2C 0xE2 0x4F.
w25qxx: sdfp[232-239] is 0x47 0xB0 0x45 0x70 0x6A 0xBA 0x79 0xCF.
w25qxx: sdfp[240-247] is 0xB6 0x20 0x02 0xC2 0x1D 0x30 0x40 0xC5.
w25qxx: sdfp[248-255] is 0x0E 0x38 0xD7 0xD1 0x20 0x0F 0xEF 0x1C.
```

```shell
./w25qxx -e advance-spi-page-program-quad-input --type=W25Q128 --addr=0x000000 --data=0x08 --interface=spi

w25qxx: this chip can't use this function.
```

```shell
./w25qxx -e advance-spi-write-security --type=W25Q128 --num=1 --data=0x08 --interface=spi

w25qxx: write 4096 security register successful.
```

```shell
./w25qxx -e advance-qspi-set-read-parameters --type=W25Q128 --dummy=DUMMY_8_80MHZ --length=8 --interface=spi

w25qxx: this chip can't use this function.
```

```shell
./w25qxx -e advance-spi-set-burst --type=W25Q128 --wrap=WRAP_8_BYTE --interface=spi

w25qxx: set burst with wrap successful.
```

```shell
./w25qxx -h

Usage:
  w25qxx (-i | --information)
  w25qxx (-h | --help)
  w25qxx (-p | --port)
  w25qxx (-t reg | --test=reg) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-t read | --test=read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e power-down | --example=power-down) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e wake-up | --example=wake-up) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e chip-erase | --example=chip-erase) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e get-id | --example=get-id) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e read | --example=read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address>
  w25qxx (-e write | --example=write) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address> --data=<hex>
  w25qxx (-e advance-power-down | --example=advance-power-down) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-wake-up | --example=advance-wake-up) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-chip-erase | --example=advance-chip-erase) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-get-id | --example=advance-get-id) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-read | --example=advance-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address>
  w25qxx (-e advance-write | --example=advance-write) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address> --data=<hex>
  w25qxx (-e advance-page-program | --example=advance-page-program) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address> --data=<hex>
  w25qxx (-e advance-erase-4k | --example=advance-erase-4k) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address>
  w25qxx (-e advance-erase-32k | --example=advance-erase-32k) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address>
  w25qxx (-e advance-erase-64k | --example=advance-erase-64k) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address>
  w25qxx (-e advance-fast-read | --example=advance-fast-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address>
  w25qxx (-e advance-get-status1 | --example=advance-get-status1) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-get-status2 | --example=advance-get-status2) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-get-status3 | --example=advance-get-status3) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-set-status1 | --example=advance-set-status1) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --status=<hex>
  w25qxx (-e advance-set-status2 | --example=advance-set-status2) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --status=<hex>
  w25qxx (-e advance-set-status3 | --example=advance-set-status3) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --status=<hex>
  w25qxx (-e advance-get-jedec-id | --example=advance-get-jedec-id) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-global-lock | --example=advance-global-lock) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-global-unlock | --example=advance-global-unlock) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-block-lock | --example=advance-block-lock) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address>
  w25qxx (-e advance-block-unlock | --example=advance-block-unlock) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address>
  w25qxx (-e advance-read-block | --example=advance-read-block) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
         --addr=<address>
  w25qxx (-e advance-reset | --example=advance-reset) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] [--interface=<spi | qspi>]
  w25qxx (-e advance-spi-read | --example=advance-spi-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>] --addr=<address>
  w25qxx (-e advance-spi-dual-output-read | --example=advance-spi-dual-output-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --addr=<address>
  w25qxx (-e advance-spi-quad-output-read | --example=advance-spi-quad-output-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --addr=<address>
  w25qxx (-e advance-spi-dual-io-read | --example=advance-spi-dual-io-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --addr=<address>
  w25qxx (-e advance-spi-quad-io-read | --example=advance-spi-quad-io-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --addr=<address>
  w25qxx (-e advance-spi-word-quad-io-read | --example=advance-spi-word-quad-io-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --addr=<address>
  w25qxx (-e advance-spi-octal-word-quad-io-read | --example=advance-spi-octal-word-quad-io-read) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --addr=<address>
  w25qxx (-e advance-spi-page-program-quad-input | --example=advance-spi-page-program-quad-input) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --addr=<address> --data=<hex>
  w25qxx (-e advance-spi-get-id-dual-io | --example=advance-spi-get-id-dual-io) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
  w25qxx (-e advance-spi-get-id-quad-io | --example=advance-spi-get-id-quad-io) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
  w25qxx (-e advance-spi-get-sfdp | --example=advance-spi-get-sfdp) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
  w25qxx (-e advance-spi-write-security | --example=advance-spi-write-security) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --num=<1 | 2 | 3> --data=<hex>
  w25qxx (-e advance-spi-read-security | --example=advance-spi-read-security) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --num=<1 | 2 | 3>
  w25qxx (-e advance-qspi-set-read-parameters | --example=advance-qspi-set-read-parameters) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --dummy=<DUMMY_2_33MHZ | DUMMY_4_55MHZ | DUMMY_6_80MHZ | DUMMY_8_80MHZ> --length=<8 | 16 | 32 | 64>
  w25qxx (-e advance-spi-set-burst | --example=advance-spi-set-burst) [--type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>]
         --wrap=<WRAP_NONE | WRAP_8_BYTE | WRAP_16_BYTE | WRAP_32_BYTE | WRAP_64_BYTE>

Options:
      --addr=<address>               Set the operator address and it is hexadecimal.([default: 0x00000000])
      --data=<hex>                   Set the input data and it is hexadecimal.([default: 0x00000000])
      --dummy=<DUMMY_2_33MHZ | DUMMY_4_55MHZ | DUMMY_6_80MHZ | DUMMY_8_80MHZ>
                                     Set the dummy.([default: DUMMY_8_80MHZ])
  -e <power-down | wake-up | chip-erase | get-id | read | write | advance-power-down | advance-wake-up | advance-chip-erase
     | advance-get-id | advance-read | advance-write | advance-page-program | advance-erase-4k | advance-erase-32k | advance-erase-64k
     | advance-fast-read | advance-get-status1 | advance-get-status2 | advance-get-status3 | advance-set-status1 | advance-set-status2
     | advance-set-status3 | advance-get-jedec-id | advance-global-lock | advance-global-unlock | advance-block-lock | advance-block-unlock
     | advance-read-block | advance-reset | advance-spi-read | advance-spi-dual-output-read | advance-spi-quad-output-read
     | advance-spi-dual-io-read | advance-spi-quad-io-read | advance-spi-word-quad-io-read | advance-spi-octal-word-quad-io-read
     | advance-spi-page-program-quad-input | advance-spi-get-id-dual-io | advance-spi-get-id-quad-io | advance-spi-get-sfdp
     | advance-spi-write-security | advance-spi-read-security | advance-qspi-set-read-parameters | advance-spi-set-burst>, --example=<power-down
     | wake-up | chip-erase | get-id | read | write | advance-power-down | advance-wake-up | advance-chip-erase
     | advance-get-id | advance-read | advance-write | advance-page-program | advance-erase-4k | advance-erase-32k | advance-erase-64k
     | advance-fast-read | advance-get-status1 | advance-get-status2 | advance-get-status3 | advance-set-status1 | advance-set-status2
     | advance-set-status3 | advance-get-jedec-id | advance-global-lock | advance-global-unlock | advance-block-lock | advance-block-unlock
     | advance-read-block | advance-reset | advance-spi-read | advance-spi-dual-output-read | advance-spi-quad-output-read
     | advance-spi-dual-io-read | advance-spi-quad-io-read | advance-spi-word-quad-io-read | advance-spi-octal-word-quad-io-read
     | advance-spi-page-program-quad-input | advance-spi-get-id-dual-io | advance-spi-get-id-quad-io | advance-spi-get-sfdp
     | advance-spi-write-security | advance-spi-read-security | advance-qspi-set-read-parameters | advance-spi-set-burst>
                                     Run the driver example.
  -h, --help                         Show the help.
      --length=<8 | 16 | 32 | 64>    Set the dummy length.([default: 8])
  -i, --information                  Show the chip information.
      --interface=<spi | qspi>       Set the chip interface.([default: spi])
      --num=<1 | 2 | 3>              Set the security number.([default: 1])
  -p, --port                         Display the pin connections of the current board.
      --status=<hex>                 Set the status and it is hexadecimal.([default: 0x00])
  -t <reg | read>, --test=<reg | read>
                                     Run the driver test.
      --type=<W25Q80 | W25Q16 | W25Q32 | W25Q64 | W25Q128 | W25Q256>
                                     Set the chip type.([default: W25Q128])
      --wrap=<WRAP_NONE | WRAP_8_BYTE | WRAP_16_BYTE | WRAP_32_BYTE | WRAP_64_BYTE>
                                     Set the wrap.([default: WRAP_8_BYTE])
```

