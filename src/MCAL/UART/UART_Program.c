/*=================================================================================*/
/*  File        : UART_Program.c                                                   */
/*  Description : This file includes UART Driver implementations for stm32f401CC   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 19/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/*==========================================*/
/* Include Header Files From include Folder */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*==========================================*/
#include "../../../include/stm32F401CC.h"
#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Config.h"
/*==========================================*/
/* Global Variable */
u8 global_u8String[100];
void (*USART1_CallBack)(void);
void (*USART2_CallBack)(void);
void (*USART6_CallBack)(void);

/************************************************************************************************/
/* Function Name   : USART_voidInit                                                             */
/* Description     : Initialization of USARTx                                                   */
/* Fun. Argument1  : USART_InitType *A_InitStruct { Pointer to Struct }                         */
/* Struct1 Elements: {BaudRate , DataWidth , StopBits , Parity_Enable , Parity_Selection,       */
/*                 :  TransferDirection , HardwareFlowControl , Oversampling }                  */
/* Fun. Argument2  : USART_ClockInitTypeDef *A_ClockInitStruct { Pointer to Struct }            */
/* Struct2 Elements: {ClockOutput , ClockPolarity , ClockPhase , LastBitClockPulse }            */
/* Fun. Argument3  : USART_t *USARTx { Pointer to Struct }                                      */
/* Struct3 Elements: {UART1 , UART2 , UART6 }                                                   */
/* Fun. Return     : void                                                                       */
/************************************************************************************************/
void USART_voidInit(USART_InitType *A_InitStruct,USART_ClockInitTypeDef *A_ClockInitStruct,USART_t *USARTx)
{
	/* Configure BAUDRATE */
	USARTx->BRR = A_InitStruct->BaudRate ;
	/*---------------------------------------------------------------------------------------------------*/
	/* Configre Control Register [CR1] */
	USARTx->CR1 = (A_InitStruct->Oversampling     << USART_CR1_OVER8_BIT )   |
				  (A_InitStruct->DataWidth        << USART_CR1_M_BIT     )   |
				  (A_InitStruct->Parity_Enable    << USART_CR1_PCE_BIT   )   |
				  (A_InitStruct->Parity_Selection << USART_CR1_PS_BIT    )   ;
	switch (A_InitStruct->TransferDirection)
	{
		case TX_ONLY: CLEAR_BIT(USARTx->CR1, USART_CR1_RE_BIT); 
					  SET_BIT  (USARTx->CR1, USART_CR1_TE_BIT); break;
		case RX_ONLY: CLEAR_BIT(USARTx->CR1, USART_CR1_TE_BIT); 
		    		  SET_BIT  (USARTx->CR1, USART_CR1_RE_BIT); break;
		case TX_RX:   SET_BIT  (USARTx->CR1, USART_CR1_TE_BIT);
				  	  SET_BIT  (USARTx->CR1, USART_CR1_RE_BIT); break;
	}
	/*---------------------------------------------------------------------------------------------------*/
	/* Configre Control Register [CR2] */
	USARTx->CR2 =   (A_InitStruct->StopBits               << USART_CR2_STOP_BIT )  |
					(A_ClockInitStruct->ClockOutput       << USART_CR2_CLKEN_BIT)  |
					(A_ClockInitStruct->ClockPhase        << USART_CR2_CPHA_BIT )  |
					(A_ClockInitStruct->ClockPolarity     << USART_CR2_CPOL_BIT )  |
					(A_ClockInitStruct->LastBitClockPulse << USART_CR2_LBCL_BIT )  ;
	/*---------------------------------------------------------------------------------------------------*/
	/* Clear Status Register SR for Sure (Clear all Flags) */
	USARTx->SR = 0;
}

