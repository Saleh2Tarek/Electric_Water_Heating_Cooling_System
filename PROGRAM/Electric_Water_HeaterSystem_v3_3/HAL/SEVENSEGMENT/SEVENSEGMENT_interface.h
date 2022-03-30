/*
 * SEVENSEGMENT_interface.h
 *
 *  Created on: Oct 13, 2021
 *      Author: Tarek ElDallal
 */

#ifndef HAL_SEVENSEGMENT_INTERFACE_H_
#define HAL_SEVENSEGMENT_INTERFACE_H_
/*-------------------------------------- SEVEN SEGMENTS DISPLAY MODULE FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/


//INITIALIZATION,DISPLAY,ENABLE,DISABLE,STOPDISPLAY
ES_t SevenSegment_enuInit(SSG_t * Copy_pAstrSevenSegmentConf);
ES_t SevenSegment_enuEnableCommon(SSG_t * Copy_pstrSevenSegmentInfo);
ES_t SevenSegment_enuEnableDot(SSG_t * Copy_pstrSevenSegmentInfo);
ES_t SevenSegment_enuDisplayNumber(SSG_t * Copy_pstrSevenSegmentInfo ,u8_t Copy_u8_tNumber);
ES_t SevenSegment_enuwrite(u16_t Copy_u16_tNumber);
void SevenSegment_Write(u8_t Copy_u8_tNumber);
ES_t SevenSegment_enuDisableCommon(SSG_t * Copy_pstrSevenSegmentInfo);
ES_t SevenSegment_enuDisableDot(SSG_t * Copy_pstrSevenSegmentInfo);
ES_t SevenSegment_enuStopDisplay(SSG_t * Copy_pstrSevenSegmentInfo);
ES_t SevenSegment_enuToggleDisplay(SSG_t * Copy_pstrSevenSegmentInfo);


//stop display the common on GIO

#endif /* HAL_SEVENSEGMENT_INTERFACE_H_ */
