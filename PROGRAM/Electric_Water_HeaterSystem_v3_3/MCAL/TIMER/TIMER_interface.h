/*
 * TIMER_ZERO_interface.h
 *
 *  Created on: Feb 27, 2022
 *      Author: Tarek ElDallal
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_


/*-------------------------------------- TIMER MODULE FUNCTIONS --------------------------------*/
/*-------------------------------------- TIMER ZERO FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/


ES_t TIMER0_enuInit(void);
ES_t TIMER0_enuStartTimer(void);
ES_t TIMER0_enuInterruptEnable(void);
ES_t TIMER0_enuInterruptDisable(void);
ES_t TIMER0_enuSetCallBackDelay( void( *Copy_pfunISRFun) (void),u8_t Copy_u8_tTimer0IntIndex, u16_t Copy_u16_tTimer0Delay);
ES_t TIMER0_enuStopTimer(void);

/*-------------------------------------- TIMER ONE FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/

ES_t TIMER1_enuInit(void);
ES_t TIMER1_enuStartTimer(void);
ES_t TIMER1_enuInterruptEnable(void);
ES_t TIMER1_enuInterruptDisable(void);
ES_t TIMER1_enuSetCallBackDelay( void( *Copy_pfunISRFun) (void),u8_t Copy_u8_tTimer0IntIndex, u16_t Copy_u16_tTimer0Delay);
ES_t TIMER1_enuStopTimer(void);

/*-------------------------------------- TIMER TWO FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/


ES_t TIMER2_enuInit(void);
ES_t TIMER2_enuStartTimer(void);
ES_t TIMER2_enuInterruptEnable(void);
ES_t TIMER2_enuInterruptDisable(void);
ES_t TIMER2_enuSetCallBackDelay( void( *Copy_pfunISRFun) (void),u8_t Copy_u8_tTimer2IntIndex, u16_t Copy_u16_tTimer2Delay);
ES_t TIMER2_enuStopTimer(void);


//ES_t Timer0_enuSetCallBack( void(*Copy_pfunISRFun)(void),u8_t Copy_u8_tTimerIntIndex)

//ES_t Timer0_enuSetCallBack( void(*Copy_pfunISRFun)(void),u8_t Copy_u8_tTimerIntIndex, u8_t Copy_u8_tTimerDelay)
//ES_t TIMER0_enuCallBackCTC(volatile void( *Copy_pfunAppFun) (void));


#define TIMER_OVF0_INTERRUPT_INDEX		0
#define TIMER_CTC0_INTERRUPT_INDEX		1
#define TIMER_OVF1_INTERRUPT_INDEX		0
#define TIMER_CTC1A_INTERRUPT_INDEX		1
#define TIMER_CTC1B_INTERRUPT_INDEX		2

#define TIMER_OVF2_INTERRUPT_INDEX		0
#define TIMER_CTC2_INTERRUPT_INDEX		1
#define TIMER1_100_MILE_SECOND			1

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
