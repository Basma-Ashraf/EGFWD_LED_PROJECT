/******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port_Types.h
 *
 * Description: contain Types related to the Interrupt PORT driver
 *
 * Author: Basma Ashraf
 *
 *******************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 *												 INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  										GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define LOCK    0x4C4F434B

/**********************************************************************************************************************
 *  									GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    PORT_CHANNEL_A0,     //0
    PORT_CHANNEL_A1,
    PORT_CHANNEL_A2,
    PORT_CHANNEL_A3,
    PORT_CHANNEL_A4,
    PORT_CHANNEL_A5,
    PORT_CHANNEL_A6,
    PORT_CHANNEL_A7,

    PORT_CHANNEL_B0,     //8
    PORT_CHANNEL_B1,
    PORT_CHANNEL_B2,
    PORT_CHANNEL_B3,
    PORT_CHANNEL_B4,
    PORT_CHANNEL_B5,
    PORT_CHANNEL_B6,
    PORT_CHANNEL_B7,

    PORT_CHANNEL_C0,     //16
    PORT_CHANNEL_C1,
    PORT_CHANNEL_C2,
    PORT_CHANNEL_C3,
    PORT_CHANNEL_C4,
    PORT_CHANNEL_C5,
    PORT_CHANNEL_C6,
    PORT_CHANNEL_C7,

    PORT_CHANNEL_D0,     //24
    PORT_CHANNEL_D1,
    PORT_CHANNEL_D2,
    PORT_CHANNEL_D3,
    PORT_CHANNEL_D4,
    PORT_CHANNEL_D5,
    PORT_CHANNEL_D6,
    PORT_CHANNEL_D7,

    PORT_CHANNEL_E0,     //32
    PORT_CHANNEL_E1,
    PORT_CHANNEL_E2,
    PORT_CHANNEL_E3,
    PORT_CHANNEL_E4,
    PORT_CHANNEL_E5,

    PORT_CHANNEL_F0 = 40,     //38
    PORT_CHANNEL_F1,
    PORT_CHANNEL_F2,
    PORT_CHANNEL_F3,
    PORT_CHANNEL_F4
}Port_ChannelType;

typedef enum 
{
    PORT_PIN_DIRECTION_INPUT = 0,
    PORT_PIN_DIRECTION_OUTPUT = 1
}Port_PinDirectionType;

typedef enum
{
 PORT_PIN_MODE_DIO = 0,
}Port_PinModeType;

typedef enum
{
    PORT_INTERNAL_ATTACH_PULLUP = 0,
    PORT_INTERNAL_ATTACH_PULLDOWN = 1,
    PORT_INTERNAL_ATTACH_OPENDRAIN = 2,
    PORT_INTERNAL_ATTACH_PUSHPULL = 3
}Port_PinInternalAttachType;

typedef enum
{   
    PORT_PIN_OUTPUT_CURRENT_2MA = 0,
    PORT_PIN_OUTPUT_CURRENT_4MA = 1,
    PORT_PIN_OUTPUT_CURRENT_8MA = 2
}Port_PinOutputCurrentType;
 
#endif  /* PORT_TYPES_H */
