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
 * @file      driver_ds1307_output.c
 * @brief     driver ds1307 output source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2023-05-31
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2023/05/31  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_ds1307_output.h"

static ds1307_handle_t gs_handle;        /**< ds1307 handle */
static int8_t gs_time_zone = 0;          /**< local zone */

/**
 * @brief  output example init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t ds1307_output_init(void)
{
    uint8_t res;

    /* link functions */
    DRIVER_DS1307_LINK_INIT(&gs_handle, ds1307_handle_t);
    DRIVER_DS1307_LINK_IIC_INIT(&gs_handle, ds1307_interface_iic_init);
    DRIVER_DS1307_LINK_IIC_DEINIT(&gs_handle, ds1307_interface_iic_deinit);
    DRIVER_DS1307_LINK_IIC_READ(&gs_handle, ds1307_interface_iic_read);
    DRIVER_DS1307_LINK_IIC_WRITE(&gs_handle, ds1307_interface_iic_write);
    DRIVER_DS1307_LINK_DELAY_MS(&gs_handle, ds1307_interface_delay_ms);
    DRIVER_DS1307_LINK_DEBUG_PRINT(&gs_handle, ds1307_interface_debug_print);

    /* init ds1307 */
    res = ds1307_init(&gs_handle);
    if (res != 0)
    {
        ds1307_interface_debug_print("ds1307: init failed.\n");

        return 1;
    }

    /* set oscillator */
    res = ds1307_set_oscillator(&gs_handle, DS1307_BOOL_TRUE);
    if (res != 0)
    {
        ds1307_interface_debug_print("ds1307: set oscillator failed.\n");
        (void)ds1307_deinit(&gs_handle);

        return 1;
    }

    /* set output mode */
    res = ds1307_set_output_mode(&gs_handle, DS1307_OUTPUT_MODE_LEVEL);
    if (res != 0)
    {
        ds1307_interface_debug_print("ds1307: set output mode failed.\n");
        (void)ds1307_deinit(&gs_handle);

        return 1;
    }

    return 0;
}

/**
 * @brief  output example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t ds1307_output_deinit(void)
{
    if (ds1307_deinit(&gs_handle) != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief     output example set the time
 * @param[in] *t points to a time structure
 * @return    status code
 *            - 0 success
 *            - 1 set time failed
 * @note      none
 */
