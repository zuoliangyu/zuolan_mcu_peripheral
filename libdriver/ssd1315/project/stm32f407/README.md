### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

SPI Pin: SCK/MISO/MOSI/CS PA5/PA6/PA7/PA4.

GPIO Pin: command pin/ reset pin PA8/PA0.

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

### 3. SSD1315

#### 3.1 Command Instruction

1. Show ssd1315 chip and driver information.

   ```shell
   ssd1315 (-i | --information)
   ```

2. Show ssd1315 help.

   ```shell
   ssd1315 (-h | --help)
   ```

3. Show ssd1315 pin connections of the current board.

   ```shell
   ssd1315 (-p | --port)
   ```

4. Run ssd1315 display test. 

   ```shell
   ssd1315 (-t display | --test=display) [--addr=<0 | 1>] [--interface=<iic | spi>]
   ```

5. Run ssd1315 init function.

   ```shell
   ssd1315 (-e basic-init | --example=basic-init) [--addr=<0 | 1>] [--interface=<iic | spi>]
   ```

6. Run ssd1315 deinit function.

   ```shell
   ssd1315 (-e basic-deinit | --example=basic-deinit)
   ```

7. Run ssd1315 show string function, string is the shown string. 

   ```shell
   ssd1315 (-e basic-str | --example=basic-str) [--str=<string>]
   ```

8. Run ssd1315 display on function.

   ```shell
   ssd1315 (-e basic-display-on | --example=basic-display-on)
   ```

9. Run ssd1315 display off function.

   ```shell
   ssd1315 (-e basic-display-off | --example=basic-display-off)
   ```

10. Run ssd1315 clear screen function.

    ```shell
    ssd1315 (-e basic-clear | --example=basic-clear)
    ```

11. Run ssd1315 writepoint function, x0 is the x of the point and y0 is the y of the point.

    ```shell
    ssd1315 (-e basic-point | --example=basic-point) --x0=<x0> --y0=<y0> [--color=<0 | 1>]
    ```

12. Run ssd1315 readpoint function, x0 is the x of the point and y0 is the y of the point.

    ```shell
    ssd1315 (-e basic-point | --example=basic-point) --x0=<x0> --y0=<y0>
    ```

13. Run ssd1315 drawing rectangle function, x1 is the top left x of the rect, y1 is the top left y of the rect, x2 is the bottom right x of the rect and y2 is the bottom right y of the rect.

    ```shell
    ssd1315 (-e basic-rect | --example=basic-rect) --x1=<x1> --y1=<y1> --x2=<x2> --y2=<y2> [--color=<0 | 1>]
    ```

14. Run ssd1315 init function. 

    ```shell
    ssd1315 (-e advance-init | --example=advance-init) [--addr=<0 | 1>] [--interface=<iic | spi>]
    ```

15. Run ssd1315 deinit function.

    ```shell
    ssd1315 (-e advance-deinit | --example=advance-deinit)
    ```

16. Run ssd1315 show string function, string is the shown string.

    ```shell
    ssd1315 (-e advance-str | --example=advance-str) [--str=<string>]
    ```

17. Run ssd1315 display on function. 

    ```shell
    ssd1315 (-e advance-display-on | --example=advance-display-on)
    ```

18. Run ssd1315 display off function.

    ```shell
    ssd1315 (-e advance-display-off | --example=advance-display-off)
    ```

19. Run ssd1315 clear screen function. 

    ```shell
    ssd1315 (-e advance-clear | --example=advance-clear)
    ```

20. Run ssd1315 writepoint function, x0 is the x of the point and y0 is the y of the point.

    ```shell
    ssd1315 (-e advance-point | --example=advance-point) --x0=<x0> --y0=<y0> [--color=<0 | 1>]
    ```

21. Run ssd1315 readpoint function, x0 is the x of the point and y0 is the y of the point.

    ```shell
    ssd1315 (-e advance-point | --example=advance-point) --x0=<x0> --y0=<y0>
    ```