/************************************************************************************************/
/* Function Name   : USART_Enable                                                               */
/* Description     : Enable USARTx                                                              */
/* Fun. Argument1  : USART_t *USARTx { Pointer to Struct }                                      */
/* Struct1 Elements: {UART1 , UART2 , UART6 }                                                   */
/* Fun. Return     : void                                                                       */
/************************************************************************************************/
void USART_Enable(USART_t *USARTx)
{
	SET_BIT(USARTx->CR1,USART_CR1_UE_BIT);	    // Enable USARTx 
}

/************************************************************************************************/
/* Function Name   : USART_Disable                                                              */
/* Description     : Disable USARTx                                                             */
/* Fun. Argument1  : USART_t *USARTx { Pointer to Struct }                                      */
/* Struct1 Elements: {UART1 , UART2 , UART6 }                                                   */
/* Fun. Return     : void                                                                       */
/************************************************************************************************/
void USART_Disable(USART_t *USARTx)
{
	CLEAR_BIT(USARTx->CR1,USART_CR1_UE_BIT);   // Disable USARTx
}

/************************************************************************************************/
/* Function Name   : USART_voidTransmitByte                                                     */
/* Description     : Transmit Byte by USARTx                                                    */
/* Fun. Argument1  : USART_t *USARTx { Pointer to Struct }                                      */
/* Struct1 Elements: {UART1 , UART2 , UART6 }                                                   */
/* Fun. Argument2  : A_u8Byte { u8 Data }                                                       */
/* Fun. Return     : void                                                                       */
/************************************************************************************************/
void USART_voidTransmitByte (USART_t *USARTx,u8 A_u8Byte)
{
	/* Polling While Transmit data register is empty */
	while ((GET_BIT(USARTx->SR,USART_SR_TXE_BIT))==0);

	/* Write Data on Data Register */
	USARTx->DR= A_u8Byte;

	/* Polling While Transmission complete */
	while ((GET_BIT(USARTx->SR,USART_SR_TC_BIT))==0);

	/* Clear Transmission complete Flag */
	CLEAR_BIT(USARTx->SR,USART_SR_TC_BIT);
}

/************************************************************************************************/
/* Function Name   : USART_voidTransmitString                                                   */
/* Description     : Transmit String by USARTx                                                  */
/* Fun. Argument1  : USART_t *USARTx { Pointer to Struct }                                      */
/* Struct1 Elements: {UART1 , UART2 , UART6 }                                                   */
/* Fun. Argument2  : A_u8Byte { u8 * string }                                                   */
/* Fun. Return     : void                                                                       */
/************************************************************************************************/
void USART_voidTransmitString (USART_t *USARTx, u8 * A_ptru8String )
{
	u8 Local_u8Iterator =0;
	while (A_ptru8String[Local_u8Iterator] != '\0')
	{
		USART_voidTransmitByte(USARTx, A_ptru8String[Local_u8Iterator]);
		Local_u8Iterator++;
	}
}

/************************************************************************************************/
/* Function Name   : USART_u8ReceiveByteSynchNonBlocking                                        */
/* Description     : Receive Byte Synchronous NonBlocking by USARTx                             */
/* Fun. Argument1  : USART_t *USARTx { Pointer to Struct }                                      */
/* Struct1 Elements: {UART1 , UART2 , UART6 }                                                   */
/* Fun. Return     : u8 Recieved Data                                                           */
/************************************************************************************************/
u8 USART_u8ReceiveByteSynchNonBlocking ( USART_t *USARTx )
{
	u8 Local_u8Data = 0;
	u32 Local_u8TimeOut = 0;
	while (((GET_BIT(USARTx->SR,USART_SR_RXNE_BIT))==0) && (Local_u8TimeOut < THRESHOLD_VALUE) )
	{
		Local_u8TimeOut++;
	}
	if (Local_u8TimeOut == THRESHOLD_VALUE)
	{
		Local_u8Data = 255;
	}
	else
	{
		Local_u8Data = USARTx->DR;
	}
	return Local_u8Data;
}

