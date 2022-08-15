/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  TimerCrtl.c
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
#include "TimerCtrl.h"
#include "TimerCtrl_Cfg.h"
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
GptNotification Notifications[NO_OF_TIMERS]={};

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
* \Syntax          : void TimerCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


void Gpt_1US_16BIT_TIMER(void)
{
	SET_BIT(RCGCTIMER,0);
	CLR_BIT(TIMER0_CTL,0);							/*DISABLE TIMER BEFORE CONFIGURATION */
	TIMER0_CFG= 0x04;
	TIMER0_TAMR = 0x02;
	TIMER0_APR=16;	
	TIMER0_ICR|= 0x1;
}

void Gpt_1US_32BIT_TIMER(void)
{
	SET_BIT(RCGCWTIMER,0);
	CLR_BIT(WTIMER0_CTL,0);							/*DISABLE TIMER BEFORE CONFIGURATION */
	WTIMER0_CFG= 0x00;
	WTIMER0_TAMR = 0x02;	
	WTIMER0_APR=16;

	WTIMER0_ICR|= 0x1;
}

void Gpt_100US_32BIT_TIMER(void)
{
	SET_BIT(RCGCWTIMER,0);
	CLR_BIT(WTIMER0_CTL,0);							/*DISABLE TIMER BEFORE CONFIGURATION */
	WTIMER0_CFG= 0x00;
	WTIMER0_APR=16000;
	WTIMER0_ICR|= 0x1;
}



void Gpt_Init(const Gpt_ConfigType *Cfg)
{
	#if GPT_ENABLE_PREDEFTIMER == Enable
	
			#if GPT_PREDEFTIMER == 5
					Gpt_1US_16BIT_TIMER();
		
			#elif GPT_PREDEFTIMER == 7
					Gpt_1US_32BIT_TIMER();
		
			#elif GPT_PREDEFTIMER == 8
					Gpt_100US_32BIT_TIMER();
		#endif
	
	#else
		uint8 i;
		for(i=0;i<NO_OF_TIMERS;i++)
		{
			uint8 CH=Cfg[i].Gpt_ChannelId;
			if(CH<6)
			{
					SET_BIT(RCGCTIMER,0);
					CLR_BIT(TIMER0_CTL,0);							/*DISABLE TIMER BEFORE CONFIGURATION */
					TIMER0_CFG= 0x04;
					TIMER0_TAMR = Cfg[i].ChannelMode;
					TIMER0_APR=(16/Cfg[i].Gpt_ChannelTickFrequency);	
					TIMER0_ICR|= 0x1;
					if(Cfg[i].callback !=NULL)
						Notifications[i]=Cfg[i].callback ;
						
			}
			else
			{
				SET_BIT(RCGCWTIMER,0);
				CLR_BIT(WTIMER0_CTL,0);							/*DISABLE TIMER BEFORE CONFIGURATION */
				WTIMER0_CFG= 0x00;
				WTIMER0_TAMR = Cfg[i].ChannelMode;	
				WTIMER0_APR=(16/Cfg[i].Gpt_ChannelTickFrequency);	
				WTIMER0_ICR|= 0x1;
				if(Cfg[i].callback !=NULL)
				Notifications[i]=Cfg[i].callback ;
			}
		}
	
	#endif

}


void Gpt_StartTimer(Gpt_ChannelType Channel,uint8 value)
{
if(Channel<6)
	{
		TIMER0_TAILR =value;
		TIMER0_CTL|= 0x01;
		while((TIMER0_MRIS& 0x1) == 0);   
		
        TIMER0_ICR = 0x1; 
	}
	else
	{
		WTIMER0_TAILR =value;
		WTIMER0_CTL|= 0x01;
		while((WTIMER0_MRIS& 0x1) == 0);   
		
        WTIMER0_ICR = 0x1; 		
	}
}
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
	if(Channel<6){
		CLR_BIT(TIMER0_CTL,0);
		TIMER0_IMR=0x0;
	}
	else
		CLR_BIT(WTIMER0_CTL,0);
}

uint16 Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
	uint16 LOC_RET;
	if(Channel<6){
		LOC_RET = TIMER0_TAR;
		LOC_RET*=TIMER0_APR;
	}
	else
	{
		LOC_RET = WTIMER0_TAR;
		LOC_RET*=WTIMER0_APR;
	}
	return LOC_RET;
}

uint16 Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
	uint16 LOC_RET;
	if(Channel<6){
		LOC_RET = (TIMER0_TAILR-TIMER0_TAR);
		LOC_RET*=TIMER0_APR;
	}
	else
	{
		LOC_RET = (WTIMER0_TAILR-WTIMER0_TAR);
		LOC_RET*=WTIMER0_APR;
	}
	return LOC_RET;
}

Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType predefTimer,uint32*TimeValuePtr)
{
	#if GPT_ENABLE_PREDEFTIMER == Disable
	return E_NOT_OK;
	#else
		switch(predefTimer)
		{
				uint32 LOC_RET;
			case GPT_PREDEF_TIMER_1US_16BIT:
						LOC_RET = TIMER0_TAR;
						LOC_RET*=TIMER0_APR;
			break;
			case GPT_PREDEF_TIMER_1US_32BIT:
						LOC_RET = WTIMER0_TAR;
						LOC_RET*=WTIMER0_APR;
			break;
			case GPT_PREDEF_TIMER_100US_32BIT:
						LOC_RET = WTIMER0_TAR;
						LOC_RET*=WTIMER0_APR;
			break;
			case GPT_PREDEF_TIMER_1US_24BIT:
						LOC_RET = TIMER0_TAR;
						LOC_RET*=TIMER0_APR;
			break;
			
			*TimeValuePtr=LOC_RET;
		}	
		return E_OK;
	#endif

	
}

void Gpt_EableNotification(Gpt_ChannelType Channel)
{
	if(Channel<6)
	TIMER0_IMR=0x1;
	else
	WTIMER0_IMR=0x1;

}
void Gpt_DisableNotification(Gpt_ChannelType Channel)
	
{
	if(Channel<6)
	TIMER0_IMR=0x0;
	else
	WTIMER0_IMR=0x0;
}/*
void LED_TOGGLE()
{
	volatile uint8 read;
	read=Dio_ReadChannel(PIN0);
	if(read ==0)
	Dio_WriteChannel(PIN0,Lvl_High);
	else if(read)
	Dio_WriteChannel(PIN0,Lvl_Low);
	return;
}*/

TIMER0A_Handler(void){
	Gpt_StopTimer(Channel0);
	LED_TOGGLE();
	TIMER0_ICR=0x1;
	
}

/**********************************************************************************************************************
 *  END OF FILE: TimerCrtl.c
 *********************************************************************************************************************/
