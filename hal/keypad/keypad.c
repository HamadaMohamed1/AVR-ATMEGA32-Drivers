/*
 * keypad.c
 *
 *  Created on: Nov 6, 2023
 *      Author: hamad
 */

#include "keypad.h"


static const uint8 button_values[KEYPAD_ROWS][KEYPAD_COLUMNS] =
{
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'#','0','=','+'}
};



Std_ReturnType keypad_initialize(const keypad_t *keypad_obj)
{
	Std_ReturnType ret = E_OK;
	uint8 local_row_counter =0;
	uint8 local_col_counter =0;
	if(NULL == keypad_obj)
	{
		ret  = E_NOT_OK ;
	}
	else
	{
		for(local_row_counter = 0 ; local_row_counter < KEYPAD_ROWS ; local_row_counter++)
		{
			ret = gpio_pin_intialize(&(keypad_obj->kpd_row_pins[local_row_counter]));
		}
		for(local_col_counter = 0 ; local_col_counter < KEYPAD_COLUMNS ; local_col_counter++)
		{
			ret = gpio_pin_intialize(&(keypad_obj->kpd_col_pins[local_col_counter]));
			ret = gpio_pin_write_logic(&(keypad_obj->kpd_col_pins[local_col_counter]),GPIO_HIGH);
		}
		ret = E_OK;
	}
	return ret;
}

Std_ReturnType keypad_get_value(const keypad_t *keypad_obj , uint8 *value)
{
	Std_ReturnType ret = E_OK;
	uint8 local_row_counter =0;
	uint8 local_col_counter =0;
	uint8 local_counter =0;
	uint8 logic;

	if((NULL == keypad_obj) || (NULL == value))
	{
		ret  = E_NOT_OK ;
	}
	else
	{
		for(local_row_counter = 0 ; local_row_counter < KEYPAD_ROWS ; local_row_counter++)
		{
			for(local_counter= 0 ; local_counter < KEYPAD_ROWS ; local_counter++)
			{
				ret = gpio_pin_write_logic(&(keypad_obj->kpd_row_pins[local_counter]) , GPIO_HIGH);
			}
			ret = gpio_pin_write_logic(&(keypad_obj->kpd_row_pins[local_row_counter]) , GPIO_LOW);
			_delay_ms(10);
			for(local_col_counter=0;local_col_counter<KEYPAD_COLUMNS ; local_col_counter++)
			{
				ret = gpio_pin_read_logic(&(keypad_obj->kpd_col_pins[local_col_counter]) , &logic);
				if(GPIO_LOW== logic)
				{
					*value = button_values[local_row_counter][local_col_counter];
				}
			}
		}

		ret = E_OK;
	}
	return ret;
}


