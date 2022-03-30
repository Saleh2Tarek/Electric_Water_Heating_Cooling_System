/*
 * EXTI_config.h
 *
*  Created on: Feb 11, 2022
 *      Author: Tarek ElDallal
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

typedef struct
{
	u8_t Int_State;
	u8_t Sence_level;
}EXTI_t;

#define INT_NUM 					3

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
