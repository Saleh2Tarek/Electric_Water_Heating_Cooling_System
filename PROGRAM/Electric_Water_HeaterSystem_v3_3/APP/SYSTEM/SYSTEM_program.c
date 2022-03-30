/*
 * SYSTEM_program.c
 *
 *  Created on: Mar 24, 2022
 *      Author: Tarek ElDallal
 */

#include "../../LIBRARIES/std_types.h"
#include "../../LIBRARIES/error_state.h"
#include "../../LIBRARIES/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"



#include "../../HAL/SWITCH/SWITCH_config.h"
#include "../../HAL/SWITCH/SWITCH_interface.h"

#include "../../MCAL/ADC/ADC_interface.h"

#include "../../MCAL/TIMER/TIMER_interface.h"

#include "../../MCAL/EXTI/EXTI_config.h"
#include "../../MCAL/EXTI/EXTI_interface.h"


#include "../../MCAL/GIE/GIE_interface.h"


//#include "../../MCAL/IIC/I2C_interface.h"
//#include "../../HAL/EEPROM/EEPROM_interface.h"

#include "../../HAL/SEVENSEGMENT/SEVENSEGMENT_config.h"
#include "../../HAL/SEVENSEGMENT/SEVENSEGMENT_interface.h"
#include "../../HAL/LCD/LCD_interface.h"
#include "../../HAL/LED_SYSTEM/LED_SYSTEM_interface.h"
#include "../../HAL/HEAT_COOL/HEAT_COOL_Elements_interface.h"
#include "../../HAL/TEMPERATURE_SENSOR/TEMP_SENSOR_interface.h"
#include "../../MCAL/INTERNAL_EEPROM/EPROM_interface.h"

#include "../../MCAL/interrupt.h"
#include "SYSTEM_private.h"
#include <util/delay.h>

extern EXTI_t EXTI_AstrEXTIConfig[INT_NUM];
extern SSG_t SEVENSEGMENT_AstrSevenSegmentConfig [SSG_NUMBER];
extern SW_t SWITCH_AstrSwitchConfig [SW_NUM];
extern u32_t Global_32_tTIMER1_CTCA_SecondsCounter;
extern u16_t Global_u16_tTimer0CTC_OneSecondCounter;
u16_t Global_u16_tTempRead,Global_u16_tFive_SecondToggleFlag,Global_u16_tOne_SecondToggleFlag, Global_u16_tAverageTemp,Global_u16_tDesiredTemp,Global_u16_tFive_SecondCounter=0;
u16_t Global_Au16_tTempArr[NUM_OF_TEMP_MEASURES];
u8_t  Global_u8_tCurrentState,Global_u8_tTempMeasureFlag,Global_u8_tReadData,Global_u8_tArrCounter,Global_u8_tUPSwitchFlag,Global_u8_tDOWNSwitchFlag;


ES_t SYSTEM_enuGetTemp(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8_t Local_u8_tIterator;
	u16_t Local_u16_tFirstTempReading;
	/*Getting the Temperature every 100mSecond*/
	TempSensor_enuGetTempReading(&Local_u16_tFirstTempReading);
	//SYSTEM_enuAddNewTemp(Global_Au16_tTempArr,Global_u16_tTempRead);
	for (Local_u8_tIterator = 0; Local_u8_tIterator<NUM_OF_TEMP_MEASURES; Local_u8_tIterator++)
	{
		Global_Au16_tTempArr[Local_u8_tIterator]= Local_u16_tFirstTempReading;
	}
	//SYSTEM_enuCalculateAverateTemp(Global_Au16_tTempArr,&Global_u16_tAverageTemp);

	Global_u8_tArrCounter=0;
	//SYSTEM_enuCalculateAverateTemp(Global_Au16_tTempArr,&Global_u16_tAverageTemp);

	/***********************************EEPROM**************************************/


	return Local_enuErrorState;
}