uint8_t ds1307_output_set_time(ds1307_time_t *t)
{
    /* set time */
    if (ds1307_set_time(&gs_handle, t) != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief     output example set the time by a unix timestamp
 * @param[in] timestamp is a unix timestamp
 * @return    status code
 *            - 0 success
 *            - 1 set timestamp failed
 * @note      none
 */
uint8_t ds1307_output_set_timestamp(time_t timestamp)
{
    ds1307_time_t t;
    struct tm *timeptr;

    /* convert times */
    timestamp += (time_t)(gs_time_zone * 3600);
    timeptr = localtime(&timestamp);
    t.am_pm = DS1307_AM;
    t.date = (uint8_t)timeptr->tm_mday;
    t.format = DS1307_FORMAT_24H;
    t.hour = (uint8_t)timeptr->tm_hour;
    t.minute = (uint8_t)timeptr->tm_min;
    t.month = (uint8_t)timeptr->tm_mon + 1;
    t.second = (uint8_t)timeptr->tm_sec;
    if (timeptr->tm_wday == 0)
    {
        t.week  = 7;
    }
    else
    {
        t.week = (uint8_t)timeptr->tm_wday;
    }
    t.year = (uint16_t)(timeptr->tm_year + 1900);

    /* set time */
    if (ds1307_set_time(&gs_handle, &t) != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief     output example set the local time zone
 * @param[in] zone is the local time zone
 * @return    status code
 *            - 0 success
 * @note      none
 */
uint8_t ds1307_output_set_timestamp_time_zone(int8_t zone)
{
    gs_time_zone = zone;

    return 0;
}

/**
 * @brief      output example get the time
 * @param[out] *t points to a time structure
 * @return     status code
 *             - 0 success
 *             - 1 get time failed
 * @note       none
 */
uint8_t ds1307_output_get_time(ds1307_time_t *t)
{
    /* get time */
    if (ds1307_get_time(&gs_handle, t) != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief      output example get the time in a unix timestamp
 * @param[out] *timestamp points to a unix timestamp buffer
 * @return     status code
 *             - 0 success
 *             - 1 get timestamp failed
 * @note       none
 */
uint8_t ds1307_output_get_timestamp(time_t *timestamp)
{
    ds1307_time_t t;
    struct tm timeptr;

    /* get time */
    if (ds1307_get_time(&gs_handle, &t) != 0)
    {
        return 1;
    }
    timeptr.tm_year = t.year - 1900;
    timeptr.tm_mon = t.month - 1;
    timeptr.tm_wday = t.week;
    timeptr.tm_mday = t.date;
    if (t.format == DS1307_FORMAT_24H)
    {
        timeptr.tm_hour = t.hour;
    }
    else
    {
        timeptr.tm_hour = t.hour % 12 + t.am_pm * 12;
    }
    timeptr.tm_min = t.minute;
    timeptr.tm_sec = t.second;

    /* make time */
    *timestamp = mktime(&timeptr) - gs_time_zone * 3600;

    return 0;
}

/**
 * @brief      output example get the local time zone
 * @param[out] *zone points to a local time zone buffer
 * @return     status code
 *             - 0 success
 * @note       none
 */
uint8_t ds1307_output_get_timestamp_time_zone(int8_t *zone)
{
    *zone = gs_time_zone;

    return 0;
}

/**
 * @brief      output example get the ascii time
 * @param[out] *buf points to an ascii buffer
 * @param[in]  len is the data length
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t ds1307_output_get_ascii_time(char *buf, uint8_t len)
{
    ds1307_time_t t;

    /* get time */
    if (ds1307_get_time(&gs_handle, &t) != 0)
    {
        return 1;
    }

    if (t.format == DS1307_FORMAT_24H)
    {
        (void)snprintf(buf, len, "%04d-%02d-%02d %02d:%02d:%02d %d.\n", t.year, t.month, t.date, t.hour, t.minute, t.second, t.week);
    }
    else
    {
        (void)snprintf(buf, len, "%04d-%02d-%02d %s %02d:%02d:%02d %d.\n", t.year, t.month, t.date, (t.am_pm == DS1307_AM) ? "AM" : "PM",
                       t.hour, t.minute, t.second, t.week
                      );
    }

    return 0;
}

/**
 * @brief     output example set output mode
 * @param[in] mode is the output mode
 * @return    status code
 *            - 0 success
 *            - 1 set mode failed
 * @note      none
 */
uint8_t ds1307_output_set_mode(ds1307_output_mode_t mode)
{
    /* set output mode */
    if (ds1307_set_output_mode(&gs_handle, mode) != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief      output example get output mode
 * @param[out] *mode points to an output mode buffer
 * @return     status code
 *             - 0 success
 *             - 1 get mode failed
 * @note       none
 */
uint8_t ds1307_output_get_mode(ds1307_output_mode_t *mode)
{
    /* get output mode */
    if (ds1307_get_output_mode(&gs_handle, mode) != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief     output example set output level
 * @param[in] level is the output level
 * @return    status code
 *            - 0 success
 *            - 1 set level failed
 * @note      none
 */
uint8_t ds1307_output_set_level(ds1307_output_level_t level)
{
    /* set output level */
    if (ds1307_set_output_level(&gs_handle, level) != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief      output example get output level
 * @param[out] *level points to an output level buffer
 * @return     status code
 *             - 0 success
 *             - 1 get level failed
 * @note       none
 */
uint8_t ds1307_output_get_level(ds1307_output_level_t *level)
{
    /* get output level */
    if (ds1307_get_output_level(&gs_handle, level) != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief     output example set square wave frequency
 * @param[in] freq is the square wave frequency
 * @return    status code
 *            - 0 success
 *            - 1 set square wave frequency failed
 * @note      none
 */
uint8_t ds1307_output_set_square_wave_frequency(ds1307_square_wave_frequency_t freq)
{
    /* set square wave frequency */
    if (ds1307_set_square_wave_frequency(&gs_handle, freq) != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief      output example get square wave frequency
 * @param[out] *freq points to a square wave frequency buffer
 * @return     status code
 *             - 0 success
 *             - 1 get square wave frequency failed
 * @note       none
 */
uint8_t ds1307_output_get_square_wave_frequency(ds1307_square_wave_frequency_t *freq)
{
    /* get square wave frequency */
    if (ds1307_get_square_wave_frequency(&gs_handle, freq) != 0)
    {
        return 1;
    }

    return 0;
}
