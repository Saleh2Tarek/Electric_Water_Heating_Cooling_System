/*
 * SWITCH_config.h
 *
 *  Created on: Oct 6, 2021
 *      Author: Tarek ElDallal
 */

#ifndef HAL_SWITCH_CONFIG_H_
#define HAL_SWITCH_CONFIG_H_

#define SW_NUM			3

//# define SWITCH_u8_tSwitchNumbers = SW_NUM;

typedef struct
{
		u8_t SW_Port;
		u8_t SW_Pin;
		u8_t SW_State;

}SW_t;


/*
#define SW_PORT		DIO_u8_tPORT_A
#define SW_PIN			DIO_u8_tPIN1
#define SW_STATE		DIO_u8_tFLOAT
*/

#endif /* HAL_SWITCH_CONFIG_H_ */
