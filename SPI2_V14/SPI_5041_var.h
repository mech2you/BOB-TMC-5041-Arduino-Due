/*
 * SPI_5160_var.h
 *
 *  Created on: 24.07.2019
 *  Author: Adam Wilczek    
 */
#ifndef SPI_5041Var
#define SPI_5041Var

#define CHIP_SELECT       6 // Pin für SPI ChipSelect Low für aktive Kommunikation
#define EN_PIN            5 // Enable

struct DataOut{
	byte adresse; // 8 Bit Bspeispiel Hex 0x01 BIN 0000 0001
	unsigned long daten; // 4 mal 8 Bit=>32 Bit Bspeispiel HEX 0x00 00 00 0f   BIN 00000000 00000000 00000000 00001111 
};
#endif
