/*=================================================================================*/
/*  File        : NVIC_Private.c                                                   */
/*  Description : This Private file includes NVIC Driver macros for stm32f401CC    */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 19/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd*/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
/*================================================================================================================*/
/**************************************       Private Macros & struct       ***************************************/
/*================================================================================================================*/
typedef struct NVIC_Private
{
    volatile u32 ISER[32];
    volatile u32 ICER[32];
    volatile u32 ISPR[32];
    volatile u32 ICPR[32];
    volatile u32 IABR[32];
    volatile u32  RES[32];
    volatile u8  IPR[240];                                // to access byte by byte
    
}NVIC_t;
#define NVIC            ((volatile NVIC_t*)0xE000E100)    // First address of NVIC struct
#define SCB_AIRCR         *((volatile u32*)0xE000ED0C)    // SCB System Control Block 
#define VECTOR_KEY                         0x05FA0000     // VEKTOR KEY To access SCB_AIRCR
/*================================================================================================================*/
#endif