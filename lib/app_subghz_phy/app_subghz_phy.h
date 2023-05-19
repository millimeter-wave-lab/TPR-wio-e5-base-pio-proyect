/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_subghz_phy.h
  * @author  MCD Application Team
  * @brief   Header of application of the SubGHz_Phy Middleware
   ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#ifndef __APP_SUBGHZ_PHY_H__
#define __APP_SUBGHZ_PHY_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

typedef enum
{
  BW_7kHz = 0,
  BW_12kHz = 1,
  BW_31kHz = 2,
  BW_62kHz = 3,
  BW_125kHz = 4,
  BW_250kHz = 5,
  BW_500kHz = 6,
} Lora_BandWidth_t;


typedef struct
{
  uint32_t modulation;         /* 0: FSK, 1: Lora, 2:BPSK(Tx) */
  uint32_t freq;               /* in Hz */
  int32_t power;               /* [-9 :22]dBm */
  uint32_t bandwidth;          /* Lora [0:7.8125, 1: 15.625, 2: 31.25, 3: 62.5, 4: 125, 5: 250, 6: 500]kHz
                                  FSK : [4800Hz :467000 Hz] */
  uint32_t loraSf_datarate;    /* Lora[SF5..SF12] FSK [600..300000 bits/s] */
  uint32_t codingRate;         /* Lora Only [1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8] */
  uint32_t lna;                /* 0:off 1:On */
  uint32_t paBoost;            /* 0:off 1:On */
  uint32_t payloadLen;         /* [1:256] */
  uint32_t fskDev;             /* FSK only [4800:467000]
                                  Note: no check applied wrt bandwidth. Common practice is to have bandwidth>1,5*fskDev */
  uint32_t lowDrOpt;           /* Lora Only 0: off, 1:On, 2: Auto (1 when SF11 or SF12, 0 otherwise) */
  uint32_t BTproduct;          /* FSK only [0 no Gaussian Filter Applied, 1: BT=0,3, 2: BT=0,5, 3: BT=0,7, 4: BT=1] */
} testParameter_t;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define TEST_FSK                           0
#define TEST_LORA                          1
#define TEST_BPSK                          2

/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported Functions Prototypes ---------------------------------------------*/
/**
  * @brief  Init SubGHz Radio Application
  */
void MX_SubGHz_Phy_Init(void);

/**
  * @brief  SubGHz Radio Application Process
  */
void MX_SubGHz_Phy_Process(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /*__APP_SUBGHZ_PHY_H__*/
