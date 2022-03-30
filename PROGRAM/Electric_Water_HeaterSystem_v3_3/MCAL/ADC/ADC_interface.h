/*
 * ADC_interface.h
 *
 *  Created on: Feb 7, 2022
 *      Author: Tarek ElDallal
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

/*-------------------------------------- ANALOG DIGITAL CONVERTER MODULE FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/



ES_t ADC_enuInit(void);
ES_t ADC_enuEnableADC(void);
ES_t ADC_enuDisableADC(void);
ES_t ADC_enuEnableADC_Intrrupt(void);
ES_t ADC_enuDisableADC_Intrrupt(void);
ES_t ADC_enuStartConversion(void);
ES_t ADC_enuChannelSelect(u8_t Ccopy_u8_tChannelID);
ES_t ADC_enuAutoTriggerSource(u8_t Copy_u8_tInterruptSource);
ES_t ADC_enuAutoTriggerDisable(void);
ES_t ADC_enuReadDataRegister(u16_t * Copy_pu16_tConversionResult);

ES_t ADC_enuCallBack(volatile void( *Copy_pfunAppFun) (void));

ES_t ADC_enuPolling(void);


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
