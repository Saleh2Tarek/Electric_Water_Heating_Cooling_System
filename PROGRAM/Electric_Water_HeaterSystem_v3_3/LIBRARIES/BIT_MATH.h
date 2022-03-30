/*
 * SYSTEM_program.c
 *
 *  Created on: Mar 19, 2022
 *      Author: Tarek ElDallal
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT_NB) (VAR)|=(1<<(BIT_NB))
#define CLR_BIT(VAR,BIT_NB) (VAR)&=~(1<<(BIT_NB))
#define TOGGLE_BIT(VAR,BIT_NB) (VAR)^=(1<<(BIT_NB))
#define GET_BIT(VAR,BIT_NB) ((VAR>>BIT_NB)&0x01)

#define ASSIGN_BIT(VAR,BIT_NB,VAL) VAR=(VAR&(~(1<<BIT_NB)))|(VAL<<BIT_NB)


#define set_bit(reg,bit) reg=reg|(1<<bit) //reg|=(1<<bit)
#define clr_bit(reg,bit) reg=reg&(~(1<<bit))
#define tog_bit(reg,bit) reg=reg^(1<<bit)
#define read_bit(reg,bit) reg&(1<<bit)
#define is_bit_set(reg,bit) reg&(1<<bit)>>bit
#define is_bit_clr(reg,bit) !(reg&(1<<bit)>>bit)


#endif /* BIT_MATH_H_ */
