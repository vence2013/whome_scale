/***************************************************************************//**
 * @file
 * @brief I2CSPM Config
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef SL_I2CSPM_OLED_I2C_CONFIG_H
#define SL_I2CSPM_OLED_I2C_CONFIG_H

// <<< Use Configuration Wizard in Context Menu

// <h>I2CSPM settings

// <o SL_I2CSPM_OLED_I2C_REFERENCE_CLOCK> Reference clock frequency
// <i> Frequency in Hz of the reference clock.
// <i> Select 0 to use the frequency of the currently selected clock.
// <i> Default: 0
#define SL_I2CSPM_OLED_I2C_REFERENCE_CLOCK 0

// <o SL_I2CSPM_OLED_I2C_SPEED_MODE> Speed mode
// <0=> Standard mode (100kbit/s)
// <1=> Fast mode (400kbit/s)
// <2=> Fast mode plus (1Mbit/s)
// <i> Default: 0
#define SL_I2CSPM_OLED_I2C_SPEED_MODE      0
// </h> end I2CSPM config

// <<< end of configuration section >>>

// <<< sl:start pin_tool >>>
// <i2c signal=SCL,SDA> SL_I2CSPM_OLED_I2C
// $[I2C_SL_I2CSPM_OLED_I2C]
#define SL_I2CSPM_OLED_I2C_PERIPHERAL            I2C1
#define SL_I2CSPM_OLED_I2C_PERIPHERAL_NO         1

// I2C1 SCL on PD00
#define SL_I2CSPM_OLED_I2C_SCL_PORT              gpioPortD
#define SL_I2CSPM_OLED_I2C_SCL_PIN               0

// I2C1 SDA on PD01
#define SL_I2CSPM_OLED_I2C_SDA_PORT              gpioPortD
#define SL_I2CSPM_OLED_I2C_SDA_PIN               1
// [I2C_SL_I2CSPM_OLED_I2C]$
// <<< sl:end pin_tool >>>

#endif // SL_I2CSPM_OLED_I2C_CONFIG_H
