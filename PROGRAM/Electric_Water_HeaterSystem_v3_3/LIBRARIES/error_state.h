/*
 * error_state.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Tarek ElDallal
 */

#ifndef ERROR_STATE_H_
#define ERROR_STATE_H_

typedef enum
{
	ES_NOK,
	ES_OK,
	ES_OUT_OF_RANG,
	ES_NULL_POINTER,
	ES_I2C_Ok,
	ES_I2C_SC_Error,
	ES_I2C_RSC_Error,
	ES_I2C_SLA_W_Error,
	ES_I2C_SLA_R_Error,
	ES_I2C_DATA_Error,
	ES_I2C_MR_DATA_Error
}ES_t;

/*
typedef enum
{
	I2C_Ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_SLA_W_Error,
	I2C_SLA_R_Error,
	I2C_DATA_Error,
	I2C_MR_DATA_Error

}I2C_Error_States;
*/

#endif /* ERROR_STATE_H_ */
