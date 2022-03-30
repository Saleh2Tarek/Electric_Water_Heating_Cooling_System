/*
 * EEPROM_register.h
 *
 *  Created on: Mar 26, 2022
 *      Author: Tarek ElDallal
 */

#ifndef MCAL_INTERNAL_EEPROM_EEPROM_REGISTER_H_
#define MCAL_INTERNAL_EEPROM_EEPROM_REGISTER_H_

#define		EEDR					*((volatile u8_t*)(0x3D))

#define		EECR					*((volatile u8_t*)(0x3C))

#define		EEARH					*((volatile u8_t*)(0x3F))

#define		EEARL					*((volatile u8_t*)(0x3E))
#define		EEAR					*((volatile u8_t*)(0x3E))


#define EECR_EERIE						3
#define EECR_EEMWE						2
#define EECR_EEWE						1
#define EECR_EERE						0



#endif /* MCAL_INTERNAL_EEPROM_EEPROM_REGISTER_H_ */
