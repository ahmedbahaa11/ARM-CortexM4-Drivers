/*=================================================================================*/
/*  File        : SYSTICK_Private.c                                                */
/*  Description : This Private file includes SYSTICK Driver macros for stm32f401CC */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 13/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd*/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/
#define     STK_CTRL             *((volatile u32*)0xE000E010)
#define     STK_LOAD             *((volatile u32*)0xE000E014)
#define     STK_VAL              *((volatile u32*)0xE000E018)
#define     STK_CALIB            *((volatile u32*)0xE000E01C)
/*================================================================================================================*/
/*==============================================*/
#define STK_SingleInterval          1
#define STK_PeriodicInterval        2
/*==============================================*/

#define NULL        ((void*)(0))

#endif