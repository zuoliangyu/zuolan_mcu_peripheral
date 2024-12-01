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
 * @file      driver_sts3x.h
 * @brief     driver sts3x header file
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

#ifndef DRIVER_STS3X_H
#define DRIVER_STS3X_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup sts3x_driver sts3x driver function
 * @brief    sts3x driver modules
 * @{
 */

/**
 * @addtogroup sts3x_base_driver
 * @{
 */

/**
 * @brief sts3x address enumeration definition
 */
typedef enum
{
    STS3X_ADDRESS_0 = (0x4A << 1),        /**< ADDR pin connected to GND */
    STS3X_ADDRESS_1 = (0x4B << 1),        /**< ADDR pin connected to VCC */
} sts3x_address_t;

/**
 * @brief sts3x bool enumeration definition
 */
typedef enum
{
    STS3X_BOOL_FALSE = 0x00,        /**< disable function */
    STS3X_BOOL_TRUE  = 0x01,        /**< enable function */
} sts3x_bool_t;

/**
 * @brief sts3x rate enumeration definition
 */
typedef enum
{
    STS3X_RATE_0P5HZ = 0x20,        /**< 0.5Hz sample rate */
    STS3X_RATE_1HZ   = 0x21,        /**< 1Hz sample rate */
    STS3X_RATE_2HZ   = 0x22,        /**< 2Hz sample rate */
    STS3X_RATE_4HZ   = 0x23,        /**< 4Hz sample rate */
    STS3X_RATE_10HZ  = 0x27,        /**< 10Hz sample rate */
} sts3x_rate_t;

/**
 * @brief sts3x repeatability enumeration definition
 */
typedef enum  
{
    STS3X_REPEATABILITY_HIGH   = 0x00,        /**< high repeatability */
    STS3X_REPEATABILITY_MEDIUM = 0x01,        /**< medium repeatability */
    STS3X_REPEATABILITY_LOW    = 0x02,        /**< low repeatability */
} sts3x_repeatability_t;

/**
 * @brief sts3x status enumeration definition
 */
typedef enum  
{
    STS3X_STATUS_ALERT_PENDING_STATUS = (1 << 15),        /**< alert pending status */
    STS3X_STATUS_HEATER_ON            = (1 << 13),        /**< heater on */
    STS3X_STATUS_TEMPERATURE_ALERT    = (1 << 10),        /**< temperature alert */
    STS3X_STATUS_SYSTEM_RESET         = (1 << 4),         /**< system reset */
    STS3X_STATUS_COMMAND_STATUS       = (1 << 1),         /**< command status */
    STS3X_STATUS_CHECKSUM_STATUS      = (1 << 0),         /**< checksum status */
} sts3x_status_t;

/**
 * @brief sts3x handle structure definition
 */
typedef struct sts3x_handle_s
{
    uint8_t (*iic_init)(void);                                                                     /**< point to an iic_init function address */
    uint8_t (*iic_deinit)(void);                                                                   /**< point to an iic_deinit function address */
    uint8_t (*iic_write_address16)(uint8_t addr, uint16_t reg, uint8_t *buf, uint16_t len);        /**< point to an iic_write_address16 function address */
    uint8_t (*iic_read_address16)(uint8_t addr, uint16_t reg, uint8_t *buf, uint16_t len);         /**< point to an iic_read_address16 function address */
    void (*delay_ms)(uint32_t ms);                                                                 /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                                               /**< point to a debug_print function address */
    uint8_t iic_addr;                                                                              /**< iic device address */
    uint8_t repeatability;                                                                         /**< repeatability value */
    uint8_t inited;                                                                                /**< inited flag */
} sts3x_handle_t;

/**
 * @brief sts3x information structure definition
 */
typedef struct sts3x_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} sts3x_info_t;

/**
 * @}
 */

/**
 * @defgroup sts3x_link_driver sts3x link driver function
 * @brief    sts3x link driver modules
 * @ingroup  sts3x_driver
 * @{
 */

/**
 * @brief     initialize sts3x_handle_t structure
 * @param[in] HANDLE points to an sts3x handle structure
 * @param[in] STRUCTURE is sts3x_handle_t
 * @note      none
 */
#define DRIVER_STS3X_LINK_INIT(HANDLE, STRUCTURE)            memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link iic_init function
 * @param[in] HANDLE points to an sts3x handle structure
 * @param[in] FUC points to an iic_init function address
 * @note      none
 */
#define DRIVER_STS3X_LINK_IIC_INIT(HANDLE, FUC)              (HANDLE)->iic_init = FUC

/**
 * @brief     link iic_deinit function
 * @param[in] HANDLE points to an sts3x handle structure
 * @param[in] FUC points to an iic_deinit function address
 * @note      none
 */
#define DRIVER_STS3X_LINK_IIC_DEINIT(HANDLE, FUC)            (HANDLE)->iic_deinit = FUC

/**
 * @brief     link iic_read_address16 function
 * @param[in] HANDLE points to an sts3x handle structure
 * @param[in] FUC points to an iic_read_address16 function address
 * @note      none
 */
#define DRIVER_STS3X_LINK_IIC_READ_ADDRESS16(HANDLE, FUC)    (HANDLE)->iic_read_address16 = FUC

/**
 * @brief     link iic_write_address16 function
 * @param[in] HANDLE points to an sts3x handle structure
 * @param[in] FUC points to an iic_write_address16 function address
 * @note      none
 */
#define DRIVER_STS3X_LINK_IIC_WRITE_ADDRESS16(HANDLE, FUC)   (HANDLE)->iic_write_address16 = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE points to an sts3x handle structure
 * @param[in] FUC points to a delay_ms function address
 * @note      none
 */
