/*
 * SEVENSEGMENT_program.c
 *
 *  Created on: Oct 13, 2021
 *      Author: Tarek ElDallal
 */
#include "../../LIBRARIES/error_state.h"
#include "../../LIBRARIES/std_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SEVENSEGMENT_config.h"
#include "SEVENSEGMENT_private.h"
#include <util/delay.h>

extern SSG_t SEVENSEGMENT_AstrSevenSegmentConfig [SSG_NUMBER];


ES_t SevenSegment_enuInit(SSG_t * Copy_pAstrSevenSegmentConf)
{
ES_t Local_enuErrorState	=ES_NOK;

u8_t Local_u8_tIterator;
u32_t Local_u32_tErrorState;
for(Local_u8_tIterator=0;Local_u8_tIterator<SSG_NUMBER;Local_u8_tIterator++)
{
	Local_u32_tErrorState=	DIO_enuSetPinDirection(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinA_Port,Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinA_Pin,DIO_u8_tOUTPUT);
	Local_u32_tErrorState=	DIO_enuSetPinDirection(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinB_Port,Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinB_Pin,DIO_u8_tOUTPUT)<< TWO_BITS_SHIFT;
	Local_u32_tErrorState=	DIO_enuSetPinDirection(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinC_Port,Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinC_Pin,DIO_u8_tOUTPUT)<< FOUR_BITS_SHIFT;
	Local_u32_tErrorState=	DIO_enuSetPinDirection(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinD_Port,Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinD_Pin,DIO_u8_tOUTPUT)<< SIX_BITS_SHIFT;
	Local_u32_tErrorState=	DIO_enuSetPinDirection(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinE_Port,Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinE_Pin,DIO_u8_tOUTPUT)<< EIGHT_BITS_SHIFT;
	Local_u32_tErrorState=	DIO_enuSetPinDirection(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinF_Port,Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinF_Pin,DIO_u8_tOUTPUT)<< TEN_BITS_SHIFT;
	Local_u32_tErrorState=	DIO_enuSetPinDirection(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinG_Port,Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_PinG_Pin,DIO_u8_tOUTPUT)<< TWELVE_BITS_SHIFT;

	//COMMENT AND DOT PIN IF CONNECTED set direction output

	if(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_Common_Port != NOT_CONNECTED &&Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_Common_Pin != NOT_CONNECTED )
	{
		DIO_enuSetPinDirection(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_Common_Port,Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_Common_Pin,DIO_u8_tOUTPUT);

	}

	if(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_Dot_Port != NOT_CONNECTED &&Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_Dot_Pin != NOT_CONNECTED )
		{
			DIO_enuSetPinDirection(Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_Dot_Port,Copy_pAstrSevenSegmentConf[Local_u8_tIterator].SSG_Dot_Pin,DIO_u8_tOUTPUT);

		}
}
if(Local_u32_tErrorState== SSG_CHECKVALUE)
{
Local_enuErrorState=ES_OK;
}
return Local_enuErrorState;

}//end of initialization

ES_t SevenSegment_enuDisplayNumber(SSG_t * Copy_pstrSevenSegmentInfo ,u8_t Copy_u8_tNumber)
{
	ES_t Local_enuErrorState	=ES_NOK;
	u32_t Local_u32_tErrorState;

		/*Boundary check*/

	if(Copy_pstrSevenSegmentInfo->SSG_Type == COMMON_ANODE)
	{
		/*Representation of the sent number*/
		Copy_u8_tNumber= ~ SEVENSEGMENT_Au8_tCOMMON_CATHODE_VALUES[Copy_u8_tNumber];
	}
	else if (Copy_pstrSevenSegmentInfo->SSG_Type == COMMON_CATHOND)
	{
		/*Representation of the sent number*/
			Copy_u8_tNumber=  SEVENSEGMENT_Au8_tCOMMON_CATHODE_VALUES[Copy_u8_tNumber];
	}

	Local_u32_tErrorState = DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinA_Port, Copy_pstrSevenSegmentInfo->SSG_PinA_Pin, (( Copy_u8_tNumber>>0)&1) );
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinB_Port, Copy_pstrSevenSegmentInfo->SSG_PinB_Pin,((Copy_u8_tNumber>>1)&1))<< TWO_BITS_SHIFT;
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinC_Port, Copy_pstrSevenSegmentInfo->SSG_PinC_Pin,((Copy_u8_tNumber>>2)&1))<< FOUR_BITS_SHIFT;
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinD_Port, Copy_pstrSevenSegmentInfo->SSG_PinD_Pin,((Copy_u8_tNumber>>3)&1))<< SIX_BITS_SHIFT;
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinE_Port, Copy_pstrSevenSegmentInfo->SSG_PinE_Pin,((Copy_u8_tNumber>>4)&1))<< EIGHT_BITS_SHIFT;
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinF_Port, Copy_pstrSevenSegmentInfo->SSG_PinF_Pin,((Copy_u8_tNumber>>5)&1))<< TEN_BITS_SHIFT;
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinG_Port, Copy_pstrSevenSegmentInfo->SSG_PinG_Pin,((Copy_u8_tNumber>>6)&1))<< TWELVE_BITS_SHIFT;
	if(Local_u32_tErrorState== SSG_CHECKVALUE)
	{
	Local_enuErrorState=ES_OK;
	}

	return Local_enuErrorState;
}
ES_t SevenSegment_enuToggleDisplay(SSG_t * Copy_pstrSevenSegmentInfo)
{
	ES_t Local_enuErrorState	=ES_NOK;
if(Copy_pstrSevenSegmentInfo->SSG_Common_Port != NOT_CONNECTED
		&& Copy_pstrSevenSegmentInfo->SSG_Common_Pin !=NOT_CONNECTED)
{
	if(Copy_pstrSevenSegmentInfo->SSG_Type ==COMMON_ANODE)
	{

		DIO_enuTogPinValue(Copy_pstrSevenSegmentInfo->SSG_Common_Port, Copy_pstrSevenSegmentInfo->SSG_Common_Pin);
	}
	else if(Copy_pstrSevenSegmentInfo->SSG_Type ==COMMON_CATHOND)
	{
		DIO_enuTogPinValue(Copy_pstrSevenSegmentInfo->SSG_Common_Port, Copy_pstrSevenSegmentInfo->SSG_Common_Pin);
	}
	Local_enuErrorState=ES_OK;
}




	return Local_enuErrorState;
}

