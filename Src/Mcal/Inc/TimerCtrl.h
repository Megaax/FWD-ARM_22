/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TimerCrtl.h
 *       Module:  TimerCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef TimerCrtl_H
#define TimerCrtl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "TimerCtrl_Cfg.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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




void Gpt_Init(const  Gpt_ConfigType *Cfg);
void Gpt_StartTimer(Gpt_ChannelType Channel,uint8 value);
void Gpt_StopTimer(Gpt_ChannelType Channel);
uint16 Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
uint16 Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType predefTimer,uint32*TimeValuePtr);
void Gpt_DisableNotification(Gpt_ChannelType Channel);
void Gpt_EableNotification(Gpt_ChannelType Channel);



#endif  /* TimerCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: TimerCrtl.h
 *********************************************************************************************************************/