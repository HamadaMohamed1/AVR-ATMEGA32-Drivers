/*
 * gpio.h
 *
 *  Created on: Nov 4, 2023
 *      Author: hamada
 */

#ifndef MCAL_GPIO_GPIO_H_
#define MCAL_GPIO_GPIO_H_

/*---------- Includes ----------*/
#include <avr/io.h>
#include <stdio.h>
#include "../../library/std_types.h"
#include "../../library/bit_math.h"

/*---------- Section: Macro Declarations ----------*/

#define PORT_MAX_NUMBER 	4

/*---------- Section: Macro Functions Declarations ----------*/


/*---------- Section: Data Type Declarations ----------*/
typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
}port_index_t;

typedef enum{
    GPIO_LOW = 0,
    GPIO_HIGH
}logic_t;

typedef enum{
	GPIO_DIRECTION_INPUT = 0,
    GPIO_DIRECTION_OUTPUT
}direction_t;

typedef enum{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_index_t;

typedef struct{
    uint8 port : 3;      /* @ref port_index_t */
    uint8 pin : 3;       /* @ref pin_index_t */
    uint8 direction : 1; /* @ref direction_t */
    uint8 logic : 1;     /* @ref logic_t */
}pin_config_t;



/*---------- Section: Function Declarations ----------*/


/*
 * @brief Initialize the direction of a specific pin @ref direction_t
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config);
/*
 * @brief Get the direction of a specific pin
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @param direction_status : to store the direction of a pin @ref direction_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status);
/*
 * @brief Writing logic HIGH or LOW on a specific pin @ref logic_t
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @param logic : The logic to be written HIGH or LOW
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic);
/*
 * @brief Read logic HIGH or LOW from a specific pin @ref logic_t
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @param logic : to store pin logic
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic);
/*
 * @brief Toggle the logic of a specific pin
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);
/*
 * @brief Initialize the direction of a specific pin
 * @param _pin_config : pointer to the configurations @ref pin_config_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config);
/*
 * @brief Initialize the direction of a specific port
 * @param port : port name @ref port_index_t
 * @param direction : desired direction
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction);
/*
 * @brief Get the direction of a specific port
 * @param port : port name @ref port_index_t
 * @param direction_status : to store the port direction
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status);
/*
 * @brief Writing logic to a specific port
 * @param port : port name @ref port_index_t
 * @param logic : desired logic
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic);
/*
 * @brief Reading the logic of a specific port
 * @param port : port name @ref port_index_t
 * @param logic : to store the port logic
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic);
/*
 * @brief Toggle the logic of a specific port
 * @param port : port name @ref port_index_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gpio_port_toggle_logic(port_index_t port);




#endif /* MCAL_GPIO_GPIO_H_ */
