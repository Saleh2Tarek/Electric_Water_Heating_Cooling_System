/*
 * SWITCH_config.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Tarek ElDallal
 */

#include "../../LIBRARIES/std_types.h"
#include "../../LIBRARIES/error_state.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SWITCH_config.h"
#include "SWITCH_private.h"

//u8_t SWITCH_u8_tSwitchNumbers=SW_NUM;

SW_t SWITCH_AstrSwitchConfig [SW_NUM]=
{
		/* UP_SWITCH on Port B Pin0*/{DIO_u8_tPORT_D,DIO_u8_tPIN2,DIO_u8_tFLOAT},
		/* DOWN_SWITCH on Port B Pin1*/{DIO_u8_tPORT_D,DIO_u8_tPIN3,DIO_u8_tFLOAT},
		/* ON_OFF_SWITCH on Port B Pin2*/{DIO_u8_tPORT_B,DIO_u8_tPIN2,DIO_u8_tFLOAT}

};
