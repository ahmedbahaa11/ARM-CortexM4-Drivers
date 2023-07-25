/*=================================================================================*/
/*  File        : EXTI_Program.c                                                   */
/*  Description : This file includes EXTI Driver implementations for stm32f401CC   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 20/5/2023                                                        */
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
#include "../RCC/RCC_Interface.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h" 
/*==========================================*/
static void (*EXTI_APF[16])(void) = {NULL};  

/************************************************************************************************/
/* Function Name   : EXTI_u8PinInit                                                             */
/* Description     : Init Specific PIN at Specific PORT as an EXTI PIN                          */
/* Fun. Argument1  : EXTI_PinConfig_t * Copy_pstrPinInit { Pointer to Struct }                  */
/* Struct Element1 : PortID        -> { EXTI_GPIOA , EXTI_GPIOB , EXTI_GPIOC }                  */
/* Struct Element2 : PinID         -> { from EXTI_PIN0 -> EXTI_PIN15 }                          */
/* Struct Element3 : TriggerLevel  -> { EXTI_FALLING_EDGE, EXTI_RAISING_EDGE, EXTI_ON_CHANGE }  */
/* Struct Element4 : void (*PF)(void)  -> { CALLBACK Function to IRQHandler }                   */
/* Fun. Return     : Local_u8ErrorStatus                                                        */
/************************************************************************************************/
u8 EXTI_u8PinInit (const EXTI_PinConfig_t * Copy_pstrPinInit)
{
    u8 Local_u8ErrorStatus = STD_TYPES_OK ;
    u8 Local_u8ShiftValue ;
    if ( Copy_pstrPinInit != NULL || Copy_pstrPinInit->PinID <= EXTI_PIN15 || Copy_pstrPinInit->PortID <= EXTI_GPIOC )
    {
        /*---------------------------------------------------------------------------------------------------*/
        /* Enable Clock to SYSCFG Peripheral */
    	RCC_voidEnablePeripheralClock(APB2,RCC_SYSCFG);
        /*---------------------------------------------------------------------------------------------------*/
        /* Enable Interrupt */
        EXTI_u8EnableINT(Copy_pstrPinInit->PinID);
        /*---------------------------------------------------------------------------------------------------*/
        /* Set SYSCFG to select the PORT */
        Local_u8ShiftValue = (Copy_pstrPinInit->PinID % 4) * 4 ;
        SYSCFG->EXTICR[(Copy_pstrPinInit->PinID / 4)] &= ~( 0b1111 << Local_u8ShiftValue ) ;                       // Clear the 4 Bits Before Modified
        SYSCFG->EXTICR[(Copy_pstrPinInit->PinID / 4)] |=  ( (Copy_pstrPinInit->PortID) << Local_u8ShiftValue ) ;   // Set the 4 Bits of the Port {0b0000,0b0001,0b0010}
        /*---------------------------------------------------------------------------------------------------*/
        /* Select Trigger Source (FALLING_EDGE , RAISING_EDGE , ON_CHANGE )*/
        switch (Copy_pstrPinInit->TriggerLevel)
        {
            case EXTI_FALLING_EDGE :
                                    CLEAR_BIT(EXTI->RTSR , Copy_pstrPinInit->PinID);
                                    SET_BIT(EXTI->FTSR , Copy_pstrPinInit->PinID);
                                    break;
            case EXTI_RAISING_EDGE :
                                    CLEAR_BIT(EXTI->FTSR , Copy_pstrPinInit->PinID);
                                    SET_BIT(EXTI->RTSR , Copy_pstrPinInit->PinID);
                                    break;
            case EXTI_ON_CHANGE    :
                                    SET_BIT(EXTI->RTSR , Copy_pstrPinInit->PinID);
                                    SET_BIT(EXTI->FTSR , Copy_pstrPinInit->PinID);
                                    break;
            default                :
                                    break;
        }
        /*---------------------------------------------------------------------------------------------------*/
        /* Set Global Pointer to Function */
        EXTI_APF[Copy_pstrPinInit->PinID] = Copy_pstrPinInit->PF ;
        /*---------------------------------------------------------------------------------------------------*/
    }
    else
    {
        Local_u8ErrorStatus = STD_TYPES_NOK ;
    }
    return Local_u8ErrorStatus ;
}

/************************************************************************************************/
/* Function Name : EXTI_u8EnableINT                                                             */
/* Description   : Enable INT Linex from Line0 to Line15                                        */
/* Fun. Argument1: Copy_u8EXTINum { from EXTI_PIN0 -> EXTI_PIN15 }                              */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
u8 EXTI_u8EnableINT (u8 Copy_u8EXTINum)
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8EXTINum <= EXTI_PIN15)
    {
        SET_BIT(EXTI->IMR , Copy_u8EXTINum);
    }
    else
    {   Local_u8ErrorState = STD_TYPES_NOK;    }
    return Local_u8ErrorState ;
}

