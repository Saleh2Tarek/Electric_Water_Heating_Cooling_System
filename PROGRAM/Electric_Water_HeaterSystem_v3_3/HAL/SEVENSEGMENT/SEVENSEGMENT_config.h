/*
 * SEVENSEGMENT_config.h
 *
 *  Created on: Oct 13, 2021
 *      Author: Tarek ElDallal
 */

#ifndef HAL_SEVENSEGMENT_CONFIG_H_
#define HAL_SEVENSEGMENT_CONFIG_H_

#define SSG_NUMBER 								2

typedef  struct
{
	//SSG_Seven Pins
	u8_t SSG_PinA_Port;				u8_t SSG_PinA_Pin;
	u8_t SSG_PinB_Port;				u8_t SSG_PinB_Pin;
	u8_t SSG_PinC_Port;				u8_t SSG_PinC_Pin;
	u8_t SSG_PinD_Port;				u8_t SSG_PinD_Pin;
	u8_t SSG_PinE_Port;				u8_t SSG_PinE_Pin;
	u8_t SSG_PinF_Port;				u8_t SSG_PinF_Pin;
	u8_t SSG_PinG_Port;				u8_t SSG_PinG_Pin;


	u8_t SSG_Common_Port;				u8_t SSG_Common_Pin;
	u8_t SSG_Dot_Port;					u8_t SSG_Dot_Pin;

	u8_t SSG_Type;



}SSG_t;




#endif /* HAL_SEVENSEGMENT_CONFIG_H_ */
