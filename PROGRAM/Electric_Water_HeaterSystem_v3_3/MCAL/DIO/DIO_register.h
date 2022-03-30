/*
 * DIO_register.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Tarek ElDallal
 */
/*File Guard*/
#ifndef MCAL_DIO_REGISTER_H_
#define MCAL_DIO_REGISTER_H_
/*PORTA*/
#define		PORTA				*((volatile u8_t*)(0x3B))
#define		DDRA				*((volatile u8_t*)(0x3A))
#define		PINA				*((volatile u8_t*)(0x39))
/*PORTB*/
#define		PORTB				*((volatile u8_t*)(0x38))
#define		DDRB				*((volatile u8_t*)(0x37))
#define		PINB				*((volatile u8_t*)(0x36))
/*PORTC*/
#define		PORTC				*((volatile u8_t*)(0x35))
#define		DDRC				*((volatile u8_t*)(0x34))
#define		PINC				*((volatile u8_t*)(0x33))
/*PORTD*/
#define		PORTD				*((volatile u8_t*)(0x32))
#define		DDRD				*((volatile u8_t*)(0x31))
#define		PIND				*((volatile u8_t*)(0x30))
#endif /* MCAL_DIO_REGISTER_H_ */
