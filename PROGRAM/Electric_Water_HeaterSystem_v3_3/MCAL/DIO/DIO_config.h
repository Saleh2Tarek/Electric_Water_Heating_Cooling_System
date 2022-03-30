/*
 * DIO_config.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Tarek ElDallal
 */
#ifndef MCAL_DIO_CONFIG_H_
#define MCAL_DIO_CONFIG_H_

/*Direction of PORTA:[ DIO_u8_tINPUT or DIO_u8_tOUTPUT]*/
#define DIO_u8_tPinA0_Direction		DIO_u8_tOUTPUT
#define DIO_u8_tPinA1_Direction		DIO_u8_tOUTPUT
#define DIO_u8_tPinA2_Direction		DIO_u8_tOUTPUT
#define DIO_u8_tPinA3_Direction		DIO_u8_tINPUT
#define DIO_u8_tPinA4_Direction		DIO_u8_tOUTPUT
#define DIO_u8_tPinA5_Direction		DIO_u8_tOUTPUT
#define DIO_u8_tPinA6_Direction		DIO_u8_tINPUT
#define DIO_u8_tPinA7_Direction		DIO_u8_tOUTPUT

/*Value of PORTA Pins:
 *  1-In case of InPut Direction[ DIO_u8_tFLOAT or DIO_u8_tPULL_UP]
 *  2-In case of OUTPut Direction[ DIO_u8_tLOW or DIO_u8_tHIGH]*/
#define DIO_u8_tPinA0_Value       DIO_u8_tLOW
#define DIO_u8_tPinA1_Value       DIO_u8_tLOW
#define DIO_u8_tPinA2_Value       DIO_u8_tHIGH
#define DIO_u8_tPinA3_Value       DIO_u8_tFLOAT
#define DIO_u8_tPinA4_Value       DIO_u8_tHIGH
#define DIO_u8_tPinA5_Value       DIO_u8_tLOW
#define DIO_u8_tPinA6_Value       DIO_u8_tFLOAT
#define DIO_u8_tPinA7_Value       DIO_u8_tLOW





/*Direction of PORTB:[ DIO_u8_tINPUT or DIO_u8_tOUTPUT]*/
#define DIO_u8_tPinB0_Direction				DIO_u8_tINPUT
#define DIO_u8_tPinB1_Direction				DIO_u8_tINPUT
#define DIO_u8_tPinB2_Direction				DIO_u8_tINPUT
#define DIO_u8_tPinB3_Direction
#define DIO_u8_tPinB4_Direction
#define DIO_u8_tPinB5_Direction
#define DIO_u8_tPinB6_Direction
#define DIO_u8_tPinB7_Direction



/*Value of PORTB Pins:
 *  1-In case of InPut Direction[ DIO_u8_tFLOAT or DIO_u8_tPULL_UP]
 *  2-In case of OUTPut Direction[ DIO_u8_tLOW or DIO_u8_tHIGH]*/
#define DIO_u8_tPinBA0_Value				DIO_u8_tFLOAT
#define DIO_u8_tPinBA1_Value				DIO_u8_tFLOAT
#define DIO_u8_tPinBA2_Value				DIO_u8_tPULL_UP
#define DIO_u8_tPinBA3_Value
#define DIO_u8_tPinBA4_Value
#define DIO_u8_tPinBA5_Value
#define DIO_u8_tPinBA6_Value
#define DIO_u8_tPinBA7_Value



/*Direction of PORTC:[ DIO_u8_tINPUT or DIO_u8_tOUTPUT]*/
#define DIO_u8_tPinC0_Direction
#define DIO_u8_tPinC1_Direction
#define DIO_u8_tPinC2_Direction
#define DIO_u8_tPinC3_Direction
#define DIO_u8_tPinC4_Direction
#define DIO_u8_tPinC5_Direction
#define DIO_u8_tPinC6_Direction
#define DIO_u8_tPinC7_Direction


/*Value of PORTC Pins:
 *  1-In case of InPut Direction[ DIO_u8_tFLOAT or DIO_u8_tPULL_UP]
 *  2-In case of OUTPut Direction[ DIO_u8_tLOW or DIO_u8_tHIGH]*/
#define DIO_u8_tPinC0_Value
#define DIO_u8_tPinC1_Value
#define DIO_u8_tPinC2_Value
#define DIO_u8_tPinC3_Value
#define DIO_u8_tPinC4_Value
#define DIO_u8_tPinC5_Value
#define DIO_u8_tPinC6_Value
#define DIO_u8_tPinC7_Value



/*Direction of PORTD:[ DIO_u8_tINPUT or DIO_u8_tOUTPUT]*/
#define DIO_u8_tPinD0_Direction
#define DIO_u8_tPinD1_Direction
#define DIO_u8_tPinD2_Direction
#define DIO_u8_tPinD3_Direction
#define DIO_u8_tPinD4_Direction
#define DIO_u8_tPinD5_Direction
#define DIO_u8_tPinD6_Direction
#define DIO_u8_tPinD7_Direction


/*Value of PORTD Pins:
 *  1-In case of InPut Direction[ DIO_u8_tFLOAT or DIO_u8_tPULL_UP]
 *  2-In case of OUTPut Direction[ DIO_u8_tLOW or DIO_u8_tHIGH]*/
#define DIO_u8_tPinD0_Value
#define DIO_u8_tPinD1_Value
#define DIO_u8_tPinD2_Value
#define DIO_u8_tPinD3_Value
#define DIO_u8_tPinD4_Value
#define DIO_u8_tPinD5_Value
#define DIO_u8_tPinD6_Value
#define DIO_u8_tPinD7_Value




#endif /* MCAL_DIO_CONFIG_H_ */
