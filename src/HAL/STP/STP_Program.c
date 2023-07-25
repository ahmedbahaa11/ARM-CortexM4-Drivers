/*=================================================================================*/
/*  File        : RCC_Program.c                                                    */
/*  Description : This file includes STP Driver implementations for stm32f401CC    */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 10/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/*==========================================*/
/* Include Header Files From include Folder */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*==========================================*/
/*   Include Header Files From MCAL Folder  */
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"
/*==========================================*/
#include "../include/stm32F401CC.h"
#include "STP_Interface.h"
#include "STP_Private.h"
#include "STP_Config.h"
/*==========================================*/

void STP_voidInit(void)
{
    /* Config Pin A0,A1,A2 as Output */
    GPIO_voidPinInit(STP_SERIAL_DATA,OUTPUT,PUSH_PULL,LOW_SPEED);
    GPIO_voidPinInit(STP_STORE_CLOCK,OUTPUT,PUSH_PULL,LOW_SPEED);
    GPIO_voidPinInit(STP_SHIFT_CLOCK,OUTPUT,PUSH_PULL,LOW_SPEED);
}

void STP_voidSendSynchronus(u8 Copy_u8DataToBeSent)
{
    s8 Local_s8Counter ;
    u8 Local_u8Bit ;
    for( Local_s8Counter = 7 ; Local_s8Counter >= 0 ; Local_s8Counter-- )
    {
        Local_u8Bit = GET_BIT(Copy_u8DataToBeSent, Local_s8Counter);
        GPIO_voidSetPinValueAtomic(STP_SERIAL_DATA,Local_u8Bit);
        /* Send Pulse To Shift Clock */
        GPIO_voidSetPinValueAtomic(STP_SHIFT_CLOCK,SET);
        STK_voidSetBusyWait(1);
        GPIO_voidSetPinValueAtomic(STP_SHIFT_CLOCK,RST);
        STK_voidSetBusyWait(1);
    }
    /* Send pulse to Store Clock */
    GPIO_voidSetPinValueAtomic(STP_STORE_CLOCK,SET);
    STK_voidSetBusyWait(1);
    GPIO_voidSetPinValueAtomic(STP_STORE_CLOCK,RST);
    STK_voidSetBusyWait(1);
}