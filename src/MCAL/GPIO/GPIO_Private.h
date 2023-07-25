/*=================================================================================*/
/*  File        : GPIO_Private.c                                                   */
/*  Description : This Private file includes GPIO Driver macros for stm32f401CC    */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 12/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd*/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/
/*============     GPIO Base Address     ============*/
#define GPIOA_BASE_ADDRESS                0x40020000                            // GPIOA Base Adress
#define GPIOB_BASE_ADDRESS                0x40020400                            // GPIOB Base Adress
#define GPIOC_BASE_ADDRESS                0x40020800                            // GPIOC Base Adress

typedef struct
{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_MemMap_t;

#define GPIOA_REG     ((volatile GPIO_MemMap_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB_REG     ((volatile GPIO_MemMap_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC_REG     ((volatile GPIO_MemMap_t*)(GPIOC_BASE_ADDRESS))


/*============     [GPIOA] Registers     ============*/
// #define GPIOA_MODER             *((volatile u32*)(GPIOA_BASE_ADDRESS+0x00))     // GPIOA port mode register (GPIOA_MODER)
// #define GPIOA_OTYPER            *((volatile u32*)(GPIOA_BASE_ADDRESS+0x04))     // GPIOA port output type register (GPIOA_OTYPER) 
// #define GPIOA_OSPEEDR           *((volatile u32*)(GPIOA_BASE_ADDRESS+0x08))     // GPIOA port output speed register (GPIOA_OSPEEDR) 
// #define GPIOA_ODR               *((volatile u32*)(GPIOA_BASE_ADDRESS+0x14))     // GPIOA port output data register (GPIOA_ODR) 
// #define GPIOA_BSRR              *((volatile u32*)(GPIOA_BASE_ADDRESS+0x18))     // GPIOA port bit set/reset register (GPIOA_BSRR) 
// #define GPIOA_INPUT_TYPE        *((volatile u32*)(GPIOA_BASE_ADDRESS+0x0C))     // GPIOA port pull-up/pull-down register (GPIOA_PUPDR) 
// #define GPIOA_IDR               *((volatile u32*)(GPIOA_BASE_ADDRESS+0x10))     // GPIOA port input data register (GPIOA_IDR) 
// /*============     [GPIOB] Registers     ============*/
// #define GPIOB_MODER             *((volatile u32*)(GPIOB_BASE_ADDRESS+0x00))     // GPIOB port mode register (GPIOB_MODER)  
// #define GPIOB_OTYPER            *((volatile u32*)(GPIOB_BASE_ADDRESS+0x04))     // GPIOB port output type register (GPIOB_OTYPER)   
// #define GPIOB_OSPEEDR           *((volatile u32*)(GPIOB_BASE_ADDRESS+0x08))     // GPIOB port output speed register (GPIOB_OSPEEDR)   
// #define GPIOB_ODR               *((volatile u32*)(GPIOB_BASE_ADDRESS+0x14))     // GPIOB port output data register (GPIOB_ODR)   
// #define GPIOB_BSRR              *((volatile u32*)(GPIOB_BASE_ADDRESS+0x18))     // GPIOB port bit set/reset register (GPIOB_BSRR)   
// #define GPIOB_INPUT_TYPE        *((volatile u32*)(GPIOB_BASE_ADDRESS+0x0C))     // GPIOB port pull-up/pull-down register (GPIOB_PUPDR)   
// #define GPIOB_IDR               *((volatile u32*)(GPIOB_BASE_ADDRESS+0x10))     // GPIOB port input data register (GPIOB_IDR)  
// /*============     [GPIOC] Registers     ============*/
// #define GPIOC_MODER             *((volatile u32*)(GPIOC_BASE_ADDRESS+0x00))     // GPIOC port mode register (GPIOC_MODER)  
// #define GPIOC_OTYPER            *((volatile u32*)(GPIOC_BASE_ADDRESS+0x04))     // GPIOC port output type register (GPIOC_OTYPER)   
// #define GPIOC_OSPEEDR           *((volatile u32*)(GPIOC_BASE_ADDRESS+0x08))     // GPIOC port output speed register (GPIOC_OSPEEDR)   
// #define GPIOC_ODR               *((volatile u32*)(GPIOC_BASE_ADDRESS+0x14))     // GPIOC port output data register (GPIOC_ODR)   
// #define GPIOC_BSRR              *((volatile u32*)(GPIOC_BASE_ADDRESS+0x18))     // GPIOC port bit set/reset register (GPIOC_BSRR)   
// #define GPIOC_INPUT_TYPE        *((volatile u32*)(GPIOC_BASE_ADDRESS+0x0C))     // GPIOC port pull-up/pull-down register (GPIOC_PUPDR)   
// #define GPIOC_IDR               *((volatile u32*)(GPIOC_BASE_ADDRESS+0x10))     // GPIOC port input data register (GPIOC_IDR)  
/*================================================================================================================*/



#endif