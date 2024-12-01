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
 * @file      driver_sfa30.h
 * @brief     driver sfa30 header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2023-07-30
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2023/07/30  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_SFA30_H
#define DRIVER_SFA30_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup sfa30_driver sfa30 driver function
 * @brief    sfa30 driver modules
 * @{
 */

/**
 * @addtogroup sfa30_basic_driver
 * @{
 */

/**
 * @brief sfa30 interface enumeration definition
 */
typedef enum
{
    SFA30_INTERFACE_IIC  = 0x00,       /**< iic interface */
    SFA30_INTERFACE_UART = 0x01,       /**< uart interface */
} sfa30_interface_t;

/**
 * @brief sfa30 data structure definition
 */
typedef struct sfa30_data_s
{
    int16_t formaldehyde_raw;        /**< formaldehyde raw */
    int16_t humidity_raw;            /**< humidity raw */
    int16_t temperature_raw;         /**< temperature raw */
    float formaldehyde;              /**< formaldehyde in ppb */
    float humidity;                  /**< humidity in % */
    float temperature;               /**< humidity in C */
} sfa30_data_t;

/**
 * @brief sfa30 handle structure definition
 */
typedef struct sfa30_handle_s
{
    uint8_t (*iic_init)(void);                                                /**< point to an iic_init function address */
    uint8_t (*iic_deinit)(void);                                              /**< point to an iic_deinit function address */
    uint8_t (*iic_write_cmd)(uint8_t addr, uint8_t *buf, uint16_t len);       /**< point to an iic_write_cmd function address */
    uint8_t (*iic_read_cmd)(uint8_t addr, uint8_t *buf, uint16_t len);        /**< point to an iic_read_cmd function address */
    uint8_t (*uart_init)(void);                                               /**< point to a uart_init function address */
    uint8_t (*uart_deinit)(void);                                             /**< point to a uart_deinit function address */
    uint16_t (*uart_read)(uint8_t *buf, uint16_t len);                        /**< point to a uart_read function address */
    uint8_t (*uart_flush)(void);                                              /**< point to a uart_flush function address */
    uint8_t (*uart_write)(uint8_t *buf, uint16_t len);                        /**< point to a uart_write function address */
    void (*delay_ms)(uint32_t ms);                                            /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                          /**< point to a debug_print function address */
    uint8_t inited;                                                           /**< inited flag */
    uint8_t iic_uart;                                                         /**< iic uart */
    uint8_t buf[256];                                                         /**< inner buffer */
} sfa30_handle_t;

/**
 * @brief sfa30 information structure definition
 */
typedef struct sfa30_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[16];                /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} sfa30_info_t;

/**
 * @}
 */

/**
 * @defgroup sfa30_link_driver sfa30 link driver function
 * @brief    sfa30 link driver modules
 * @ingroup  sfa30_driver
 * @{
 */

/**
 * @brief     initialize sfa30_handle_t structure
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] STRUCTURE is sfa30_handle_t
 * @note      none
 */
#define DRIVER_SFA30_LINK_INIT(HANDLE, STRUCTURE)              memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link uart_init function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to a uart_init function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_UART_INIT(HANDLE, FUC)              (HANDLE)->uart_init = FUC

/**
 * @brief     link uart_deinit function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to a uart_deinit function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_UART_DEINIT(HANDLE, FUC)            (HANDLE)->uart_deinit = FUC

/**
 * @brief     link uart_read function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to a uart_read function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_UART_READ(HANDLE, FUC)              (HANDLE)->uart_read = FUC

/**
 * @brief     link uart_write function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to a uart_write function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_UART_WRITE(HANDLE, FUC)             (HANDLE)->uart_write = FUC

/**
 * @brief     link uart_flush function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to a uart_flush function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_UART_FLUSH(HANDLE, FUC)             (HANDLE)->uart_flush = FUC

/**
 * @brief     link iic_init function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to an iic_init function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_IIC_INIT(HANDLE, FUC)               (HANDLE)->iic_init = FUC

/**
 * @brief     link iic_deinit function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to an iic_deinit function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_IIC_DEINIT(HANDLE, FUC)             (HANDLE)->iic_deinit = FUC

/**
 * @brief     link iic_write_cmd function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to an iic_write_cmd function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_IIC_WRITE_COMMAND(HANDLE, FUC)      (HANDLE)->iic_write_cmd = FUC

/**
 * @brief     link iic_read_cmd function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to an iic_read_cmd function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_IIC_READ_COMMAND(HANDLE, FUC)       (HANDLE)->iic_read_cmd = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to a delay_ms function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_DELAY_MS(HANDLE, FUC)               (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE points to an sfa30 handle structure
 * @param[in] FUC points to a debug_print function address
 * @note      none
 */
