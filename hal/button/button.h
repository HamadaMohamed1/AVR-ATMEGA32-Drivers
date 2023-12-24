/*
 * button.h
 *
 *  Created on: Nov 6, 2023
 *      Author: hamada
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

/*---------- Includes ----------*/
#include "../../library/std_types.h"
#include "../../mcal/gpio/gpio.h"
/*---------- Section: Macro Declarations ----------*/



/*---------- Section: Macro Functions Declarations ----------*/


/*---------- Section: Data Type Declarations ----------*/
typedef enum {
	BUTTON_PRESSED =0,
	BUTTON_RELEASED
}button_state_t;

/**
 * @breif : PULL_UP_RESISTOR is an internal connection on the microcontroller
 * 			BUTTON_ACTIVE_LOW & BUTTON_ACTIVE_HIGH are external hardware connection
 */
typedef enum {
	BUTTON_ACTIVE_LOW = 0,
	BUTTON_ACTIVE_HIGH,
	PULL_UP_RESISTOR
}button_connection_t;


typedef struct
{
	pin_config_t btn_pin ;
	button_state_t btn_state;
	button_connection_t btn_connection;
}button_t;

/*---------- Section: Function Declarations ----------*/


/*
 * @brief Initialize the button
 * @param btn : pointer to the configurations @ref button_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType button_init(const button_t *btn);
/*
 * @brief Read button status pressed or released @ref button_state_t
 * @param btn : pointer to the configurations @ref button_t
 * @param btn_state : to store button status
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType button_read_state(const button_t *btn ,button_state_t *btn_state);




#endif /* HAL_BUTTON_BUTTON_H_ */
