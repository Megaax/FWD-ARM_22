/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include	"DioCtrl.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
typedef struct 
{
	uint32 ACTLR;
}SCB_t;

typedef struct 
{
    uint32 EN			[5];
		uint32 RESV0	[27];
    uint32 DS			[5];
		uint32 RESV1	[27];
    uint32 PEN		[5];
		uint32 RESV2	[27];
    uint32 UNPEN	[5];
		uint32 RESV3	[27];
    uint32 ACTV		[5];
		uint32 RESV4	[59];
    uint32 PRI		[35];
}NVIC_t;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E100
#define  RCC_BASE_ADDRESS                      0x400FE060  


#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))

#define SYSCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD10))
#define CFGCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD14))
#define SYSPRI1                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))

#define NVIC ((volatile NVIC_t *) CORTEXM4_PERI_BASE_ADDRESS)
	
/**************************GPIO*******************************************************/

#define GPIO_BASE_ADDRESS										 PORT
#define RCC                                				 	*((volatile uint32*)(RCC_BASE_ADDRESS))
#define GPIO_DATA                                  	GPIO_BASE_ADDRESS
#define GPIO_DIR                                 		*((volatile uint32*)(GPIO_BASE_ADDRESS+0x400))
#define GPIO_CLK																		*((volatile uint32*)(0x400FE608))
#define GPIO_EN                                  		*((volatile uint32*)(GPIO_BASE_ADDRESS+0x51C))
#define GPIO_FSEL                                  		*((volatile uint32*)(GPIO_BASE_ADDRESS+0x420))
#define GPIO_R2R                                  		*((volatile uint32*)(GPIO_BASE_ADDRESS+0x500))
#define GPIO_R4R                                 		*((volatile uint32*)(GPIO_BASE_ADDRESS+0x504))
#define GPIO_R8R                                 		*((volatile uint32*)(GPIO_BASE_ADDRESS+0x508))
#define GPIO_ODR                                  		*((volatile uint32*)(GPIO_BASE_ADDRESS+0x50C))
#define GPIO_PUR                                  		*((volatile uint32*)(GPIO_BASE_ADDRESS+0x510))
#define GPIO_PDR                                  		*((volatile uint32*)(GPIO_BASE_ADDRESS+0x514))


/**************************NARROW TIMERS*******************************************************/
#define TIMER0_BASE_ADDRESS 			    0x40030000 
#define RCGCTIMER                                	  *((volatile uint32*)(0x400FE604))
#define TIMER0_CFG                                	  *((volatile uint32*)(TIMER0_BASE_ADDRESS))
#define TIMER0_TAMR                                   *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x004))
#define TIMER0_TAILR                                 	*((volatile uint32*)(TIMER0_BASE_ADDRESS+0x028))
#define TIMER0_CTL                                    *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x00C))
#define TIMER0_MRIS       	                          *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x01C))
#define TIMER0_ICR                                    *((volatile uint32*)(0x40030024))
#define TIMER0_IMR                                    *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x018))
#define TIMER0_APR                                  	*((volatile uint32*)(TIMER0_BASE_ADDRESS+0x038))
#define TIMER0_TAR                                  	*((volatile uint32*)(TIMER0_BASE_ADDRESS+0x048))
/**************************WIDE TIMERS*******************************************************/
#define WIDETIMER0_BASE_ADDRESS       0x40036000
#define RCGCWTIMER                                	  *((volatile uint32*)(0x400FE000+0x65C))
#define WTIMER0_CFG                                	  *((volatile uint32*)(WIDETIMER0_BASE_ADDRESS))
#define WTIMER0_TAMR                                  *((volatile uint32*)(WIDETIMER0_BASE_ADDRESS+0x004))
#define WTIMER0_TAILR                                 *((volatile uint32*)(WIDETIMER0_BASE_ADDRESS+0x028))
#define WTIMER0_CTL                                   *((volatile uint32*)(WIDETIMER0_BASE_ADDRESS+0x00C))
#define WTIMER0_MRIS       	                          *((volatile uint32*)(WIDETIMER0_BASE_ADDRESS+0x01C))
#define WTIMER0_ICR                                   *((volatile uint32*)(0x40036024))
#define WTIMER0_IMR                                   *((volatile uint32*)(WIDETIMER0_BASE_ADDRESS+0x018))
#define WTIMER0_APR                                  	*((volatile uint32*)(WIDETIMER0_BASE_ADDRESS+0x038))
#define WTIMER0_TAR                                  	*((volatile uint32*)(WIDETIMER0_BASE_ADDRESS+0x048))


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
