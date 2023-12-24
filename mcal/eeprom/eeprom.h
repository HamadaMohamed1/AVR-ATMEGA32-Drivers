/*
 * eeprom.h
 *
 *  Created on: Nov 4, 2023
 *      Author: hamada
 */

#ifndef MCAL_EEPROM_EEPROM_H_
#define MCAL_EEPROM_EEPROM_H_

/*---------- Includes ----------*/
#include <avr/io.h>
#include "../../library/std_types.h"

/*---------- Section: Macro Declarations ----------*/
/*---------- Section: Macro Functions Declarations ----------*/
/*---------- Section: Data Type Declarations ----------*/

/*---------- Section: Function Declarations ----------*/

Std_ReturnType eeprom_write_byte(uint16 bAdd, uint8 bData );
Std_ReturnType eeprom_read_byte(uint16 bAdd, uint8 *bData );


#endif /* MCAL_EEPROM_EEPROM_H_ */
