/*
 * TEMP_SENSOR_program.c
 *
 *  Created on: Feb 14, 2022
 *      Author: Tarek ElDallal
 */
#include "../../LIBRARIES/error_state.h"
#include "../../LIBRARIES/std_types.h"

#include "../../MCAL/interrupt.h"

#include "TEMP_SENSOR_interface.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "../../MCAL/ADC/ADC_config.h"
#include "../../MCAL/ADC/ADC_interface.h"


#include "../../MCAL/EXTI/EXTI_config.h"
#include "../../MCAL/EXTI/EXTI_interface.h"
#include "../../MCAL/TIMER/TIMER_interface.h"

#include "../../MCAL/GIE/GIE_interface.h"
#include "TEMP_SENSOR_private.h"

#include "TEMP_SENSOR_config.h"

extern EXTI_t EXTI_AstrEXTIConfig[TEMP_SENSOR_EXTERNAL_INTERRUPT_SOURCES];

 static  u8_t TempSensor_u8_tFlag =TEMP_SENSOR_FLAG_NOT_RISED;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------
 * Local Function:
 * Responsible for rising a local static flag.
 * --------------------------------------------------------------------------------------------------------------------------------------------------------*/
void TempSensor_RiseFlag (void)
{
	TempSensor_u8_tFlag =TEMP_SENSOR_FLAG_RISED;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------
 * Initialization Function:
 * - Set the direction and value of the Sensor reading voltage to the microcontroller.
 * --------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* ------ADDING THE TIMER1 COMPARE MATCH INTERRUPT ON CHANNEL B TO TRIGGER THE ADC 21/3 ------------- */

ES_t TempSensor_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	u32_t Local_u32_tErrorState=TEMPSENSOR_INITIALVALUE ;
	if (TEMP_SENSOR_PIN<= DIO_u8_tPIN7)
	{
		/*--------------------------------------------------------------------------------------------------------------------------------------------------------
		 *Identify the Temperature sensor pin Direction and value Among the ADC CHANNELS PORT A from PIN 0 to PIN 7
		 *
		 * --------------------------------------------------------------------------------------------------------------------------------------------------------*/

		Local_u32_tErrorState  = DIO_enuSetPinDirection(TEMP_SENSOR_PORT,TEMP_SENSOR_PIN,TEMP_SENSOR_DIRECTION);
		/*There was a bug in the next line. that was solved on 26/2/2022*/
		Local_u32_tErrorState |= (DIO_enuSetPinValue(TEMP_SENSOR_PORT,TEMP_SENSOR_PIN,TEMP_SENSOR_STATE)<<TWO_BITS_SHIFT);

		Local_u32_tErrorState |= (ADC_enuChannelSelect(ADC_CHANNEL_SELECTION)<<FOUR_BITS_SHIFT);
/* ------------------------------- ADDING THE TIMER COMPARE MATCH AUTO TRIGGERING 21/3 -----------------------*/
	#if ADC_AUTO_TRIGGERING_SOURCE	== ADC_u8_tExternalInterruptRequest_0
		DIO_enuSetPinDirection(DIO_u8_tPORT_D, DIO_u8_tPIN2, DIO_u8_tINPUT);
		DIO_enuSetPinValue(DIO_u8_tPORT_D, DIO_u8_tPIN2, DIO_u8_tFLOAT);
		EXTI_enuInit(EXTI_AstrEXTIConfig);
		/*--------------------------------------------------------------------------------------------------------------------------------------------------------
		 * External Interrupt Direction and value selection:
		 * Responsible for rising a local static flag.
		 * --------------------------------------------------------------------------------------------------------------------------------------------------------*/

		Local_u32_tErrorState |= (		ADC_enuAutoTriggerSource(ADC_AUTO_TRIGGERING_SOURCE)<<SIX_BITS_SHIFT);
	#elif  ADC_AUTO_TRIGGERING_SOURCE== ADC_u8_tTimerInterrupt_CompareMatchB
		/*AS PD4 OC1B is connected to the SSD, then it will be disconnected */
		//DIO_enuSetPinDirection(DIO_u8_tPORT_D, DIO_u8_tPIN4, DIO_u8_tOUTPUT);
		TIMER1_enuInit();
		//DIO_enuSetPinDirection(DIO_u8_tPORT_D,DIO_u8_tPIN4,DIO_u8_tOUTPUT);
		TIMER1_enuInterruptEnable();
		TIMER1_enuStartTimer();
		Local_u32_tErrorState |= (		ADC_enuAutoTriggerSource(ADC_AUTO_TRIGGERING_SOURCE)<<SIX_BITS_SHIFT);

	#elif  ADC_AUTO_TRIGGERING_SOURCE	== ADC_u8_tSingleConversion
		Local_u32_tErrorState |= (		ADC_enuAutoTriggerDisable()<<SIX_BITS_SHIFT);
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------
 * 		Local_u32_tErrorState |= (		ADC_enuStartConversion()<<EIGHTEEN_BITS_SHIFT);
-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	#elif ADC_AUTO_TRIGGERING_SOURCE	== ADC_u8_tFreeRunningMode
		Local_u32_tErrorState |= (		ADC_enuAutoTriggerSource(ADC_AUTO_TRIGGERING_SOURCE)<<SIX_BITS_SHIFT);
		Local_u32_tErrorState |= (		ADC_enuStartConversion()<<EIGHTEEN_BITS_SHIFT);
	#else
		Local_u32_tErrorState |= (		ADC_enuAutoTriggerSource(ADC_AUTO_TRIGGERING_SOURCE)<<TWENTY_BITS_SHIFT);
	#endif
	}

	Local_u32_tErrorState |= (ADC_enuEnableADC_Intrrupt()<<EIGHT_BITS_SHIFT);
	Local_u32_tErrorState |= (TIMER1_enuSetCallBackDelay((volatile void (*) (void) ) ADC_enuEnableADC,TIMER_CTC1B_INTERRUPT_INDEX,TIMER1_100_MILE_SECOND) /*ADC_enuEnableADC()*/<<TEN_BITS_SHIFT);
	Local_u32_tErrorState |= (ADC_enuCallBack( (volatile void (*) (void) ) TempSensor_RiseFlag)<<TWELVE_BITS_SHIFT);
	Local_u32_tErrorState |= (ADC_enuInit()<<FOURTEEN_BITS_SHIFT);
	GIE_enu_Enable();
	//*((volatile u8_t*)(0x34))= Local_u32_tErrorState>>8;
	//*((volatile u8_t*)(0x34))= Local_u32_tErrorState;

	//0b00000001;

//	*((volatile u8_t*)(0x31)) = 0b011000000;
	//*((volatile u8_t*)(0x34))=0b11;

	if(Local_u32_tErrorState == TEMPSENSOR_CEACKVALUE_SIXTEEN || Local_u32_tErrorState == TEMPSENSOR_CEACKVALUE_FOURTEEN || Local_u32_tErrorState == TEMPSENSOR_CEACKVALUE_TWENTY)
	{
		Local_enuErrorState = ES_OK;
//		*((volatile u8_t*)(0x34))=0b01;
	}

	return Local_enuErrorState;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------
 * Get tempreature reading Fuction:
 * --------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------- HERE I WANT THE SYSTEM TO SUM TEN TERMPERATURE READING THEN GET THE AVRADGE TO DISPLAY ----------*/

ES_t TempSensor_enuGetTempReading(u16_t * Copy_pu16_tTempReading)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8_t Local_u8_tErrorState=TEMPSENSOR_INITIALVALUE ;
	u16_t Local_u16_tADC_Reading, Local_u16_tOneTempReading;
	u32_t Local_u32_tADC_Voltage;

#if  ADC_AUTO_TRIGGERING_SOURCE	== ADC_u8_tSingleConversion
	Local_u8_tErrorState = ADC_enuStartConversion();

#endif

	if (TempSensor_u8_tFlag == TEMP_SENSOR_FLAG_RISED )
	{
		Local_u8_tErrorState = ADC_enuReadDataRegister(&Local_u16_tADC_Reading);
		/*----------------------------------- ADC READING CALCULATION -------------------------------*/
		Local_u32_tADC_Voltage = Local_u16_tADC_Reading * ADC_VOLTAGE_EQUATION_STEP;
//		*Copy_pu16_tTempReading = Local_u32_tADC_Voltage/ ADC_READING_DIVISION_FACTOR;
		Local_u16_tOneTempReading = Local_u32_tADC_Voltage/ ADC_READING_DIVISION_FACTOR;
		* Copy_pu16_tTempReading= Local_u16_tOneTempReading;
		TempSensor_u8_tFlag =TEMP_SENSOR_FLAG_NOT_RISED;
//		*((volatile u8_t*)(0x34))=*Copy_pu16_tTempReading;
	}
	if (Local_u8_tErrorState ==TEMPSENSOR_CEACKVALUE_ONE )
	{
		Local_enuErrorState = ES_OK;
		//*((volatile u8_t*)(0x34))=Local_u8_tErrorState;
	}
	return Local_enuErrorState;
}
