/*
 * EXTI_interface.h
 *
*  Created on: Feb 11, 2022
 *      Author: Tarek ElDallal
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/*-------------------------------------- EXIT INTERRUPT MODULE FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/



ES_t EXTI_enuInit(EXTI_t * Copy_pAstrEXTIConfig);

ES_t EXTI_enuSetSenseLevel(u8_t Copy_u8IntNum, u8_t Copy_u8SenceLevel);

ES_t EXTI_enuEnableInterrupt(u8_t Copy_u8IntNum);

ES_t EXTI_enuDisableInterrupt(u8_t Copy_u8IntNum);

ES_t EXTI_enuCallBack(volatile void (* Copy_pfunAppFun)(void), u8_t Copy_u8IntNum);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
