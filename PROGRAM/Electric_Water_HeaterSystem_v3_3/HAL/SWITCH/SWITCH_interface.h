/*
 * SWITCH_interface.h
 *
 *  Created on: Oct 6, 2021
 *      Author: Tarek ElDallal
 */

#ifndef HAL_SWITCH_INTERFACE_H_
#define HAL_SWITCH_INTERFACE_H_

/*-------------------------------------- SWITCH LINKING TIME MODULE FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/


ES_t SWITCH_enuIniti(SW_t * Copy_pAstrSwitchConfig);

//ES_t SWITCH_enuIniti(SW_t * Copy_pAstrSwitchConfig);
/*switch is always input> so we need to know whether it is float or pull_up*/
 ES_t SWITCH_enuGetState(SW_t * Copy_pAstrSwitchInfo, u8_t * Copy_pu8_tValue);


#endif /* HAL_SWITCH_INTERFACE_H_ */