ES_t SYSTEM_enuCalculateAverateTemp(u16_t * Copy_pu16_tAstrTempReadings, u16_t * Copy_u16_tReturnTempValue)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	u16_t Local_u16_tSumOfReadings = ZERO_VALUE;
	u16_t Local_u16_tAverageOfReadings;
	u8_t Local_u8_tIterator;

	for(Local_u8_tIterator=0; Local_u8_tIterator<NUM_OF_TEMP_MEASURES; Local_u8_tIterator++){
		Local_u16_tSumOfReadings = Local_u16_tSumOfReadings + Copy_pu16_tAstrTempReadings[Local_u8_tIterator];

	}
	Local_u16_tAverageOfReadings = (u16_t) Local_u16_tSumOfReadings / NUM_OF_TEMP_MEASURES;
	* Copy_u16_tReturnTempValue=Local_u16_tAverageOfReadings;
	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}

ES_t SYSTEM_enuAddNewTemp(u16_t * Copy_pu16_tAstrTempReadings, u16_t Copy_u16_tAddedTempValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8_t Local_u8_tIterator;
	for(Local_u8_tIterator=ZERO_VALUE;Local_u8_tIterator<NUM_OF_TEMP_MEASURES;Local_u8_tIterator++)
	{
		Copy_pu16_tAstrTempReadings [Global_u8_tArrCounter] =Copy_u16_tAddedTempValue;
		_delay_ms(10);
		Global_u8_tArrCounter++;
		if(Global_u8_tArrCounter==NUM_OF_TEMP_MEASURES)
			{
				Global_u8_tArrCounter=ZERO_VALUE;
			}
	}

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}