22. Run ssd1315 drawing rectangle function, x1 is the top left x of the rect, y1 is the top left y of the rect, x2 is the bottom right x of the rect and y2 is the bottom right y of the rect.

    ```shell
    ssd1315 (-e advance-rect | --example=advance-rect) --x1=<x1> --y1=<y1> --x2=<x2> --y2=<y2> [--color=<0 | 1>]
    ```

23. Run ssd1315 enable zoom function.

    ```shell
    ssd1315 (-e advance-enable-zoom | --example=advance-enable-zoom)
    ```

24. Run ssd1315 disable zoom function.

    ```shell
    ssd1315 (-e advance-disable-zoom | --example=advance-disable-zoom)
    ```

25. Run ssd1315 deactivate scroll function.

    ```shell
    ssd1315 (-e advance-deactivate-scroll | --example=advance-deactivate-scroll)
    ```

26. Run ssd1315 fade blinking function, f means the running frames.  

    ```shell
    ssd1315 (-e advance-fade-blinking | --example=advance-fade-blinking) [--mode=<DISABLE | FADE-OUT | BLINKING>] [--frames=<f>]
    ```

27. Run ssd1315 setting vertical left horizontal scroll function, spage means start page and it can be "0"-"7", epage means end page and it can be "0"-"7", r means display rows and it can be "0" - "63".

    ```shell
    ssd1315 (-e advance-left-scroll | --example=advance-left-scroll) [--start=<spage>] [--stop=<epage>] [--row=<r>] [--frame=<FRAME_2 | FRAME_3 | FRAME_4 | FRAME_5 | FRAME_6 | FRAME_32 | FRAME_64 | FRAME_128>]
    ```

28. Run ssd1315 setting vertical right horizontal scroll function, spage means start page and it can be "0"-"7", epage means end page and it can be "0"-"7", r means display rows and it can be "0" - "63".

    ```shell
    ssd1315 (-e advance-right-scroll | --example=advance-right-scroll) [--start=<spage>] [--stop=<epage>] [--row=<r>] [--frame=<FRAME_2 | FRAME_3 | FRAME_4 | FRAME_5 | FRAME_6 | FRAME_32 | FRAME_64 | FRAME_128>]
    ```

#### 3.2 Command Example

```shell
ssd1315 -i

ssd1315: chip is Solomon Systech SSD1315.
ssd1315: manufacturer is Solomon Systech.
ssd1315: interface is IIC SPI.
ssd1315: driver version is 1.0.
ssd1315: min supply voltage is 1.6V.
ssd1315: max supply voltage is 3.5V.
ssd1315: max current is 1.00mA.
ssd1315: max temperature is 85.0C.
ssd1315: min temperature is -40.0C.
```

```shell
ssd1315 -p

ssd1315: SPI interface SCK connected to GPIOA PIN5.
ssd1315: SPI interface MISO connected to GPIOA PIN6.
ssd1315: SPI interface MOSI connected to GPIOA PIN7.
ssd1315: SPI interface CS connected to GPIOA PIN4.
ssd1315: SPI interface cmd data gpio GPIO connected to GPIOA PIN8.
ssd1315: SPI interface reset GPIO connected to GPIOA PIN0.
ssd1315: IIC interface SCL connected to GPIOB PIN8.
ssd1315: IIC interface SDA connected to GPIOB PIN9.
ssd1315: IIC interface reset GPIO connected to GPIOA PIN0.
```

```shell
ssd1315 -t display --addr=0 --interface=iic

ssd1315: chip is Solomon Systech SSD1315.
ssd1315: manufacturer is Solomon Systech.
ssd1315: interface is IIC SPI.
ssd1315: driver version is 1.0.
ssd1315: min supply voltage is 1.6V.
ssd1315: max supply voltage is 3.5V.
ssd1315: max current is 1.00mA.
ssd1315: max temperature is 85.0C.
ssd1315: min temperature is -40.0C.
ssd1315: start display test.
ssd1315: font 12 test.
ssd1315: font 16 test.
ssd1315: font 24 test.
ssd1315: rectangle test.
ssd1315: rand point test.
ssd1315: picture test.
ssd1315: graphic acceleration test.
ssd1315: right horizontal scroll.
ssd1315: left horizontal scroll.
ssd1315: vertical right horizontal scroll.
ssd1315: vertical left horizontal scroll.
ssd1315: advance graphic test.
ssd1315: zoom in.
ssd1315: fade mode.
ssd1315: right horizontal scroll one column.
ssd1315: left horizontal scroll one column.
ssd1315: finish display test.
```

