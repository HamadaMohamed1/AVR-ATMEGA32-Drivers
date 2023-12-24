/*
 * uart.h
 *
 *  Created on: Nov 23, 2023
 *      Author: hamada
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

/*---------- Includes ----------*/
#include <avr/io.h>
#include "../../library/std_types.h"
#include "../../library/bit_math.h"

/*---------- Section: Macro Declarations ----------*/
#define F_CPU 	8000000UL



/*---------- Section: Macro Functions Declarations ----------*/




/*---------- Section: Function Declarations ----------*/
/*
 * @brief Initialize the USART
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType uart_initialize(void);
/*
 * @brief  : Send char data over usart
 * @param  : data -> The char to be sent
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType uart_send_char(uint8 data);
/*
 * @brief  : receive char data over usart
 * @param  : *data ->Pointer to store the char to be received
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType uart_receive_char(uint8 *data);

/*
 * @brief  : Send string over usart
 * @param  : *str -> The data to be sent
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType uart_send_string(const uint8 *str);

/*
 * @brief  : receive string data over usart
 * @param  : *str ->Pointer to store the data to be received
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType uart_receive_string(uint8 *str);


#endif /* MCAL_UART_UART_H_ */
