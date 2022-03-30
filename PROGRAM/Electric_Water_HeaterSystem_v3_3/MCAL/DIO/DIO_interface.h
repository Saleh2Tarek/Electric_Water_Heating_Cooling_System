/*
 * DIO_interface.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Tarek ElDallal
 */

/*File_Guard*/
#ifndef MCAL_DIO_INTERFACE_H_
#define MCAL_DIO_INTERFACE_H_

/*-------------------------------------- DIGITAL INPUT OUTPUT MODULE FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/

/*1-The Prototypes which the API needs * 2-Definitions which the API + HAL need.*/
/*What this MCAL layer do?*/

/*1-Initialization*/
ES_t DIO_enuInit(void); //Void for PreBuild Configuration level

/*2-SetPinDirection[input/output]*/
ES_t DIO_enuSetPinDirection(u8_t Copy_u8_tPortID, u8_t Copy_u8_tPinID, u8_t Copy_u8_tDirection);

/*3-SetPinValue*/
ES_t DIO_enuSetPinValue(u8_t Copy_u8_tPortID, u8_t Copy_u8_tPinID, u8_t Copy_u8_tValue);

/*4-GetPin*/
ES_t DIO_enuGetPinValue(u8_t Copy_u8_tPortID, u8_t Copy_u8_tPinID,u8_t  * Copy_pu8_tValue);

/*5-TogglePin*/
ES_t DIO_enuTogPinValue(u8_t Copy_u8_tPortID, u8_t Copy_u8_tPinID);


typedef enum
{
	DIO_u8_tPORT_A,
	DIO_u8_tPORT_B,
	DIO_u8_tPORT_C,
	DIO_u8_tPORT_D,

	DIO_u8_tPIN0 =0,
	DIO_u8_tPIN1,
	DIO_u8_tPIN2,
	DIO_u8_tPIN3,
	DIO_u8_tPIN4,
	DIO_u8_tPIN5,
	DIO_u8_tPIN6,
	DIO_u8_tPIN7,

	DIO_u8_tINPUT =0,
	DIO_u8_tOUTPUT,

	DIO_u8_tLOW =0,
	DIO_u8_tHIGH,

	DIO_u8_tFLOAT =0,
	DIO_u8_tPULL_UP,
}ES_interface;

/*

#define DIO_u8_tPORT_A		0
#define DIO_u8_tPORT_B		1
#define DIO_u8_tPORT_C		2
#define DIO_u8_tPORT_D		3

#define DIO_u8_tPIN0  			0
#define DIO_u8_tPIN1			1
#define DIO_u8_tPIN2			2
#define DIO_u8_tPIN3			3
#define DIO_u8_tPIN4			4
#define DIO_u8_tPIN5			5
#define DIO_u8_tPIN6			6
#define DIO_u8_tPIN7			7

#define DIO_u8_tINPUT 		0
#define DIO_u8_tOUTPUT	1

#define DIO_u8_tLOW 			0
#define DIO_u8_tHIGH			1

#define DIO_u8_tFLOAT 		0
#define DIO_u8_tPULL_UP	1

*/

#endif /* MCAL_DIO_INTERFACE_H_ */
