/*
 * GIE_private.h
 *
 *  Created on: Nov 1, 2021
 *      Author: Tarek ElDallal
 */

#ifndef MCAL_GIE_GIE_PRIVATE_H_
#define MCAL_GIE_GIE_PRIVATE_H_

/***************ADDRESS OF STATUS REGISTER NEED PIN 7 FOR GLOBAL INTERRUPT ENABLE***********/
#define SREG											*((volatile u8_t*)(0x5f))


#define BIT_MASKING 							1
#define GIE_BIT_I  									7



#endif /* MCAL_GIE_GIE_PRIVATE_H_ */
