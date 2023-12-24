/*
 * relay.h
 *
 *  Created on: Nov 23, 2023
 *      Author: hamada
 */

#ifndef HAL_RELAY_RELAY_H_
#define HAL_RELAY_RELAY_H_

/*---------- Includes ----------*/
#include "../../mcal/gpio/gpio.h"

/*---------- Section: Macro Declarations ----------*/

/*---------- Section: Macro Functions Declarations ----------*/

/*---------- Section: Data Type Declarations ----------*/
typedef enum{
	RELAY_OFF = 0,
	RELAY_ON
}relay_status;

typedef struct{
	uint8 port 	 : 4;	/*@ref port_index_t*/
	uint8 pin 	 : 3;	/*@ref pin_index_t*/
	uint8 status : 1;	/*@ref relay_status*/
}relay_t;

/*---------- Section: Function Declarations ----------*/

/*
 * @brief Initialize the relay pin
 * @param relay_obj : pointer to the configurations @ref relay_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType relay_initialize(const relay_t *relay_obj);
/*
 * @brief relay turn on
 * @param relay_obj : pointer to the configurations @ref relay_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType relay_turn_on(const relay_t *relay_obj);
/*
 * @brief relay turn off
 * @param relay_obj : pointer to the configurations @ref relay_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType relay_turn_off(const relay_t *relay_obj);
/*
 * @brief toggle relay status
 * @param relay_obj : pointer to the configurations @ref relay_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType relay_turn_toggle(const relay_t *relay_obj);




#endif /* HAL_RELAY_RELAY_H_ */
