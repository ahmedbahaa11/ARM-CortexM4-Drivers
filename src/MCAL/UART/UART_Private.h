/*=================================================================================*/
/*  File        : UART_Private.c                                                   */
/*  Description : This Private file includes UART Driver macros for stm32f401CC    */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 19/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/* File Gaurd*/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/*====================================================================================================*/
/*===============================================================*/
/*==========================   SR BITS   ========================*/
/*===============================================================*/
#define  USART_SR_PE_BIT	0   // Parity error					
#define  USART_SR_FE_BIT	1   // Framing error					
#define  USART_SR_NE_BIT	2   // Noise error flag				
#define  USART_SR_ORE_BIT	3   // Overrun error					
#define  USART_SR_IDLE_BIT	4   // IDLE line detected				
#define  USART_SR_RXNE_BIT	5   // Read data register not empty	
#define  USART_SR_TC_BIT	6   // Transmission complete			
#define  USART_SR_TXE_BIT	7   // Transmit data register empty	
#define  USART_SR_LBD_BIT	8   // LIN break detection flag		
#define  USART_SR_CTS_BIT	9   // CTS flag						
/*===============================================================*/
/*==========================   CR1 BITS   =======================*/
/*===============================================================*/
#define  USART_CR1_SBK_BIT	    0   // Send break	bit	
#define  USART_CR1_RWU_BIT	    1   // Recevier Wakeup	bit	
#define  USART_CR1_RE_BIT	    2   // Recevier Enable bit	
#define  USART_CR1_TE_BIT	    3   // Transmitter Enable bit	
#define  USART_CR1_IDLEIE_BIT	4   // IDLE interrupt enable bit	
#define  USART_CR1_RXNEIE_BIT	5   // RXNEIE interrupt enable bit	
#define  USART_CR1_TCIE_BIT		6   // Transmission complete interrupt enable bit	
#define  USART_CR1_TXEIE_BIT	7   // TXE interrupt enable bit	
#define  USART_CR1_PEIE_BIT		8   // PE interrupt enable bit	
#define  USART_CR1_PS_BIT		9   // Parity selection bit	
#define  USART_CR1_PCE_BIT		10  // Parity control enable bit	
#define  USART_CR1_WAKE_BIT		11  // Wakeup method bit	
#define  USART_CR1_M_BIT		12  // Word length bit	
#define  USART_CR1_UE_BIT		13  // USART enable bit	
#define  USART_CR1_OVER8_BIT    15  // USART Oversampling bit	
/*===============================================================*/
/*==========================   CR2 BITS   =======================*/
/*===============================================================*/
#define  USART_CR2_ADD0_BIT		0    // Address of the USART node bit0
#define  USART_CR2_ADD1_BIT		1    // Address of the USART node bit1
#define  USART_CR2_ADD2_BIT		2    // Address of the USART node bit2
#define  USART_CR2_ADD3_BIT		3    // Address of the USART node bit3
#define  USART_CR2_LBDL_BIT	    5    //	lin break detection length bit	
#define  USART_CR2_LBDIE_BIT    6    //	LIN break detection interrupt enable bit	
#define  USART_CR2_LBCL_BIT		8    //	Last bit clock pulse bit	
#define  USART_CR2_CPHA_BIT		9    //	Clock phase bit	
#define  USART_CR2_CPOL_BIT		10   //	Clock polarity bit	
#define  USART_CR2_CLKEN_BIT	11   //	Clock enable bit	
#define  USART_CR2_STOP_BIT		12   //	STOP bit start 
#define  USART_CR2_STOP0_BIT	12   //	STOP bit0 	
#define  USART_CR2_STOP1_BIT	13   //	STOP bit1 
#define  USART_CR2_LINEN_BIT	14   //	LIN mode enable bit	
/*===============================================================*/
/*==========================   CR3 BITS   =======================*/
/*===============================================================*/
#define  USART_CR3_CTSIE_BIT	10   //	CTS interrupt enable bit	
#define  USART_CR3_CTSE_BIT		9    //	CTS enable bit	
#define  USART_CR3_RTSE_BIT		8    //	RTS enable bit	
#define  USART_CR3_DMAT_BIT		7    //	DMA enable transmitter bit	
#define  USART_CR3_DMAR_BIT		6    //	DMA enable receiver bit	
#define  USART_CR3_SCEN_BIT		5    //	Smartcard mode enable bit	
#define  USART_CR3_NACK_BIT		4    //	Smartcard NACK enable bit	
#define  USART_CR3_HDSEL_BIT	3    //	Half-duplex selection bit	
#define  USART_CR3_IRLP_BIT		2    //	IrDA low-power bit	
#define  USART_CR3_IREN_BIT		1    //	IrDA mode enable bit	
#define  USART_CR3_EIE_BIT		0    //	Error interrupt enable bit	
/*===============================================================*/

#endif /* UART_PRIVATE_H_ */
