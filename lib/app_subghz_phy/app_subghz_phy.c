/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_subghz_phy.c
  * @author  MCD Application Team
  * @brief   Application of the SubGHz_Phy Middleware
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

/* Includes ------------------------------------------------------------------*/
#include "app_subghz_phy.h"
#include "subghz_phy_app.h"
#include "sys_app.h"
#include "radio.h"
#include "usart.h"

/* USER CODE BEGIN Includes */
#include "radio_def.h"
/* USER CODE END Includes */

/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define F_868MHz                      868000000
#define F_915MHz                      915000000
#define P_14dBm                       14
#define P_22dBm                       22
#define SF12                          12
#define CR4o5                         1
#define EMISSION_POWER                P_14dBm
#define CONTINUOUS_TIMEOUT           0xFFFF
#define LORA_PREAMBLE_LENGTH          8         /* Same for Tx and Rx */
#define LORA_SYMBOL_TIMEOUT           30        /* Symbols */
#define TX_TIMEOUT_VALUE              3000
#define LORA_FIX_LENGTH_PAYLOAD_OFF   false
#define LORA_IQ_INVERSION_OFF         false
#define TX_TEST_TONE                  (1<<0)
#define RX_TEST_RSSI                  (1<<1)
#define TX_TEST_LORA                  (1<<2)
#define RX_TEST_LORA                  (1<<3)
#define RX_TIMEOUT_VALUE              5000
#define RX_CONTINUOUS_ON              1
#define PRBS9_INIT                    ( ( uint16_t) 2 )
#define DEFAULT_PAYLOAD_LEN           16
#define DEFAULT_LDR_OPT               2
#define DEFAULT_FSK_DEVIATION         25000
#define DEFAULT_GAUSS_BT              3 /*Lora default in legacy*/

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t LoraSnr_FskCfo){
  uint8_t msg[] = "Received a message";
  HAL_UART_Transmit(&huart1, msg, sizeof(msg), 19);

}
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
static testParameter_t testParam = { TEST_LORA, F_915MHz, EMISSION_POWER, BW_125kHz, SF12, CR4o5, 0, 0, DEFAULT_PAYLOAD_LEN, DEFAULT_FSK_DEVIATION, DEFAULT_LDR_OPT, DEFAULT_GAUSS_BT};
RxConfigGeneric_t RxConfig;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Exported functions --------------------------------------------------------*/

void MX_SubGHz_Phy_Init(void)
{
  /* USER CODE BEGIN MX_SubGHz_Phy_Init_1 */

  /* USER CODE END MX_SubGHz_Phy_Init_1 */
  SystemApp_Init();
  /* USER CODE BEGIN MX_SubGHz_Phy_Init_1_1 */

  /* USER CODE END MX_SubGHz_Phy_Init_1_1 */
  SubghzApp_Init();
  /* USER CODE BEGIN MX_SubGHz_Phy_Init_2 */
  RxConfig.lora.Bandwidth = (RADIO_LoRaBandwidths_t) testParam.bandwidth;
  RxConfig.lora.SpreadingFactor = (RADIO_LoRaSpreadingFactors_t) testParam.loraSf_datarate; /*BitRate*/
  RxConfig.lora.Coderate = (RADIO_LoRaCodingRates_t)testParam.codingRate;
  RxConfig.lora.LowDatarateOptimize = (RADIO_Ld_Opt_t)testParam.lowDrOpt; /*0 inactive, 1 active, 2: auto*/
  RxConfig.lora.PreambleLen = LORA_PREAMBLE_LENGTH;
  RxConfig.lora.LengthMode = RADIO_LORA_PACKET_VARIABLE_LENGTH;
  RxConfig.lora.CrcMode = RADIO_LORA_CRC_ON;
  RxConfig.lora.IqInverted = RADIO_LORA_IQ_NORMAL;
  Radio.RadioSetRxGenericConfig(GENERIC_LORA, &RxConfig, RX_CONTINUOUS_ON, LORA_SYMBOL_TIMEOUT);
  Radio.Rx(0);
  uint8_t msg[] = "finished initializating lora radio";
  HAL_UART_Transmit(&huart1,msg,sizeof(msg),10);
  // HAL_UART_Transmit(&huart2,msg,sizeof(msg),10);
  /* USER CODE END MX_SubGHz_Phy_Init_2 */
}

void MX_SubGHz_Phy_Process(void)
{
  /* USER CODE BEGIN MX_SubGHz_Phy_Process_1 */

  /* USER CODE END MX_SubGHz_Phy_Process_1 */
  /* USER CODE BEGIN MX_SubGHz_Phy_Process_OS */

  /* USER CODE END MX_SubGHz_Phy_Process_OS */
}

/* USER CODE BEGIN EF */

/* USER CODE END EF */

/* Private Functions Definition -----------------------------------------------*/
/* USER CODE BEGIN PrFD */


/* USER CODE END PrFD */
