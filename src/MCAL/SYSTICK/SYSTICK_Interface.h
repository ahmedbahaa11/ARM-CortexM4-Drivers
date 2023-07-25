/*==================================================================================*/
/*  File        : SYSTICK_Interface.c                                               */
/*  Description : interface file includes SYSTICK Driver prototypes for stm32f401CC */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                       */
/*  Date        : 13/5/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                         */
/*  Git account : https://github.com/ahmedbahaa11                                   */
/*  mail        : abahaa14842@gmil.com                                              */
/*==================================================================================*/

/* File Gaurd*/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

/*====================================================================================================*/
/*==========================     A.BAHAA SYSTICK Functions Prototypes      ===========================*/
/*====================================================================================================*/
/*********************************    STK_voidInit                       ******************************/
/*********************************    STK_voidSetBusyWait                ******************************/ 
/*********************************    STK_voidSetIntervalSingle          ******************************/ 
/*********************************    STK_voidSetIntervalPeriodic        ******************************/ 
/*********************************    STK_voidStopInterval               ******************************/ 
/*********************************    STK_u32GetElapsedTime              ******************************/ 
/*********************************    STK_u32GetRemainingTime            ******************************/ 
/*********************************    SysTick_Handler                    ******************************/ 
/*====================================================================================================*/


void STK_voidInit (void);
void STK_voidSetBusyWait(u32 Copy_u32TimeMs);
void STK_voidSetIntervalSingle  (u32 Copy_u32TimeMs,void (*Copy_ptr)(void));
void STK_voidSetIntervalPeriodic(u32 Copy_u32TimeMs,void (*Copy_ptr)(void));
void STK_voidStopInterval (void);
u32  STK_u32GetElapsedTime (void);
u32  STK_u32GetRemainingTime (void);


#endif