ES_t SYSTEM_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
/*  To initialize the system functions:
 * 	-Digital Input Output Module.
 * 	-Push button switches. 		                    [INPUT]
 * 	-Temperature Sensor. 		                    [INPUT]
 * 	-Analog to Digital Converter. 			        [INTERRUPT]
 * 	-External Interrupt.                            [INTERRUPT]
	-Timer/Counter 0 8-bit. 	                    [INTERRUPT]
	-Timer/Counter 1 16-bit. 	                    [INTERRUPT]
	-Timer/Counter 2 8-bit. 	                    [INTERRUPT]
	-Global Interrupt Enable. 						[INTERRUPT]
	-LED system.				                    [OUTPUT]
	-Seven Segment Display.		                    [OUTPUT]
	-Liquid Crystal Display.	                    [OUTPUT]
	-Heating and Cooling Elements.                  [OUTPUT]



*/
	DIO_enuInit();
	EXTI_enuInit(EXTI_AstrEXTIConfig);
	SevenSegment_enuInit( SEVENSEGMENT_AstrSevenSegmentConfig);
	SevenSegment_enuDisableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[0]);
	SevenSegment_enuDisableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[1]);
	SWITCH_enuIniti(SWITCH_AstrSwitchConfig);
	LCD_enuInit();
	HEAT_COOL_ELEMENTS_enuIniti();
	LED_SYSTEM_enuIniti();
	TIMER0_enuInit();
	TIMER1_enuInit();
	TIMER2_enuInit();


	/* ------- In TEMPSENSOR MODULE THE ADC AND THE TIMER1 IS INITIALIZED ---------- */
	TempSensor_enuInit();
	GIE_enu_Init();
	//I2C_voidMasterInit();
	/*No need for it, as the EXTI_config.c has been edited*/
	//EXTI_enuSetSenseLevel(ON_OFF_SWITCH,RISED);

	EXTI_enuEnableInterrupt(TEMP_UP_SWITCH);
	EXTI_enuEnableInterrupt(TEMP_DOWN_SWITCH);
	EXTI_enuEnableInterrupt(ON_OFF_SWITCH);
	TIMER0_enuInterruptEnable();
	TIMER1_enuInterruptEnable();
	TIMER2_enuInterruptEnable();

	GIE_enu_Enable();
	TIMER0_enuStartTimer();
	TIMER1_enuStartTimer();
	TIMER2_enuStartTimer();

	DIO_enuSetPinDirection(DIO_u8_tPORT_B,DIO_u8_tPIN3,DIO_u8_tOUTPUT);
	DIO_enuSetPinDirection(DIO_u8_tPORT_D,DIO_u8_tPIN4,DIO_u8_tOUTPUT);

	DIO_enuSetPinDirection(DIO_u8_tPORT_D,DIO_u8_tPIN5,DIO_u8_tOUTPUT);
	DIO_enuSetPinDirection(DIO_u8_tPORT_D,DIO_u8_tPIN7,DIO_u8_tOUTPUT);


	Global_u8_tCurrentState = OFF_STATE;
	Global_u8_tUPSwitchFlag = NOT_RISED;
	Global_u8_tDOWNSwitchFlag = NOT_RISED;

	SYSTEM_enuGetTemp();

	/*---------- PROJECT Message ----------*/
	LCD_enuSendCommand(FIRST_LINE);
	LCD_enuSendpcString("Welcome to AMIT      ");
	LCD_enuSendCommand(SECOND_LINE);
	LCD_enuSendpcString("graduation Project    ");
	_delay_ms(700);
	LCD_enuSendCommand(FIRST_LINE);
	LCD_enuSendpcString("ELECTRIC WATER			");
	LCD_enuSendCommand(SECOND_LINE);
	LCD_enuSendpcString("HEATER SYSTEM	 		");
	_delay_ms(1000);
	/*---------- PROJECT Message ----------*/


	//setting initial temp. and fill array
	EEPROM_enuReadByteFromAddress(0x0000,&Global_u8_tReadData);
	if(Global_u8_tReadData != 0xFF)
		{
			Global_u16_tDesiredTemp = Global_u8_tReadData;
		}
	else
		{
			Global_u16_tDesiredTemp = 60;
		}
	// Save desired temp in EEPROM, which is the INITIAL_DESIRED_TEMP.

	EEPROM_enuWriteByteToAddress(0x0000,Global_u16_tDesiredTemp);

	/*---------- Welcome Message ----------*/

	//LCD_enuSendCommand(SECOND_LINE+12);
	//LCD_enuDisplayIntegerNum(Global_u16_tDesiredTemp);
	LCD_enuSendCommand(FIRST_LINE);
	LCD_enuSendpcString("                   ");
	LCD_enuSendCommand(SECOND_LINE);
	LCD_enuSendpcString("SAVED Temp=   C	");
	LCD_enuSendCommand(SECOND_LINE +12);
	LCD_enuDisplayIntegerNum(Global_u16_tDesiredTemp);
	_delay_ms(1500);
	/*---------- Welcome Message ----------*/

	/*The Function to be used in Callback must be built|| declared before using*/
	//EXTI_enuCallBack( (volatile void (*) (void)) SYSTEM_enuSettingState,ON_OFF_SWITCH);
	return Local_enuErrorState;
}


void SYSTEM_vTogSevenSeg (void)
{
	SevenSegment_enuDisableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[0]);
	SevenSegment_enuDisableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[1]);

}
ES_t LED_SYSTEM_enuSystemToggle(void)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	/* SETPIN */
	/*The bug reason is here because second condition*/
	/*Hopefuly the bug has been solved
	 * confermation, bug is fixed on 28/3/2022 tarek eldallal.*/
	if (Global_u8_tCurrentState==ON_STATE && (Global_u16_tDesiredTemp > Global_u16_tAverageTemp - FIVE_TEMP_DEGREE))
	{
		LED_SYSTEM_enuLedToggle();
		if  (Global_u16_tDesiredTemp < Global_u16_tAverageTemp + FIVE_TEMP_DEGREE)
		{
			LED_SYSTEM_enuLedStop();

		}
	}
	else if(Global_u8_tCurrentState==SETTINT_STATE)
	{
		SYSTEM_vTogSevenSeg();

	}
	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;

}

