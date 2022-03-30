/*
 * TMU_interface.h
 *
 *  Created on: Mar 11, 2022
 *      Author: Tarek ElDallal
 */

#ifndef APP_TMU_TMU_INTERFACE_H_
#define APP_TMU_TMU_INTERFACE_H_

/*-------------------------------------- TIME MANEGMENT UNIT MODULE FUNCTIONS --------------------------------*/
/*-----------------------------------------------------------------------------------------------*/


ES_t TMU_enuInit(void);
ES_t TMU_enuCreateTask(void(*Copy_pfunTask)(void),u8_t Copy_u8_tPriority, u8_t Copy_u8_tPeriodicity);
ES_t TMU_enuStartScheduler(void);

ES_t TMU_enuSuspendTask(u8_t Copy_u8_tPriority);
ES_t TMU_enuResumeTask (u8_t Copy_u8_tPriority);
ES_t TMU_enuDeleteTask (u8_t Copy_u8_tPriority);

#define READY										11
#define SUSPEND										12
#define KILLED										13

#endif /* APP_TMU_TMU_INTERFACE_H_ */
