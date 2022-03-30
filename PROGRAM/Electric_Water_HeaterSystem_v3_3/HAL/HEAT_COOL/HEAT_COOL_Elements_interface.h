/*
 * HEAT_COOL_Elements_interface.h
 *
 *  Created on: Mar 19, 2022
 *      Author: Tarek ElDallal
 */

#ifndef HAL_HEAT_COOL_HEAT_COOL_ELEMENTS_INTERFACE_H_
#define HAL_HEAT_COOL_HEAT_COOL_ELEMENTS_INTERFACE_H_

/*-------------------------------------- HEATTING AND COOLING ELEMENTS MODULE FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/

ES_t HEAT_COOL_ELEMENTS_enuIniti(void);
ES_t HEAT_COOL_ELEMENTS_enuHeaterStart(void);
ES_t HEAT_COOL_ELEMENTS_enuHeaterStop(void);
ES_t HEAT_COOL_ELEMENTS_enuHeaterToggle(void);

ES_t HEAT_COOL_ELEMENTS_enuCoolerStart(void);
ES_t HEAT_COOL_ELEMENTS_enuCoolerStop(void);



#endif /* HAL_HEAT_COOL_HEAT_COOL_ELEMENTS_INTERFACE_H_ */
