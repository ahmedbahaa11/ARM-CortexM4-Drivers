/*==================================================================================*/
/*  File        : SYSTICK_Config.c                                                  */
/*  Description : This file includes SYSTICK Driver implementations for stm32f401CC */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                       */
/*  Date        : 13/5/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                         */
/*  Git account : https://github.com/ahmedbahaa11                                   */
/*  mail        : abahaa14842@gmil.com                                              */
/*==================================================================================*/

/* File Gaurd*/
#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

/*==============================================*/
/*============  Select SYSTIC Source   =========*/
/*==============================================*/
#define AHB_CLOCK                           0
#define AHB_CLOCK_DividedBy_8               1
/*==============================================*/
#define STK_CLOCK_SOURCE    AHB_CLOCK_DividedBy_8
/*==============================================*/


#endif