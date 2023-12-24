/*
 * general_interrupt.h
 *
 *  Created on: Nov 5, 2023
 *      Author: hamada
 */

#ifndef MCAL_INTERRUPT_GENERAL_INTERRUPT_H_
#define MCAL_INTERRUPT_GENERAL_INTERRUPT_H_

/*---------- Includes ----------*/
#include <avr/io.h>
#include "../../library/std_types.h"
#include "../../library/bit_math.h"
/*---------- Section: Macro Declarations ----------*/

#define GIE_ENABLE 		0
#define GIE_DISABLE 	1

#define GIE_BIT			7


/*---------- Section: Macro Functions Declarations ----------*/

/*---------- Section: Data Type Declarations ----------*/
/*---------- Section: Function Declarations ----------*/


/*
 * @brief  : Enable general interrupt
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gie_interrupt_enable(void);

/*
 * @brief  : Disable general interrupt
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gie_interrupt_disable(void);





#endif /* MCAL_INTERRUPT_GENERAL_INTERRUPT_H_ */
