/*=================================================================================*/
/*  File        : RCC_Config.c                                                    */
/*  Description : This file includes RCC Driver implementations for stm32f401CC    */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 10/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/


/* File Gaurd*/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*=======================================*/
/*=========  Configration List   ========*/
/*=== { HSI , HSE_OSC , HSE_RC , PLL } ==*/
/*=======================================*/
#define RCC_CLOCK_SOURCE    HSI
/*=======================================*/
/*=======================================*/
/*=========    AHB Prescaller    ========*/
#define system_clock_divided_by_2           0
#define system_clock_divided_by_4           1
#define system_clock_divided_by_8           2
/*=======================================*/
#define AHB_PRESCALLER      system_clock_divided_by_2
/*=======================================*/


#endif