```shell
ssd1315 -e basic-str --str=12345abcdEFGH!@#$<>?{}[];<>

ssd1315: 12345abcdEFGH!@#$<>?{}[];<>.
```

```shell
ssd1315 -e basic-init --addr=0 --interface=iic

ssd1315: init success.
```

```shell
ssd1315 -e basic-display-off

ssd1315: display off.
```

```shell
ssd1315 -e basic-display-on

ssd1315: display on.
```

```shell
ssd1315 -e basic-clear

ssd1315: clear screen.
```

```shell
ssd1315 -e basic-deinit

ssd1315: deinit ssd1315.
```

```shell
ssd1315 -e basic-point --x0=16 --y0=16 --color=1

ssd1315: write point 16 16 1.
```

```shell
ssd1315 -e basic-point --x0=16 --y0=16

ssd1315: read point 16 16 is 1.
```

```shell
ssd1315 -e basic-rect --x1=0 --y1=0 --x2=32 --y2=32 --color=1

ssd1315: draw rect 0 0 32 32.
```

```shell
ssd1315 -e advance-init --addr=0 --interface=iic

ssd1315: init success.
```

```shell
ssd1315 -e advance-str --str=12345abcdEFGH!@#$<>?{}[];<>

ssd1315: 12345abcdEFGH!@#$<>?{}[];<>.
```

```shell
ssd1315 -e advance-display-off

ssd1315: display off.
```

```shell
ssd1315 -e advance-display-on

ssd1315: display on.
```

```shell
ssd1315 -e advance-clear

ssd1315: clear screen.
```

```shell
ssd1315 -e advance-point --x0=16 --y0=16 --color=1

ssd1315: write point 16 16 1.
```

```shell
ssd1315 -e advance-point --x0=16 --y0=16

ssd1315: read point 16 16 is 1.
```

```shell
ssd1315 -e advance-rect --x1=0 --y1=0 --x2=32 --y2=32 --color=1

ssd1315: draw rect 0 0 32 32.
```

```shell
ssd1315 -e advance-deinit

ssd1315: deinit ssd1315.
```

```shell
ssd1315 -e advance-enable-zoom

ssd1315: enable zoom in.
```

```shell
ssd1315 -e advance-disable-zoom

ssd1315: disable zoom in.
```

```shell
ssd1315 -e advance-fade-blinking --mode=BLINKING --frames=0

ssd1315: set fade blinking blinking mode with 0 frames.
```

```shell
ssd1315 -e advance-deactivate-scroll

ssd1315: deactivate scroll.
```

```shell
ssd1315 -e advance-left-scroll --start=0 --stop=7 --row=0 --frame=FRAME_2

ssd1315: vertical left horizontal scroll start stop rows frames 0 7 0.
```

```shell
ssd1315 -e advance-right-scroll --start=0 --stop=7 --row=0 --frame=FRAME_2

ssd1315: vertical right horizontal scroll start stop rows frames 0 7 0.
```

