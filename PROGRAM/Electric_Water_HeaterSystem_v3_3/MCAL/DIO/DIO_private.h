/*
 * DIO_private.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Tarek ElDallal
 */

#ifndef MCAL_DIO_PRIVATE_H_
#define MCAL_DIO_PRIVATE_H_

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)			0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)				CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)



#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0) 				0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC_D(b7,b6,b5,b4,b3,b2,b1,b0)							 CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_V(b7,b6,b5,b4,b3,b2,b1,b0)							 CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)


#define INIT_DDR_DIRECTION			 									CONC_D(DIO_u8_tPinA7_Direction,DIO_u8_tPinA6_Direction,DIO_u8_tPinA5_Direction,DIO_u8_tPinA4_Direction,DIO_u8_tPinA3_Direction,DIO_u8_tPinA2_Direction,DIO_u8_tPinA1_Direction,DIO_u8_tPinA0_Direction)
#define INIT_PORT_VALUE		 												CONC_V(DIO_u8_tPinA7_Value,DIO_u8_tPinA6_Value,DIO_u8_tPinA5_Value,DIO_u8_tPinA4_Value,DIO_u8_tPinA3_Value,DIO_u8_tPinA2_Value,DIO_u8_tPinA1_Value,DIO_u8_tPinA0_Value)
/*
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
};
*/
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



#define DIO_MASK_BIT 		1

#endif /* MCAL_DIO_PRIVATE_H_ */
