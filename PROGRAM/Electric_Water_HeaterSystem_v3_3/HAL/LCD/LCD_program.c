/*
 * LCD_program.c
 *
 *  Created on: Oct 19, 2021
 *      Author: Tarek ElDallal
 */
#include "../../LIBRARIES/error_state.h"
#include "../../LIBRARIES/std_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include <util/delay.h>



ES_t LCD_enuInit(void)
{
ES_t Local_enu_ErrorState = ES_NOK;

DIO_enuSetPinDirection(RS_PORT,RS_PIN,DIO_u8_tOUTPUT);
DIO_enuSetPinDirection(RW_PORT,RW_PIN,DIO_u8_tOUTPUT);
DIO_enuSetPinDirection(EN_PORT,EN_PIN,DIO_u8_tOUTPUT);

DIO_enuSetPinDirection(DB7_PORT,DB7_PIN,DIO_u8_tOUTPUT);
DIO_enuSetPinDirection(DB6_PORT,DB6_PIN,DIO_u8_tOUTPUT);
DIO_enuSetPinDirection(DB5_PORT,DB5_PIN,DIO_u8_tOUTPUT);
DIO_enuSetPinDirection(DB4_PORT,DB4_PIN,DIO_u8_tOUTPUT);

_delay_ms(POWER_ON_DELAY);
#if LCD_MODE ==FOUR_BIT
DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tLOW); /*Send command*/
LCD_enuWriteNLatch(FUNCTION_SET_FOUR_BIT);
_delay_ms(FUNCTION_SET_DELAY);

#elif LCD_MODE == EIGHT_BIT
DIO_enuSetPinDirection(DB3_PORT,DB3_PIN,DIO_u8_tOUTPUT);
DIO_enuSetPinDirection(DB2_PORT,DB2_PIN,DIO_u8_tOUTPUT);
DIO_enuSetPinDirection(DB1_PORT,DB1_PIN,DIO_u8_tOUTPUT);
DIO_enuSetPinDirection(DB0_PORT,DB0_PIN,DIO_u8_tOUTPUT);

DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tLOW); /*Send command*/
LCD_enuWriteNLatch(FUNCTION_SET_EIGHT_BIT);
_delay_ms(FUNCTION_SET_DELAY);
#endif

_delay_ms(FUNCTION_SET_DELAY);
DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tLOW); /*Send command*/
LCD_enuWriteNLatch(DISPLAY_ON_OFF_BIT);

_delay_ms(FUNCTION_SET_DELAY);
DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tLOW); /*Send command*/
LCD_enuWriteNLatch(DISPLAY_CLEAR_BIT);

_delay_ms(DISPLAY_CLEAR_DELAY);
DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tLOW); /*Send command*/
LCD_enuWriteNLatch(ENTERY_MODE_BIT);
Local_enu_ErrorState= ES_OK;
return Local_enu_ErrorState;
}

ES_t LCD_enuSendData(u8_t Copy_u8_tData)
{
	ES_t Local_enu_ErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tHIGH ); /*Send data*/
	LCD_enuWriteNLatch(Copy_u8_tData);


	return Local_enu_ErrorState;
}

ES_t LCD_enuSendCommand(u8_t Copy_u8_tCommand)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tLOW); /*Send command*/

	LCD_enuWriteNLatch(Copy_u8_tCommand);

	return Local_enu_ErrorState;
}


ES_t LCD_enuSendPosition(u8_t Copy_u8_tLine, u8_t Copy_u8_tPosition)
{
	//u8_t Copy_u8_tIterator;
	ES_t Local_enu_ErrorState = ES_NOK;
	DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tLOW); /*Send command*/
	switch (Copy_u8_tLine)
	{
	case 0 : LCD_enuWriteNLatch(FIRST_LINE+Copy_u8_tPosition);
	break;

	case 1: LCD_enuWriteNLatch(SECOND_LINE+Copy_u8_tPosition);
	break;

//	default:
	//#warning The LCD line position is incorrect
	}



/*	for(Copy_u8_tIterator=1;Copy_u8_tIterator<Copy_u8_tPosition;Copy_u8_tIterator++)
	{
		LCD_enuWriteNLatch(DISPLAY_POSITION_SHIFT);

	}
*/
	return Local_enu_ErrorState;
}



