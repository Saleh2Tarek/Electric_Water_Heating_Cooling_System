/*
 * EEPROM_interface.h
 *
 *  Created on: Mar 26, 2022
 *      Author: Tarek ElDallal
 */

#ifndef HAL_EPROM3_EPROM_INT_H_
#define HAL_EPROM3_EPROM_INT_H_

/*-------------------------------------- INTERNAL EEPROM MODULE FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/


ES_t EEPROM_enuReadByteFromAddress( const u16_t Copy_u16_tAddress ,  u8_t * Copy_u18_tdata);
ES_t EEPROM_enuReadBlockFromAddress(const u16_t Copy_u16_tAddress, u8_t* Copy_u8_tDistnation,const u16_t Copy_u16_tSize);
ES_t EEPROM_enuWriteByteToAddress(const u16_t Copy_u16_tAddress, const u8_t Copy_u8_tData);
ES_t EEPROM_enuWriteBlockToAddress(const u16_t Copy_u16_tAddress, const u8_t* Copy_u8_tData,const u16_t Copy_u16_tSize);

#endif /* HAL_EPROM3_EPROM_INT_H_ */