#define DRIVER_SFA30_LINK_DEBUG_PRINT(HANDLE, FUC)            (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup sfa30_basic_driver sfa30 basic driver function
 * @brief    sfa30 basic driver modules
 * @ingroup  sfa30_driver
 * @{
 */

/**
 * @brief      get chip information
 * @param[out] *info points to an sfa30 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t sfa30_info(sfa30_info_t *info);

/**
 * @brief     set the chip interface
 * @param[in] *handle points to an sfa30 handle structure
 * @param[in] interface is the chip interface
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t sfa30_set_interface(sfa30_handle_t *handle, sfa30_interface_t interface);

/**
 * @brief      get the chip interface
 * @param[in]  *handle points to an sfa30 handle structure
 * @param[out] *interface points to a chip interface buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t sfa30_get_interface(sfa30_handle_t *handle, sfa30_interface_t *interface);

/**
 * @brief     initialize the chip
 * @param[in] *handle points to an sfa30 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic or uart initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 *            - 4 reset failed
 * @note      none
 */
uint8_t sfa30_init(sfa30_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle points to an sfa30 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic or uart deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 soft reset failed
 * @note      none
 */
uint8_t sfa30_deinit(sfa30_handle_t *handle);

/**
 * @brief      read the result
 * @param[in]  *handle points to an sfa30 handle structure
 * @param[out] *data points to an sfa30_data_t structure
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t sfa30_read(sfa30_handle_t *handle, sfa30_data_t *data);

/**
 * @brief     start the measurement
 * @param[in] *handle points to an sfa30 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 start measurement failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t sfa30_start_measurement(sfa30_handle_t *handle);

/**
 * @brief     stop the measurement
 * @param[in] *handle points to an sfa30 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 stop measurement failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t sfa30_stop_measurement(sfa30_handle_t *handle);

/**
 * @brief     reset the chip
 * @param[in] *handle points to an sfa30 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 reset failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t sfa30_reset(sfa30_handle_t *handle);

/**
 * @brief      get device information
 * @param[in]  *handle points to an sfa30 handle structure
 * @param[out] *info points to an info buffer
 * @return     status code
 *             - 0 success
 *             - 1 get device information failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t sfa30_get_device_information(sfa30_handle_t *handle, char info[32]);

/**
 * @}
 */

/**
 * @defgroup sfa30_extern_driver sfa30 extern driver function
 * @brief    sfa30 extern driver modules
 * @ingroup  sfa30_driver
 * @{
 */

/**
 * @brief      set and get the chip register with uart interface
 * @param[in]  *handle points to an sfa30 handle structure
 * @param[in]  *input points to an input buffer
 * @param[in]  in_len is the input length
 * @param[out] *output points to an output buffer
 * @param[in]  out_len is the output length
 * @return     status code
 *             - 0 success
 *             - 1 write read failed
 * @note       none
 */
uint8_t sfa30_set_get_reg_uart(sfa30_handle_t *handle, uint8_t *input, uint16_t in_len, uint8_t *output, uint16_t out_len);

/**
 * @brief     set the chip register with iic interface
 * @param[in] *handle points to an sfa30 handle structure
 * @param[in] reg is the iic register address
 * @param[in] *buf points to a data buffer
 * @param[in] len is the data buffer length
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t sfa30_set_reg_iic(sfa30_handle_t *handle, uint16_t reg, uint8_t *buf, uint16_t len);

/**
 * @brief      get the chip register with iic interface
 * @param[in]  *handle points to an sfa30 handle structure
 * @param[in]  reg is the iic register address
 * @param[out] *buf points to a data buffer
 * @param[in]  len is the data buffer length
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t sfa30_get_reg_iic(sfa30_handle_t *handle, uint16_t reg, uint8_t *buf, uint16_t len);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
