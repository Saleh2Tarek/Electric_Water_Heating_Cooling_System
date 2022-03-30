/*
 * HEAT_COOL_Elements_program.c
 *
 *  Created on: Mar 19, 2022
 *      Author: Tarek ElDallal
 */

#include "../../LIBRARIES/std_types.h"
#include "../../LIBRARIES/error_state.h"
#include"../../MCAl/DIO/DIO_interface.h"

#include "../HEAT_COOL/HEAT_COOL_Elements_config.h"
#include "../HEAT_COOL/HEAT_COOL_Elements_private.h"

ES_t HEAT_COOL_ELEMENTS_enuIniti(void)
{
	ES_t Local_enu_ErrorState = ES_NOK;

		/* HEATING ELEMENT*/
		/* Direction */
	DIO_enuSetPinDirection(HE_PORT,HE_PIN, DIO_u8_tOUTPUT);
		/* SETPIN */
	DIO_enuSetPinValue(HE_PORT,HE_PIN,DIO_u8_tLOW);

	/* COOLING ELEMENT*/
		/* Direction */
	DIO_enuSetPinDirection(CE_PORT,CE_PIN, DIO_u8_tOUTPUT);
		/* SETPIN */
	DIO_enuSetPinValue(CE_PORT,CE_PIN,DIO_u8_tLOW);

	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}
ES_t HEAT_COOL_ELEMENTS_enuHeaterStart(void)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	/* SETPIN */
	DIO_enuSetPinValue(HE_PORT,HE_PIN,DIO_u8_tHIGH);
	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}
ES_t HEAT_COOL_ELEMENTS_enuHeaterToggle(void)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	/* SETPIN */
	DIO_enuTogPinValue(HE_PORT,HE_PIN);
	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}
ES_t HEAT_COOL_ELEMENTS_enuHeaterStop(void)

{
	ES_t Local_enu_ErrorState = ES_NOK;
	/* SETPIN */
	DIO_enuSetPinValue(HE_PORT,HE_PIN,DIO_u8_tLOW);
	Local_enu_ErrorState = ES_OK;
return Local_enu_ErrorState;
}
ES_t HEAT_COOL_ELEMENTS_enuCoolerStart(void)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	/* SETPIN */
	DIO_enuSetPinValue(CE_PORT,CE_PIN,DIO_u8_tHIGH);
	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}
ES_t HEAT_COOL_ELEMENTS_enuCoolerStop(void)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	/* SETPIN */
	DIO_enuSetPinValue(CE_PORT,CE_PIN,DIO_u8_tLOW);
	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}
