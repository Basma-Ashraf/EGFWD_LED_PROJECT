/******************************************************************************
 *
 * Module: PORT configurations
 *
 * File Name: MCAL_Port_Config.c
 *
 * Description: Configration port for this project led control
 *
 * Author: Basma Ashraf
 *
 *******************************************************************************/
/**********************************************************************************************************************
 *  											INCLUDES
 *********************************************************************************************************************/
#include "MCAL_Port_Config.h"

const Port_ConfigType Port_Config[NUM_OF_CHANNELS] =
 {
    {
     PORT_CHANNEL_F2,
     PORT_PIN_MODE_DIO,
     PORT_PIN_DIRECTION_OUTPUT,
     PORT_INTERNAL_ATTACH_PUSHPULL,
     PORT_PIN_OUTPUT_CURRENT_2MA
    }


};
