/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  ClkCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef ClkCTRL_CFG_H
#define ClkCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
 #define PIOSC 				0
 #define MOSC 				1
 #define PIOSC_DIV_4 	2
 #define LFIOSC 			3
 
 enum SysDiv
 {
	 SYSCTL_SYSDIV_1=0x0,
	 SYSCTL_SYSDIV_2,
	 SYSCTL_SYSDIV_3,
	 SYSCTL_SYSDIV_4,
	 SYSCTL_SYSDIV_5,
	 SYSCTL_SYSDIV_6,
	 SYSCTL_SYSDIV_7,
	 SYSCTL_SYSDIV_8,
	 SYSCTL_SYSDIV_9,
	 SYSCTL_SYSDIV_10,
	 SYSCTL_SYSDIV_11,
	 SYSCTL_SYSDIV_12,
	 SYSCTL_SYSDIV_13,
	 SYSCTL_SYSDIV_14,
	 SYSCTL_SYSDIV_15,
	 SYSCTL_SYSDIV_16
	 
	 
 };
 
  enum XTAL_val
 {
	 XTAL_4=0x06,
	 XTAL_4_1,
	 XTAL_4_9,
	 XTAL_5,
	 XTAL_5_12,
	 XTAL_6,
	 XTAL_6_144,
	 XTAL_7_3728,
	 XTAL_8,
	 XTAL_8_19,
	 XTAL_10,
	 XTAL_12,
	 XTAL_12_288,
	 XTAL_13_56,
	 XTAL_14_318,
	 XTAL_16,
	 XTAL_16_384,
	 XTAL_18,
	 XTAL_20,
	 XTAL_24,
	 XTAL_25
 };
 
 /*OPTIONS:
	 PIOSC 					/Precision internal oscillator/
	 MOSC 			 		/Main oscillator/
	 PIOSC_DIV_4 		/Precision internal oscillator divided by 4/
	 LFIOSC 				/Low-frequency internal oscillator/
 */

#define RCC_CLOCK_TYPE PIOSC
 
 #if RCC_CLOCK_TYPE == MOSC
 /*CHOOSE FROM XTAL_val enum */
 #define XTAL_VALUE XTAL_16
 
 #endif
 
/*CHOOSE FROM SysDiv enum */
#define SYS_DIVISOR 	SYSCTL_SYSDIV_1
 
 
#define PLL_OFF 				0
#define PLL_ON 					1

/*OPTIONS 
	 PLL_ON
	 PLL_OFF
*/
 
#define RCC_PLL_MODE  PLL_OFF



#endif
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/* ClkCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: ClkCtrl_Cfg.h
 *********************************************************************************************************************/