/************************************************************************************************/
/* Function Name : EXTI_u8DisableINT                                                            */
/* Description   : Disable INT Linex from Line0 to Line15                                       */
/* Fun. Argument1: Copy_u8EXTINum { from EXTI_PIN0 -> EXTI_PIN15 }                              */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
u8 EXTI_u8DisableINT (u8 Copy_u8EXTINum)
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8EXTINum <= EXTI_PIN15)
    {
        CLEAR_BIT(EXTI->IMR , Copy_u8EXTINum);
    }
    else
    {   Local_u8ErrorState = STD_TYPES_NOK ;   }
    return Local_u8ErrorState ;
}

/************************************************************************************************/
/* Function Name : EXTI_u8ClearPendingFlag                                                      */
/* Description   : Clear Pending Flag to Linex from Line0 to Line15                             */
/* Fun. Argument1: Copy_u8EXTINum { from EXTI_PIN0 -> EXTI_PIN15 }                              */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
u8 EXTI_u8ClearPendingFlag (u8 Copy_u8EXTINum)
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8EXTINum <= EXTI_PIN15)
    {
        SET_BIT(EXTI->PR , Copy_u8EXTINum);
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    return Local_u8ErrorState ;
}

/*==============================================================================================*/
/*==================================         IRQ Handlers         ==============================*/
/*==============================================================================================*/
/***************************************/
/* Function Name : EXTI0_IRQHandler    */
/***************************************/
void EXTI0_IRQHandler (void)
{
    if ( EXTI_APF[0] != NULL )
    {
        EXTI_APF[0]();
    }
    /* Clear Pending Flag */
    EXTI_u8ClearPendingFlag(0);
}
/***************************************/
/* Function Name : EXTI1_IRQHandler    */
/***************************************/
void EXTI1_IRQHandler (void)
{
    if ( EXTI_APF[1] != NULL )
    {
        EXTI_APF[1]();
    }
    /* Clear Pending Flag */
    EXTI_u8ClearPendingFlag(1);
}
/***************************************/
/* Function Name : EXTI2_IRQHandler    */
/***************************************/
void EXTI2_IRQHandler (void)
{
    if ( EXTI_APF[2] != NULL )
    {
        EXTI_APF[2]();
    }
    /* Clear Pending Flag */
    EXTI_u8ClearPendingFlag(2);
}
/***************************************/
/* Function Name : EXTI3_IRQHandler    */
/***************************************/
void EXTI3_IRQHandler (void)
{
    if ( EXTI_APF[3] != NULL )
    {
        EXTI_APF[3]();
    }
    /* Clear Pending Flag */
    EXTI_u8ClearPendingFlag(3);
}
/***************************************/
/* Function Name : EXTI4_IRQHandler    */
/***************************************/
void EXTI4_IRQHandler (void)
{
    if ( EXTI_APF[4] != NULL )
    {
        EXTI_APF[4]();
    }
    /* Clear Pending Flag */
    EXTI_u8ClearPendingFlag(4);
}
/***************************************/
/* Function Name : EXTI9_5_IRQHandler  */
/***************************************/
void EXTI9_5_IRQHandler(void)
{
    if ( EXTI_APF[5] != NULL )
    {
        EXTI_APF[5]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(5);
    }
    if ( EXTI_APF[6] != NULL )
    {
        EXTI_APF[6]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(6);
    }
    if ( EXTI_APF[7] != NULL )
    {
        EXTI_APF[7]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(7);
    }
    if ( EXTI_APF[8] != NULL )
    {
        EXTI_APF[8]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(8);
    }
    if ( EXTI_APF[9] != NULL )
    {
        EXTI_APF[9]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(9);
    } 
}
/*****************************************/
/* Function Name : EXTI15_10_IRQHandler  */
/*****************************************/
void EXTI15_10_IRQHandler(void)
{
    if ( EXTI_APF[10] != NULL )
    {
        EXTI_APF[10]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(10);
    }
    if ( EXTI_APF[11] != NULL )
    {
        EXTI_APF[11]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(11);
    }
    if ( EXTI_APF[12] != NULL )
    {
        EXTI_APF[12]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(12);
    }
    if ( EXTI_APF[13] != NULL )
    {
        EXTI_APF[13]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(13);
    }
    if ( EXTI_APF[14] != NULL )
    {
        EXTI_APF[14]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(14);
    } 
    if ( EXTI_APF[15] != NULL )
    {
        EXTI_APF[15]();
        /* Clear Pending Flag */
        EXTI_u8ClearPendingFlag(15);
    } 
}
/*==============================================================================================*/