ES_t SYSTEM_enuChangeTemp(void){
	ES_t Local_enu_ErrorState = ES_NOK;
	/*SYSTEM IN IDLE STATE NO NEED FOR ACTION*/
	if( (Global_u16_tDesiredTemp < Global_u16_tAverageTemp + FIVE_TEMP_DEGREE) && (Global_u16_tDesiredTemp > Global_u16_tAverageTemp - FIVE_TEMP_DEGREE) )
	{
		// Actual Temperature is in ten dergee range of the Desired set Temperature
		// Neither Heating or Cooling Systems are needed
		HEAT_COOL_ELEMENTS_enuHeaterStop();
		HEAT_COOL_ELEMENTS_enuCoolerStop();
		LED_SYSTEM_enuLedStop();
	}

	else if(Global_u16_tDesiredTemp < Global_u16_tAverageTemp + FIVE_TEMP_DEGREE)
	{
		// Actual Temperature is Higher than the saved desired temperature
		// The Cooling system is needed

		HEAT_COOL_ELEMENTS_enuHeaterStop();
		HEAT_COOL_ELEMENTS_enuCoolerStart();
		LED_SYSTEM_enuLedStart();

	}
	else if (Global_u16_tDesiredTemp > Global_u16_tAverageTemp - FIVE_TEMP_DEGREE)
	{
		// Actual Temperature is Lower than the saved desired temperature
		// The Heating system is needed

		HEAT_COOL_ELEMENTS_enuHeaterStart();
		HEAT_COOL_ELEMENTS_enuCoolerStop();
		/*------------------ TOGGLE THE LED EVERY ONE SECOND -----------------*/
		TIMER0_enuSetCallBackDelay(( void (*) (void))LED_SYSTEM_enuSystemToggle,TIMER0_CTC_INDEX,TIMER0_DELAY_ONE_SECOND);

		/*
		if (Global_u16_tOne_SecondToggleFlag == RISED)
		{
			LED_SYSTEM_enuLedStart();

		}
		else {
			LED_SYSTEM_enuLedStop();
		}
		*/

	}
	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}


ES_t SYSTEM_enuOnState(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	u16_t Local_u16_tNewTempReading;

	SevenSegment_enuEnableCommon(SEVENSEGMENT_AstrSevenSegmentConfig);
/*
	LCD_enuSendCommand(SECOND_LINE);
	LCD_enuSendpcString("              ");
	LCD_enuSendCommand(FIRST_LINE);
	LCD_enuSendpcString("Setting Mode On");
	LCD_enuSendCommand(SECOND_LINE);
	LCD_enuSendpcString("Saved Temp=    C");
	LCD_enuSendCommand(SECOND_LINE+12);
	LCD_enuDisplayIntegerNum(Global_u16_tSavedTemp);
	_delay_ms(1000);
*/

/*----------------------------- POWERED BY THE TIMER1 INTERRUPRT ---------------------------------------*/
/*
 * TempSensor_enuGetTempReading() Function depends on the TempSensor_enuInit() Function:
 * Which Contain :	Two CallBack Function for Timer1 Interrupt and ADC Interrupt: Both aim to
 * read the Value of the ADC readying every 100m second.
 * 					 TIMER1_enuSetCallBackDelay((volatile void (*) (void) ) ADC_enuEnableADC,TIMER_CTC1B_INTERRUPT_INDEX,TIMER1_100_MILE_SECOND);
 * 					 ADC_enuCallBack( (volatile void (*) (void) ) TempSensor_RiseFlag);
 */

	TempSensor_enuGetTempReading(&Local_u16_tNewTempReading);

	SYSTEM_enuAddNewTemp(Global_Au16_tTempArr,Local_u16_tNewTempReading);
	SYSTEM_enuCalculateAverateTemp(Global_Au16_tTempArr, &Global_u16_tAverageTemp);


	//LCD_enuSendCommand(SECOND_LINE);
	//LCD_enuSendpcString("                ");
	LCD_enuSendCommand(FIRST_LINE);
	LCD_enuSendpcString("NORMAL MODE ON  	");
	LCD_enuSendCommand(SECOND_LINE);
	LCD_enuSendpcString("Actual Temp=    C");
	LCD_enuSendCommand(SECOND_LINE +13);
	LCD_enuDisplayIntegerNum(Global_u16_tAverageTemp);
	SevenSegment_Write(Global_u16_tAverageTemp);
	SYSTEM_enuChangeTemp();

	/*------------------- Listen for the UP|DOWN SWITCHES IF CHANGE OCCURES
	 *------------------- THEN, CHANGE THE CURRENT STATE MODE -------------------------*/

	if(Global_u8_tUPSwitchFlag==RISED||Global_u8_tDOWNSwitchFlag ==RISED)
	{

		Global_u8_tCurrentState= SETTINT_STATE;
		Global_u8_tUPSwitchFlag=NOT_RISED;
		Global_u8_tDOWNSwitchFlag=NOT_RISED;
		LCD_enuSendCommand(FIRST_LINE);
		LCD_enuSendpcString("                ");
		LCD_enuSendCommand(SECOND_LINE);
		LCD_enuSendpcString("                ");

		LCD_enuSendCommand(FIRST_LINE);
		LCD_enuSendpcString("Welcome to the    ");
		LCD_enuSendCommand(SECOND_LINE);
		LCD_enuSendpcString("Setting Mode      ");
		_delay_ms(500);
	}

	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;

}

