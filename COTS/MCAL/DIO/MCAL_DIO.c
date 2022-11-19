/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO.c
 *
 * Description: The Driver Configure All DIO pins write/read/flip channels
 *
 * Author: Basma Ashraf
 *
 *******************************************************************************/

/**********************************************************************************************************************
 *  											INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "MCAL_DIO.h"

/**********************************************************************************************************************
 *                                              LOCAL DATA
 *********************************************************************************************************************/

static const U32 GPIO_PORT_BASE[6] = {GPIO_PORTA,GPIO_PORTB,GPIO_PORTC,GPIO_PORTD,GPIO_PORTE,GPIO_PORTF};


/******************************************************************************
* Syntax          : DIO_LevelType Dio_ReadChannel(Dio_ChannelType channelID)
* Description     : Read the value of specific channel (pin in port)
* Sync\Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Dio_ChannelType channelID
* Parameters (out): None
* Return value:   : DIO_LevelType
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelID){

    U8 Port_ID = channelID / 8;
    U8 Pin_ID = channelID % 8;

    return GPIO_REG( GPIO_PORT_BASE[Port_ID], GPIODATA + ( 1 << (2 + Pin_ID) ) );
}



/******************************************************************************
* Syntax          : void Dio_WriteChannel(Dio_ChannelType channelID, DIO_LevelType level)
* Description     : write value in specific channel (pin in port)
* Sync\Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Dio_ChannelType channelID, DIO_LevelType level
* Parameters (out): None
* Return value:   : None
*******************************************************************************/

void Dio_WriteChannel(Dio_ChannelType channelID, Dio_LevelType level){

    U32 Port_ID = ((U32) channelID) / 8;
    U32 Pin_ID = ((U32) channelID) % 8;

    GPIO_REG(GPIO_PORT_BASE[Port_ID], GPIODATA) =  (U32)level << Pin_ID ;
}



/******************************************************************************
* Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType portID)
* Description     : Read the value of specific Port
* Sync\Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Dio_PortType portID
* Parameters (out): None
* Return value:   : Dio_PortLevelType  {0 - 255}
*******************************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType portID){

    return GPIO_REG( GPIO_PORT_BASE[portID], GPIODATA + (255 <<2) );

}



/******************************************************************************
* Syntax          : void Dio_WritePort(Dio_PortType portID, Dio_PortLevelType level )
* Description     : write value on specific port
* Sync\Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Dio_PortType portID, Dio_PortLevelType level
* Parameters (out): None
* Return value:   : None
*******************************************************************************/

void Dio_WritePort(Dio_PortType portID, Dio_PortLevelType level){

    GPIO_REG( GPIO_PORT_BASE[portID], GPIODATA + (255 <<2) ) = level;

}



/******************************************************************************
* Syntax          : DIO_LevelType Dio_FlipChannel(Dio_ChannelType channelID)
* Description     : toggle the value of specific channel (pin in port)
* Sync\Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Dio_ChannelType channelID
* Parameters (out): None
* Return value:   : DIO_LevelType
*******************************************************************************/

Dio_LevelType Dio_FlipChannel(Dio_ChannelType channelID){
    U8 Port_ID = channelID / 8;
    U8 Pin_ID = channelID % 8;
    U8 current_level = GPIO_REG( GPIO_PORT_BASE[Port_ID], GPIODATA + ( 1 << (2 + Pin_ID) ) );
  
	TOGGLE_BIT(GPIO_REG( GPIO_PORT_BASE[Port_ID], GPIODATA ), Pin_ID);
	
		return ((U8) (1 ^ current_level) << Pin_ID );

}
