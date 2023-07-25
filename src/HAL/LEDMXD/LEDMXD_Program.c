/*=================================================================================*/
/*  File        : LEDMXD_Program.c                                                 */
/*  Description : This file includes LEDMXD Driver implementations for stm32f401CC */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 24/5/2023                                                        */
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
#include "LEDMXD_Interface.h"
#include "LEDMXD_Private.h"
#include "LEDMXD_Config.h"
/*==========================================*/

void LEDMXD_voidInit(void)
{
    /* Set Mode for Rows Pins */
    for ( u8 iter = 0 ; iter < 8 ; iter++ )
    {   GPIO_voidPinInit(LEDMXD_ROWs_GPIO,iter,OUTPUT,PUSH_PULL,LOW_SPEED);  }
    /* Set Mode for Cols Pins */
    for ( u8 iter = 0 ; iter < 11 ; iter++ )
    {
        if ( iter == 2 || iter == 3 || iter == 4 )
        {continue;}
        GPIO_voidPinInit(LEDMXD_COLs_GPIO,iter,OUTPUT,PUSH_PULL,LOW_SPEED);
    }
}

void LEDMXD_u8Display(u8 * Copy_pu8Data)
{
	for (u8 i=0 ; i<6 ; i++) 		// for 1 second make 50 iteration // for 100msec -> i=5
	{
		u8 ArrayIteration = 0 ;
		for ( u8 iter = 0 ; iter < 11 ; iter++ )
		{
			if ( iter == 2 || iter == 3 || iter == 4 )
			{   continue;   }
			/* Disable All Columns */
			LEDMXD_voidDisableAllColumns();
			/* Set Row Value */
			LEDMXD_voidSetRowsValues(Copy_pu8Data[ArrayIteration]);
			/* Activate Column */
			GPIO_voidSetPinValueNonAtomic(LEDMXD_COLs_GPIO,iter,LOW);
			/* Delay for 2.5 msec */
			STK_voidSetBusyWait(2500);
			/* Increment Iteration of Array */
			ArrayIteration ++ ;
		}
	}
}

void LEDMXD_voidDisableAllColumns(void)
{
    for ( u8 iter = 0 ; iter < 11 ; iter++ )
    {
        if ( iter == 2 || iter == 3 || iter == 4 )
        {   continue;   }
        GPIO_voidSetPinValueNonAtomic(LEDMXD_COLs_GPIO,iter,HIGH);
    }
}
static void LEDMXD_voidSetRowsValues(u8 Copy_u8Value)
{
    /* Set Copy_u8Value on 8Pins of 8Rows */
	GPIO_voidSetPortValueu8NonAtomic(LEDMXD_ROWs_GPIO,Copy_u8Value);
}