void SYSTEM_vFiveSecondsInSettingMode(void)
{
		if (Global_u16_tFive_SecondToggleFlag ==1 && Global_u8_tCurrentState == SETTINT_STATE)
		{
			Global_u8_tCurrentState = ON_STATE;
			Global_u16_tFive_SecondToggleFlag=0;
		}
		/* else if  (Global_u16_tFive_SecondToggleFlag ==1 && Global_u8_tCurrentState== ON_STATE)
			{
				Global_u8_tCurrentState =SETTINT_STATE;
				Global_u16_tFive_SecondToggleFlag=0;
			}*/

}
ES_t SYSTEM_enuSettingState(void)
{
	ES_t Local_enuErrorState =ES_NOK;

	HEAT_COOL_ELEMENTS_enuCoolerStop();
	HEAT_COOL_ELEMENTS_enuHeaterStop();
	LED_SYSTEM_enuLedStop();

	/*------------------ Toggle the SevenSegment every 5 Seconds -------------------*/
	//TIMER0_enuSetCallBackDelay((volatile void (*)(void))SYSTEM_vTogSevenSeg/*new fuction to toggle the sevensegment*/,TIMER0_CTC_INDEX,DELAY_FIVE_SECONDS);


	LCD_enuSendCommand(FIRST_LINE);
	LCD_enuSendpcString("Setting Mode On   ");
	LCD_enuSendCommand(SECOND_LINE);
	LCD_enuSendpcString("Desired Temp=   C ");
	LCD_enuSendCommand(SECOND_LINE+13);
	LCD_enuDisplayIntegerNum(Global_u16_tDesiredTemp);
	SevenSegment_Write(Global_u16_tDesiredTemp);
//	Global_32_tTIMER1_CTCA_SecondsCounter==TIMER1_DELAY_FIVE_SECONDS

	_delay_ms(1000);

	if (Global_u8_tUPSwitchFlag == RISED && (Global_u16_tDesiredTemp < MAXIMUM_TEMP))
	{
		Global_u16_tDesiredTemp = Global_u16_tDesiredTemp + FIVE_TEMP_DEGREE;
		SevenSegment_Write(Global_u16_tDesiredTemp);
		Global_u8_tUPSwitchFlag=NOT_RISED;

	}

	else if (Global_u8_tDOWNSwitchFlag == RISED&& (Global_u16_tDesiredTemp > MINIMUM_TEMP))
		{
			Global_u16_tDesiredTemp = Global_u16_tDesiredTemp - FIVE_TEMP_DEGREE;
			SevenSegment_Write(Global_u16_tDesiredTemp);
			Global_u8_tDOWNSwitchFlag= NOT_RISED;
		}
	if (Global_u8_tDOWNSwitchFlag == NOT_RISED && Global_u8_tUPSwitchFlag == NOT_RISED)
	{
		TIMER1_enuSetCallBackDelay((void (*)(void))SYSTEM_vFiveSecondsInSettingMode, TIMER_CTC1A_INTERRUPT_INDEX, TIMER1_DELAY_FIVE_SECONDS);

	}
	//TIMER1_enuStartTimer();




	EEPROM_enuWriteByteToAddress(0x0000,Global_u16_tDesiredTemp);
/*EDIT THE TIME OF BLINKING THE SSD*/


	/*------------------------- Here need to exit the setting mode after 5 seconds of no change ----------------------------------*/



	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;

}


