/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
#include "usart.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  LL_USART_InitTypeDef USART_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2);

  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  /**USART2 GPIO Configuration
  PA2   ------> USART2_TX
  PA3   ------> USART2_RX
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_2|LL_GPIO_PIN_3;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USART2 DMA Init */

  /* USART2_TX Init */
  LL_DMA_SetChannelSelection(DMA1, LL_DMA_STREAM_6, LL_DMA_CHANNEL_4);

  LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_STREAM_6, LL_DMA_DIRECTION_MEMORY_TO_PERIPH);

  LL_DMA_SetStreamPriorityLevel(DMA1, LL_DMA_STREAM_6, LL_DMA_PRIORITY_MEDIUM);

  LL_DMA_SetMode(DMA1, LL_DMA_STREAM_6, LL_DMA_MODE_NORMAL);

  LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_STREAM_6, LL_DMA_PERIPH_NOINCREMENT);

  LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_STREAM_6, LL_DMA_MEMORY_INCREMENT);

  LL_DMA_SetPeriphSize(DMA1, LL_DMA_STREAM_6, LL_DMA_PDATAALIGN_BYTE);

  LL_DMA_SetMemorySize(DMA1, LL_DMA_STREAM_6, LL_DMA_MDATAALIGN_BYTE);

  LL_DMA_EnableFifoMode(DMA1, LL_DMA_STREAM_6);

  LL_DMA_SetFIFOThreshold(DMA1, LL_DMA_STREAM_6, LL_DMA_FIFOTHRESHOLD_1_4);

  LL_DMA_SetMemoryBurstxfer(DMA1, LL_DMA_STREAM_6, LL_DMA_MBURST_SINGLE);

  LL_DMA_SetPeriphBurstxfer(DMA1, LL_DMA_STREAM_6, LL_DMA_PBURST_SINGLE);

  /* USART2_RX Init */
  LL_DMA_SetChannelSelection(DMA1, LL_DMA_STREAM_5, LL_DMA_CHANNEL_4);

  LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_STREAM_5, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);

  LL_DMA_SetStreamPriorityLevel(DMA1, LL_DMA_STREAM_5, LL_DMA_PRIORITY_MEDIUM);

  LL_DMA_SetMode(DMA1, LL_DMA_STREAM_5, LL_DMA_MODE_NORMAL);

  LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_STREAM_5, LL_DMA_PERIPH_NOINCREMENT);

  LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_STREAM_5, LL_DMA_MEMORY_INCREMENT);

  LL_DMA_SetPeriphSize(DMA1, LL_DMA_STREAM_5, LL_DMA_PDATAALIGN_BYTE);

  LL_DMA_SetMemorySize(DMA1, LL_DMA_STREAM_5, LL_DMA_MDATAALIGN_BYTE);

  LL_DMA_EnableFifoMode(DMA1, LL_DMA_STREAM_5);

  LL_DMA_SetFIFOThreshold(DMA1, LL_DMA_STREAM_5, LL_DMA_FIFOTHRESHOLD_1_4);

  LL_DMA_SetMemoryBurstxfer(DMA1, LL_DMA_STREAM_5, LL_DMA_MBURST_SINGLE);

  LL_DMA_SetPeriphBurstxfer(DMA1, LL_DMA_STREAM_5, LL_DMA_PBURST_SINGLE);

  /* USART2 interrupt Init */
  NVIC_SetPriority(USART2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),5, 0));
  NVIC_EnableIRQ(USART2_IRQn);

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  USART_InitStruct.BaudRate = 115200;
  USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
  USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
  USART_InitStruct.Parity = LL_USART_PARITY_NONE;
  USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
  USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
  USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_8;
  LL_USART_Init(USART2, &USART_InitStruct);
  LL_USART_ConfigAsyncMode(USART2);
  LL_USART_Enable(USART2);
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/* USER CODE BEGIN 1 */
#define UART_CONFIG_USE_DMA				(0)

#if UART_CONFIG_USE_DMA ==0
#define UART_CONFIG_USE_INTERRUPT		(1)
#endif

//#if UART_CONFIG_USE_INTERRUPT ==1
//
//#endif // UART_CONFIG_USE_INTERRUPT

void UART_Config(void)//Receiver
{
	/************************RX CONFIG********************************** */
	//1. Enable the USART by writing the UE bit in USART_CR1 register to 1
	LL_USART_Enable(USART2);
	//2.define word lenght- Already in tools
	//3  stop-bit                  -Already in tools
	//4. DMA -tạm thời chưa cấu hình
	//5.Baudrate -ALready in tools
	//6.Set bit RE(Receive enable)
	LL_USART_EnableDirectionRx(USART2);

	#if UART_CONFIG_USE_INTERRUPT
		LL_USART_EnableIT_RXNE(USART2);
		//Khi đọc data ra thì cờ RXNE sẽ bị xóa
	#endif // UART_CONFIG_USE_INTERRUPT

		/************************TX CONFIG********************************** */
		//1. Enable UE (đã bật trên RX)
		//2.define word lenght- Already in tools
		//3  stop-bit                  -Already in tools
		//4. DMA -tạm thời chưa cấu hình
		//5.Baudrate -ALready in tools
		//6.Set bit TE(Teceive enable)
		//LL_USART_EnableDirectionTx(USART2);
		//Write data to DR REG

		//Wait TC =1


}

#define UART_MAX_LEN 		(128U)
uint8_t uart_buffer[]={0};
volatile uint32_t uart_buf_ptr=0;

void UART_Put_Char(uint8_t c)
{
	if(uart_buf_ptr >= UART_MAX_LEN)
	{
		uart_buf_ptr=0;
	}
	uart_buffer[uart_buf_ptr] = c;
//	__disable_irq();
	uart_buf_ptr+=1; // tắt toàn bộ ngắt để tránh trường hợp khi cập nhật giá trị chỗ này thì bị ngắt khác làm phiền
//	__enable_irq();
}

void UART_Send_String(const char * str, uint32_t len)
{

	if(str == NULL){ return  ;};
	// Check TX busy (chờ đường truyền gửi xong hết
	while( !LL_USART_IsActiveFlag_TC(USART2)){ };

	while (len --) // check NULL pointer (rồi mới nạp dữ liệu mới vào)
	{
		UART_Put_Char(*str++);
	}
	LL_USART_EnableDirectionTx(USART2); // sau khi đưa vào bộ nhớ bật khối Tx này lên
	//Enable ngắt TX
#if UART_CONFIG_USE_INTERRUPT
	LL_USART_EnableIT_TXE(USART2);
//Khi đọc data ra thì cờ RXNE sẽ bị xóa
#endif // UART_CONFIG_USE_INTERRUPT
}

void UART_Handle_Rx_Data(void)
{

}

/* USER CODE END 1 */
