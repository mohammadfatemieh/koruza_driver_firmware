/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @author  Ac6
  * @version V1.0
  * @date    02-Feb-2015
  * @brief   Default Interrupt Service Routines.
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#ifdef USE_RTOS_SYSTICK
#include <cmsis_os.h>
#endif
#include "stm32f4xx_it.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_adc1;

extern TIM_HandleTypeDef    TimHandle;
extern SPI_HandleTypeDef hspi2;
extern TIM_HandleTypeDef htim9;

/******************************************************************************/
/*            	  	    Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles SysTick Handler, but only if no RTOS defines it.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
#ifdef USE_RTOS_SYSTICK
	osSystickHandler();
#endif
}

/**
* @brief This function handles USART1 global interrupt.
*/
void USART1_IRQHandler(void)
{

  HAL_UART_IRQHandler(&huart1);

}

/**
* @brief This function handles DMA2 stream0 global interrupt.
*/
void DMA2_Stream0_IRQHandler(void)
{

  HAL_DMA_IRQHandler(&hdma_adc1);

}

/**
* @brief This function handles TIM1 break interrupt and TIM9 global interrupt.
*/
void TIM1_BRK_TIM9_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim9);
}

/**
  * @brief  This function handles TIM interrupt request.
  * @param  None
  * @retval None
  */
void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TimHandle);
}

/**
* @brief This function handles SPI2 global interrupt.
*/
void SPI2_IRQHandler(void)
{
  HAL_SPI_IRQHandler(&hspi2);
}

