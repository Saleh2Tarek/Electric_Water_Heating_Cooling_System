/*
 * SWITCH_program.c
 *
 *  Created on: Oct 6, 2021
 *      Author: Tarek ElDallal
 */
#include "../../LIBRARIES/std_types.h"
#include "../../LIBRARIES/error_state.h"
#include"../../MCAl/DIO/DIO_interface.h"

#include"SWITCH_config.h"
#include"SWITCH_private.h"


extern ES_t SWITCH_enuIniti(SW_t * Copy_pAstrSwitchConfig)
{
	ES_t Local_enu_ErrorState = ES_NOK;
	u8_t Local_u8_tIterator;
	for(Local_u8_tIterator=0;Local_u8_tIterator<SW_NUM;Local_u8_tIterator++)
	{
		/*Direction*/ DIO_enuSetPinDirection(Copy_pAstrSwitchConfig[Local_u8_tIterator].SW_Port,Copy_pAstrSwitchConfig[Local_u8_tIterator].SW_Pin, DIO_u8_tINPUT);
		/*SETPIN*/ DIO_enuSetPinValue((Copy_pAstrSwitchConfig+Local_u8_tIterator)->SW_Port,(Copy_pAstrSwitchConfig+Local_u8_tIterator)->SW_Pin,(Copy_pAstrSwitchConfig+Local_u8_tIterator)->SW_State);
	}
	Local_enu_ErrorState = ES_OK;
	return Local_enu_ErrorState;
}

extern ES_t SWITCH_enuGetState(SW_t * Copy_pAstrSwitchInfo,u8_t * Copy_pu8_tValue)
{
	ES_t Local_enu_ErrorState = ES_NOK;

	Local_enu_ErrorState = DIO_enuGetPinValue(Copy_pAstrSwitchInfo->SW_Port,Copy_pAstrSwitchInfo->SW_Pin, Copy_pu8_tValue);

	return Local_enu_ErrorState;

}

