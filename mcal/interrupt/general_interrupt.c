/*
 * general_interrupt.c
 *
 *  Created on: Nov 5, 2023
 *      Author: hamada
 */
/*---------- Includes ----------*/
#include "general_interrupt.h"



/*
 * @brief  : Enable general interrupt
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gie_interrupt_enable(void)
{
	SET_BIT(SREG,GIE_BIT);
	return E_OK ;
}

/*
 * @brief  : Disable general interrupt
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType gie_interrupt_disable(void)
{
	CLEAR_BIT(SREG,GIE_BIT);
	return E_OK ;
}
