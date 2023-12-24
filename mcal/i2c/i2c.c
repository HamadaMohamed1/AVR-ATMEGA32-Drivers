/*
 * i2c.c
 *
 *  Created on: Nov 24, 2023
 *      Author: hamada
 */


#include "i2c.h"

/*
 * @brief  : Initialize the I2C protocol
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_init(void)
{
	Std_ReturnType ret = E_OK;
	// Set prescaler to 1
	TWSR = 0;
	// Set bit rate
	TWBR = ((F_CPU / SCL_CLOCK) - 16) / 2;
	// Enable TWI, generate ACK, and enable TWI interrupt
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWINT);
	return ret;
}

/*
 * @brief  : Generate start condition
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_start(void)
{
	Std_ReturnType ret = E_OK;
    // Enable TWI, generate start condition, and clear interrupt flag
    SET_BIT(TWCR,TWSTA);
    SET_BIT(TWCR,TWEN);
    SET_BIT(TWCR,TWINT);
    // Wait until TWI interrupt flag is set
    while(!READ_BIT(TWCR,TWINT));
    return ret;
}
/*
 * @brief  : Generate stop condition
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_stop(void) {
	Std_ReturnType ret = E_OK;
    // Enable TWI, generate stop condition, and clear interrupt flag
	SET_BIT(TWCR,TWSTO);
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEN);
    // Wait until stop condition is executed
    while(READ_BIT(TWCR,TWSTO));
    return ret;
}

/*
 * @brief  : Generates an Acknowledge (ACK) after receiving a byte
 * @param  : *data : Pointer to store the byte after it is received
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_read_ack(uint8 *data) {
	Std_ReturnType ret = E_OK;
	if(NULL==data)
	{
		ret = E_NOT_OK;
	}
	else
	{
		// Enable TWI, generate ACK, and clear interrupt flag
		 SET_BIT(TWCR,TWEA);
		 SET_BIT(TWCR,TWEN);
		 SET_BIT(TWCR,TWINT);
		// Wait until data is received
		while(!READ_BIT(TWCR,TWINT));
		// Return received data
		*data = TWDR;
		ret = E_OK;
	}
    return ret;
}
/*
 * @brief  : Does not generate an Acknowledge (NACK) after receiving a byte
 * @param  : *data : Pointer to store the byte after it is received
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_read_nack(uint8 *data) {
	Std_ReturnType ret = E_OK;
	if(NULL==data)
	{
		ret = E_NOT_OK;
	}
	else
	{
		// Enable TWI and clear interrupt flag, but don't generate ACK
		SET_BIT(TWCR,TWEN);
		SET_BIT(TWCR,TWINT);
		// Wait until data is received
		while(!READ_BIT(TWCR,TWINT));
		// Return received data
		*data = TWDR;
		ret = E_OK;
	}
    return ret;
}

/*
 * @brief  : Send a byte
 * @param  : data : The byte to be sent
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_write(uint8 data) {
	Std_ReturnType ret = E_OK;
    // Load data into data register
    TWDR = data;
    // Enable TWI and clear interrupt flag
	TWCR = (1 << TWEN) | (1 << TWINT);
    // Wait until data is transmitted
    while(!READ_BIT(TWCR,TWINT));
    return ret;
}
