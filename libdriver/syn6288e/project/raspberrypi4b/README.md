### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

UART Pin: TX/RX GPIO14/GPIO15.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```
#### 2.2 Configuration

Enable serial port.

Disable serial console.

#### 2.3 Makefile

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

#### 2.4 CMake

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
find_package(syn6288e REQUIRED)
```

#### 2.5 Command Problem

Each command will sent a sleep command to the chip, but raspberry can't run wake up command, so you should power down and power on SYN6288E every time before your any new command.

### 3. SYN6288E

#### 3.1 Command Instruction

1. Show syn6288e chip and driver information.

   ```shell
   syn6288e (-i | --information)
   ```

2. Show syn6288e help.

   ```shell
   syn6288e (-h | --help)
   ```

3. Show syn6288e pin connections of the current board.

   ```shell
   syn6288e (-p | --port)
   ```

4. Run syn6288e register test.

   ```shell
   syn6288e (-t reg | --test=reg)
   ```

5. Run syn6288e synthesis test.

   ```shell
   syn6288e (-t syn | --test=syn)
   ```

6. Run syn6288e synthesis text function, gb2312 format is gb2312.

   ```shell
   syn6288e (-e syn | --example=syn) --text=<gb2312>
   ```

7. Run syn6288e advance synthesis text function, gb2312 format is gb2312.

   ```shell
   syn6288e (-e advance-syn | --example=advance-syn) --text=<gb2312>
   ```

8. Run syn6288e advance synthesis sound function, type can be "A" - "Y".

   ```shell
   syn6288e (-e advance-sound | --example=advance-sound) --sound=<type>
   ```

9. Run syn6288e advance synthesis message function, type can be "A" - "H".

   ```shell
   syn6288e (-e advance-msg | --example=advance-msg) --msg=<type>
   ```

10. Run syn6288e advance synthesis ring function, type can be "A" - "O".

    ```shell
    syn6288e (-e advance-ring | --example=advance-ring) --ring=<type>
    ```

#### 3.2 Command Example

```shell
./syn6288e -i

syn6288e: chip is YuToneWorld SYN6288E.
syn6288e: manufacturer is YuToneWorld.
syn6288e: interface is UART.
syn6288e: driver version is 1.0.
syn6288e: min supply voltage is 2.4V.
syn6288e: max supply voltage is 5.1V.
syn6288e: max current is 280.00mA.
syn6288e: max temperature is 85.0C.
syn6288e: min temperature is -35.0C.
```

```shell
./syn6288e -p

syn6288e: TX connected to GPIO15(BCM).
syn6288e: RX connected to GPIO14(BCM).
```

```shell
./syn6288e -t reg

syn6288e: chip is YuToneWorld SYN6288E.
syn6288e: manufacturer is YuToneWorld.
syn6288e: interface is UART.
syn6288e: driver version is 1.0.
syn6288e: min supply voltage is 2.4V.
syn6288e: max supply voltage is 5.1V.
syn6288e: max current is 280.00mA.
syn6288e: max temperature is 85.0C.
syn6288e: min temperature is -35.0C.
syn6288e: start register test.
syn6288e: syn6288e_set_baud_rate/syn6288e_get_baud_rate test.
syn6288e: set 9600 bps.
syn6288e: check baud rate ok.
syn6288e: syn6288e_set_mode/syn6288e_get_mode test.
syn6288e: set background_15 mode.
syn6288e: check mode ok.
syn6288e: syn6288e_set_text_type/syn6288e_get_text_type test.
syn6288e: set gb2312 text type.
syn6288e: check text type ok.
syn6288e: set gbk text type.
syn6288e: check text type ok.
syn6288e: set big5 text type.
syn6288e: check text type ok.
syn6288e: set unicode text type.
syn6288e: check text type ok.
syn6288e: syn6288e_set_synthesis_volume/syn6288e_get_synthesis_volume test.
syn6288e: set synthesis volume 6.
syn6288e: check synthesis volume ok.
syn6288e: syn6288e_set_background_volume/syn6288e_get_background_volume test.
syn6288e: set background volume 8.
syn6288e: check background volume ok.
syn6288e: syn6288e_set_synthesis_speed/syn6288e_get_synthesis_speed test.
syn6288e: set synthesis speed 3.
syn6288e: check synthesis speed ok.
syn6288e: syn6288e_set_command test.
syn6288e: check command ok.
syn6288e: finish register test.
```

```shell
./syn6288e -t syn

syn6288e: chip is YuToneWorld SYN6288E.
syn6288e: manufacturer is YuToneWorld.
syn6288e: interface is UART.
syn6288e: driver version is 1.0.
syn6288e: min supply voltage is 2.4V.
syn6288e: max supply voltage is 5.1V.
syn6288e: max current is 280.00mA.
syn6288e: max temperature is 85.0C.
syn6288e: min temperature is -35.0C.
syn6288e: start synthesis test.
syn6288e: synthesis text test.
syn6288e: gb2312 synthesis text.
syn6288e: gbk synthesis text.
syn6288e: big5 synthesis text.
syn6288e: unicode synthesis text.
syn6288e: synthesis sound test.
syn6288e: synthesis message test.
syn6288e: synthesis ring test.
syn6288e: synthesis control test.
syn6288e: synthesis control pause.
syn6288e: synthesis control resume.
syn6288e: synthesis control stop.
syn6288e: synthesis volume test.
syn6288e: set synthesis volume 5.
syn6288e: synthesis speed test.
syn6288e: set synthesis speed 0.
syn6288e: synthesis mode test.
syn6288e: background mode on.
syn6288e: command test.
syn6288e: set command 0.
syn6288e: set command 1.
syn6288e: finish synthesis test.
```

```shell
./syn6288e -e syn --text=Hello

syn6288e: synthesis Hello.
```

```shell
./syn6288e -e advance-syn --text=Hello

syn6288e: synthesis Hello.
```

```shell
./syn6288e -e advance-sound --sound=A

syn6288e: synthesis sound a.
```

```shell
./syn6288e -e advance-msg --msg=A

syn6288e: synthesis message a.
```

```shell
./syn6288e -e advance-ring --ring=A

syn6288e: synthesis ring a.
```

```shell
./syn6288e -h

Usage:
  syn6288e (-i | --information)
  syn6288e (-h | --help)
  syn6288e (-p | --port)
  syn6288e (-t reg | --test=reg)
  syn6288e (-t syn | --test=syn)
  syn6288e (-e syn | --example=syn) --text=<gb2312>
  syn6288e (-e advance-syn | --example=advance-syn) --text=<gb2312>
  syn6288e (-e advance-sound | --example=advance-sound) --sound=<type>
  syn6288e (-e advance-msg | --example=advance-msg) --msg=<type>
  syn6288e (-e advance-ring | --example=advance-ring) --ring=<type>

Options:
  -e <syn | advance-syn | advance-sound | advance-msg | advance-ring>, --example=<syn
     | advance-syn | advance-sound | advance-msg | advance-ring>
                          Run the driver example.
  -h, --help              Show the help.
  -i, --information       Show the chip information.
      --msg=<type>        Set the synthesis message and type can be "A" - "H".
  -p, --port              Display the pin connections of the current board.
      --ring=<type>       Set the synthesis ring and type can be "A" - "O".
      --sound=<type>      Set the synthesis sound and type can be "A" - "Y".
  -t <reg | syn>, --test=<reg | syn>
                          Run the driver test.
      --text=<gb2312>     Set the synthesis text and it's format is GB2312.
```

