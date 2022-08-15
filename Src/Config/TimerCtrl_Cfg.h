/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TIMERCTRL_CFG.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef TIMERCTRL_CFG_H
#define TIMERCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

#define NULL        (void *)0
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Enable 1
#define Disable 0
#define NO_CALLBACK 0
#define NO_OF_TIMERS 2


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum 
{
	Channel0  , 
	Channel1  ,
	Channel2  , 
	Channel3  , 
	Channel4  ,
	Channel5  ,
	Channel6  ,
	Channel7  ,
	Channel8   ,
	Channel9   ,
	Channel10  ,
	Channel11  
}Gpt_ChannelType;


typedef enum 
{
	 GPT_PREDEF_TIMER_1US_16BIT=5,
	 GPT_PREDEF_TIMER_1US_24BIT=6,
	 GPT_PREDEF_TIMER_1US_32BIT=7,
	 GPT_PREDEF_TIMER_100US_32BIT=8
	
}Gpt_PredefTimerType;

typedef enum 
{
	GPT_CH_MODE_ONESHOT=0x01,
	GPT_CH_MODE_CONTINUOUS
	
	
}Gpt_ChannelMode;


#define GPT_PREDEFTIMER 					5 		/*Choose from the Gpt_PredefTimerType ENUM */
#define GPT_ENABLE_PREDEFTIMER	 Enable     										/*Enable Disable*/
	

typedef uint16 Gpt_ValueType;
typedef   void (*GptNotification)(void);



typedef struct 
{
	Gpt_ChannelType Gpt_ChannelId;
	uint8 Gpt_ChannelTickFrequency;
	Gpt_ValueType Gpt_ChannelTickValueMax;
	Gpt_ChannelMode ChannelMode;
	GptNotification callback;
}Gpt_ConfigType;




 
#endif  /* TIMERCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: TIMERCTRL_CFG.h
 *********************************************************************************************************************/
