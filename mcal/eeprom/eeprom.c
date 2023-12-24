/*
 * eeprom.c
 *
 *  Created on: Nov 4, 2023
 *      Author: hamada
 */

#include "eeprom.h"


Std_ReturnType eeprom_write_byte(uint16 bAdd, uint8 bData )
{
	Std_ReturnType ret = E_OK ;

	/* Wait for completion of previous write */
	//while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEAR = bAdd;
	EEDR = bData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);

	return ret;
}
Std_ReturnType eeprom_read_byte(uint16 bAdd, uint8 *bData )
{
	Std_ReturnType ret = E_OK ;
	if(NULL == bData)
	{
		ret = E_NOT_OK ;
	}
	else
	{
		/* Wait for completion of previous write */
		//while(EECR & (1<<EEWE));
		/* Set up address register */
		EEAR = bAdd;
		/* Start eeprom read by writing EERE */
		EECR |= (1<<EERE);
		/* Return data from data register */
		*bData = EEDR;
		ret = E_OK;
	}
	return ret ;
}
