/*
 * TMU_program.c
 *
 *  Created on: Mar 11, 2022
 *      Author: Tarek ElDallal
 */


#include "../../LIBRARIES/std_types.h"
#include "../../LIBRARIES/error_state.h"
#include "TIMER_register.h"
#include "../../MCAL/GIE/GIE_interface.h"
#include "../../MCAL/interrupt.h"
#include "../../MCAL/DIO/DIO_register.h"

//#include "../../MCAL/TIMER/TIMER_interface.h"

#include"TMU_config.h"
#include "TMU_private.h"


static u16_t Global_u16_tCounterENTERCTCISR=0;
static u16_t Global_u16_tCounterCTC =0;
TCB_t TASKS[MAX_TASKS_NUMBER];
ES_t TMU_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

/*------------------------- TIMER0 SETTING ---------------------------*/

	TCCR0|=(TIMER_MASK_BIT<<TCCR0_CS02);
	TCCR0&=~(TIMER_MASK_BIT<<TCCR0_CS01);
	TCCR0|=(TIMER_MASK_BIT<<TCCR0_CS00);
	TCCR0|=(TIMER_MASK_BIT<<TCCR0_WGM01);

#if TICK_TIME <= MAX_TICK_TIME && TICK_TIME >=MIN_TICK_TIME

	OCR0 = (TICK_TIME * OCRN_COUNTS);
	Global_u16_tCounterENTERCTCISR =1;
	Global_u16_tCounterCTC =1;
#elif TICK_TIME > MAX_TICK_TIME
	u8_t Local_u8_tMaxNumber, Local_u8_tCounter;
	for(Local_u8_tCounter=1; Local_u8_tCounter<= MAX_TICK_TIME; Local_u8_tCounter++)
	{
		if(TICK_TIME % Local_u8_tCounter == TMU_ZERO_NUMBER)
			Local_u8_tMaxNumber =Local_u8_tCounter;
	}
	OCR0 = (Local_u8_tMaxNumber * OCRN_COUNTS);
	DDRB=OCR0;
	Global_u16_tCounterENTERCTCISR =(TICK_TIME / Local_u8_tMaxNumber);
	Global_u16_tCounterCTC = Global_u16_tCounterENTERCTCISR;
#else
#error	"TICK_TIME SELECTION IS NOT CORRECT"
#endif

	return Local_enuErrorState;

}

ES_t TMU_enuCreateTask(void(*Copy_pfunTask)(void),u8_t Copy_u8_tPriority, u8_t Copy_u8_tPeriodicity)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pfunTask !=NULL)
	{
		TASKS[Copy_u8_tPriority].Pfun=Copy_pfunTask;
		TASKS[Copy_u8_tPriority].priodicity=Copy_u8_tPeriodicity;
		TASKS[Copy_u8_tPriority].counter=Copy_u8_tPeriodicity-1;
		TASKS[Copy_u8_tPriority].State= READY;

	}
	else
		Local_enuErrorState = ES_NULL_POINTER;

	return Local_enuErrorState;
}


ES_t TMU_enuSuspendTask(u8_t Copy_u8_tPriority)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8_tPriority	< MAX_TASKS_NUMBER)
	{
		TASKS[Copy_u8_tPriority].State= SUSPEND;
	}

	return Local_enuErrorState;
}
ES_t TMU_enuResumeTask (u8_t Copy_u8_tPriority)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8_tPriority< MAX_TASKS_NUMBER)
		{
			TASKS[Copy_u8_tPriority].State= READY;
			TASKS[Copy_u8_tPriority].counter= TASKS[Copy_u8_tPriority].priodicity; //=0;

		}
	return Local_enuErrorState;
}




ES_t TMU_enuDeleteTask (u8_t Copy_u8_tPriority)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8_tPriority< MAX_TASKS_NUMBER)
		{
			TASKS[Copy_u8_tPriority].State= SUSPEND;
			TASKS[Copy_u8_tPriority].Pfun= NULL;

		}
	return Local_enuErrorState;
}



ES_t TMU_enuStartScheduler(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	 //Enable the CTC Interrupt
	 TIMSK |= (TIMER_MASK_BIT<<TIMSK_OCIE0);
	 GIE_enu_Enable();
	 while(1);


	return Local_enuErrorState;
}

/*

ISR (VECT_TIMER0_CTC)
{
		Global_u16_tCounterCTC --;

	if (Global_u16_tCounterCTC ==0)
	{
		// scheduler
		for(u8_t Local_u8_tCounter=0; Local_u8_tCounter< MAX_TASKS_NUMBER ; Local_u8_tCounter++)
		{
			if(TASKS[Local_u8_tCounter].Pfun !=NULL && TASKS[Local_u8_tCounter].counter ==0 &&TASKS[Local_u8_tCounter].State ==READY)
			{
				TASKS[Local_u8_tCounter].Pfun();
				TASKS[Local_u8_tCounter].counter= TASKS[Local_u8_tCounter].priodicity-1;

			}
			else
			{
				TASKS[Local_u8_tCounter].counter--;

			}
		}
		Global_u16_tCounterCTC = Global_u16_tCounterENTERCTCISR;
	}

}
*/
