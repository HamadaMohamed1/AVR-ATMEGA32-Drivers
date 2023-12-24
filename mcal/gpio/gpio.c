/*
 * gpio.c
 *
 *  Created on: Nov 4, 2023
 *      Author: hamada
 */

#include "gpio.h"

/* Reference to the Data Direction Control Registers */
volatile uint8 *Ddr_registers[] = {&DDRA, &DDRB, &DDRC, &DDRD};
/* Reference to the Data Latch Register (Read and Write to Data Latch) */
volatile uint8 *Port_registers[]  = {&PORTA , &PORTB , &PORTC , &PORTD};
/* Reference to the Port Status Register  */
volatile uint8 *Pin_registers[] = {&PINA, &PINB, &PINC, &PIND};

/*
 *
 * @brief Initialize the direction of a specific pin @ref direction_t
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config)
{
	Std_ReturnType ret = E_OK;
	if(NULL == _pin_config)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(_pin_config->direction)
		{
			case GPIO_DIRECTION_INPUT :
				CLEAR_BIT(*Ddr_registers[_pin_config->port] ,_pin_config->pin);
				ret = E_OK;
			break;
			case GPIO_DIRECTION_OUTPUT :
				SET_BIT(*Ddr_registers[_pin_config->port] ,_pin_config->pin);
				ret = E_OK;
			break;
			default : ret = E_NOT_OK ; break;
		}
	}
	return ret;
}

/*
 * @brief Get the direction of a specific pin
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @param direction_status : to store the direction of a pin @ref direction_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status)
{
	Std_ReturnType ret = E_OK;
		if(NULL == _pin_config)
		{
			ret = E_NOT_OK;
		}
		else
		{
			*direction_status = READ_BIT(*Ddr_registers[_pin_config->port] ,_pin_config->pin);
			ret = E_OK;
		}
	return ret;
}

/*
 * @brief Writing logic HIGH or LOW on a specific pin @ref logic_t
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @param logic : The logic to be written HIGH or LOW
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic)
{
	Std_ReturnType ret = E_OK;
		if(NULL == _pin_config)
		{
			ret = E_NOT_OK;
		}
		else
		{
			switch(logic)
			{
				case GPIO_HIGH :
						SET_BIT(*Port_registers[_pin_config->port] , _pin_config->pin);
				ret = E_OK;
				break;
				case GPIO_LOW :
						CLEAR_BIT(*Port_registers[_pin_config->port] , _pin_config->pin);
				ret = E_OK;
				break;
				default :
						ret = E_NOT_OK ;
				break;
			}
			ret = E_OK;
		}
	return ret;
}

/*
 * @brief Read logic HIGH or LOW from a specific pin @ref logic_t
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @param logic : to store pin logic
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic)
{
	Std_ReturnType ret = E_OK;
			if((NULL == _pin_config) || (NULL == logic))
			{
				ret = E_NOT_OK;
			}
			else
			{
				*logic = READ_BIT(*Pin_registers[_pin_config->port],_pin_config->pin);
				ret = E_OK;
			}
		return ret;

}

/*
 * @brief Toggle the logic of a specific pin
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config)
{
	Std_ReturnType ret = E_OK;
		if(NULL == _pin_config)
		{
			ret = E_NOT_OK;
		}
		else
		{
			TOGGLE_BIT(*Port_registers[_pin_config->port],_pin_config->pin);
			ret = E_OK;
		}
	return ret;
}

/*
 * @brief Initialize the direction of a specific pin
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config)
{
	Std_ReturnType ret = E_OK;
	if(NULL == _pin_config)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = gpio_pin_direction_intialize(_pin_config);
		ret = gpio_pin_write_logic(_pin_config , _pin_config->logic);
		ret = E_OK;
	}
	return ret;
}

/*
 * @brief Initialize the direction of a specific port
 * @param port : port name @ref port_index_t
 * @param direction : desired direction
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction)
{
	Std_ReturnType ret = E_OK;
	if(port > (PORT_MAX_NUMBER-1))
	{
		ret = E_NOT_OK;
	}
	else
	{
		*Ddr_registers[port] = direction;
		ret = E_OK;
	}
	return ret;
}

/*
 * @brief Get the direction of a specific port
 * @param port : port name @ref port_index_t
 * @param direction_status : to store the port direction
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status)
{
	Std_ReturnType ret = E_OK;
	if((NULL == direction_status) || port > (PORT_MAX_NUMBER-1))
	{
		ret = E_NOT_OK;
	}
	else
	{
		*direction_status = *Ddr_registers[port];
		ret = E_OK;
	}
	return ret;
}

/*
 * @brief Writing logic to a specific port
 * @param port : port name @ref port_index_t
 * @param logic : desired logic
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic)
{
	Std_ReturnType ret = E_OK;
	if(port > (PORT_MAX_NUMBER-1))
	{
		ret = E_NOT_OK;
	}
	else
	{
		 *Port_registers[port] = logic;
		ret = E_OK;
	}
	return ret;
}

/*
 * @brief Reading the logic of a specific port
 * @param port : port name @ref port_index_t
 * @param logic : to store the port logic
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic)
{
	Std_ReturnType ret = E_OK;
	if((NULL == logic) || (port > PORT_MAX_NUMBER-1))
	{
		ret = E_NOT_OK;
	}
	else
	{
		*logic = *Port_registers[port];
		ret = E_OK;
	}
	return ret;
}

/*
 * @brief Toggle the logic of a specific port
 * @param port : port name @ref port_index_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
	Std_ReturnType ret = E_OK;
	if(port > (PORT_MAX_NUMBER-1))
	{
		ret = E_NOT_OK;
	}
	else
	{
		*Port_registers[port] ^= 0xff;
		ret = E_OK;
	}
	return ret;
}
