/******************************************************************************
 *
 * Module: PORT
 *
 * File Name: MCAL_Port.c
 *
 * Description: The Driver Configure All port pins in the microcontroller
 *
 * Author: Basma Ashraf
 *
 *******************************************************************************/
/**********************************************************************************************************************
 * 										 INCLUDES
 *********************************************************************************************************************/
#include "MCAL_PORT.h"

/**********************************************************************************************************************
 *  												LOCAL DATA
 *********************************************************************************************************************/
static const U32 GPIO_PORT_BASE[6]   = {GPIO_PORTA,GPIO_PORTB,GPIO_PORTC,GPIO_PORTD,GPIO_PORTE,GPIO_PORTF};

/******************************************************************************
* Syntax          : void Port_Init(const Port_ConfigType* configPtr)
* Description     : initialize configurations of GPIO pins
* Sync\Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : const Port_ConfigType* configPtr
* Parameters (out): None
* Return value:   : None
*******************************************************************************/
void Port_Init(void){
    U8 count;
    U32 Port_ID;
    U32 Pin_ID;

    for(count = 0; count < NUM_OF_CHANNELS ; count++){

        Port_ID = ( (U32)(Port_Config[count].channelID) / 8);
        Pin_ID = ( (U32)(Port_Config[count].channelID) % 8);

       

        /*unlock the commit*/
        GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIOLOCK) = LOCK;
        GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIOCR) |= (1<< Pin_ID);

        /*setting mode*/
        switch(Port_Config[count].mode){
            case PORT_PIN_MODE_DIO:{
                GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIODEN) &= ~(1U << Pin_ID); //clear Pin before inserting value
                GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIODEN) |= (1<< Pin_ID);  //inserting value
                break;
            }
        }

        /* setting Direction */
        GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIODIR) &= ~(1U << Pin_ID); //clear Pin direction before inserting
        GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIODIR) |= ( (U32) Port_Config[count].direction << Pin_ID);    //writing the direction

        /*setting internal attach*/
        switch (Port_Config[count].internalAttach)
        {
        case PORT_INTERNAL_ATTACH_PULLUP:
            GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIOPUR) |= (1<< Pin_ID);  //inserting value
            break;
        case PORT_INTERNAL_ATTACH_PULLDOWN:
            GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIOPDR) |= (1<< Pin_ID);  //inserting value
            break;
        case PORT_INTERNAL_ATTACH_OPENDRAIN:
            GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIOODR) |= (1<< Pin_ID);  //inserting value
            break;
        case PORT_INTERNAL_ATTACH_PUSHPULL:
            break;            
        }

         /*setting current*/
        switch (Port_Config[count].outputCurrent)
        {
        case PORT_PIN_OUTPUT_CURRENT_2MA:
            GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIODR2R) |= (1<< Pin_ID);  //inserting value
            break;

        case PORT_PIN_OUTPUT_CURRENT_4MA:
            GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIODR4R) |= (1<< Pin_ID);  //inserting value
            break;

        case PORT_PIN_OUTPUT_CURRENT_8MA:
            GPIO_REG(GPIO_PORT_BASE[Port_ID],GPIODR8R) |= (1<< Pin_ID);  //inserting value
            break;
        }
    }
}
/*******************************************************************************************************************************************************************************************************/
