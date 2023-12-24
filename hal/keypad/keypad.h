/*
 * keypad.h
 *
 *  Created on: Nov 6, 2023
 *      Author: hamad
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

/*---------- Includes ----------*/
#include <avr/delay.h>
#include "../../library/std_types.h"
#include "../../mcal/gpio/gpio.h"
/*---------- Section: Macro Declarations ----------*/

#define KEYPAD_ROWS 		4
#define KEYPAD_COLUMNS 		4


/*---------- Section: Macro Functions Declarations ----------*/



/*---------- Section: Data Type Declarations ----------*/
typedef struct{
	pin_config_t kpd_row_pins[4];
	pin_config_t kpd_col_pins[4];
}keypad_t;

/*---------- Section: Function Declarations ----------*/
Std_ReturnType keypad_initialize(const keypad_t *keypad_obj);

Std_ReturnType keypad_get_value(const keypad_t *keypad_obj , uint8 *value);




#endif /* HAL_KEYPAD_KEYPAD_H_ */
