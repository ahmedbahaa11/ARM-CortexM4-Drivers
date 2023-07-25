/*=================================================================================*/
/*  File        : RCC_Private.c                                                    */
/*  Description : This Private file includes RCC Driver macros for stm32f401CC     */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 10/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/
/*============     RCC Base Address    ============*/
#define RCC_BASE_ADDRESS                0x40023800                
/*============     [RCC] Registers     ============*/
#define RCC_CR           *((volatile u32*)(RCC_BASE_ADDRESS+0x00))  // RCC clock control register (RCC_CR)
#define RCC_PLLCEGR      *((volatile u32*)(RCC_BASE_ADDRESS+0x04))  // RCC PLL configuration register (RCC_PLLCFGR)
#define RCC_CFGR         *((volatile u32*)(RCC_BASE_ADDRESS+0x08))  // RCC clock configuration register (RCC_CFGR)
#define RCC_AHB1ENR      *((volatile u32*)(RCC_BASE_ADDRESS+0x30))  // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
#define RCC_AHB2ENR      *((volatile u32*)(RCC_BASE_ADDRESS+0x34))  // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
#define RCC_APB1ENR      *((volatile u32*)(RCC_BASE_ADDRESS+0x40))  // RCC APB1 peripheral clock enable register (RCC_APB1ENR)
#define RCC_APB2ENR      *((volatile u32*)(RCC_BASE_ADDRESS+0x44))  // RCC APB1 peripheral clock enable register (RCC_APB1ENR)
/*================================================================================================================*/
#define HSI                         0
#define HSE_OSC                     1
#define HSE_RC                      2
#define PLL                         3
/*================================================================================================================*/

#endif