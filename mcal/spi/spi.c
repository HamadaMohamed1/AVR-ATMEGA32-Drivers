/*
 * spi.c
 *
 *  Created on: Dec 22, 2023
 *      Author: hamada
 */

#include "spi.h"


// Initialize SPI as master or slave
void SPI_Init(void) {
#if SPI_MODE==MASTER
        // Set MOSI, SCK, and SS as output
        DDRB |= (1 << DDB2) | (1 << DDB3) | (1 << DDB5);

        // Enable SPI, Set as Master, and clock = F_CPU/16
        SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
#elif SPI_MODE==SlAVE       // Set MISO as output, all others as input
        DDRB |= (1 << DDB4);

        // Enable SPI
        SPCR = (1 << SPE);
#endif

}

// Transmit data through SPI
void SPI_Transmit(uint8_t data) {
    // Start transmission
    SPDR = data;

    // Wait for transmission complete
    while (!(SPSR & (1 << SPIF)))
        ;
}

// Receive data through SPI
uint8_t SPI_Receive() {
    // Wait for reception complete
    while (!(SPSR & (1 << SPIF)))
        ;

    // Return received data
    return SPDR;
}
