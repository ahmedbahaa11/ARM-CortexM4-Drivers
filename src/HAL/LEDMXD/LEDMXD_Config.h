/*=================================================================================*/
/*  File        : LEDMXD_Config.c                                                  */
/*  Description : This file includes LEDMXD Driver implementations for stm32f401CC */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 24/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd */
#ifndef LEDMXD_CONFIG_H
#define LEDMXD_CONFIG_H

/*==========================================*/ 
/*==========   PIN Configrations   =========*/
/*=======  Options { PIN0...PIN15 }  =======*/
/*-------   ROW PINs   -------*/
#define LEDMXD_ROW0         PIN0  
#define LEDMXD_ROW1         PIN1 
#define LEDMXD_ROW2         PIN2 
#define LEDMXD_ROW3         PIN3 
#define LEDMXD_ROW4         PIN4 
#define LEDMXD_ROW5         PIN5 
#define LEDMXD_ROW6         PIN6 
#define LEDMXD_ROW7         PIN7   
/*-------   COL PINs   -------*/
#define LEDMXD_COL0         PIN0  
#define LEDMXD_COL1         PIN1 
#define LEDMXD_COL2         PIN5 
#define LEDMXD_COL3         PIN6 
#define LEDMXD_COL4         PIN7 
#define LEDMXD_COL5         PIN8 
#define LEDMXD_COL6         PIN9 
#define LEDMXD_COL7         PIN10
/*==========================================*/ 
/*========  GPIO Port Configration  ========*/
/*=====  Options { GPIOA,GPIOB,GPIOC}  =====*/
#define LEDMXD_ROWs_GPIO        GPIOA 
#define LEDMXD_COLs_GPIO        GPIOB  
/*==========================================*/     

#endif