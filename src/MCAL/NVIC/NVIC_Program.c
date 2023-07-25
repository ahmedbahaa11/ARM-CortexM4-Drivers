/*=================================================================================*/
/*  File        : NVIC_Program.c                                                   */
/*  Description : This file includes NVIC Driver implementations for stm32f401CC   */
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
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"
/*==========================================*/
/* Global Variable */
u8 Global_u8PriorityOption = 0;

/*====================================================================================================*/
/*=========================     A.BAHAA NVIC Functions Implementation      ===========================*/
/*====================================================================================================*/

/************************************************************************************************/
/* Function Name : NVIC_voidEnablePeripheralINT                                                 */
/* Description   : Enable Interrupt to Peripheral                                               */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
u8 NVIC_voidEnablePeripheralINT (u8 Copy_u8INTID)
{
    u8 Local_u8ErrorStatus = STD_TYPES_OK ;
    /* I/P Validation */
    if (Copy_u8INTID < 240)
    {
        NVIC->ISER[(Copy_u8INTID / 32)] = ( 1 << (Copy_u8INTID % 32)) ;
    }
    else
    {
        Local_u8ErrorStatus = STD_TYPES_NOK ;
    }
    return Local_u8ErrorStatus ;
}

/************************************************************************************************/
/* Function Name : NVIC_voidDisablePeripheralINT                                                */
/* Description   : Disable Interrupt to Peripheral                                              */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
u8 NVIC_voidDisablePeripheralINT (u8 Copy_u8INTID)
{
    u8 Local_u8ErrorStatus = STD_TYPES_OK ;
    /* I/P Validation */
    if (Copy_u8INTID < 240)
    {
        NVIC->ICER[(Copy_u8INTID / 32)] = ( 1 << (Copy_u8INTID % 32)) ;
    }
    else
    {
        Local_u8ErrorStatus = STD_TYPES_NOK ;
    }
    return Local_u8ErrorStatus ;
}

/************************************************************************************************/
/* Function Name : NVIC_voidSetPendingFlag                                                      */
/* Description   : Set Pending Flag to any INT for Testing usage                                */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
u8 NVIC_voidSetPendingFlag (u8 Copy_u8INTID)
{
    u8 Local_u8ErrorStatus = STD_TYPES_OK ;
    /* I/P Validation */
    if (Copy_u8INTID < 240)
    {
        NVIC->ISPR[(Copy_u8INTID / 32)] = ( 1 << (Copy_u8INTID % 32)) ;
    }
    else
    {
        Local_u8ErrorStatus = STD_TYPES_NOK ;
    }
    return Local_u8ErrorStatus ;
}

/************************************************************************************************/
/* Function Name : NVIC_voidClearPendingFlag                                                    */
/* Description   : Clear Pending Flag                                                           */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
u8 NVIC_voidClearPendingFlag (u8 Copy_u8INTID)
{
    u8 Local_u8ErrorStatus = STD_TYPES_OK ;
    /* I/P Validation */
    if (Copy_u8INTID < 240)
    {
        NVIC->ICPR[(Copy_u8INTID / 32)] = ( 1 << (Copy_u8INTID % 32)) ;
    }
    else
    {
        Local_u8ErrorStatus = STD_TYPES_NOK ;
    }
    return Local_u8ErrorStatus ;
}

/************************************************************************************************/
/* Function Name : NVIC_voidSetPriorityConfig                                                   */
/* Description   : Set Software Grouping Priority Configration                                  */
/* Fun. Argument1: Copy_u8PriorityOption                                                        */                
/*               (16 GR - 0  SubGR)    GR4BITS_SubGR0BITS   ->   0b011  (3)                     */
/*               (8  GR - 2  SubGR)    GR3BITS_SubGR1BITS   ->   0b100  (4)                     */
/*               (4  GR - 4  SubGR)    GR2BITS_SubGR2BITS   ->   0b101  (5)                     */
/*               (2  GR - 8  SubGR)    GR1BITS_SubGR3BITS   ->   0b110  (6)                     */
/*               (0  GR - 16 SubGR)    GR0BITS_SubGR4BITS   ->   0b111  (7)                     */                                                        
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
u8 NVIC_voidSetPriorityConfig (u8 Copy_u8PriorityOption)
{
    u8 Local_u8ErrorStatus = STD_TYPES_OK ;
    /* I/P Validation */
    if( Copy_u8PriorityOption < 3 || Copy_u8PriorityOption > 7 )
    {
        Local_u8ErrorStatus = STD_TYPES_NOK ;
    }
    else
    {
        Global_u8PriorityOption = Copy_u8PriorityOption ;
        SCB_AIRCR = VECTOR_KEY | (Copy_u8PriorityOption << 8) ;
    }
    return Local_u8ErrorStatus ;
}

/************************************************************************************************/
/* Function Name : NVIC_voidSetINTPriority                                                      */
/* Description   : Set Software Priority for Peripheral INT                                     */
/* Fun. Argument1: Copy_u8INTID { from 0 -> 240 | interface file enum(WWDG -> SPI4) }           */
/* Fun. Argument2: Copy_u8GroupID    { from 0 -> 16 }                                           */
/* Fun. Argument2: Copy_u8SubGroupID { from 0 -> 16 }                                           */
/* Fun. Return   : Local_u8ErrorStatus                                                          */
/************************************************************************************************/
u8 NVIC_voidSetINTPriority (u8 Copy_u8INTID , u8 Copy_u8GroupID , u8 Copy_u8SubGroupID)
{
    u8 Local_u8ErrorStatus = STD_TYPES_OK ;
    /* I/P Validation */
    if (Copy_u8INTID < 240)
    {
        u8 Local_u8Priority = Copy_u8SubGroupID | (Copy_u8GroupID << (Global_u8PriorityOption - GR4BITS_SubGR0BITS)) ;
        NVIC -> IPR[Copy_u8INTID] = (Local_u8Priority << 4) ;
    }
    else
    {
        Local_u8ErrorStatus = STD_TYPES_NOK ;
    }
    return Local_u8ErrorStatus ;
}
