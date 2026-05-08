/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

#include "stm32g4xx_ll_usart.h"
#include "stm32g4xx_ll_rcc.h"
#include "stm32g4xx_ll_bus.h"
#include "stm32g4xx_ll_cortex.h"
#include "stm32g4xx_ll_system.h"
#include "stm32g4xx_ll_utils.h"
#include "stm32g4xx_ll_pwr.h"
#include "stm32g4xx_ll_gpio.h"
#include "stm32g4xx_ll_dma.h"

#include "stm32g4xx_ll_exti.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DRAIN_EN_Pin GPIO_PIN_13
#define DRAIN_EN_GPIO_Port GPIOC
#define DEBUG_SW_NRST_Pin GPIO_PIN_10
#define DEBUG_SW_NRST_GPIO_Port GPIOG
#define TC_FAULT2_OUT_N_Pin GPIO_PIN_0
#define TC_FAULT2_OUT_N_GPIO_Port GPIOC
#define SPI2_TC_CS2_N_Pin GPIO_PIN_3
#define SPI2_TC_CS2_N_GPIO_Port GPIOC
#define FLASH_RESET_Pin GPIO_PIN_4
#define FLASH_RESET_GPIO_Port GPIOA
#define QSPI_BK_NCS_Pin GPIO_PIN_5
#define QSPI_BK_NCS_GPIO_Port GPIOA
#define TRANSCEIVER_DE_Pin GPIO_PIN_2
#define TRANSCEIVER_DE_GPIO_Port GPIOB
#define TRANSCEIVER_RE_N_Pin GPIO_PIN_7
#define TRANSCEIVER_RE_N_GPIO_Port GPIOE
#define TC_DRDY1_OUT_N_Pin GPIO_PIN_9
#define TC_DRDY1_OUT_N_GPIO_Port GPIOE
#define TC_FAULT1_OUT_N_Pin GPIO_PIN_10
#define TC_FAULT1_OUT_N_GPIO_Port GPIOE
#define ADC1_IN7_Pin GPIO_PIN_12
#define ADC1_IN7_GPIO_Port GPIOE
#define ADC1_IN1_Pin GPIO_PIN_13
#define ADC1_IN1_GPIO_Port GPIOE
#define SPI2_TC_CS1_N_Pin GPIO_PIN_15
#define SPI2_TC_CS1_N_GPIO_Port GPIOE
#define SPI2_TC_SCK_Pin GPIO_PIN_13
#define SPI2_TC_SCK_GPIO_Port GPIOB
#define SPI2_TC_MOSI_Pin GPIO_PIN_15
#define SPI2_TC_MOSI_GPIO_Port GPIOB
#define I2C3_SCL_TEMP_Pin GPIO_PIN_8
#define I2C3_SCL_TEMP_GPIO_Port GPIOC
#define I2C3_SDA_TEMP_Pin GPIO_PIN_9
#define I2C3_SDA_TEMP_GPIO_Port GPIOC
#define SPI2_TC_CS3_N_Pin GPIO_PIN_9
#define SPI2_TC_CS3_N_GPIO_Port GPIOA
#define HEATER_ENABLE_Pin GPIO_PIN_4
#define HEATER_ENABLE_GPIO_Port GPIOB
#define MEV_ENABLE_Pin GPIO_PIN_5
#define MEV_ENABLE_GPIO_Port GPIOB
#define TC_FAULT3_OUT_N_Pin GPIO_PIN_6
#define TC_FAULT3_OUT_N_GPIO_Port GPIOB
#define TC_DRDY3_OUT_N_Pin GPIO_PIN_7
#define TC_DRDY3_OUT_N_GPIO_Port GPIOB
#define TC_DRDY2_OUT_N_Pin GPIO_PIN_9
#define TC_DRDY2_OUT_N_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
