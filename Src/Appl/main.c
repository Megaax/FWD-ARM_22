#include "Std_Types.h"
#include "DioCtrl.h"
#include "Mcu_Hw.h"
#include "TimerCtrl_Cfg.h"

void LED_TOGGLE()
{
	volatile uint8 read;
	read=Dio_ReadChannel(PIN1);
	if(read ==0)
	Dio_WriteChannel(PIN1,Lvl_High);
	else if(read)
	Dio_WriteChannel(PIN1,Lvl_Low);
return;
}

void h(){uint16 x=5;}

void LedControl(uint32 ON_TIME,uint32 OFF_TIME)
{
	Gpt_EableNotification(Channel0);
Gpt_StartTimer(Channel0,ON_TIME);
Gpt_EableNotification(Channel0);
Gpt_StartTimer(Channel0,OFF_TIME);
	
}
int main(void)
{


static  Gpt_ConfigType Cfg[NO_OF_TIMERS]={
    {Channel0,16,65535,GPT_CH_MODE_CONTINUOUS,LED_TOGGLE},
    {Channel1,16,65535,GPT_CH_MODE_CONTINUOUS,h}
}; 

IntCrtl_Init();
ClkCrtl_Init();

Gpt_Init(Cfg);


LedControl(10,5);



	
while(1)
	{	
		
			
	}
	return 0;
}