```shell
ssd1315 -h

Usage:
  ssd1315 (-i | --information)
  ssd1315 (-h | --help)
  ssd1315 (-p | --port)
  ssd1315 (-t display | --test=display) [--addr=<0 | 1>] [--interface=<iic | spi>]
  ssd1315 (-e basic-init | --example=basic-init) [--addr=<0 | 1>] [--interface=<iic | spi>]
  ssd1315 (-e basic-deinit | --example=basic-deinit)
  ssd1315 (-e basic-str | --example=basic-str) [--str=<string>]
  ssd1315 (-e basic-display-on | --example=basic-display-on)
  ssd1315 (-e basic-display-off | --example=basic-display-off)
  ssd1315 (-e basic-clear | --example=basic-clear)
  ssd1315 (-e basic-point | --example=basic-point) --x0=<x0> --y0=<y0> [--color=<0 | 1>]
  ssd1315 (-e basic-rect | --example=basic-rect) --x1=<x1> --y1=<y1> --x2=<x2> --y2=<y2> [--color=<0 | 1>]
  ssd1315 (-e advance-init | --example=advance-init) [--addr=<0 | 1>] [--interface=<iic | spi>]
  ssd1315 (-e advance-deinit | --example=advance-deinit)
  ssd1315 (-e advance-str | --example=advance-str) [--str=<string>]
  ssd1315 (-e advance-display-on | --example=advance-display-on)
  ssd1315 (-e advance-display-off | --example=advance-display-off)
  ssd1315 (-e advance-clear | --example=advance-clear)
  ssd1315 (-e advance-point | --example=advance-point) --x0=<x0> --y0=<y0> [--color=<0 | 1>]
  ssd1315 (-e advance-rect | --example=advance-rect) --x1=<x1> --y1=<y1> --x2=<x2> --y2=<y2> [--color=<0 | 1>]
  ssd1315 (-e advance-enable-zoom | --example=advance-enable-zoom)
  ssd1315 (-e advance-disable-zoom | --example=advance-disable-zoom)
  ssd1315 (-e advance-deactivate-scroll | --example=advance-deactivate-scroll)
  ssd1315 (-e advance-fade-blinking | --example=advance-fade-blinking) [--mode=<DISABLE | FADE-OUT | BLINKING>]
          [--frames=<f>]
  ssd1315 (-e advance-left-scroll | --example=advance-left-scroll) [--start=<spage>] [--stop=<epage>] [--row=<r>]
          [--frame=<FRAME_2 | FRAME_3 | FRAME_4 | FRAME_5 | FRAME_6 | FRAME_32 | FRAME_64 | FRAME_128>]
  ssd1315 (-e advance-right-scroll | --example=advance-right-scroll) [--start=<spage>] [--stop=<epage>] [--row=<r>]
          [--frame=<FRAME_2 | FRAME_3 | FRAME_4 | FRAME_5 | FRAME_6 | FRAME_32 | FRAME_64 | FRAME_128>]

Options:
      --addr=<0 | 1>      Set the iic addr pin.([default: 0])
      --color=<0 | 1>     Set the chip color.([default: 1])
  -e <basic-init | basic-deinit | basic-str | basic-display-on | basic-display-off | basic-clear 
     | basic-point | basic-rect>, --example=<advance-init | advance-deinit | advance-str | advance-display-on
     | advance-display-off | advance-clear | advance-point | advance-rect | advance-enable-zoom | advance-disable-zoom
     | advance-fade-blinking | advance-left-scroll | advance-right-scroll | advance-deactivate-scroll>
                          Run the driver example.
      --frame=<FRAME_2 | FRAME_3 | FRAME_4 | FRAME_5 | FRAME_6 | FRAME_32 | FRAME_64 | FRAME_128>
                          Set the scrolling frame.([default: FRAME_2])
      --frames=<f>        Se the fade-blinking frames.([default: 0])
  -h, --help              Show the help.
  -i, --information       Show the chip information.
      --interface=<iic | spi>
                          Set the chip interface.([default: iic])
      --mode=<DISABLE | FADE-OUT | BLINKING>
                          Set the fade-blinking mode.([default: DISABLE])
  -p, --port              Display the pin connections of the current board.
      --row=<r>           Set the scrolling row.([default: 0])
      --start=<spage>     Set the scrolling start page.([default: 0])
      --stop=<epage>      Set the scrolling stop page.([default: 7])
      --str=<string>      Set the display string.([default: libdriver])
  -t <display>, --test=<display>
                          Run the driver test.
      --x0=<x0>           Set the x0 and it is the x of the point.
      --x1=<x1>           Set the x1 and it is the top left x of the rect.
      --x2=<x2>           Set the x2 and it is the bottom right x of the rect.
      --y0=<y0>           Set the y0 and it is the y of the point.
      --y1=<y1>           Set the y1 and it is the top left y of the rect.
      --y2=<y2>           Set the y2 and it is the bottom right y of the rect.
```

