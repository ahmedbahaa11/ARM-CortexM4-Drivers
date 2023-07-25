/*=================================================================================*/
/*  File        : UART_Interface.c                                                 */
/*  Description : interface file includes UART Driver prototypes for stm32f401CC   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 19/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd*/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*============================================*/
/*============ 	 UART BAUDRATES   ============*/
/*============================================*/
typedef enum{
    B_1200   = 0x44505400,
    B_2400   = 0x43d05800,
    B_9600   = 0x683,
    B_19200  = 0x42504000,
    B_38400  = 0x41d08000,
    B_57600  = 0x418b0000,
    B_115200 = 0x410b0000
}u_BaudRate_t;
/*=============================================*/
/*======== 	 USART Register Structure   =======*/
/*=============================================*/
typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_t;
/*=============================================*/
/*=====   The USART Structure Pointer 	=======*/
/*=============================================*/
#define 	UART1 		((USART_t *)0x40011000)
#define 	UART2 		((USART_t *)0x40014400)
#define 	UART6 		((USART_t *)0x40011400)
/*=============================================*/
/*========   The USART Init Parameters   ======*/
/*=============================================*/
typedef struct
{
	u32 BaudRate;
	u8 DataWidth;
	u8 StopBits;
	u8 Parity_Enable;
	u8 Parity_Selection;
	u8 TransferDirection; 	// TX_ONLY  RX_ONLY  TX_RX
	u8 HardwareFlowControl;
	u8 Oversampling;
}USART_InitType;
/*=============================================*/
/*=======   The USART Clock Parameters   ======*/
/*=============================================*/
typedef struct
{
	u8 ClockOutput;
	u8 ClockPolarity;
	u8 ClockPhase;
	u8 LastBitClockPulse;
}USART_ClockInitTypeDef;
/*==================================*/
/*=========   Oversampling  ========*/
/*==================================*/
#define OVER_SAMPLING_16	0
#define OVER_SAMPLING_8 	1
/*==================================*/
/*=========   DataWidth   ==========*/
/*==================================*/
#define MODE_8BIT			0
#define MODE_9BIT			1
/*==================================*/
/*=========  Parity Enable  ========*/
/*==================================*/
#define DISABLE				0
#define ENABLE				1
/*==================================*/
/*=======  Parity Selection  =======*/
/*==================================*/
#define EVEN_PARITY         0
#define ODD_PARITY          1
/*==================================*/
/*=======  Transfer Direction ======*/
/*==================================*/
#define TX_ONLY             0
#define RX_ONLY             1
#define TX_RX               2
/*==================================*/
/*===========  Stop Bits  ==========*/
/*==================================*/
#define STOP_BIT_1			0
#define STOP_BIT_0_5		1
#define STOP_BIT_2			2
#define STOP_BIT_1_5		3
/*==================================*/


void USART_voidInit(USART_InitType *A_InitStruct,USART_ClockInitTypeDef *A_ClockInitStruct,USART_t *USARTx);
void USART_Enable(USART_t *USARTx);
void USART_voidTransmitByte (USART_t *USARTx,u8 A_u8Byte);
void USART_voidTransmitString (USART_t *USARTx, u8 * A_ptru8String );
u8 USART_u8ReceiveByteSynchNonBlocking ( USART_t *USARTx );
void USART_ptrReceiveStringSynchNonBlocking ( USART_t *USARTx , u8 A_pADataString[] );
void USART_RxIntSetStatus(USART_t *USARTx, u8 copy_u8Status);
void USART_voidClearFlags(USART_t *USARTx);
u8 USART_u8ReadDataRegister(USART_t *USARTx);
void USART1_voidSetCallBack( void (*ptr) (void) );
void USART2_voidSetCallBack( void (*ptr) (void) );
void USART6_voidSetCallBack( void (*ptr) (void) );


#endif 
