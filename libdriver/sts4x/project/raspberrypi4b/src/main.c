/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      main.c
 * @brief     main source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2024-09-30
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2024/09/30  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_sts4x_read_test.h"
#include "driver_sts4x_basic.h"
#include <getopt.h>
#include <stdlib.h>

/**
 * @brief     sts4x full function
 * @param[in] argc is arg numbers
 * @param[in] **argv is the arg address
 * @return    status code
 *            - 0 success
 *            - 1 run failed
 *            - 5 param is invalid
 * @note      none
 */
uint8_t sts4x(uint8_t argc, char **argv)
{
    int c;
    int longindex = 0;
    const char short_options[] = "hipe:t:";
    const struct option long_options[] =
    {
        {"help", no_argument, NULL, 'h'},
        {"information", no_argument, NULL, 'i'},
        {"port", no_argument, NULL, 'p'},
        {"example", required_argument, NULL, 'e'},
        {"test", required_argument, NULL, 't'},
        {"addr", required_argument, NULL, 1},
        {"times", required_argument, NULL, 2},
        {NULL, 0, NULL, 0},
    };
    char type[33] = "unknown";
    uint32_t times = 3;
    sts4x_address_t addr = STS4X_ADDRESS_0;
    
    /* if no params */
    if (argc == 1)
    {
        /* goto the help */
        goto help;
    }
    
    /* init 0 */
    optind = 0;
    
    /* parse */
    do
    {
        /* parse the args */
        c = getopt_long(argc, argv, short_options, long_options, &longindex);
        
        /* judge the result */
        switch (c)
        {
            /* help */
            case 'h' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "h");
                
                break;
            }
            
            /* information */
            case 'i' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "i");
                
                break;
            }
            
            /* port */
            case 'p' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "p");
                
                break;
            }
            
            /* example */
            case 'e' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "e_%s", optarg);
                
                break;
            }
            
            /* test */
            case 't' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "t_%s", optarg);
                
                break;
            }
            
            /* addr */
            case 1 :
            {
                /* set the addr pin */
                if (strcmp("0", optarg) == 0)
                {
                    addr = STS4X_ADDRESS_0;
                }
                else if (strcmp("1", optarg) == 0)
                {
                    addr = STS4X_ADDRESS_1;
                }
                else if (strcmp("2", optarg) == 0)
                {
                    addr = STS4X_ADDRESS_2;
                }
                else
                {
                    return 5;
                }
                
                break;
            }
            
            /* running times */
            case 2 :
            {
                /* set the times */
                times = atol(optarg);
                
                break;
            } 
            
            /* the end */
            case -1 :
            {
                break;
            }
            
            /* others */
            default :
            {
                return 5;
            }
        }
    } while (c != -1);

    /* run functions */
    if (strcmp("t_read", type) == 0)
    {
        /* run read test */
        if (sts4x_read_test(addr, times) != 0)
        {
            return 1;
        }
        
        return 0;
    }
    else if (strcmp("e_read", type) == 0)
    {
        uint8_t res;
        uint32_t i;
        float temperature;
        
        /* basic init */
        res = sts4x_basic_init(addr);
        if (res != 0)
        {
            return 1;
        }
        
        /* loop */
        for (i = 0; i < times; i++)
        {
            /* delay 1000ms */
            sts4x_interface_delay_ms(1000);
            
            /* read data */
            res = sts4x_basic_read((float *)&temperature);
            if (res != 0)
            {
                (void)sts4x_basic_deinit();
                
                return 1;
            }
            
            /* output */
            sts4x_interface_debug_print("sts4x: %d/%d.\n", (uint32_t)(i + 1), (uint32_t)times);
            sts4x_interface_debug_print("sts4x: temperature is %0.2fC.\n", temperature);
        }
        
        /* basic deinit */
        (void)sts4x_basic_deinit();
        
        return 0;
    }
    else if (strcmp("e_number", type) == 0)
    {
        uint8_t res;
        uint8_t num[4];
        
        /* basic init */
        res = sts4x_basic_init(addr);
        if (res != 0)
        {
            return 1;
        }
        
        /* get serial number */
        res = sts4x_basic_get_serial_number(num);
        if (res != 0)
        {
            (void)sts4x_basic_deinit();
            
            return 1;
        }
        
        /* output */
        sts4x_interface_debug_print("sts4x: serial number is 0x%02X 0x%02X 0x%02X 0x%02X.\n", num[0], num[1], num[2], num[3]);
        
        /* basic deinit */
        (void)sts4x_basic_deinit();
        
        return 0;
    }
    else if (strcmp("h", type) == 0)
    {
        help:
        sts4x_interface_debug_print("Usage:\n");
        sts4x_interface_debug_print("  sts4x (-i | --information)\n");
        sts4x_interface_debug_print("  sts4x (-h | --help)\n");
        sts4x_interface_debug_print("  sts4x (-p | --port)\n");
        sts4x_interface_debug_print("  sts4x (-t read | --test=read) [--addr=<0 | 1 | 2>] [--times=<num>]\n");
        sts4x_interface_debug_print("  sts4x (-e read | --example=read) [--addr=<0 | 1 | 2>] [--times=<num>]\n");
        sts4x_interface_debug_print("  sts4x (-e number | --example=number) [--addr=<0 | 1 | 2>]\n");
        sts4x_interface_debug_print("\n");
        sts4x_interface_debug_print("Options:\n");
        sts4x_interface_debug_print("      --addr=<0 | 1 | 2>\n");
        sts4x_interface_debug_print("                        Set the addr.([default: 0])\n");
        sts4x_interface_debug_print("  -e <read | number>, --example=<read | number>\n");
        sts4x_interface_debug_print("                        Run the driver example.\n");
        sts4x_interface_debug_print("  -h, --help            Show the help.\n");
        sts4x_interface_debug_print("  -i, --information     Show the chip information.\n");
        sts4x_interface_debug_print("  -p, --port            Display the pin connections of the current board.\n");
        sts4x_interface_debug_print("  -t <read>, --test=<read>\n");
        sts4x_interface_debug_print("                        Run the driver test.\n");
        sts4x_interface_debug_print("      --times=<num>     Set the running times.([default: 3])\n");
        
        return 0;
    }
    else if (strcmp("i", type) == 0)
    {
        sts4x_info_t info;
        
        /* print sts4x info */
        sts4x_info(&info);
        sts4x_interface_debug_print("sts4x: chip is %s.\n", info.chip_name);
        sts4x_interface_debug_print("sts4x: manufacturer is %s.\n", info.manufacturer_name);
        sts4x_interface_debug_print("sts4x: interface is %s.\n", info.interface);
        sts4x_interface_debug_print("sts4x: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        sts4x_interface_debug_print("sts4x: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        sts4x_interface_debug_print("sts4x: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        sts4x_interface_debug_print("sts4x: max current is %0.2fmA.\n", info.max_current_ma);
        sts4x_interface_debug_print("sts4x: max temperature is %0.1fC.\n", info.temperature_max);
        sts4x_interface_debug_print("sts4x: min temperature is %0.1fC.\n", info.temperature_min);
        
        return 0;
    }
    else if (strcmp("p", type) == 0)
    {
        /* print pin connection */
        sts4x_interface_debug_print("sts4x: SCL connected to GPIO3(BCM).\n");
        sts4x_interface_debug_print("sts4x: SDA connected to GPIO2(BCM).\n");
        
        return 0;
    }
    else
    {
        return 5;
    }
}

/**
 * @brief     main function
 * @param[in] argc is arg numbers
 * @param[in] **argv is the arg address
 * @return    status code
 *             - 0 success
 * @note      none
 */
int main(uint8_t argc, char **argv)
{
    uint8_t res;

    res = sts4x(argc, argv);
    if (res == 0)
    {
        /* run success */
    }
    else if (res == 1)
    {
        sts4x_interface_debug_print("sts4x: run failed.\n");
    }
    else if (res == 5)
    {
        sts4x_interface_debug_print("sts4x: param is invalid.\n");
    }
    else
    {
        sts4x_interface_debug_print("sts4x: unknown status code.\n");
    }

    return 0;
}
