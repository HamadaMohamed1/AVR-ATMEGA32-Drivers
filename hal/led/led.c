/*
 * led.c
 *
 *  Created on: Nov 6, 2023
 *      Author: hamada
 */

#include "led.h"
/*
 * @brief : Initialize the led
 * @param : led : pointer to the configurations @ref led_t
 * @return:
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType led_initialize(const led_t *led)
{
	Std_ReturnType ret = E_OK;

	if(NULL == led)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t led_pin ={
								.port = led->port ,
								.pin = led->pin ,
								.logic = led->led_status ,
								.direction = GPIO_DIRECTION_OUTPUT
		};
		ret = gpio_pin_intialize(&led_pin);
		ret = E_OK;
	}
	return ret;
}
/*
 * @brief : led turn on
 * @param : led : pointer to the configurations @ref led_t
 * @return:
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType led_turn_on(const led_t *led)
{
	Std_ReturnType ret = E_OK;
		if(NULL == led)
		{
			ret = E_NOT_OK;
		}
		else
		{
			pin_config_t led_pin ={
									.port = led->port ,
									.pin = led->pin ,
									.logic = led->led_status ,
									.direction = GPIO_DIRECTION_OUTPUT
			};
			ret = gpio_pin_write_logic(&(led_pin) , GPIO_HIGH);
			ret = E_OK;
		}
		return ret;
}
/*
 * @brief : led turn off
 * @param : led : pointer to the configurations @ref led_t
 * @return:
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType led_turn_off(const led_t *led)
{
	Std_ReturnType ret = E_OK;
		if(NULL == led)
		{
			ret = E_NOT_OK;
		}
		else
		{
			pin_config_t led_pin ={
									.port = led->port ,
									.pin = led->pin ,
									.logic = led->led_status ,
									.direction = GPIO_DIRECTION_OUTPUT
			};
			ret = gpio_pin_write_logic(&(led_pin) , GPIO_LOW);
			ret = E_OK;
		}
		return ret;
}
/*
 * @brief : toggle led status
 * @param : led : pointer to the configurations @ref led_t
 * @return:
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType led_turn_toggle(const led_t *led)
{
	Std_ReturnType ret = E_OK;
		if(NULL == led)
		{
			ret = E_NOT_OK;
		}
		else
		{
			pin_config_t led_pin ={
									.port = led->port ,
									.pin = led->pin ,
									.logic = led->led_status ,
									.direction = GPIO_DIRECTION_OUTPUT
			};
			ret = gpio_pin_toggle_logic(&led_pin) ;
			ret = E_OK;
		}
		return ret;
}
