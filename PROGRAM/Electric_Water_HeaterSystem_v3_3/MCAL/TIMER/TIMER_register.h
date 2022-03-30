/*
 * TIMER_ZERO_register.h
 *
 *  Created on: Feb 27, 2022
 *      Author: Tarek ElDallal
 */

#ifndef MCAL_TIMER_TIMER_REGISTER_H_
#define MCAL_TIMER_TIMER_REGISTER_H_


/*----------------------------------- TIMER ZERO Registers --------------------------------------*/

/***************THE Timer0 Control Register – TCCR0 [ADDRESS]***************/
#define		TCCR0					*((volatile u8_t*)(0x53))
/***************THE Timer0 Register – TCNT0 [ADDRESS]***************/
#define		TCNT0					*((volatile u8_t*)(0x52))
/***************THE TIMER0 Output Compare Register – OCR0 [ADDRESS]***************/
#define		OCR0					*((volatile u8_t*)(0x5c))
/***************THE Timer0 Interrupt Mask Register – TIMSK [ADDRESS]***************/
#define		TIMSK					*((volatile u8_t*)(0x59))
/***************THE Timer0 Interrupt Flag Register – TIFR [ADDRESS]***************/
#define		TIFR					*((volatile u8_t*)(0x58))

/*----------------------------------- TIMER ONE Registers --------------------------------------*/

/***************THE TIMER1 Output Compare Register – TCCR1A [ADDRESS]***************/
#define		TCCR1A					*((volatile u8_t*)(0x4F))
/***************THE TIMER1 Output Compare Register – TCCR1B [ADDRESS]***************/
#define		TCCR1B					*((volatile u8_t*)(0x4E))
/***************THE TIMER1 Output Compare Register – TCNT1H [ADDRESS]***************/
#define		TCNT1H					*((volatile u8_t*)(0x4D))
/***************THE TIMER1 Output Compare Register – TCNT1L [ADDRESS]***************/
#define		TCNT1L					*((volatile u8_t*)(0x4C))
/***************THE TIMER1 Output Compare Register – OCR1AH [ADDRESS]***************/
#define		OCR1AH					*((volatile u8_t*)(0x4B))
/***************THE TIMER1 Output Compare Register – OCR1AL [ADDRESS]***************/
#define		OCR1AL					*((volatile u8_t*)(0x4A))
/***************THE TIMER1 Output Compare Register – OCR1BH [ADDRESS]***************/
#define		OCR1BH					*((volatile u8_t*)(0x49))
/***************THE TIMER1 Output Compare Register – OCR1BL [ADDRESS]***************/
#define		OCR1BL					*((volatile u8_t*)(0x48))
/***************THE TIMER1 Output Compare Register – ICR1H [ADDRESS]***************/
#define		ICR1H					*((volatile u8_t*)(0x47))
/***************THE TIMER1 Output Compare Register – ICR1L [ADDRESS]***************/
#define		ICR1L					*((volatile u8_t*)(0x46))

/*----------------------------------- TIMER TWO Registers --------------------------------------*/

/***************THE TIMER0 Output Compare Register – ASSR [ADDRESS]***************/
#define		ASSR					*((volatile u8_t*)(0x42))
/***************THE TIMER0 Output Compare Register – OCR2 [ADDRESS]***************/
#define		OCR2					*((volatile u8_t*)(0x43))
/***************THE Timer0 Register – TCNT2 [ADDRESS]***************/
#define		TCNT2					*((volatile u8_t*)(0x44))
/***************THE Timer2 Control Register – TCCR0 [ADDRESS]***************/
#define		TCCR2					*((volatile u8_t*)(0x45))

/*------------------------------------------------------------------------------------------------*/



#endif /* MCAL_TIMER_TIMER_REGISTER_H_ */
