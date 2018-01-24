/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "TN4F" // TinyF4 Frsky
#define TARGET_CONFIG

#define LED0_PIN                PC13
#define LED1_PIN                PC14

#define USE_SPI
#define USE_SPI_DEVICE_1
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_3

#define SPI1_NSS_PIN            PA4
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN   	    PA6
#define SPI1_MOSI_PIN   	    PA7

#define SPI2_NSS_PIN            PB12
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN   	    PB14
#define SPI2_MOSI_PIN   	    PB15

#define SPI3_NSS_PIN            PA15
#define SPI3_SCK_PIN            PB3
#define SPI3_MISO_PIN   	    PB4
#define SPI3_MOSI_PIN   	    PB5

// *************** Gyro & ACC **********************
#define GYRO
#define ACC
#define USE_GYRO_SPI_MPU6500
#define USE_ACC_SPI_MPU6500

#define MPU6500_CS_PIN          SPI1_NSS_PIN
#define MPU6500_SPI_INSTANCE    SPI1

#define USE_EXTI
#define MPU_INT_EXTI            PB0
#define USE_MPU_DATA_READY_SIGNAL

#define GYRO_MPU6500_ALIGN      CW270_DEG
#define ACC_MPU6500_ALIGN       CW270_DEG

// *************** UART *****************************
#define USE_VCP
#define USE_UART1
#define USE_UART2

#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10

#define UART2_TX_PIN            PA2
#define UART2_RX_PIN            PA3

#define SERIAL_PORT_COUNT       3

#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_SBUS
#define SERIALRX_UART           SERIAL_PORT_USART1

// *************** OSD *****************************
#define OSD
#define USE_MAX7456
#define MAX7456_SPI_INSTANCE    SPI3
#define MAX7456_SPI_CS_PIN      SPI3_NSS_PIN
// #define MAX7456_SPI_CS_PIN      PA14

// *************** VTX *****************************
#define VTX_RTC6705
#define RTC6705_CS_PIN          PA14
#define RTC6705_SPI_INSTANCE    SPI3
// #define USE_RTC6705_CLK_HACK
// #define RTC6705_CLK_PIN         SPI3_SCK_PIN
// #define VTX_RTC6705_OPTIONAL
// #define VTX_RTC6705SOFTSPI
// #define VTX_CONTROL
// #define RTC6705_SPIDATA_PIN     SPI3_MOSI_PIN
// #define RTC6705_SPILE_PIN       PA14
// #define RTC6705_SPICLK_PIN      SPI3_SCK_PIN

// *************** ADC *****************************
#define USE_ADC
#define ADC_INSTANCE            ADC1
#define VBAT_ADC_PIN            PB1

#define USE_ESCSERIAL
#define USE_SERIAL_4WAY_BLHELI_INTERFACE

#define DEFAULT_FEATURES                (FEATURE_OSD | FEATURE_TELEMETRY)
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_NONE

#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         (BIT(2))

#define USABLE_TIMER_CHANNEL_COUNT 10
#define USED_TIMERS             ( TIM_N(1)|TIM_N(2)|TIM_N(3)|TIM_N(4)|TIM_N(5)|TIM_N(9) )
