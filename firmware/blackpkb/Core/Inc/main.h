/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define LED_YELLOW_Pin GPIO_PIN_0
#define LED_YELLOW_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_1
#define LED_RED_GPIO_Port GPIOA
#define LED_GREEN_Pin GPIO_PIN_2
#define LED_GREEN_GPIO_Port GPIOA
#define ENCODER_B_Pin GPIO_PIN_6
#define ENCODER_B_GPIO_Port GPIOA
#define ENCODER_A_Pin GPIO_PIN_7
#define ENCODER_A_GPIO_Port GPIOA
#define ENCODER_GND_Pin GPIO_PIN_0
#define ENCODER_GND_GPIO_Port GPIOB
#define ENCODER_SW_Pin GPIO_PIN_1
#define ENCODER_SW_GPIO_Port GPIOB
#define COL_1_Pin GPIO_PIN_12
#define COL_1_GPIO_Port GPIOB
#define COL_2_Pin GPIO_PIN_13
#define COL_2_GPIO_Port GPIOB
#define COL_3_Pin GPIO_PIN_14
#define COL_3_GPIO_Port GPIOB
#define ROW_1_Pin GPIO_PIN_3
#define ROW_1_GPIO_Port GPIOB
#define ROW_2_Pin GPIO_PIN_4
#define ROW_2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