ES_t LCD_enuSendCustomCharacter(u8_t * Copy_u8_tPArrCustomCharacter, u8_t Copy_u8_tPatternsNumber,u8_t Copy_u8_tXPosition,u8_t Copy_u8_tYPosition,u8_t Copy_u8_tDirection)
{
	ES_t Local_enu_ErrorState = ES_NOK;

	/****************DRAW THE CUSTOM CHARACTOR ON CGRAM*****************/

	u8_t Local_u8_tIterator;
	DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tLOW); /*Send command*/

	LCD_enuWriteNLatch(FIRST_CGRAM_PATTERN); //First Pattern location in CGRAM


	for(Local_u8_tIterator=0; Local_u8_tIterator<PATTERMS_NUMBER_BITS;Local_u8_tIterator++)
		{
			//LCD_enuWriteNLatch((Copy_u8_tPArrCustomCharacter[Local_u8_tIterator]));

			//LCD_enuWriteNLatch((*Copy_u8_tPArrCustomCharacter+Local_u8_tIterator));

			//LCD_enuWriteNLatch((u8_t*)(Copy_u8_tPArrCustomCharacter+Local_u8_tIterator));

		DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tHIGH); /*Send data*/

			LCD_enuWriteNLatch(*(Copy_u8_tPArrCustomCharacter+Local_u8_tIterator));

	}
/*****************************POSITION & DIRECTION****************************/

	DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tLOW); /*Send command*/

	if(Copy_u8_tXPosition>1||Copy_u8_tYPosition>16||Copy_u8_tPatternsNumber>8||Copy_u8_tDirection>1)
	{
		Local_enu_ErrorState=ES_NOK;
	}
	else
	{
		if (Copy_u8_tDirection) /*****************WRITING FROM LIFT TO RIGHT*******************/
		{
			switch  (Copy_u8_tXPosition)
			{
			case 0 : LCD_enuWriteNLatch(FIRST_LINE+Copy_u8_tYPosition);
			break;

			case 1: LCD_enuWriteNLatch(SECOND_LINE+Copy_u8_tYPosition);
			break;
			}
		}
		else /*****************WRITING FROM RIGHT TO LIFT*******************/
		{
			switch  (Copy_u8_tXPosition)
			{
			case 0 : LCD_enuWriteNLatch(END_FIRST_LINE-Copy_u8_tYPosition);
						LCD_enuWriteNLatch(RIGHT_TO_LEFT_DIRECTION);

			break;

			case 1: LCD_enuWriteNLatch(END_SECOND_LINE-Copy_u8_tYPosition);
						LCD_enuWriteNLatch(RIGHT_TO_LEFT_DIRECTION);

			break;
			}
		}
	}

	/*******************************PRINTING THE CUSTOM CHARACTERS*********************************/
	DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tHIGH ); /*Send data*/
	LCD_enuWriteNLatch(Copy_u8_tPatternsNumber);


	return Local_enu_ErrorState;


}

ES_t LCD_enuSendpcString(const char * Copy_pcString)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	while(*Copy_pcString) //true value as false =0 =='/0' Null character.
	{
		DIO_enuSetPinValue(RS_PORT,RS_PIN, DIO_u8_tHIGH ); /*Send String data*/
		LCD_enuWriteNLatch(* Copy_pcString++); //Adding incrementing operation.
	}
	return Local_enu_ErrorState;
}