ES_t SYSTEM_enuSleepMode(void){
	ES_t Local_enu_ErrorState = ES_NOK;
	/*Sleep Mode Select --> IDLE STATE*/
	MCUCR&=~(1<<MCUCR_SM0);
	MCUCR&=~(1<<MCUCR_SM1);
	MCUCR&=~(1<<MCUCR_SM2);
	/* Sleep mode Enable */
	MCUCR|=(1<<MCUCR_SE);

	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}

ES_t SYSTEM_enuOffState(void)
{
	ES_t Local_enuErrorState =ES_NOK;

		SevenSegment_enuDisableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[0]);
		SevenSegment_enuDisableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[1]);
		LCD_enuClearDisplay();
		LED_SYSTEM_enuLedStop();
		HEAT_COOL_ELEMENTS_enuHeaterStop();
		HEAT_COOL_ELEMENTS_enuCoolerStop();
		//TIMER0_enuStopTimer();
		//TIMER1_enuStopTimer();
		/*Power Management and Sleep Modes*/
		SYSTEM_enuSleepMode();

	Local_enuErrorState=ES_OK;
	return Local_enuErrorState;
}




/*
ES_t SYSTEM_enuDisplayTemp(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	SevenSegment_Write(Global_u16_tAverageTemp);
	LCD_enuSendCommand(SECOND_LINE+12);
	LCD_enuDisplayIntegerNum(Global_u16_tAverageTemp);
	return Local_enuErrorState;
}
*/






ISR(VECT_INT0) //TEMP_UP_SWITCH
{
	if (Global_u8_tUPSwitchFlag==NOT_RISED)
	{
		Global_u8_tUPSwitchFlag=RISED;
	}

}

ISR(VECT_INT1)	//TEMP_DOWN_SWITCH
{
	if (Global_u8_tDOWNSwitchFlag==NOT_RISED)
	{
		Global_u8_tDOWNSwitchFlag=RISED;
	}


}
ISR(VECT_INT2)	//ON_OFF_SWITCH
{
	if(Global_u8_tCurrentState==OFF_STATE)
	{
		Global_u8_tCurrentState = ON_STATE;
		EEPROM_enuReadByteFromAddress(0x0000,&Global_u8_tReadData);
		Global_u16_tDesiredTemp = Global_u8_tReadData;
	}
	else if (Global_u8_tCurrentState==ON_STATE || Global_u8_tCurrentState==SETTINT_STATE){
		Global_u8_tCurrentState = OFF_STATE;
	}
}

/*- Timer 2 is responsible for the five seconds delay between the setting mode and the normal mode when no switch is pressed in setting mode ------*/
ISR (VECT_TIMER2_CTC)
{

	if(Global_u8_tCurrentState==SETTINT_STATE || Global_u8_tCurrentState== ON_STATE)
	{
		Global_u16_tFive_SecondCounter ++;
		if (Global_u16_tFive_SecondCounter == FIVE_SECONDS)
		{

			Global_u16_tFive_SecondToggleFlag=1;
		}
	}

}
