/*=================================================================================*/
/*  File        : NVIC_Interface.c                                                 */
/*  Description : interface file includes NVIC Driver prototypes for stm32f401CC   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 19/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd*/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*====================================================================================================*/
/*============================     A.BAHAA NVIC Functions Prototypes      ============================*/
/*====================================================================================================*/
u8 NVIC_voidEnablePeripheralINT (u8 Copy_u8INTID);
u8 NVIC_voidDisablePeripheralINT (u8 Copy_u8INTID);
u8 NVIC_voidSetPendingFlag (u8 Copy_u8INTID);
u8 NVIC_voidClearPendingFlag (u8 Copy_u8INTID);
u8 NVIC_voidSetPriorityConfig (u8 Copy_u8PriorityOption);
u8 NVIC_voidSetINTPriority (u8 Copy_u8INTID , u8 Copy_u8GroupID , u8 Copy_u8SubGroupID);
/*====================================================================================================*/
/*=================================     A.BAHAA NVIC User Macros      ================================*/
/*====================================================================================================*/
#define GR4BITS_SubGR0BITS    0b011   //(3)
#define GR3BITS_SubGR1BITS    0b100   //(4)
#define GR2BITS_SubGR2BITS    0b101   //(5)
#define GR1BITS_SubGR3BITS    0b110   //(6)
#define GR0BITS_SubGR4BITS    0b111   //(7)
/*====================================================================================================*/
/*=================================     A.BAHAA NVIC User enums      =================================*/
/*====================================================================================================*/
enum
{
	WWDG,
	EXTI16_PVD,
	EXTI21_TAMP_STAMP,
	EXTI22_RTC_WKUP,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	RESERVED19,
	RESERVED20,
	RESERVED21,
	RESERVED22,
	EXTI9_5,
	TIM1_BRK_TIM9,
	TIM1_BRK_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	RESERVED39,
	EXTI15_10,
	EXTI17_RTC_Alarm,
	EXTI18_OTG_FS_WKUP,
	RESERVED43,
	RESERVED44,
	RESERVED45,
	RESERVED46,
	DMA1_Stream7,
	RESERVED48,
	SDIO,
	TIM5,
	SPI3,
	RESERVED52,
	RESERVED53,
	RESERVED54,
	RESERVED55,
	DMA2_Stream0,
	DMA2_Stream1,
	DMA2_Stream2,
	DMA2_Stream3,
	DMA2_Stream4,
	RESERVED61,
	RESERVED62,
	RESERVED63,
	RESERVED64,
	RESERVED65,
	RESERVED66,
	OTG_FS,
	DMA2_Stream5,
	DMA2_Stream6,
	DMA2_Stream7,
	USART6,
	I2C3_EV,
	I2C3_ER,
	RESERVED74,
	RESERVED75,
	RESERVED76,
	RESERVED77,
	RESERVED78,
	RESERVED79,
	RESERVED80,
	FPU,
	RESERVED82,
	RESERVED83,
	SPI4,
};
/*====================================================================================================*/
#endif