ES_t SevenSegment_enuEnableCommon(SSG_t * Copy_pstrSevenSegmentInfo)
{
	ES_t Local_enuErrorState	=ES_NOK;
if(Copy_pstrSevenSegmentInfo->SSG_Common_Port != NOT_CONNECTED
		&& Copy_pstrSevenSegmentInfo->SSG_Common_Pin !=NOT_CONNECTED)
{
	if(Copy_pstrSevenSegmentInfo->SSG_Type ==COMMON_ANODE)
	{
		DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_Common_Port, Copy_pstrSevenSegmentInfo->SSG_Common_Pin,DIO_u8_tHIGH);
	}
	else if(Copy_pstrSevenSegmentInfo->SSG_Type ==COMMON_CATHOND)
	{
		DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_Common_Port, Copy_pstrSevenSegmentInfo->SSG_Common_Pin,DIO_u8_tLOW);
	}
	Local_enuErrorState=ES_OK;
}




	return Local_enuErrorState;
}

ES_t SevenSegment_enuDisableCommon(SSG_t * Copy_pstrSevenSegmentInfo)
{
	ES_t Local_enuErrorState	=ES_NOK;

	if(Copy_pstrSevenSegmentInfo->SSG_Common_Port != NOT_CONNECTED
			&& Copy_pstrSevenSegmentInfo->SSG_Common_Pin !=NOT_CONNECTED)
	{
		if(Copy_pstrSevenSegmentInfo->SSG_Type ==COMMON_ANODE)
		{
			DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_Common_Port, Copy_pstrSevenSegmentInfo->SSG_Common_Pin,DIO_u8_tLOW);
		}
		else if(Copy_pstrSevenSegmentInfo->SSG_Type ==COMMON_CATHOND)
		{
			DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_Common_Port, Copy_pstrSevenSegmentInfo->SSG_Common_Pin,DIO_u8_tHIGH);
		}
		Local_enuErrorState=ES_OK;
	}


	return Local_enuErrorState;
}

ES_t SevenSegment_enuEnableDot(SSG_t * Copy_pstrSevenSegmentInfo)
{
	ES_t Local_enuErrorState	=ES_NOK;

	if(Copy_pstrSevenSegmentInfo->SSG_Dot_Port != NOT_CONNECTED
			&& Copy_pstrSevenSegmentInfo->SSG_Dot_Pin !=NOT_CONNECTED)
	{
		if(Copy_pstrSevenSegmentInfo->SSG_Type ==COMMON_ANODE)
		{
			DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_Dot_Port, Copy_pstrSevenSegmentInfo->SSG_Dot_Pin,DIO_u8_tLOW);
		}
		else if(Copy_pstrSevenSegmentInfo->SSG_Type ==COMMON_CATHOND)
		{
			DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_Dot_Port, Copy_pstrSevenSegmentInfo->SSG_Dot_Pin,DIO_u8_tHIGH);
		}
		Local_enuErrorState=ES_OK;
	}


	return Local_enuErrorState;
}
ES_t SevenSegment_enuDisableDot(SSG_t * Copy_pstrSevenSegmentInfo)
{
	ES_t Local_enuErrorState	=ES_NOK;

	if(Copy_pstrSevenSegmentInfo->SSG_Dot_Port != NOT_CONNECTED
			&& Copy_pstrSevenSegmentInfo->SSG_Dot_Pin !=NOT_CONNECTED)
	{
		if(Copy_pstrSevenSegmentInfo->SSG_Type ==COMMON_ANODE)
		{
			DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_Dot_Port, Copy_pstrSevenSegmentInfo->SSG_Dot_Pin,DIO_u8_tHIGH);
		}
		else if(Copy_pstrSevenSegmentInfo->SSG_Type ==COMMON_CATHOND)
		{
			DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_Dot_Port, Copy_pstrSevenSegmentInfo->SSG_Dot_Pin,DIO_u8_tLOW);
		}
		Local_enuErrorState=ES_OK;
	}



	return Local_enuErrorState;
}

