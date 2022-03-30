/*
 * HEAT_COOL_Elements_config.h
 *
 *  Created on: Mar 19, 2022
 *      Author: Tarek ElDallal
 */

#ifndef HAL_HEAT_COOL_HEAT_COOL_ELEMENTS_CONFIG_H_
#define HAL_HEAT_COOL_HEAT_COOL_ELEMENTS_CONFIG_H_

#define HE_PORT 		DIO_u8_tPORT_B
#define HE_PIN			DIO_u8_tPIN4

#define CE_PORT			DIO_u8_tPORT_B
#define CE_PIN			DIO_u8_tPIN5


#define HEAT_PORT_DIR 					DDRB
#define HEAT_PORT 						PORTB
#define HEAT_PIN 						4

#define COOL_PORT_DIR 					DDRB
#define COOL_PORT						PORTB
#define COOL_PIN 						5

#endif /* HAL_HEAT_COOL_HEAT_COOL_ELEMENTS_CONFIG_H_ */
