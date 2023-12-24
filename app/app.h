/*
 * app.h
 *
 *  Created on: Nov 4, 2023
 *      Author: hamada
 */

#ifndef APP_APP_H_
#define APP_APP_H_

/*---------- Includes ----------*/
#include <avr/delay.h>
#include "string.h"
#include "../hal/led/led.h"
#include "../mcal/uart/uart.h"
#include "../hal/lcd/lcd.h"
#include "../hal/relay/relay.h"
#include "../mcal/interrupt/external_interrupt.h"

#include "../hal/button/button.h"

/*---------- Section: Macro Declarations ----------*/
#define 	TURN_ON		1
#define 	TURN_OFF	0



/*---------- Section: Macro Functions Declarations ----------*/


/*---------- Section: Data Type Declarations ----------*/



/*---------- Section: Function Declarations ----------*/
/*
 * @brief : Initialize any components in our application
 * @param : void
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType components_init(void);

/*
 * @brief : Solenoid lock control to turn it on or off
 * @param : turn_on_off : @ref (TURN_ON , TURN_OFF)
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType solenoid_lock_on_off(uint8 turn_on_off);
/*
 * @brief : Fuse pump control to turn it on or off
 * @param : turn_on_off : @ref (TURN_ON , TURN_OFF)
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType fuse_pump_on_off(uint8 turn_on_off);


void touch_sensor_handler(void);

void send_string_handler(void);

#endif /* APP_APP_H_ */
