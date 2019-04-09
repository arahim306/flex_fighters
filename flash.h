#ifndef _FLASH_H_
#define _FLASH_H_

#include "spi.h"

/////////////////////////////////////////////////////
////////////////// FLASH COMMANDS ///////////////////
/////////////////////////////////////////////////////

#define		DUMMY			0x00
#define		CHIP_ERASE		0x60
#define		W_EN			0x06
#define		STATUS_REG		0x05
#define		PROGRAM			0x02
#define		FLASH_PCS		0b1110
#define		LASTXFER		1
#define		nLASTXFER		0


/////////////////////////////////////////////////////
/////////////////// FLASH DRIVERS ///////////////////
/////////////////////////////////////////////////////

// must be expanded when introducing more spi peripherals
void flash_init(void){
	//configure pc25 as nCS for flash; disable
	REG_PIOC_PER |= PIO_PC25;
	REG_PIOC_OER |= PIO_PC25;
	REG_PIOC_SODR |= PIO_PC25;
	// initialize spi
	spi_init();
}

void flash_status_config(void){
	// enable flash SS
	REG_PIOC_CODR |= PIO_PC25;
	// send WE command
	spi_byte_exchange(0x50, FLASH_PCS, LASTXFER);
	// disable flash SS
	REG_PIOC_SODR |= PIO_PC25;
	// enable flash SS
	REG_PIOC_CODR |= PIO_PC25;
	// write status reg command
	spi_byte_exchange(0x01, FLASH_PCS, LASTXFER);
	// send status byte 1
	spi_byte_exchange(0b10000000, FLASH_PCS, LASTXFER);
	// send status byte 2
	spi_byte_exchange(0b0000000, FLASH_PCS, LASTXFER);
	// disable flash SS
	REG_PIOC_SODR |= PIO_PC25;
}

void read_status_reg1(void){
	REG_PIOC_CODR |= PIO_PC25;
	spi_byte_exchange(0x05, FLASH_PCS, LASTXFER);
	spi_byte_exchange(DUMMY, FLASH_PCS, LASTXFER);
	REG_PIOC_SODR |= PIO_PC25;
}
void read_status_reg2(void){
	REG_PIOC_CODR |= PIO_PC25;
	spi_byte_exchange(0x35, FLASH_PCS, LASTXFER);
	spi_byte_exchange(DUMMY, FLASH_PCS, LASTXFER);
	REG_PIOC_SODR |= PIO_PC25;
}

// erase entire chip; warning: polls until finished
void flash_chip_erase(void){
	// enable flash SS
	REG_PIOC_CODR |= PIO_PC25;
	// send WE command
	spi_byte_exchange(W_EN, FLASH_PCS, LASTXFER);
	// send chip erase command
	spi_byte_exchange(CHIP_ERASE, FLASH_PCS, LASTXFER);
	// disable flash SS
	REG_PIOC_SODR |= PIO_PC25;
	// poll status reg byte 1 until erase completes (busy flag = 0)
	uint8_t flag = 1;
	while(flag){
		REG_PIOC_CODR |= PIO_PC25; // enable flash SS
		spi_byte_exchange(STATUS_REG, FLASH_PCS, LASTXFER);
		flag = spi_byte_exchange(DUMMY, FLASH_PCS, LASTXFER) & 1;
		REG_PIOC_SODR |= PIO_PC25; // disable flash SS
	}
}

// returns two bytes of data, thus traversing two addresses in flash
uint8_t flash_read(uint32_t address){
	uint16_t data = 0;
	REG_PIOC_CODR |= PIO_PC25; // enable flash SS
	//send read command
	spi_byte_exchange(0x03, FLASH_PCS, LASTXFER);
	
	//send address
	spi_byte_exchange((uint8_t)(address>>15), FLASH_PCS, LASTXFER);
	spi_byte_exchange((uint8_t)(address>>7), FLASH_PCS, LASTXFER);
	spi_byte_exchange((uint8_t)(address<<1), FLASH_PCS, LASTXFER);
	data = spi_byte_exchange(DUMMY, FLASH_PCS, LASTXFER);
	data = data << 8;
	data |= spi_byte_exchange(DUMMY, FLASH_PCS, LASTXFER);
	REG_PIOC_SODR |= PIO_PC25; // disable flash SS
	return data;
}

// this function writes two bytes, MSB followed by LSB
// for better performance, create burst write 
// note: addresses written to 256KB pages at once
// if 256KB boundary passed, new data will be written to beginning of page
// must toggle CS between pages
void flash_write(uint32_t address, uint16_t data){
	REG_PIOC_CODR |= PIO_PC25; // enable flash SS
	spi_byte_exchange(W_EN, FLASH_PCS, LASTXFER);
	REG_PIOC_SODR |= PIO_PC25; // disable flash SS
	REG_PIOC_CODR |= PIO_PC25; // enable flash SS
	spi_byte_exchange(PROGRAM, FLASH_PCS, LASTXFER);
	spi_byte_exchange((uint8_t)(address>>15), FLASH_PCS, LASTXFER);
	spi_byte_exchange((uint8_t)(address>>7), FLASH_PCS, LASTXFER);
	spi_byte_exchange((uint8_t)(address<<1), FLASH_PCS, LASTXFER);
	spi_byte_exchange((uint8_t)(data>>8), FLASH_PCS, LASTXFER);
	spi_byte_exchange((uint8_t)(data), FLASH_PCS, LASTXFER);
	REG_PIOC_SODR |= PIO_PC25; // disable flash SS
 	uint8_t flag = 1;
 	while(flag){
	 	REG_PIOC_CODR |= PIO_PC25; // enable flash SS
	 	spi_byte_exchange(STATUS_REG, FLASH_PCS, LASTXFER);
	 	flag = spi_byte_exchange(DUMMY, FLASH_PCS, LASTXFER) & 1;
	 	REG_PIOC_SODR |= PIO_PC25; // disable flash SS
 	}
 }

#endif