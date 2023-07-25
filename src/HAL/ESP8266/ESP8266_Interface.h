/*=================================================================================*/
/*  File        : ESP8266_Interface.c                                              */
/*  Description : interface file includes ESP8266 Driver prototypes for stm32f401CC*/
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 19/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd*/
#ifndef ESP8266_INTERFACE_H_
#define ESP8266_INTERFACE_H_


void ESP8266_voidInit(void);
u8 voidESPValidateCMD(void);
void ESP8266_vConnectToRouter(u8* SSID , u8* Password);
void ESP8266_vOpenServerTCPConnection(u8* ServerIP, u8* PortNo);
void ESP8266_vSendHTTPRequest(u8* URL , u8* Length , u8 Data[] );


#endif
