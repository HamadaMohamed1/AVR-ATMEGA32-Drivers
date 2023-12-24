/*
 * relay.c
 *
 *  Created on: Nov 23, 2023
 *      Author: hamada
 */
/*---------- Includes ----------*/
#include "relay.h"



/*
 * @brief Initialize the relay pin
 * @param relay_obj : pointer to the configurations @ref relay_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType relay_initialize(const relay_t *relay_obj)
{
	Std_ReturnType ret = E_NOT_OK ;
	if(NULL == relay_obj)
	{
		ret = E_NOT_OK ;
	}
	else
	{
		pin_config_t relay_pin = {	.port = relay_obj->port ,
									.pin = relay_obj->pin ,
									.logic = relay_obj->status ,
									.direction = GPIO_DIRECTION_OUTPUT
									};
		gpio_pin_direction_intialize(&relay_pin);
		ret = E_OK ;
	}
	return ret ;
}
/*
 * @brief relay turn on
 * @param relay_obj : pointer to the configurations @ref relay_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType relay_turn_on(const relay_t *relay_obj)
{
	Std_ReturnType ret = E_NOT_OK ;
	if(NULL == relay_obj)
	{
		ret = E_NOT_OK ;
	}
	else
	{
		pin_config_t relay_pin = {	.port = relay_obj->port ,
									.pin = relay_obj->pin ,
									.logic = relay_obj->status ,
									.direction = GPIO_DIRECTION_OUTPUT
									};
		gpio_pin_write_logic(&relay_pin ,GPIO_HIGH);

		ret = E_OK ;
	}
	return ret ;
}
/*
 * @brief relay turn off
 * @param relay_obj : pointer to the configurations @ref relay_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType relay_turn_off(const relay_t *relay_obj)
{
	Std_ReturnType ret = E_NOT_OK ;
	if(NULL == relay_obj)
	{
		ret = E_NOT_OK ;
	}
	else
	{
		pin_config_t relay_pin = {	.port = relay_obj->port ,
									.pin = relay_obj->pin ,
									.logic = relay_obj->status ,
									.direction = GPIO_DIRECTION_OUTPUT
									};
		gpio_pin_write_logic(&relay_pin ,GPIO_LOW);

		ret = E_OK ;
	}
	return ret ;
}
/*
 * @brief toggle relay status
 * @param relay_obj : pointer to the configurations @ref relay_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType relay_turn_toggle(const relay_t *relay_obj)
{
	Std_ReturnType ret = E_NOT_OK ;
	if(NULL == relay_obj)
	{
		ret = E_NOT_OK ;
	}
	else
	{
		pin_config_t relay_pin = {	.port = relay_obj->port ,
									.pin = relay_obj->pin ,
									.logic = relay_obj->status ,
									.direction = GPIO_DIRECTION_OUTPUT
									};
		gpio_pin_toggle_logic(&relay_pin);

		ret = E_OK ;
	}
	return ret ;
}
