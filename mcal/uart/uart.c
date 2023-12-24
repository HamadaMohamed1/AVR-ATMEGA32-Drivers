/*
 * uart.c
 *
 *  Created on: Nov 23, 2023
 *      Author: hamada
 */

/*---------- Includes ----------*/
#include "uart.h"


/*
 * @brief Initialize the USART
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType uart_initialize(void)
{
	/* Calculate UBRR value for the desired baud rate
       ubrr_value = (F_CPU / (16 * BAUD_RATE)) - 1;
       if BAUD_RATE ==9600 then ubrr_value = 51
    */
	uint16 Local_Baud_Rate = 51;

	UBRRL =(uint8)Local_Baud_Rate;
	UBRRH =(uint8)(Local_Baud_Rate>>8);


	/*Normal speed*/
	CLEAR_BIT(UCSRA,U2X);
	/*Disable multi-processor*/
	CLEAR_BIT(UCSRA,MPCM);
	/*Enable receiver and transmitter*/
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	/*8 Bits Data*/
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
	CLEAR_BIT(UCSRB,UCSZ2);
	/*Asynchronous mode*/
	CLEAR_BIT(UCSRC,UMSEL);
	/*Disable parity*/
	CLEAR_BIT(UCSRC,UPM0);
	CLEAR_BIT(UCSRC,UPM1);
	/*2 stop bits*/
	SET_BIT(UCSRC,USBS);

	return E_OK;
}

/*
 * @brief  : Send char data over usart
 * @param  : data -> The char to be sent
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType uart_send_char(uint8 data)
{
	/* Wait for empty transmit buffer */
	while(READ_BIT(UCSRA,UDRE)==0);
	/* Put data into buffer, sends the data */
	UDR = data;
	return E_OK;
}
/*
 * @brief  : receive char data over usart
 * @param  : *data ->Pointer to store the char to be received
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType uart_receive_char(uint8 *data)
{
	Std_ReturnType ret = E_OK;
	if(NULL == data)
	{
		ret = E_NOT_OK;
	}
	else
	{
		/* Wait for data to be received */
		while(READ_BIT(UCSRA,RXC)==0);
		/* Get received data from buffer */
		*data = UDR;
		ret = E_OK;
	}

	return ret;
}

/*
 * @brief  : Send string over usart
 * @param  : *str -> The data to be sent
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType uart_send_string(const uint8 *str)
{
	Std_ReturnType ret = E_OK;
	if(NULL == str)
	{
		ret = E_NOT_OK;
	}
	else
	{
		uint8 *local_str = str;
		/* Wait for empty transmit buffer */
		while(READ_BIT(UCSRA,UDRE)==0);
		while(*local_str !='\0')
		{
			uart_send_char(*local_str++);
		}
		ret = E_OK;
	}
	return ret;
}

/*
 * @brief  : receive string data over usart
 * @param  : *str ->Pointer to store the data to be received
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType uart_receive_string(uint8 *str)
{
	Std_ReturnType ret = E_OK;
	if(NULL == str)
	{
		ret = E_NOT_OK;
	}
	else
	{
		uint8 i = 0;
		uart_receive_char(&str[i]);
		while(str[i] != '\r')
		{
			i++;
			uart_receive_char(&str[i]);
		}
		str[i] = '\0';
		ret = E_OK;
	}
	return ret;
}
