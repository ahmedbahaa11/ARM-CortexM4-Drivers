/*=================================================================================*/
/*  File        : UART_Program.c                                                   */
/*  Description : This file includes UART Driver implementations for stm32f401CC   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 19/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/*==========================================*/
/* Include Header Files From include Folder */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*==========================================*/
#include "../../../include/stm32F401CC.h"
#include "ESP8266_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"
/*==========================================*/

void ESP8266_voidInit(void)
{
	u8 Local_u8Result = 0 ;

	/* disable the Echo */
	while(Local_u8Result == 0)
	{
		USART_voidTransmitString(UART1,"ATE0\r\n");
		Local_u8Result = voidESPValidateCMD();
	}
	Local_u8Result = 0 ;

	/* set Mode: station */
	while(Local_u8Result == 0)
	{
		USART_voidTransmitString(UART1,"AT+CWMODE=1\r\n");
		Local_u8Result = voidESPValidateCMD();
	}
	Local_u8Result = 0 ;

}

u8 voidESPValidateCMD(void)
{
	u8 Local_u8Response[100] = {0};
	u8 iter = 0 ;
	u8 Dummy = 0 ;
	u8 Result = 0 ;
	while( Dummy != 255 )
	{
		Dummy = USART_u8ReceiveByteSynchNonBlocking(UART1);
		Local_u8Response[iter] = Dummy ;
		iter++;
	}

	/* Check if OK */
	if (Local_u8Response[0]=='O'  &&  Local_u8Response[0]=='K')
	{
		Result = 1 ;
	}

	return Result ;
}

void ESP8266_vConnectToRouter(u8* SSID , u8* Password)
{
	USART_voidTransmitString(UART1,"AT+CWJAP_CUR=\"");
	USART_voidTransmitString(UART1,SSID);
	USART_voidTransmitString(UART1,"\",\"");
	USART_voidTransmitString(UART1,Password);
	USART_voidTransmitString(UART1,"\"\r\n");

	/* Delay 5 sec*/
	STK_voidSetBusyWait(5000);
}


void ESP8266_vOpenServerTCPConnection(u8* ServerIP, u8* PortNo)
{
	USART_voidTransmitString(UART1,"AT+CIPSTART=\"TCP\",\"");
	USART_voidTransmitString(UART1,ServerIP);
	USART_voidTransmitString(UART1,"\",");
	USART_voidTransmitString(UART1,PortNo);
	USART_voidTransmitString(UART1,"\r\n");

	/* Delay 1 sec*/
	STK_voidSetBusyWait(1000);
}


void ESP8266_vSendHTTPRequest(u8* URL , u8* Length , u8 Data[] )
{
	USART_voidTransmitString(UART1,"AT+CIPSEND=");
	USART_voidTransmitString(UART1,Length);
	USART_voidTransmitString(UART1,"\r\n");

	/* Delay 0.1 sec*/
	STK_voidSetBusyWait(100);

	USART_voidTransmitString(UART1,URL);
	USART_voidTransmitString(UART1,"\r\n");

	/* Recieving String */
	USART_ptrReceiveStringSynchNonBlocking(UART1,Data);
}











