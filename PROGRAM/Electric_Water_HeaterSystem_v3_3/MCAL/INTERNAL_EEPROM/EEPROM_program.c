#include "../../LIBRARIES/std_types.h"
#include "../../LIBRARIES/error_state.h"
#include "EEPROM_register.h"
#include "EEPROM_private.h"


ES_t EEPROM_enuReadByteFromAddress( const u16_t Copy_u16_tAddress ,  u8_t * Copy_u18_tData)
{
	ES_t Local_enuErrorState = ES_NOK;
	/* Wait for completion of previous write */
	while (((EECR & (1 << EECR_EEWE))>>EECR_EEWE)==1);
	/* Set up address register */
	EEAR = Copy_u16_tAddress;
	/* Start EEPROM read by writing EERE */
	EECR |= (1 << EECR_EERE);
	/* Return data from data register */
	(*Copy_u18_tData) = EEDR;

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t EEPROM_enuReadBlockFromAddress(const u16_t Copy_u16_tAddress, u8_t* Copy_u8_tDistnation,const u16_t Copy_u16_tSize)
{
	ES_t Local_enuErrorState = ES_NOK;
	/* Wait for completion of previous write */
	while (((EECR & (1 << EECR_EEWE))>>EECR_EEWE)==1)
	;

	u16_t Local_u16_tCounter = 0;//the Local_u16_tCounter of bytes that are read

	while (Local_u16_tCounter < Copy_u16_tSize) //loop until move all bytes to the given array
	{
		/* Set up address register */
		EEAR = Copy_u16_tAddress + Local_u16_tCounter;
		/* Start EEPROM read by writing EECR_EERE */
		EECR |= (1 << EECR_EERE);
		/* move data from data register to the array */
		*(Copy_u8_tDistnation + Local_u16_tCounter) = EEDR;

		Local_u16_tCounter++;//increase the bytes Local_u16_tCounter

	}
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}


ES_t EEPROM_enuWriteByteToAddress(const u16_t Copy_u16_tAddress, const u8_t Copy_u8_tData)
{
	ES_t Local_enuErrorState = ES_NOK;
	/* Wait for completion of previous write process*/
	while ( ( (EECR & (1 << EECR_EEWE) ) >>EECR_EEWE ) == 1)
	;
	/* Set up address register */
	EEAR = Copy_u16_tAddress;

	/* Read the byte in the address of EEAR */
	EECR |= (1 << EECR_EERE);
	if (EEDR != Copy_u8_tData)//compare the value read to the value to be written
	{//if they are not equal then write the data 
		EEDR = Copy_u8_tData;//move the data to EEDR

		/* Write logical one to EEMWE */
		EECR |= (1 << EECR_EEMWE);
		/* Start EEPROM write by setting EECR_EEWE */
		EECR |= (1 << EECR_EEWE);
	}
	else
	{

	}
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;

}

ES_t EEPROM_enuWriteBlockToAddress(const u16_t Copy_u16_tAddress, const u8_t* Copy_u8_tData,const u16_t Copy_u16_tSize)
{
	ES_t Local_enuErrorState = ES_NOK;
	u16_t Local_u16_tCounter = 0;//Bytes write Local_u16_tCounter
	while (Local_u16_tCounter < Copy_u16_tSize)
	{
		/* Wait for completion of previous write process*/
		while (( (EECR & (1 << EECR_EEWE) ) >>EECR_EEWE ) == 1)
		;
		/* Set up address register */
		EEAR = Copy_u16_tAddress + Local_u16_tCounter;

		/* Read the byte in the address of EEAR */
		EECR |= (1 << EECR_EERE);
		if (EEDR != (*(Copy_u8_tData + Local_u16_tCounter)))//compare the value read to the value to be written
		{//if they are not equal then write the data 
			EEDR = *(Copy_u8_tData + Local_u16_tCounter);//move the data to EEDR

			/* Write logical one to EECR_EEMWE */
			EECR |= (1 << EECR_EEMWE);
			/* Start EEPROM write by setting EECR_EEWE */
			EECR |= (1 << EECR_EEWE);
		}
		else
		{

		}
		Local_u16_tCounter++;//increase bytes Local_u16_tCounter
	}
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
