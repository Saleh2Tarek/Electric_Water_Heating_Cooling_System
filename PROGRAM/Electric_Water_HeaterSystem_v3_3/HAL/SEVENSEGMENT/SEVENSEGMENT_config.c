/*
 * SEVENSEGMENT_config.c
 *
 *  Created on: Oct 13, 2021
 *      Author: Tarek ElDallal
 */
#include "../../LIBRARIES/error_state.h"
#include "../../LIBRARIES/std_types.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "SEVENSEGMENT_config.h"
#include "SEVENSEGMENT_private.h"

SSG_t SEVENSEGMENT_AstrSevenSegmentConfig [SSG_NUMBER]=
{
		/*FIRST SSG 19 */
		{
			DIO_u8_tPORT_C, DIO_u8_tPIN0,
			DIO_u8_tPORT_C, DIO_u8_tPIN1,
			DIO_u8_tPORT_C, DIO_u8_tPIN2,
			DIO_u8_tPORT_C, DIO_u8_tPIN3,
			DIO_u8_tPORT_C, DIO_u8_tPIN4,
			DIO_u8_tPORT_C, DIO_u8_tPIN5,
			DIO_u8_tPORT_C, DIO_u8_tPIN6,
			DIO_u8_tPORT_B, DIO_u8_tPIN6, //COMMON PORT & PIN
			NOT_CONNECTED, NOT_CONNECTED,//DOT	PORT & PIN
			COMMON_CATHOND
		},

		/*SECOND SSG*/

		{
			DIO_u8_tPORT_C, DIO_u8_tPIN0,
			DIO_u8_tPORT_C, DIO_u8_tPIN1,
			DIO_u8_tPORT_C, DIO_u8_tPIN2,
			DIO_u8_tPORT_C, DIO_u8_tPIN3,
			DIO_u8_tPORT_C, DIO_u8_tPIN4,
			DIO_u8_tPORT_C, DIO_u8_tPIN5,
			DIO_u8_tPORT_C, DIO_u8_tPIN6,
			DIO_u8_tPORT_B, DIO_u8_tPIN7, //COMMON PORT & PIN
			NOT_CONNECTED, NOT_CONNECTED,//DOT	PORT & PIN
			COMMON_CATHOND
		}


};