/************************************************************************************************/
/* Function Name   : USART_ptrReceiveStringSynchNonBlocking                                     */
/* Description     : Receive String Synchronous NonBlocking by USARTx                           */
/* Fun. Argument1  : USART_t *USARTx { Pointer to Struct }                                      */
/* Struct1 Elements: {UART1 , UART2 , UART6 }                                                   */
/* Fun. Return     : u8 * Recieved String                                                       */
/************************************************************************************************/
void USART_ptrReceiveStringSynchNonBlocking ( USART_t *USARTx , u8 A_pADataString[] )
{
	u8 loc_Iterator = 0 , loc_u8DataCome ;
	while( loc_u8DataCome != 255 )
	{
		loc_u8DataCome = USART_u8ReceiveByteSynchNonBlocking(USARTx);
		A_pADataString[ loc_Iterator ] = loc_u8DataCome ;
		loc_Iterator++;
	}
	A_pADataString[loc_Iterator] = '\0';
}

/************************************************************************************************/
/* Function Name   : USART_u8ReadDataRegister                                                   */
/* Description     : Receive Data from USARTx                                                   */
/* Fun. Argument1  : USART_t *USARTx { Pointer to Struct }                                      */
/* Struct1 Elements: { UART1 , UART2 , UART6 }                                                  */
/* Fun. Return     : u8  Received Data                                                          */
/************************************************************************************************/
u8 USART_u8ReadDataRegister(USART_t *USARTx)
{
	return USARTx -> DR ;
}

/************************************************************************************************/
/* Function Name   : USART_voidClearFlags                                                       */
/* Description     : Clear All Flag for USARTx                                                  */
/* Fun. Argument1  : USART_t *USARTx { Pointer to Struct }                                      */
/* Struct1 Elements: { UART1 , UART2 , UART6 }                                                  */
/* Fun. Return     : void                                                                       */
/************************************************************************************************/
void USART_voidClearFlags(USART_t *USARTx)
{
	USARTx -> SR = 0 ;
}

/************************************************************************************************/
/* Function Name   : USART_RxIntSetStatus                                                       */
/* Description     : Enable or Disable for RX for USARTx                                        */
/* Fun. Argument1  : USART_t *USARTx { Pointer to Struct }                                      */
/* Struct1 Elements: { UART1 , UART2 , UART6 }                                                  */
/* Fun. Argument2  : copy_u8Status { ENABLE , DISABLE }                                         */
/* Fun. Return     : void                                                                       */
/************************************************************************************************/
void USART_RxIntSetStatus(USART_t *USARTx, u8 copy_u8Status)
{
	switch (copy_u8Status)
	{
		case ENABLE:  SET_BIT(USARTx->CR1 ,(USART_CR1_RXNEIE_BIT)); break;
		case DISABLE: CLEAR_BIT(USARTx->CR1 ,(USART_CR1_RXNEIE_BIT)); break;
	}

}

/*==============================================================================================*/
/*================================    Call Back Functions   ====================================*/
/*==============================================================================================*/
void USART1_voidSetCallBack( void (*ptr) (void) )
{
	USART1_CallBack = ptr ;
}
void USART2_voidSetCallBack( void (*ptr) (void) )
{
	USART2_CallBack = ptr ;
}
void USART6_voidSetCallBack( void (*ptr) (void) )
{
	USART6_CallBack = ptr ;
}

/*==============================================================================================*/
/*===================================    IRQ Functions   =======================================*/
/*==============================================================================================*/
void USART1_IRQHandler(void)
{
	UART1 -> SR = 0 ;		// Clear Flags
	USART1_CallBack();		// Call Back
}

void USART2_IRQHandler(void)
{
	UART2 -> SR = 0 ;		// Clear Flags
	USART2_CallBack();		// Call Back
}

void USART6_IRQHandler(void)
{
	UART6 -> SR = 0 ;		// Clear Flags
	USART6_CallBack();		// Call Back
}