static ES_t LCD_enuWriteNLatch(u8_t Copy_u8_tData) /*Static local function to make falling edge high then low*/
{
	ES_t Local_enu_ErrorState = ES_NOK;


DIO_enuSetPinValue(RW_PORT,RW_PIN, DIO_u8_tLOW ); /*Write data*/
DIO_enuSetPinValue(EN_PORT,EN_PIN, DIO_u8_tLOW);/*Enable is low*/

/***********************DATA WRITE******************/
/*******************Condition for function set step*********/
if (Copy_u8_tData == FUNCTION_SET_FOUR_BIT)
{
	u8_t Local_u8_tRS_Value;
	DIO_enuGetPinValue(RS_PORT,RS_PIN,&Local_u8_tRS_Value);

if(Local_u8_tRS_Value==DIO_u8_tLOW)
{
	/*******************************Pins from 7 to 4*********************/

	DIO_enuSetPinValue(DB7_PORT, DB7_PIN,((Copy_u8_tData>>BIT_NUMBER_7)&BIT_MASK_MOVE));
	DIO_enuSetPinValue(DB6_PORT, DB6_PIN,((Copy_u8_tData>>BIT_NUMBER_6)&BIT_MASK_MOVE));
	DIO_enuSetPinValue(DB5_PORT, DB5_PIN,((Copy_u8_tData>>BIT_NUMBER_5)&BIT_MASK_MOVE));
	DIO_enuSetPinValue(DB4_PORT, DB4_PIN,((Copy_u8_tData>>BIT_NUMBER_4)&BIT_MASK_MOVE));

	/*******************************LATCH *************************/
	DIO_enuSetPinValue(EN_PORT,EN_PIN, DIO_u8_tHIGH);/*Enable is HIGH*/
	_delay_ms(LATCH_DELAY);
	//_delay_us();
	DIO_enuSetPinValue(EN_PORT,EN_PIN, DIO_u8_tLOW);/*Enable is low*/
	_delay_ms(LATCH_DELAY);

	/*******************************LATCH  END*********************/

}
}
/********************Check the LCD MODE**************/
#if LCD_MODE == FOUR_BIT
/***************************************************************/

/*******************************Pins from 7 to 4*********************/

DIO_enuSetPinValue(DB7_PORT, DB7_PIN, ((Copy_u8_tData>>BIT_NUMBER_7)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB6_PORT, DB6_PIN, ((Copy_u8_tData>>BIT_NUMBER_6)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB5_PORT, DB5_PIN, ((Copy_u8_tData>>BIT_NUMBER_5)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB4_PORT, DB4_PIN, ((Copy_u8_tData>>BIT_NUMBER_4)&BIT_MASK_MOVE));

/*******************************LATCH *************************/
DIO_enuSetPinValue(EN_PORT,EN_PIN, DIO_u8_tHIGH);/*Enable is HIGH*/
_delay_ms(LATCH_DELAY);
//_delay_us();
DIO_enuSetPinValue(EN_PORT,EN_PIN, DIO_u8_tLOW);/*Enable is low*/
_delay_ms(LATCH_DELAY);

/*******************************LATCH  END*********************/
/*******************************Pins from 3 to 0*********************/

DIO_enuSetPinValue(DB7_PORT, DB7_PIN,((Copy_u8_tData>>BIT_NUMBER_3)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB6_PORT, DB6_PIN,((Copy_u8_tData>>BIT_NUMBER_2)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB5_PORT, DB5_PIN,((Copy_u8_tData>>BIT_NUMBER_1)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB4_PORT, DB4_PIN,((Copy_u8_tData>>BIT_NUMBER_0)&BIT_MASK_MOVE));

/*******************************LATCH *************************/
DIO_enuSetPinValue(EN_PORT,EN_PIN, DIO_u8_tHIGH);/*Enable is HIGH*/
_delay_ms(LATCH_DELAY);
//_delay_us();
DIO_enuSetPinValue(EN_PORT,EN_PIN, DIO_u8_tLOW);/*Enable is low*/
_delay_ms(LATCH_DELAY);

/*******************************LATCH  END*********************/


#elif LCD_MODE == EIGHT_BIT
/****************************************************/
/*******************************Pins from 7 to 0*********************/

DIO_enuSetPinValue(DB7_PORT, DB7_PIN,((Copy_u8_tData>>BIT_NUMBER_7)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB6_PORT, DB6_PIN,((Copy_u8_tData>>BIT_NUMBER_6)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB5_PORT, DB5_PIN,((Copy_u8_tData>>BIT_NUMBER_5)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB4_PORT, DB4_PIN,((Copy_u8_tData>>BIT_NUMBER_4)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB3_PORT, DB3_PIN,((Copy_u8_tData>>BIT_NUMBER_3)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB2_PORT, DB2_PIN,((Copy_u8_tData>>BIT_NUMBER_2)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB1_PORT, DB1_PIN,((Copy_u8_tData>>BIT_NUMBER_1)&BIT_MASK_MOVE));
DIO_enuSetPinValue(DB0_PORT, DB0_PIN,((Copy_u8_tData>>BIT_NUMBER_0)&BIT_MASK_MOVE));

/*******************************LATCH *************************/
DIO_enuSetPinValue(EN_PORT,EN_PIN, DIO_u8_tHIGH);/*Enable is HIGH*/
_delay_ms(LATCH_DELAY);
//_delay_us();
DIO_enuSetPinValue(EN_PORT,EN_PIN, DIO_u8_tLOW);/*Enable is low*/
_delay_ms(LATCH_DELAY);

/*******************************LATCH  END*********************/



#else
#error "LCD_MODE you have entered is wrong, please correct it."
#endif


return Local_enu_ErrorState;
}

ES_t LCD_enuDisplayIntegerNum(s32_t Copy_s32Num)
{
	ES_t Local_enuErrorState = ES_NOK;

	s32_t Local_s32Reverse=0;
	u8_t Local_u8Remainder=0 , Local_u8NumDigit=0;

	if(Copy_s32Num <0)
	{
		DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8_tHIGH);
		LCD_enuWriteNLatch('-');
		Copy_s32Num *= -1 ;
	}
	while (Copy_s32Num)
	{
		Local_u8Remainder = Copy_s32Num % 10;
		Local_s32Reverse = Local_s32Reverse * 10 + Local_u8Remainder;
		Copy_s32Num /=10;
		Local_u8NumDigit ++;
	}

	while (Local_u8NumDigit)
	{
		Local_u8Remainder = Local_s32Reverse % 10;
		DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8_tHIGH);
		LCD_enuWriteNLatch(Local_u8Remainder + '0');
		Local_s32Reverse /= 10;
		Local_u8NumDigit --;
	}

	return Local_enuErrorState;
}
ES_t LCD_enuClearDisplay( void )
{

	ES_t Local_enuerrorStates = ES_NOK;

		Local_enuerrorStates = DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8_tLOW);
		LCD_enuWriteNLatch(0x01);

	return Local_enuerrorStates;

}
