/*=================================================================================*/
/*  File        : RCC_Program.c                                                    */
/*  Description : This file includes RCC Driver implementations for stm32f401CC    */
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
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"
/*==========================================*/

/*======================================================================================================================*/
/*====================================     A.BAHAA RCC Functions Implementation      ===================================*/
/*======================================================================================================================*/
/********************************************    RCC_voidInitSystemClock            *************************************/
/********************************************    RCC_voidEnablePeripheralClock      *************************************/ 
/********************************************    RCC_voidDisablePeripheralClock     *************************************/ 
/*======================================================================================================================*/

/************************************************************************************************/
/* Function Name : RCC_voidInitSystemClock                                                      */
/* Description : Initilization of RCC to initialize System clock                                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void RCC_voidInitSystemClock (void)
{
    #if  (RCC_CLOCK_SOURCE == HSI) 
        SET_BIT(RCC_CR,0U);                  // Enable HSI (Set HSI BIT) 
        /* Select HSI as Sys CLOCK Source */
        CLEAR_BIT(RCC_CFGR,0U);              
        CLEAR_BIT(RCC_CFGR,1U);
    #elif (RCC_CLOCK_SOURCE == HSE_OSC) 
        CLEAR_BIT(RCC_CR,16U);               // Disable HSE Before Configer bypassing
        CLEAR_BIT(RCC_CR,18U);               // Not bypassed
        SET_BIT(RCC_CR,16U);                 // Enable HSE (Set HSE BIT)
        /* Select HSE as System CLOCK Source */
        SET_BIT(RCC_CFGR,0U);
        CLEAR_BIT(RCC_CFGR,1U);
    #elif  (RCC_CLOCK_SOURCE == HSE_RC) 
        CLEAR_BIT(RCC_CR,16U);               // Disable HSE Before Configer bypassing
        SET_BIT(RCC_CR,18U);                 // bypassed
        SET_BIT(RCC_CR,16U);                 // Enable HSE (Set HSE BIT)
        /* Select HSE as System CLOCK Source */
        SET_BIT(RCC_CFGR,0U);
        CLEAR_BIT(RCC_CFGR,1U);
    #elif  (RCC_CLOCK_SOURCE == PLL) 

    #else
        #error Invalid Clock Source 
    #endif

    #if( AHB_PRESCALLER ==  system_clock_divided_by_2 )
        CLEAR_BIT(RCC_CFGR,4);
        CLEAR_BIT(RCC_CFGR,5);
        CLEAR_BIT(RCC_CFGR,6);
          SET_BIT(RCC_CFGR,7);
    #elif ( AHB_PRESCALLER == system_clock_divided_by_4 )
          SET_BIT(RCC_CFGR,4);
        CLEAR_BIT(RCC_CFGR,5);
        CLEAR_BIT(RCC_CFGR,6);
          SET_BIT(RCC_CFGR,7);
    #elif ( AHB_PRESCALLER == system_clock_divided_by_8 )
        CLEAR_BIT(RCC_CFGR,4);
          SET_BIT(RCC_CFGR,5);
        CLEAR_BIT(RCC_CFGR,6);
          SET_BIT(RCC_CFGR,7);
    #endif
}

/************************************************************************************************/
/* Function Name : RCC_voidEnablePeripheralClock                                                */
/* Description : Enable clock source to specific Bus and spesific Peripheral                    */
/* Fun. Argument1: Copy_u8BusID { AHB1,AHB2,APB1,APB2 }                                         */
/* Fun. Argument2: Copy_u8PeripheralID { from 0 -> 32 according to Pheripheral }                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void RCC_voidEnablePeripheralClock ( u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
    /* Input Validation */
    if( Copy_u8PeripheralID > 31 )
    {
        // Nothing to be Done
    }
    else
    {
        switch(Copy_u8BusID)
        {
            case AHB1 :   SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);   break;
            case AHB2 :   SET_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);   break;
            case APB1 :   SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID);   break;
            case APB2 :   SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID);   break;
            default :                                                 break;
        }
    }
}

/************************************************************************************************/
/* Function Name : RCC_voidDisablePeripheralClock                                               */
/* Description : Disable clock source to specific Bus and spesific Peripheral                   */
/* Fun. Argument1: Copy_u8BusID { AHB1,AHB2,APB1,APB2 }                                         */
/* Fun. Argument2: Copy_u8PeripheralID { from 0 -> 32 according to Pheripheral }                */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void RCC_voidDisablePeripheralClock ( u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
    /* Input Validation */
    if( Copy_u8PeripheralID > 31 )
    {
        // Nothing to be Done
    }
    else
    {
        switch(Copy_u8BusID)
        {
            case AHB1 :   CLEAR_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);   break;
            case AHB2 :   CLEAR_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);   break;
            case APB1 :   CLEAR_BIT(RCC_APB1ENR,Copy_u8PeripheralID);   break;
            case APB2 :   CLEAR_BIT(RCC_APB2ENR,Copy_u8PeripheralID);   break;
            default :                                                   break;
        }
    }
}