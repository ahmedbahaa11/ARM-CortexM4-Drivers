/*=================================================================================*/
/*  File        : LEDMXD_Interface.c                                               */
/*  Description : interface file includes LEDMXD Driver prototypes for stm32f401CC */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 24/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd*/
#ifndef LEDMXD_INTERFACE_H
#define LEDMXD_INTERFACE_H

void LEDMXD_voidInit(void);
void LEDMXD_u8Display(u8 * Copy_pu8Data);
void LEDMXD_voidDisableAllColumns(void);
static void LEDMXD_voidSetRowsValues(u8 Copy_u8Value);


#endif