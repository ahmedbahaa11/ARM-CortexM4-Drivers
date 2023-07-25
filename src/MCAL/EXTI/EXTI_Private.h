/*=================================================================================*/
/*  File        : EXTI_Private.c                                                   */
/*  Description : This Private file includes EXTI Driver macros for stm32f401CC    */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 20/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd*/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/*================================================================================================================*/
/**************************************       Private Macros & struct       ***************************************/
/*================================================================================================================*/
/*==================================================================================================*/
/*----------------------------------------(     EXTI     )------------------------------------------*/
/*==================================================================================================*/
/*============     EXTI Base Address     ============*/
#define EXTI_BASE_ADDRESS                0x40013C00        // EXTI Base Adress
/*============     [EXTI] Registers      ============*/
typedef struct 
{
    volatile u32 IMR ;              // Interrupt mask register (EXTI_IMR)
    volatile u32 EMR ;              // Event mask register (EXTI_EMR) 
    volatile u32 RTSR ;             // Rising trigger selection register (EXTI_RTSR)
    volatile u32 FTSR ;             // Falling trigger selection register (EXTI_FTSR) 
    volatile u32 SWIER ;            // Software interrupt event register (EXTI_SWIER) 
    volatile u32 PR ;               // Pending register (EXTI_PR) 
}EXTI_RegDef_t;
#define EXTI               ((EXTI_RegDef_t *)EXTI_BASE_ADDRESS)    
 
/*================================================================================================================*/
/*-----------------------------------------------(     SYSCFG     )-----------------------------------------------*/
/*================================================================================================================*/
/*============     SYSCFG Base Address     ============*/
#define SYSCFG_BASE_ADDRESS                 0x40013800       // SYSCFG Base Adress
/*============     [SYSCFG] Registers      ============*/
typedef struct 
{
    volatile u32 MEMRMP ;
    volatile u32 PMC ;
    volatile u32 EXTICR[4] ;
    volatile u32 CMPCR ;
}SYSCFG_RegDef_t;
#define SYSCFG                 ((SYSCFG_RegDef_t *)SYSCFG_BASE_ADDRESS) 
/*================================================================================================================*/



#endif