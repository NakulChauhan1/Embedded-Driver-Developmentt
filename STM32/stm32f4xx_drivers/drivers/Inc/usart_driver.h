

#ifndef __USART_DRIVER_H
#define __USART_DRIVER_H


#include "stm32f4xx.h"

typedef struct
{
		uint8_t USART_Mode;
		uint32_t USART_Baud;
		uint8_t USART_NoOfStopBits;
		uint8_t USART_WorldLength;
		uint8_t USART_ParityControl;
		uint8_t USART_HWFlowControl;
}USART_Config_t;

typedef struct
{
		USART_RegDef_t *pUSARTx;
		USART_Config_t USART_Config;
}USART_Handle_t;


/************************* Macros for initializing Configuration Structure*************************************/

/*
 * @USART_Mode
 * Possible options for USART_Mode
 */

#define USART_MODE_TX_ONLY					0
#define USART_MODE_RX_ONLY					1
#define USART_MODE_TXRX_ONLY				2


/*
 *@USART_Baud
 * Possible options for USART_Baud
 */

#define USART_STD_BAUD_1200					1200
#define USART_STD_BAUD_2400					2400
#define USART_STD_BAUD_9600					9600
#define USART_STD_BAUD_19200				19200
#define USART_STD_BAUD_38400				38400
#define USART_STD_BAUD_57600				57600
#define USART_STD_BAUD_115200				115200
#define USART_STD_BAUD_230400				230400
#define USART_STD_BAUD_460800				460800
#define USART_STD_BAUD_921600				921600
#define USART_STD_BAUD_2M					2000000
#define USART_STD_BAUD_3M					3000000


/*
 *@USART_ParityControl
 *Possible options for USART_ParityControl
 */

#define USART_PARITY_EN_ODD 			 	2
#define USART_PARITY_EN_EVEN  				1
#define USART_PARITY_DISABLE   				0


/*
 *@USART_WordLength
 *Possible options for USART_WordLength
 */

#define USART_WORDLEN_8BITS  				0
#define USART_WORDLEN_9BITS  				1

/*
 *@USART_NoOfStopBits
 *Possible options for USART_NoOfStopBits
 */

#define USART_STOPBITS_1     				0
#define USART_STOPBITS_0_5   				1
#define USART_STOPBITS_2     				2
#define USART_STOPBITS_1_5   				3

/*
 *@USART_HWFlowControl
 *Possible options for USART_HWFlowControl
 */

#define USART_HW_FLOW_CTRL_NONE    			0
#define USART_HW_FLOW_CTRL_CTS    			1
#define USART_HW_FLOW_CTRL_RTS    			2
#define USART_HW_FLOW_CTRL_CTS_RTS			3


/*
 *	@USART related status flags definitions ( Masking details of various flags )
 */

#define USART_PE_FLAG							( 1 << 0 )
#define USART_FE_FLAG							( 1 << 1 )
#define USART_NF_FLAG							( 1 << 2 )
#define USART_ORE_FLAG							( 1 << 3 )
#define USART_IDLE_FLAG							( 1 << 4 )
#define USART_RXNE_FLAG							( 1 << 5 )
#define USART_TC_FLAG							( 1 << 6 )
#define USART_TXE_FLAG							( 1 << 7 )
#define USART_LBD_FLAG							( 1 << 8 )
#define USART_CTS_FLAG							( 1 << 9 )



/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/

/*
 * Peripheral Clock setup
 */

void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnorDi);

/*
 * Init and De-init
 */

void USART_Init(USART_Handle_t *pUSARTHandle);
void USART_DeInit(USART_RegDef_t *pUSARTx);


/*
 * Data Send and Receive
 */

void USART_SendData(USART_RegDef_t *pUSARTx,uint8_t *pTxBuffer, uint32_t Len);
void USART_ReceiveData(USART_RegDef_t *pUSARTx, uint8_t *pRxBuffer, uint32_t Len);
uint8_t USART_SendDataIT(USART_Handle_t *pUSARTHandle,uint8_t *pTxBuffer, uint32_t Len);
uint8_t USART_ReceiveDataIT(USART_Handle_t *pUSARTHandle, uint8_t *pRxBuffer, uint32_t Len);

/*
 * IRQ Configuration and ISR handling
 */

void USART_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void USART_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void USART_IRQHandling(USART_Handle_t *pHandle);

/*
 * Other Peripheral Control APIs
 */

void USART_PeripheralControl(USART_RegDef_t *pUSARTx, uint8_t EnOrDi);
uint8_t USART_GetFlagStatus(USART_RegDef_t *pUSARTx , uint32_t FlagName);
void USART_ClearFlag(USART_RegDef_t *pUSARTx, uint16_t StatusFlagName);

/*
 * Application callback
 */

void USART_ApplicationEventCallback(USART_Handle_t *pUSARTHandle,uint8_t AppEv);


#endif

