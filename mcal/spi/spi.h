/*
 * spi.h
 *
 *  Created on: Dec 22, 2023
 *      Author: hamada
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_


#include <avr/io.h>
#include "spi_cfg.h"



// Function prototypes
void SPI_Init(void);
void SPI_Transmit(uint8_t data);
uint8_t SPI_Receive();



#endif /* MCAL_SPI_SPI_H_ */
