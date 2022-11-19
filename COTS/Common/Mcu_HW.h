 /******************************************************************************
 *
 * Module: Mcu_Hw
 *
 * File Name: Mcu_Hw.h
 *
 * Description: Header file for TivaC Microcontroller Registers definition
 *
 * Author: Basma Ashraf
 ******************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 *                                              INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *                                      GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    U32 VECACT   :8;
    U32          :3;
    U32 RETBASE  :1;
    U32 VECPEND  :3;
    U32          :2;
    U32 ISRPEND  :1;
    U32 ISRPRE   :1;
    U32          :1;
    U32 PENDSTCLR:1;
    U32 PENDSTSET:1;
    U32 UNPENDSV :1;
    U32 PENDSV   :1;
    U32          :2;
    U32 NMISET   :1; 
}INTCTRL_BF;

typedef union 
{
    U32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;




typedef struct{
	U32 EN[5];
	U32 DIS[5];
	U32 PEND[5];
	U32 UNPEND[5];
	U32 ACTIVE[5];
	U32 PRI[35];
    U32 SWTRIG;
}NVIC_REGS;




/**********************************************************************************************************************
 *  											GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             (0xE000E000)
#define APINT                                  *((volatile U32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define NVIC                                    ((volatile NVIC_REGS*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))



/******** SYSTEM CONTROL REGISTERS **********/
#define RCGCGPIO        *((volatile U32*)(0x400FE608)) 
#define RCGCTIMER       *((volatile U32*)(0x400FE604)) 
#define RCGCWTIMER      *((volatile U32*)(0x400FE65C))


/******** GPIO Base address **********/
#define GPIO_PORTA      (0x40058000)
#define GPIO_PORTB      (0x40059000)
#define GPIO_PORTC      (0x4005A000)
#define GPIO_PORTD      (0x4005B000)
#define GPIO_PORTE      (0x4005C000)
#define GPIO_PORTF      (0x4005D000)


/********** REG offsets ********/
#define GPIODATA            (0x3FC)
#define GPIODIR             (0x400)
#define GPIOIS              (0x404)
#define GPIOIBE             (0x408)
#define GPIOIEV             (0x40C)
#define GPIOIM              (0x410)
#define GPIORIS             (0x414)
#define GPIOMIS             (0x418)
#define GPIOICR             (0x41C)
#define GPIOAFSEL           (0x420)
#define GPIODR2R            (0x500)
#define GPIODR4R            (0x504)
#define GPIODR8R            (0x508)
#define GPIOODR             (0x50C)
#define GPIOPUR             (0x510)
#define GPIOPDR             (0x514)
#define GPIOSLR             (0x518)
#define GPIODEN             (0x51C)
#define GPIOLOCK            (0x520)
#define GPIOCR              (0x524)
#define GPIOAMSEL           (0x528)
#define GPIOPCTL            (0x52C)
#define GPIOADCCTL          (0x530)
#define GPIODMACTL          (0x534)
#define GPIOPeriphID4       (0xFD0)
#define GPIOPeriphID5       (0xFD4)
#define GPIOPeriphID6       (0xFD8)
#define GPIOPeriphID7       (0xFDC)
#define GPIOPeriphID0       (0xFE0)
#define GPIOPeriphID1       (0xFE4)
#define GPIOPeriphID2       (0xFE8)
#define GPIOPeriphID        (0xFEC)
#define GPIOPCellID0        (0xFF0)
#define GPIOPCellID1        (0xFF4)
#define GPIOPCellID2        (0xFF8)
#define GPIOPCellID3        (0xFFC)



/******** TIMERS Base address **********/
#define TIMER0  0x40030000
#define TIMER1  0x40031000
#define TIMER2  0x40032000
#define TIMER3  0x40033000
#define TIMER4  0x40034000
#define TIMER5  0x40035000

#define TIMER0_WIDE  0x40036000
#define TIMER1_WIDE  0x40037000
#define TIMER2_WIDE  0x4004C000
#define TIMER3_WIDE  0x4004D000
#define TIMER4_WIDE  0x4004E000
#define TIMER5_WIDE  0x4004F000


/******** TIMERS REGISTERS offsets **********/

#define GPTMCFG         (0x000)
#define GPTMTAMR        (0x004)
#define GPTMTBMR        (0x008)
#define GPTMCTL         (0x00C)
#define GPTMSYNC        (0x010)
#define GPTMIMR         (0x018)
#define GPTMRIS         (0x01C)
#define GPTMMIS         (0x020)
#define GPTMICR         (0x024)
#define GPTMTAILR       (0x028)
#define GPTMTBILR       (0x02C)
#define GPTMTAMATCHR    (0x030)
#define GPTMTBMATCHR    (0x034)
#define GPTMTAPR        (0x038)
#define GPTMTBPR        (0x03C)
#define GPTMTAPMR       (0x040)
#define GPTMTBPMR       (0x044)
#define GPTMTAR         (0x048)
#define GPTMTBR         (0x04C)
#define GPTMTAV         (0x050)
#define GPTMTBV         (0x054)
#define GPTMRTCPD       (0x058)
#define GPTMTAPS        (0x05C)
#define GPTMTBPS        (0x060)
#define GPTMTAPV        (0x064)
#define GPTMTBPV        (0x068)
#define GPTMPP          (0xFC0)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