/*Will disable it pin by pin*/
ES_t SevenSegment_enuStopDisplay(SSG_t * Copy_pstrSevenSegmentInfo) /*stop display the common on GIO*/
{
	ES_t Local_enuErrorState	=ES_NOK;
	u8_t Local_u8_tStopValue=ZeroValue;
	u32_t Local_u32_tErrorState;
	if(Copy_pstrSevenSegmentInfo->SSG_Type == COMMON_CATHOND)
	{
		Local_u8_tStopValue= ~Local_u8_tStopValue; //255
	}

	Local_u32_tErrorState = DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinA_Port, Copy_pstrSevenSegmentInfo->SSG_PinA_Pin,((Local_u8_tStopValue>>0)&1));
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinB_Port, Copy_pstrSevenSegmentInfo->SSG_PinB_Pin,((Local_u8_tStopValue>>1)&1))<< TWO_BITS_SHIFT;
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinC_Port, Copy_pstrSevenSegmentInfo->SSG_PinC_Pin,((Local_u8_tStopValue>>2)&1))<< FOUR_BITS_SHIFT;
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinD_Port, Copy_pstrSevenSegmentInfo->SSG_PinD_Pin,((Local_u8_tStopValue>>3)&1))<< SIX_BITS_SHIFT;
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinE_Port, Copy_pstrSevenSegmentInfo->SSG_PinE_Pin,((Local_u8_tStopValue>>4)&1))<< EIGHT_BITS_SHIFT;
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinF_Port, Copy_pstrSevenSegmentInfo->SSG_PinF_Pin,((Local_u8_tStopValue>>5)&1))<< TEN_BITS_SHIFT;
	Local_u32_tErrorState|= DIO_enuSetPinValue(Copy_pstrSevenSegmentInfo->SSG_PinG_Port, Copy_pstrSevenSegmentInfo->SSG_PinG_Pin,((Local_u8_tStopValue>>6)&1))<< TWELVE_BITS_SHIFT;
	if(Local_u32_tErrorState== SSG_CHECKVALUE)
	{
	Local_enuErrorState=ES_OK;
	}

	return Local_enuErrorState;
}






void SevenSegment_Write(u8_t Copy_u8_tNumber)
{
	u8_t units,tens;
					units = Copy_u8_tNumber % 10;
					tens = (int) Copy_u8_tNumber / 10;

					SevenSegment_enuDisableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[0]);
					SevenSegment_enuDisplayNumber(&SEVENSEGMENT_AstrSevenSegmentConfig[1],units);
					SevenSegment_enuEnableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[1]);


					_delay_ms(3.1);

					SevenSegment_enuDisableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[1]);
					SevenSegment_enuDisplayNumber(&SEVENSEGMENT_AstrSevenSegmentConfig[0],tens);
					SevenSegment_enuEnableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[0]);
					_delay_ms(1.1);
}









/*
ES_t SevenSegment_enuwrite(u16_t Copy_u16_tNumber){
	ES_t Local_enuErrorState	=ES_NOK;
	u8_t units;
	u8_t tens;

	units = Copy_u16_tNumber % 10;
	tens = (int) Copy_u16_tNumber / 10;

	SevenSegment_enuEnableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[0]);
	SevenSegment_enuDisableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[1]);

	//SSD_enable(DISP1);
	SevenSegment_enuDisplayNumber(&SEVENSEGMENT_AstrSevenSegmentConfig[0],units);

//	SSD_send(units);
	_delay_ms(5);
	SevenSegment_enuDisableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[0]);
	SevenSegment_enuEnableCommon(&SEVENSEGMENT_AstrSevenSegmentConfig[1]);
	//SSD_enable(DISP2);
	SevenSegment_enuDisplayNumber(&SEVENSEGMENT_AstrSevenSegmentConfig[1],tens);
	//SSD_send(tens);
	_delay_ms(5);
	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;

}
*/