#define DRIVER_STS3X_LINK_DELAY_MS(HANDLE, FUC)              (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE points to an sts3x handle structure
 * @param[in] FUC points to a debug_print function address
 * @note      none
 */
#define DRIVER_STS3X_LINK_DEBUG_PRINT(HANDLE, FUC)           (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup sts3x_base_driver sts3x base driver function
 * @brief    sts3x base driver modules
 * @ingroup  sts3x_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info points to an sts3x info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t sts3x_info(sts3x_info_t *info);

/**
 * @brief     set the iic address pin
 * @param[in] *handle points to an sts3x handle structure
 * @param[in] addr_pin is the chip iic address pin
 * @return    status code
 *            - 0 success
 *            - 1 set addr pin failed
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t sts3x_set_addr_pin(sts3x_handle_t *handle, sts3x_address_t addr_pin);

/**
 * @brief      get the iic address pin
 * @param[in]  *handle points to an sts3x handle structure
 * @param[out] *addr_pin points to a chip iic address pin buffer
 * @return      status code
 *              - 0 success
 *              - 1 get addr pin failed
 *              - 2 handle is NULL
 * @note        none
 */
uint8_t sts3x_get_addr_pin(sts3x_handle_t *handle, sts3x_address_t *addr_pin);

/**
 * @brief     initialize the chip
 * @param[in] *handle points to an sts3x handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 * @note      none
 */
uint8_t sts3x_init(sts3x_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle points to an sts3x handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t sts3x_deinit(sts3x_handle_t *handle);

/**
 * @brief      read data once
 * @param[in]  *handle points to an sts3x handle structure
 * @param[in]  clock_stretching_enable is a clock stretching bool value
 * @param[out] *temperature_raw points to a raw temperature buffer
 * @param[out] *temperature_s points to a converted temperature buffer
 * @return     status code
 *             - 0 success
 *             - 1 single read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t sts3x_single_read(sts3x_handle_t *handle, sts3x_bool_t clock_stretching_enable, 
                          uint16_t *temperature_raw, float *temperature_s);

/**
 * @brief     start reading
 * @param[in] *handle points to an sts3x handle structure
 * @param[in] rate is the sample rate
 * @return    status code
 *            - 0 success
 *            - 1 start continuous read failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t sts3x_start_continuous_read(sts3x_handle_t *handle, sts3x_rate_t rate);

/**
 * @brief     stop reading
 * @param[in] *handle points to an sts3x handle structure
 * @return    status code
 *            - 0 success
 *            - 1 stop continuous read failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t sts3x_stop_continuous_read(sts3x_handle_t *handle);

/**
 * @brief      read data continuously
 * @param[in]  *handle points to an sts3x handle structure
 * @param[out] *temperature_raw points to a raw temperature buffer
 * @param[out] *temperature_s points to a converted temperature buffer
 * @return     status code
 *             - 0 success
 *             - 1 continuous read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t sts3x_continuous_read(sts3x_handle_t *handle, uint16_t *temperature_raw, float *temperature_s);

/**
 * @brief      get the current status
 * @param[in]  *handle points to an sts3x handle structure
 * @param[out] *status points to a status buffer
 * @return      status code
 *              - 0 success
 *              - 1 get status failed
 *              - 2 handle is NULL
 * @note        none
 */
uint8_t sts3x_get_status(sts3x_handle_t *handle, uint16_t *status);

/**
 * @brief     clear the current status
 * @param[in] *handle points to an sts3x handle structure
 * @return    status code
 *            - 0 success
 *            - 1 clear status failed
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t sts3x_clear_status(sts3x_handle_t *handle);

/**
 * @brief     set the measurement repeatability
 * @param[in] *handle points to an sts3x handle structure
 * @param[in] repeatability is the measurement repeatability
 * @return    status code
 *            - 0 success
 *            - 1 set repeatability failed
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t sts3x_set_repeatability(sts3x_handle_t *handle, sts3x_repeatability_t repeatability);

/**
 * @brief      get the measurement repeatability
 * @param[in]  *handle points to an sts3x handle structure
 * @param[out] *repeatability points to a measurement repeatability buffer
 * @return     status code
 *             - 0 success
 *             - 1 get repeatability failed
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t sts3x_get_repeatability(sts3x_handle_t *handle, sts3x_repeatability_t *repeatability);

/**
 * @brief     soft reset the chip
 * @param[in] *handle points to an sts3x handle structure
 * @return    status code
 *            - 0 success
 *            - 1 soft reset failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t sts3x_soft_reset(sts3x_handle_t *handle);

/**
 * @brief     enable or disable the chip heater
 * @param[in] *handle points to an sts3x handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set heater failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t sts3x_set_heater(sts3x_handle_t *handle, sts3x_bool_t enable);

/**
 * @}
 */

/**
 * @defgroup sts3x_extend_driver sts3x extend driver function
 * @brief    sts3x extend driver modules
 * @ingroup  sts3x_driver
 * @{
 */

/**
 * @brief     set the chip register
 * @param[in] *handle points to an sts3x handle structure
 * @param[in] command is the chip command
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t sts3x_set_reg(sts3x_handle_t *handle, uint16_t command);

/**
 * @brief      get the chip register
 * @param[in]  *handle points to an sts3x handle structure
 * @param[in]  command is the chip command
 * @param[out] *buf points to data buffer
 * @param[in]  len is the data length
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t sts3x_get_reg(sts3x_handle_t *handle, uint16_t command, uint8_t *buf, uint16_t len);

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
