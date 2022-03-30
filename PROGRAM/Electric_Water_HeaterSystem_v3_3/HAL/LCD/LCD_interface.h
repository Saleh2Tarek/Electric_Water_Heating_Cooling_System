/*
 * LCD_interface.h
 *
 *  Created on: Oct 19, 2021
 *      Author: Tarek ElDallal
 */

#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_
/*-------------------------------------- LCD MODULE FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/

ES_t LCD_enuInit(void);
ES_t LCD_enuSendData(u8_t Copy_u8_tData);
ES_t LCD_enuSendCommand(u8_t Copy_u8_tCommand);
ES_t LCD_enuSendpcString(const char * Copy_pcString);
ES_t LCD_enuSendPosition(u8_t Copy_u8_tLine, u8_t Copy_u8_tPosition);
ES_t LCD_enuSendCustomCharacter(u8_t Copy_u8_tPArrCustomCharacter, u8_t Copy_u8_tPatternsNumber,u8_t Copy_u8_tXPosition,u8_t Copy_u8_tYPosition,u8_t Copy_u8_tDirection);
ES_t LCD_enuDisplayIntegerNum(s32_t Copy_s32Num);
ES_t LCD_enuClearDisplay( void );

#define FIRST_LINE											 0x80
#define SECOND_LINE									 		 0xc0

#endif /* HAL_LCD_INTERFACE_H_ */
