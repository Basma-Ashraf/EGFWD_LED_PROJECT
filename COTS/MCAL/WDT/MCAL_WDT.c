/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  MCAL_WDT.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_Types.h"
#include "MCAL_WDT.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Wdg_init(const Wdg_ConfigType * ConfigPtr)
{

    //configure system clock
	

    SysCtlPeripheralEnable(SYSCTL_PERIPH_WDOG1);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_WDOG0));

    
    // Check to see if the registers are locked, and if so, unlock them.
    if(WatchdogLockState(WATCHDOG0_BASE) == true)
	{
	WatchdogUnlock(WATCHDOG0_BASE);
	}
    // Initialize the watchdog timer.
	WatchdogReloadSet(WATCHDOG0_BASE, 0x00FFFFFF); //500ms approx
	// Enable the reset.
	WatchdogResetEnable(WATCHDOG0_BASE);
	// Enable the watchdog timer
	IntEnable(INT_WATCHDOG);
	WatchdogIntEnable(WATCHDOG0_BASE);
	WatchdogEnable(WATCHDOG0_BASE);
	// Wait for the reset to occur.


}
void Wdg_SetTriggerCondition (U16 timeout)
{
//refrech wdg with new timeout
//watchdog timer load register should load it with number of ticks
}

/**********************************************************************************************************************
 *  END OF FILE: MCAL_WDT.c
 *********************************************************************************************************************/
