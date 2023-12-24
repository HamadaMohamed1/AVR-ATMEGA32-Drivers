/*
 * led.h
 *
 *  Created on: Nov 6, 2023
 *      Author: hamad
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

/*---------- Includes ----------*/
#include "../../library/std_types.h"
#include "../../mcal/gpio/gpio.h"
/*---------- Section: Macro Declarations ----------*/





/*---------- Section: Macro Functions Declarations ----------*/



/*---------- Section: Data Type Declarations ----------*/
typedef enum {
	LED_OFF =0 ,
	LED_ON
}led_status;

typedef struct{
	uint8 port :4 ;			/*@ref port_index_t*/
	uint8 pin : 3;			/*@ref pin_index_t*/
	uint8 led_status :1 ;	/*@ref led_status*/
}led_t;


/*---------- Section: Function Declarations ----------*/

/*
 * @brief : Initialize the led
 * @param : led : pointer to the configurations @ref led_t
 * @return:
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType led_initialize(const led_t *led);
/*
 * @brief : led turn on
 * @param : led : pointer to the configurations @ref led_t
 * @return:
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType led_turn_on(const led_t *led);
/*
 * @brief : led turn off
 * @param : led : pointer to the configurations @ref led_t
 * @return:
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType led_turn_off(const led_t *led);
/*
 * @brief : toggle led status
 * @param : led : pointer to the configurations @ref led_t
 * @return:
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType led_turn_toggle(const led_t *led);


#endif /* HAL_LED_LED_H_ */
