/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DioCtrl.h"
#include "Mcu_Hw.h"
#include "Platform_Types.h"
#include "BIT_MATH.h"

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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void Dio_WriteChannel(Dio_ChannelType PIN,Dio_LevelType lEVEL)
{
	SET_BIT(GPIO_CLK,5);
	GPIO_DIR=1<<PIN;
	GPIO_EN=1<<PIN;
	uint16 OFFSET=1<<(PIN+2);

	if(lEVEL == Lvl_High)
	*((volatile uint32*)(GPIO_BASE_ADDRESS+OFFSET))=1<<PIN;
	else
	*((volatile uint32*)(GPIO_BASE_ADDRESS+OFFSET))=0<<PIN;
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType PIN)
{
	SET_BIT(GPIO_CLK,5);
	uint16 OFFSET=1<<(PIN+2);
	volatile uint8  RET_LOCAL;
	RET_LOCAL= GET_BIT(*((volatile uint32*)(GPIO_BASE_ADDRESS+OFFSET)),PIN);
	
	return RET_LOCAL;
}

void Dio_WritePort(Dio_PortType Port,Dio_PortLevelType PortVal)
{
	switch(Port)
	{
		case PORTA:
			SET_BIT(GPIO_CLK,5);
			GPIO_DIR=0xFF;
			GPIO_EN=0xFF;
			*((volatile uint32*)(GPIO_BASE_ADDRESS+0x3FC))=PortVal;	
			break;

		case PORTB:
			SET_BIT(GPIO_CLK,5);
			GPIO_DIR=0xFF;
			GPIO_EN=0xFF;
			*((volatile uint32*)(GPIO_BASE_ADDRESS+0x3FC))=PortVal;	
			break;

		case PORTE:
			SET_BIT(GPIO_CLK,5);
			GPIO_DIR=0xFF;
			GPIO_EN=0xFF;
			*((volatile uint32*)(GPIO_BASE_ADDRESS+0x3FC))=PortVal;	
			break;		
		case PORTF:
			SET_BIT(GPIO_CLK,5);
			GPIO_DIR=0xFF;
			GPIO_EN=0xFF;
			*((volatile uint32*)(GPIO_BASE_ADDRESS+0x3FC))=PortVal;	
			break;
		
		case PORTC:
			SET_BIT(GPIO_CLK,5);
			GPIO_DIR=0xFF;
			GPIO_EN=0xFF;
			*((volatile uint32*)(GPIO_BASE_ADDRESS+0x3FC))=PortVal;	
			break;
		
		case PORTD:
			SET_BIT(GPIO_CLK,5);
			GPIO_DIR=0xFF;
			GPIO_EN=0xFF;
			*((volatile uint32*)(GPIO_BASE_ADDRESS+0x3FC))=PortVal;	
			break;
	}
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType Port)
{
		volatile uint8 RET_LOCAL = *((volatile uint32*)(GPIO_BASE_ADDRESS+0x3FC));
	
	return RET_LOCAL;
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
