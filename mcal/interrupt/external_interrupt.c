/*
 * external_interrupt.c
 *
 *  Created on: Nov 5, 2023
 *      Author: hamad
 */

#include "external_interrupt.h"

void __vector_1( void )__attribute__( (signal, __INTR_ATTRS) );
void __vector_2( void )__attribute__( (signal, __INTR_ATTRS) );
void __vector_3( void )__attribute__( (signal, __INTR_ATTRS) );

static interruptHandler INT0_interrptHandler = NULL;
static interruptHandler INT1_interrptHandler = NULL;
static interruptHandler INT2_interrptHandler = NULL;

static Std_ReturnType INT0_SetInterruptHandler(const interrupt_INTx_t *int_obj);
static Std_ReturnType INT1_SetInterruptHandler(const interrupt_INTx_t *int_obj);
static Std_ReturnType INT2_SetInterruptHandler(const interrupt_INTx_t *int_obj);


/*
 * @brief Initialize the pin to be an external interrupt pin
 * @param int_obj : pointer to the configurations @ref interrupt_INTx_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj)
{
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = gie_interrupt_enable();
		pin_config_t int_pin = {	.port = int_obj->INTx_port ,
									.pin = int_obj->INTx_pin ,
									.direction = GPIO_DIRECTION_OUTPUT
		};

		ret = gpio_pin_intialize(&int_pin);

		if(EXTERNAL_INTERRUPT_INT0==int_obj->INTx_src)
		{
			ret = INT0_SetInterruptHandler(int_obj);

			switch(int_obj->edge)
			{
				case INTERRUPT_LOW_LEVEL :
						CLEAR_BIT(MCUCR,ISC00);
						CLEAR_BIT(MCUCR,ISC01);
				break;
				case INTERRUPT_ANY_LOGICAL_CHANGE :
						SET_BIT(MCUCR,ISC00);
						CLEAR_BIT(MCUCR,ISC01);
				break;
				case INTERRUPT_FALLING_EDGE :
						CLEAR_BIT(MCUCR,ISC00);
						SET_BIT(MCUCR,ISC01);
				break;
				case INTERRUPT_RISING_EDGE :
						SET_BIT(MCUCR,ISC00);
						SET_BIT(MCUCR,ISC01);
				break;
				default :
						ret = E_NOT_OK;
				break;
			}
			EXT_INT0_ENABLE();
		}
		else if(EXTERNAL_INTERRUPT_INT1==int_obj->INTx_src)
		{
			ret = INT1_SetInterruptHandler(int_obj);

			switch(int_obj->edge)
			{
				case INTERRUPT_LOW_LEVEL :
						CLEAR_BIT(MCUCR,ISC10);
						CLEAR_BIT(MCUCR,ISC11);
				break;
				case INTERRUPT_ANY_LOGICAL_CHANGE :
						SET_BIT(MCUCR,ISC10);
						CLEAR_BIT(MCUCR,ISC11);
				break;
				case INTERRUPT_FALLING_EDGE :
						CLEAR_BIT(MCUCR,ISC10);
						SET_BIT(MCUCR,ISC11);
				break;
				case INTERRUPT_RISING_EDGE :
						SET_BIT(MCUCR,ISC10);
						SET_BIT(MCUCR,ISC11);
				break;
				default :
						ret = E_NOT_OK;
				break;
			}
			EXT_INT1_ENABLE();
		}
		else if(EXTERNAL_INTERRUPT_INT2==int_obj->INTx_src)
		{
			ret = INT2_SetInterruptHandler(int_obj);

			switch(int_obj->edge)
			{
				case INTERRUPT_FALLING_EDGE :
						CLEAR_BIT(MCUCSR,ISC2);
				break;
				case INTERRUPT_RISING_EDGE :
						SET_BIT(MCUCSR,ISC2);
				break;
				default :
						ret = E_NOT_OK;
				break;
			}
			EXT_INT2_ENABLE();
		}

	}
	return ret;
}

/*
 * @brief Cancel initialization of the pin
 * @param int_obj : pointer to the configurations @ref interrupt_INTx_t
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj)
{
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(int_obj->INTx_src)
		{
			case EXTERNAL_INTERRUPT_INT0 :
					EXT_INT0_DISABLE();
			break;
			case EXTERNAL_INTERRUPT_INT1 :
					EXT_INT1_DISABLE();
			break;
			case EXTERNAL_INTERRUPT_INT2 :
					EXT_INT2_DISABLE();
			break;
			default :
					ret = E_NOT_OK;
			break;
		}
	}
	return ret;
}

static Std_ReturnType INT0_SetInterruptHandler(const interrupt_INTx_t *int_obj)
{
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj)
	{
		ret = E_NOT_OK;
	}
	else
	{
		INT0_interrptHandler = int_obj->EXT_InterruptHandler;
		ret = E_OK;
	}
	return ret;
}
static Std_ReturnType INT1_SetInterruptHandler(const interrupt_INTx_t *int_obj)
{
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj)
	{
		ret = E_NOT_OK;
	}
	else
	{
		INT1_interrptHandler = int_obj->EXT_InterruptHandler;
		ret = E_OK;
	}
	return ret;
}
static Std_ReturnType INT2_SetInterruptHandler(const interrupt_INTx_t *int_obj)
{
	Std_ReturnType ret = E_OK;
	if(NULL == int_obj)
	{
		ret = E_NOT_OK;
	}
	else
	{
		INT2_interrptHandler = int_obj->EXT_InterruptHandler;
		ret = E_OK;
	}
	return ret;
}


void __vector_1( void )
{
	if(INT0_interrptHandler){ INT0_interrptHandler(); }
	else{ /* Nothing */ }
}

void __vector_2( void )
{
	if(INT1_interrptHandler){ INT1_interrptHandler(); }
	else{ /* Nothing */ }
}

void __vector_3( void )
{
	if(INT2_interrptHandler){ INT2_interrptHandler(); }
	else{ /* Nothing */ }
}











