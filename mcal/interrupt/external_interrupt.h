/*
 * external_interrupt.h
 *
 *  Created on: Nov 5, 2023
 *      Author: hamada
 */

#ifndef MCAL_INTERRUPT_EXTERNAL_INTERRUPT_H_
#define MCAL_INTERRUPT_EXTERNAL_INTERRUPT_H_

/*---------- Includes ----------*/
#include "../../library/std_types.h"
#include "general_interrupt.h"
#include "../gpio/gpio.h"
/*---------- Section: Macro Declarations ----------*/



/*---------- Section: Macro Functions Declarations ----------*/

#define EXT_INT0_ENABLE() 	(SET_BIT(GICR,INT0))
#define EXT_INT0_DISABLE() 	(CLEAR_BIT(GICR,INT0))

#define EXT_INT1_ENABLE() 	(SET_BIT(GICR,INT1))
#define EXT_INT1_DISABLE() 	(CLEAR_BIT(GICR,INT1))

#define EXT_INT2_ENABLE() 	(SET_BIT(GICR,INT2))
#define EXT_INT2_DISABLE() 	(CLEAR_BIT(GICR,INT2))




/*---------- Section: Data Type Declarations ----------*/
typedef void(*interruptHandler)(void);



typedef enum{
	EXTERNAL_INTERRUPT_INT0 = 0 ,
	EXTERNAL_INTERRUPT_INT1 ,
	EXTERNAL_INTERRUPT_INT2
}interrupt_INTx_source;

typedef enum{
	INTERRUPT_LOW_LEVEL =0,			/*INT0   INT1*/
	INTERRUPT_ANY_LOGICAL_CHANGE,	/*INT0   INT1*/
    INTERRUPT_FALLING_EDGE ,		/*INT0   INT1   INT2*/
    INTERRUPT_RISING_EDGE			/*INT0   INT1   INT2*/
}interrupt_INTx_edge;


typedef struct{
	void (* EXT_InterruptHandler)(void);
	interrupt_INTx_edge edge;			/*@ref interrupt_INTx_edge*/
	interrupt_INTx_source INTx_src;		/*@ref interrupt_INTx_source*/
	uint8 INTx_port : 4;  				/*@ref port_index_t*/
	uint8 INTx_pin  : 4;				/*@ref pin_index_t*/
}interrupt_INTx_t;

/*---------- Section: Function Declarations ----------*/

/*
 * @brief Initialize the pin to be an external interrupt pin
 * @param int_obj : pointer to the configurations @ref interrupt_INTx_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj);

/*
 * @brief Cancel initialization of the pin
 * @param int_obj : pointer to the configurations @ref interrupt_INTx_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj);







#endif /* MCAL_INTERRUPT_EXTERNAL_INTERRUPT_H_ */
