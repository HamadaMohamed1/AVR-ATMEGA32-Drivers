/*
 * button.c
 *
 *  Created on: Nov 6, 2023
 *      Author: hamada
 */

#include "button.h"

/*
 * @brief Initialize the button
 * @param btn : pointer to the configurations @ref button_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType button_init(const button_t *btn)
{
	Std_ReturnType ret = E_OK;
	if(NULL == btn)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = gpio_pin_intialize(&(btn->btn_pin));

		if(PULL_UP_RESISTOR == btn->btn_connection)
		{
			ret = gpio_pin_write_logic(&(btn->btn_pin) , GPIO_HIGH);
		}
		else
		{
			/* Nothing */
		}
		ret = E_OK;
	}
	return ret;
}

/*
 * @brief Read button status pressed or released @ref button_state_t
 * @param btn : pointer to the configurations @ref button_t
 * @param btn_state : to store button status
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType button_read_state(const button_t *btn ,button_state_t *btn_state)
{
	Std_ReturnType ret = E_OK;
	logic_t logic ;
	if((NULL == btn) || (NULL == btn_state))
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = gpio_pin_read_logic(&(btn->btn_pin) , &logic);

		if(PULL_UP_RESISTOR == btn->btn_connection)
		{
			if(GPIO_HIGH == logic)
			{
				*btn_state = BUTTON_RELEASED;
			}
			else if(GPIO_LOW ==logic)
			{
				*btn_state = BUTTON_PRESSED;
			}
		}
		else if(BUTTON_ACTIVE_HIGH == btn->btn_connection)
		{
			if(GPIO_HIGH == logic)
			{
				*btn_state = BUTTON_PRESSED;
			}
			else if(GPIO_LOW ==logic)
			{
				*btn_state = BUTTON_RELEASED;
			}
		}
		else if(BUTTON_ACTIVE_LOW == btn->btn_connection)
		{
			if(GPIO_HIGH == logic)
			{
				*btn_state = BUTTON_RELEASED;
			}
			else if(GPIO_LOW ==logic)
			{
				*btn_state = BUTTON_PRESSED;
			}
		}
		else
		{
			/* Nothing */
		}
		ret = E_OK;
	}
	return ret;
}
