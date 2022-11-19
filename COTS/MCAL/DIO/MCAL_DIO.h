/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: MCAL_DIO.h
 *
 * Description: Header file for DIO Driver
 *
 * Author: Basma Ashraf
 *
 *******************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 *                             						INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef U8   Dio_PortLevelType;



typedef enum
{
    DIO_CHANNEL_A0 = 0,     //0
    DIO_CHANNEL_A1,
    DIO_CHANNEL_A2,
    DIO_CHANNEL_A3,
    DIO_CHANNEL_A4,
    DIO_CHANNEL_A5,
    DIO_CHANNEL_A6,
    DIO_CHANNEL_A7,

    DIO_CHANNEL_B0,          //8
    DIO_CHANNEL_B1,
    DIO_CHANNEL_B2,
    DIO_CHANNEL_B3,
    DIO_CHANNEL_B4,
    DIO_CHANNEL_B5,
    DIO_CHANNEL_B6,
    DIO_CHANNEL_B7,

    DIO_CHANNEL_C0,    		 //16
    DIO_CHANNEL_C1,
    DIO_CHANNEL_C2,
    DIO_CHANNEL_C3,
    DIO_CHANNEL_C4,
    DIO_CHANNEL_C5,
    DIO_CHANNEL_C6,
    DIO_CHANNEL_C7,

    DIO_CHANNEL_D0,     	//24
    DIO_CHANNEL_D1,
    DIO_CHANNEL_D2,
    DIO_CHANNEL_D3,
    DIO_CHANNEL_D4,
    DIO_CHANNEL_D5,
    DIO_CHANNEL_D6,
    DIO_CHANNEL_D7,

    DIO_CHANNEL_E0,    		 //32
    DIO_CHANNEL_E1,
    DIO_CHANNEL_E2,
    DIO_CHANNEL_E3,
    DIO_CHANNEL_E4,
    DIO_CHANNEL_E5,

    DIO_CHANNEL_F0 = 40,     	//38
    DIO_CHANNEL_F1,
    DIO_CHANNEL_F2,
    DIO_CHANNEL_F3,
    DIO_CHANNEL_F4
}Dio_ChannelType;




typedef enum
{
   DIO_PORTA,
   DIO_PORTB,
   DIO_PORTC,
   DIO_PORTD,
   DIO_PORTE,
   DIO_PORTF

}Dio_PortType;


typedef enum
{
    DIO_LOW = 0,
    DIO_HIGH = 1

}Dio_LevelType;


/**********************************************************************************************************************
 *  									GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define GPIO_REG(GPIO_BASE,REG_OFF)       *((volatile U32*)(GPIO_BASE + REG_OFF))

/**********************************************************************************************************************
 * 										 GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
void GPIO_EnableClock(Dio_PortType portID);

Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelID);

void Dio_WriteChannel(Dio_ChannelType channelID, Dio_LevelType level);

Dio_PortLevelType Dio_ReadPort(Dio_PortType portID);

void Dio_WritePort(Dio_PortType portID, Dio_PortLevelType level );

Dio_LevelType Dio_FlipChannel(Dio_ChannelType channelID);

#endif  /* DIO_H */
