/*
 * i2c.h
 *
 *  Created on: Nov 24, 2023
 *      Author: hamada
 */

#ifndef MCAL_I2C_I2C_H_
#define MCAL_I2C_I2C_H_
/*---------- Includes ----------*/
#include "../gpio/gpio.h"


/*---------- Section: Macro Declarations ----------*/
#define F_CPU  8000000UL
#define SCL_CLOCK  100000UL



/*---------- Section: Data Type Declarations ----------*/



/*---------- Section: Function Declarations ----------*/

/*
 * @brief  : Initialize the I2C protocol
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_init(void);
/*
 * @brief  : Generate start condition
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_start(void);
/*
 * @brief  : Generate stop condition
 * @param  :
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_stop(void);
/*
 * @brief  : Generates an Acknowledge (ACK) after receiving a byte
 * @param  : *data : Pointer to store the byte after it is received
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_read_ack(uint8 *data);
/*
 * @brief  : Does not generate an Acknowledge (NACK) after receiving a byte
 * @param  : *data : Pointer to store the byte after it is received
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_read_nack(uint8 *data);
/*
 * @brief  : Send a byte
 * @param  : data : The byte to be sent
 * @return :
 * 			(E_OK) : The function done successfully
 * 			(E_NOT_OK) : The function has a problem to perform this action
 * */
Std_ReturnType I2C_write(uint8 data);



#endif /* MCAL_I2C_I2C_H_ */
