/*
 * DIO_program.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Tarek ElDallal
 */
#include "../../LIBRARIES/std_types.h"
#include "../../LIBRARIES/error_state.h"
#include"DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"




/*1-Initialization*/ //Void for PreBuild Configuration level

ES_t DIO_enuInit(void)
{
ES_t Local_enuErrorState = ES_NOK;

DDRA=INIT_DDR_DIRECTION;
PORTA=  INIT_PORT_VALUE;

return Local_enuErrorState;
}
/*2-SetPinDirection[input/output]*/
ES_t DIO_enuSetPinDirection(u8_t Copy_u8_tPortID, u8_t Copy_u8_tPinID, u8_t Copy_u8_tDirection)
{
	ES_t Local_enuErrorState = ES_NOK;
if(Copy_u8_tPortID<=DIO_u8_tPORT_D&&Copy_u8_tPinID<=DIO_u8_tPIN7&&Copy_u8_tDirection<=DIO_u8_tOUTPUT)
	{
		switch(Copy_u8_tPortID)
		{
		case DIO_u8_tPORT_A:
			DDRA &=~(DIO_MASK_BIT<<Copy_u8_tPinID);
			DDRA |= (Copy_u8_tDirection<<Copy_u8_tPinID);
			break;
		case DIO_u8_tPORT_B:
					DDRB &=~(DIO_MASK_BIT<<Copy_u8_tPinID);
					DDRB |= (Copy_u8_tDirection<<Copy_u8_tPinID);
					break;
		case DIO_u8_tPORT_C:
					DDRC &=~(DIO_MASK_BIT<<Copy_u8_tPinID);
					DDRC |= (Copy_u8_tDirection<<Copy_u8_tPinID);
					break;
		case DIO_u8_tPORT_D:
					DDRD &=~(DIO_MASK_BIT<<Copy_u8_tPinID);
					DDRD |= (Copy_u8_tDirection<<Copy_u8_tPinID);
					break;
		}
		 Local_enuErrorState = ES_OK;
	}

		else
		{
		Local_enuErrorState = ES_OUT_OF_RANG;
		}
	return  Local_enuErrorState;
}
/*3-SetPinValue*/
ES_t DIO_enuSetPinValue(u8_t Copy_u8_tPortID, u8_t Copy_u8_tPinID, u8_t Copy_u8_tValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8_tPortID<=DIO_u8_tPORT_D	&&Copy_u8_tPinID<=DIO_u8_tPIN7&&(Copy_u8_tValue<=DIO_u8_tHIGH ||Copy_u8_tValue<=DIO_u8_tPULL_UP))
		{
			switch(Copy_u8_tPortID)
			{
			case DIO_u8_tPORT_A:
						PORTA &=~(DIO_MASK_BIT<<Copy_u8_tPinID);
						PORTA |= (Copy_u8_tValue<<Copy_u8_tPinID);
						break;
			case DIO_u8_tPORT_B:
						PORTB &=~(DIO_MASK_BIT<<Copy_u8_tPinID);
						PORTB |= (Copy_u8_tValue<<Copy_u8_tPinID);
						break;
			case DIO_u8_tPORT_C:
						PORTC &=~(DIO_MASK_BIT<<Copy_u8_tPinID);
						PORTC |= (Copy_u8_tValue<<Copy_u8_tPinID);
						break;
			case DIO_u8_tPORT_D:
						PORTD &=~(DIO_MASK_BIT<<Copy_u8_tPinID);
						PORTD |= (Copy_u8_tValue<<Copy_u8_tPinID);
						break;
			}
			 Local_enuErrorState = ES_OK;
		}

			else
			{
				 Local_enuErrorState = ES_OUT_OF_RANG;
			}
		return  Local_enuErrorState;
}

/*4-GetPin*/
ES_t DIO_enuGetPinValue(u8_t Copy_u8_tPortID, u8_t Copy_u8_tPinID,u8_t *Copy_pu8_tValue)
{

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pu8_tValue!= NULL)
	{
		if(Copy_u8_tPortID<=DIO_u8_tPORT_D	&&Copy_u8_tPinID<=DIO_u8_tPIN7)
		{
			switch(Copy_u8_tPortID)
					{
					case DIO_u8_tPORT_A:
								*Copy_pu8_tValue=((PINA>>Copy_u8_tPinID) &DIO_MASK_BIT);

								break;
					case DIO_u8_tPORT_B:
						*Copy_pu8_tValue=(PINB>>Copy_u8_tPinID) &DIO_MASK_BIT;

								break;
					case DIO_u8_tPORT_C:
						*Copy_pu8_tValue=(PINC>>Copy_u8_tPinID) &DIO_MASK_BIT;

								break;
					case DIO_u8_tPORT_D:
						*Copy_pu8_tValue=(PIND>>Copy_u8_tPinID) &DIO_MASK_BIT;

								break;
					}
					 Local_enuErrorState = ES_OK;
				}

			else
			{
				Local_enuErrorState = ES_OUT_OF_RANG;
			}
		}
	else
		{
		Local_enuErrorState = ES_NULL_POINTER;
		}

	return Local_enuErrorState;
}


/*5-TogglePin*/
ES_t DIO_enuTogPinValue(u8_t Copy_u8_tPortID, u8_t Copy_u8_tPinID)
{

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8_tPortID<=DIO_u8_tPORT_D	&&Copy_u8_tPinID<=DIO_u8_tPIN7)
		{
			switch(Copy_u8_tPortID)
			{
			case DIO_u8_tPORT_A:
						PORTA ^=(DIO_MASK_BIT<<Copy_u8_tPinID);
						break;
			case DIO_u8_tPORT_B:
						PORTB ^=(DIO_MASK_BIT<<Copy_u8_tPinID);
						break;
			case DIO_u8_tPORT_C:
						PORTC ^=(DIO_MASK_BIT<<Copy_u8_tPinID);
						break;
			case DIO_u8_tPORT_D:
						PORTD ^=(DIO_MASK_BIT<<Copy_u8_tPinID);
						break;
			}
			 Local_enuErrorState = ES_OK;
		}

			else
			{
				 Local_enuErrorState = ES_OUT_OF_RANG;
			}

	return Local_enuErrorState;

}

