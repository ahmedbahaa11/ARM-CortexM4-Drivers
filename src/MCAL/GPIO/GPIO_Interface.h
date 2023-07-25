/*=================================================================================*/
/*  File        : GPIO_Interface.c                                                 */
/*  Description : interface file includes GPIO Driver prototypes for stm32f401CC   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 12/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/

/* File Gaurd*/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*====================================================================================================*/
/*===========================     A.BAHAA GPIO Functions Prototypes      =============================*/
/*====================================================================================================*/
/*********************************    GPIO_voidPinInit                   ******************************/
/*********************************    GPIO_voidSetPinMode                ******************************/ 
/*********************************    GPIO_voidSetPinType                ******************************/ 
/*********************************    GPIO_voidSetPinSpeed               ******************************/ 
/*********************************    GPIO_voidSetPinValueNonAtomic      ******************************/ 
/*********************************    GPIO_voidSetPinValueAtomic         ******************************/ 
/*********************************    GPIO_u8GetPinValue                 ******************************/ 
/*********************************    GPIO_voidPortInit                  ******************************/ 
/*********************************    GPIO_voidSetPortMode               ******************************/ 
/*********************************    GPIO_voidSetPortType               ******************************/
/*********************************    GPIO_voidSetPortSpeed              ******************************/
/*====================================================================================================*/

/*==============================================================================================*/
/* ==============================        Init Functions          ===============================*/
/*==============================================================================================*/
/************************************************************************************************/
/* Function Name : GPIO_voidPinInit                                                             */
/* Description : Inilization of Pin {Mode,Type,Speed}                                           */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Argument4: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Argument5: Copy_u8Speed {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidPinInit(u8 Copy_u8PortID ,u8 Copy_u8PinID ,u8 Copy_u8Mode ,u8 Copy_u8Type ,u8 Copy_u8Speed);

/************************************************************************************************/
/* Function Name : GPIO_voidSetPinMode                                                          */
/* Description : Inilization of Pin {Mode}                                                      */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPinMode(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Mode );

/************************************************************************************************/
/* Function Name : GPIO_voidSetPinType                                                          */
/* Description : Inilization of Pin {Type}                                                      */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPinType(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Type );

/************************************************************************************************/
/* Function Name : GPIO_voidSetPinSpeed                                                         */
/* Description : Inilization of Pin {Speed}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Speed  {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPinSpeed(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Speed );

/************************************************************************************************/
/* Function Name : GPIO_voidPortInit                                                            */
/* Description : Inilization of Port {Mode,Type,Speed}                                          */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Argument3: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Argument4: Copy_u8Speed {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidPortInit(u8 Copy_u8PortID ,u8 Copy_u8Mode ,u8 Copy_u8Type ,u8 Copy_u8Speed);

/************************************************************************************************/
/* Function Name : GPIO_voidSetPortMode                                                         */
/* Description : Inilization of Port {Mode}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortMode(u8 Copy_u8PortID , u8 Copy_u8Mode );

/************************************************************************************************/
/* Function Name : GPIO_voidSetPortType                                                         */
/* Description : Inilization of Port {Type}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortType(u8 Copy_u8PortID , u8 Copy_u8Type );

/************************************************************************************************/
/* Function Name : GPIO_voidSetPortSpeed                                                        */
/* Description : Inilization of Port {Speed}                                                    */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Speed  {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortSpeed(u8 Copy_u8PortID , u8 Copy_u8Speed );



/*========================================================================================*/
/* ===========================         Write Modules          ============================*/
/*========================================================================================*/
/******************************************************************************************/
/* Function Name : GPIO_voidSetPinValueNonAtomic                                          */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                         */
/* Fun. Argument3: Copy_u8Value { HIGH , LOW }                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPinValueNonAtomic(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value );

/******************************************************************************************/
/* Function Name : GPIO_voidSetPinValueAtomic                                             */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                         */
/* Fun. Argument3: Copy_u8Value { SET , RST }                                             */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPinValueAtomic(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value );

void GPIO_voidSetPortValueu8NonAtomic (u8 Copy_u8PortID,u8 Copy_u8Value);

/*==========================================================================*/
/*======================         Read Modules          =====================*/
/*==========================================================================*/
/****************************************************************************/
/* Function Name : GPIO_u8GetPinValue                                       */
/* Description : Read pin value from one bit of the Port register           */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                      */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                           */
/* Fun. Return :  unsigned char   { HIGH , LOW }                            */
/****************************************************************************/
u8 GPIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID );


/*===============================*/
#define     INPUT               0
#define     OUTPUT              1
#define     ALTERNATE           2
#define     ANALOG              3
/*===============================*/
#define     GPIOA               0
#define     GPIOB               1
#define     GPIOC               2
/*===============================*/
#define     PUSH_PULL           0
#define     OPEN_DRAIN          1
#define     NO_PULL_UP_DOWM     2
#define     PULL_UP             3
#define     PULL_DOWN           4
/*===============================*/
#define     LOW_SPEED           0
#define     MEDIUM_SPEED        1
#define     HIGH_SPEED          2
/*===============================*/
#define     PIN0                0 
#define     PIN1                1 
#define     PIN2                2 
#define     PIN3                3 
#define     PIN4                4 
#define     PIN5                5 
#define     PIN6                6 
#define     PIN7                7 
#define     PIN8                8 
#define     PIN9                9 
#define     PIN10               10
#define     PIN11               11
#define     PIN12               12
#define     PIN13               13
#define     PIN14               14
#define     PIN15               15
/*===============================*/
#define     AF0                0
#define     AF1                1
#define     AF2                2
#define     AF3                3
#define     AF4                4
#define     AF5                5
#define     AF6                6
#define     AF7                7
#define     AF8                8
#define     AF9                9
#define     AF10               10
#define     AF11               11
#define     AF12               12
#define     AF13               13
#define     AF14               14
#define     AF15               15
/*===============================*/
#define     SET                 0
#define     RST                 1
/*===============================*/
#define     LOW                 0
#define     HIGH                1
/*===============================*/

#endif