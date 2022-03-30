/*
 * HEAT_COOL_Elements_program.c
 *
 *  Created on: Mar 19, 2022
 *      Author: Tarek ElDallal
 */

#include "../../LIBRARIES/std_types.h"
#include "../../LIBRARIES/error_state.h"
#include"../../MCAl/DIO/DIO_interface.h"

#include "LED_SYSTEM_config.h"
#include "LED_SYSTEM_private.h"


ES_t LED_SYSTEM_enuIniti(void)
{
	ES_t Local_enu_ErrorState = ES_NOK;

		/* LED SYSTEM */
		/* Direction */
	DIO_enuSetPinDirection(LED_SYSTEM_PORT,LED_SYSTEM_PIN, DIO_u8_tOUTPUT);
		/* SETPIN */
	DIO_enuSetPinValue(LED_SYSTEM_PORT,LED_SYSTEM_PIN,DIO_u8_tLOW);


	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}
ES_t LED_SYSTEM_enuLedStart(void)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	/* SETPIN */
	DIO_enuSetPinValue(LED_SYSTEM_PORT,LED_SYSTEM_PIN,DIO_u8_tHIGH);
	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}
ES_t LED_SYSTEM_enuLedToggle(void)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	/* SETPIN */
	DIO_enuTogPinValue(LED_SYSTEM_PORT,LED_SYSTEM_PIN);
	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;

}
ES_t LED_SYSTEM_enuLedStop(void)

{
	ES_t Local_enu_ErrorState = ES_NOK;
	/* SETPIN */
	DIO_enuSetPinValue(LED_SYSTEM_PORT,LED_SYSTEM_PIN,DIO_u8_tLOW);
	Local_enu_ErrorState = ES_OK;
return Local_enu_ErrorState;
}
