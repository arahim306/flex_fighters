#ifndef _SRAM_H_
#define _SRAM_H_	

#include "sam.h"
//#include "timer.h"

/////////////////////////////////////////////////////
//////////////// SRAM PIN BIT MASKS /////////////////
/////////////////////////////////////////////////////
#define		SRAM_A0_MSK			PIO_PER_P0		// PIO A
#define		SRAM_A1_MSK			PIO_PER_P1		// PIO A
#define		SRAM_A2_MSK			PIO_PER_P2		// PIO A
#define		SRAM_A3_MSK			PIO_PER_P3		// PIO A
#define		SRAM_A4_MSK			PIO_PER_P4		// PIO A
#define		SRAM_A5_MSK			PIO_PER_P5		// PIO A
#define		SRAM_A6_MSK			PIO_PER_P6		// PIO A
#define		SRAM_A7_MSK			PIO_PER_P7		// PIO A
#define		SRAM_A8_MSK			PIO_PER_P8		// PIO A
#define		SRAM_A9_MSK			PIO_PER_P10		// PIO A
#define		SRAM_A10_MSK		PIO_PER_P15		// PIO A
#define		SRAM_A11_MSK		PIO_PER_P16		// PIO A
#define		SRAM_A12_MSK		PIO_PER_P21		// PIO A
#define		SRAM_A13_MSK		PIO_PER_P22		// PIO A
#define		SRAM_A14_MSK		PIO_PER_P23		// PIO A
#define		SRAM_A15_MSK		PIO_PER_P24		// PIO A
#define		SRAM_A16_MSK		PIO_PER_P25		// PIO A
#define		SRAM_A17_MSK		PIO_PER_P26		// PIO A
#define		SRAM_A18_MSK		PIO_PER_P27		// PIO A

#define		SRAM_IO0_MSK		PIO_PER_P28		// PIO A
#define		SRAM_IO1_MSK		PIO_PER_P29		// PIO A
#define		SRAM_IO2_MSK		PIO_PER_P30		// PIO A
#define		SRAM_IO3_MSK		PIO_PER_P31		// PIO A
#define		SRAM_IO4_MSK		PIO_PER_P0		// PIO B
#define		SRAM_IO5_MSK		PIO_PER_P1		// PIO B
#define		SRAM_IO6_MSK		PIO_PER_P2		// PIO B
#define		SRAM_IO7_MSK		PIO_PER_P3		// PIO B
#define		SRAM_IO8_MSK		PIO_PER_P28		// PIO C
#define		SRAM_IO9_MSK		PIO_PER_P27		// PIO C
#define		SRAM_IO10_MSK		PIO_PB10		// PIO B
#define		SRAM_IO11_MSK		PIO_PB11		// PIO B
#define		SRAM_IO12_MSK		PIO_PC24		// PIO C
#define		SRAM_IO13_MSK		PIO_PER_P14		// PIO B
#define		SRAM_IO14_MSK		PIO_PER_P0		// PIO C
#define		SRAM_IO15_MSK		PIO_PER_P1		// PIO C

#define		SRAM_nOE_MSK		PIO_PER_P2		// PIO C
#define		SRAM_nWE_MSK		PIO_PER_P3		// PIO C
#define		SRAM_nCE_MSK		PIO_PER_P4		// PIO C	

#define		SRAM_nLB_MSK		PIO_PER_P29		// PIO C
#define		SRAM_nUB_MSK		PIO_PER_P30		// PIO C
#define		nFPGA_SRAM_EN_MSK	PIO_PER_P31		// PIO C

/////////////////////////////////////////////////////
//////////////// SRAM PIN POSITIONS /////////////////
/////////////////////////////////////////////////////

#define		SRAM_A0_Pos			0		// PIO A
#define		SRAM_A1_Pos			1		// PIO A
#define		SRAM_A2_Pos			2		// PIO A
#define		SRAM_A3_Pos			3		// PIO A
#define		SRAM_A4_Pos			4		// PIO A
#define		SRAM_A5_Pos			5		// PIO A
#define		SRAM_A6_Pos			6		// PIO A
#define		SRAM_A7_Pos			7		// PIO A
#define		SRAM_A8_Pos			8		// PIO A
#define		SRAM_A9_Pos			10		// PIO A
#define		SRAM_A10_Pos		15		// PIO A
#define		SRAM_A11_Pos		16		// PIO A
#define		SRAM_A12_Pos		21		// PIO A
#define		SRAM_A13_Pos		22		// PIO A
#define		SRAM_A14_Pos		23		// PIO A
#define		SRAM_A15_Pos		24		// PIO A
#define		SRAM_A16_Pos		25		// PIO A
#define		SRAM_A17_Pos		26		// PIO A
#define		SRAM_A18_Pos		27		// PIO A

#define		SRAM_IO0_Pos		28		// PIO A
#define		SRAM_IO1_Pos		29		// PIO A
#define		SRAM_IO2_Pos		30		// PIO A
#define		SRAM_IO3_Pos		31		// PIO A
#define		SRAM_IO4_Pos		0		// PIO B
#define		SRAM_IO5_Pos		1		// PIO B
#define		SRAM_IO6_Pos		2		// PIO B
#define		SRAM_IO7_Pos		3		// PIO B
#define		SRAM_IO8_Pos		28		// PIO C
#define		SRAM_IO9_Pos		27		// PIO C
#define		SRAM_IO10_Pos		10		// PIO B
#define		SRAM_IO11_Pos		11		// PIO B
#define		SRAM_IO12_Pos		24		// PIO C
#define		SRAM_IO13_Pos		14		// PIO B
#define		SRAM_IO14_Pos		0		// PIO C
#define		SRAM_IO15_Pos		1		// PIO C

#define		SRAM_nOE_Pos		2		// PIO C
#define		SRAM_nWE_Pos		3		// PIO C
#define		SRAM_nCE_Pos		4		// PIO C

#define		SRAM_nLB_Pos		29		// PIO C
#define		SRAM_nUB_Pos		30		// PIO C
#define		nFPGA_SRAM_EN_Pos	31		// PIO C

/////////////////////////////////////////////////////
/////////////////// SRAM DRIVERS ////////////////////
/////////////////////////////////////////////////////

void sram_init(void) {
	// ENABLE PIO CONTROL OF SRAM CONTROL SIGNALS
	REG_PIOC_PER |= SRAM_nCE_MSK | SRAM_nOE_MSK | SRAM_nWE_MSK | SRAM_nLB_MSK | SRAM_nUB_MSK;
	
	// DISABLE FPGA ACCESS TO SRAM
	REG_PIOC_PER  |= nFPGA_SRAM_EN_MSK;
	REG_PIOC_OER  |= nFPGA_SRAM_EN_MSK;
	REG_PIOC_SODR |= nFPGA_SRAM_EN_MSK;
	
	// CONFIGURE SRAM CONTROL SIGNALS AS OUTPUTS
	REG_PIOC_OER |= SRAM_nCE_MSK | SRAM_nOE_MSK | SRAM_nWE_MSK | SRAM_nLB_MSK | SRAM_nUB_MSK;
	
	// CONFIGURE SRAM CONTROL SIGNALS TO ENABLE CHIP AND WRITE BOTH BYTES
	REG_PIOC_SODR |= SRAM_nOE_MSK | SRAM_nWE_MSK;
	REG_PIOC_CODR |= SRAM_nCE_MSK | SRAM_nLB_MSK | SRAM_nUB_MSK;
	
	// ENABLE PIO FUNCTIONALITY OF SYSTEM IO
	REG_CCFG_SYSIO |= CCFG_SYSIO_SYSIO12 | CCFG_SYSIO_SYSIO11 | CCFG_SYSIO_SYSIO10;
}

void uP_sram_write_config(void) {
	// DISABLE FPGA ACCESS TO SRAM
//	REG_PIOC_PER  |= nFPGA_SRAM_EN_MSK;
//	REG_PIOC_OER  |= nFPGA_SRAM_EN_MSK;
//	REG_PIOC_SODR |= nFPGA_SRAM_EN_MSK;
	
	// ENABLE PIO CONTROL OF ADDRESS LINES
	REG_PIOA_PER |= SRAM_A18_MSK | SRAM_A17_MSK | SRAM_A16_MSK | SRAM_A15_MSK | SRAM_A14_MSK | SRAM_A13_MSK |
					SRAM_A12_MSK | SRAM_A11_MSK | SRAM_A10_MSK | SRAM_A9_MSK  | SRAM_A8_MSK  | SRAM_A7_MSK  |
					SRAM_A6_MSK  | SRAM_A5_MSK  | SRAM_A4_MSK  | SRAM_A3_MSK  | SRAM_A2_MSK  | SRAM_A1_MSK  | SRAM_A0_MSK;  
	
	// CONFIGURE ADDRESS PINS AS OUTPUTS
	REG_PIOA_OER |= SRAM_A18_MSK | SRAM_A17_MSK | SRAM_A16_MSK | SRAM_A15_MSK | SRAM_A14_MSK | SRAM_A13_MSK |
					 SRAM_A12_MSK | SRAM_A11_MSK | SRAM_A10_MSK | SRAM_A9_MSK  | SRAM_A8_MSK  | SRAM_A7_MSK  |
					 SRAM_A6_MSK  | SRAM_A5_MSK  | SRAM_A4_MSK  | SRAM_A3_MSK  | SRAM_A2_MSK  | SRAM_A1_MSK  | SRAM_A0_MSK;
					
	// ENABLE PIO CONTROL OF IO LINES
	REG_PIOA_PER |= SRAM_IO3_MSK  | SRAM_IO2_MSK  | SRAM_IO1_MSK  | SRAM_IO0_MSK;
	REG_PIOB_PER |= SRAM_IO13_MSK | SRAM_IO11_MSK | SRAM_IO10_MSK | SRAM_IO7_MSK  | SRAM_IO6_MSK  | SRAM_IO5_MSK  | SRAM_IO4_MSK; 
	REG_PIOC_PER |= SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK  | SRAM_IO8_MSK;
	
	// CONFIGURE IO PINS AS OUTPUTS
	REG_PIOA_OER |= SRAM_IO3_MSK  | SRAM_IO2_MSK  | SRAM_IO1_MSK  | SRAM_IO0_MSK;
	REG_PIOB_OER |= SRAM_IO13_MSK | SRAM_IO11_MSK | SRAM_IO10_MSK | SRAM_IO7_MSK  | SRAM_IO6_MSK  | SRAM_IO5_MSK  | SRAM_IO4_MSK;
	REG_PIOC_OER |= SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK  | SRAM_IO8_MSK;
	
}

void uP_sram_write(uint32_t address, uint32_t data) {
	
	// SET ADDRESS LINES
	
	REG_PIOA_CODR |= (SRAM_A18_MSK | SRAM_A17_MSK | SRAM_A16_MSK | SRAM_A15_MSK | SRAM_A14_MSK | SRAM_A13_MSK |
	  				  SRAM_A12_MSK | SRAM_A11_MSK | SRAM_A10_MSK | SRAM_A9_MSK  | SRAM_A8_MSK  | SRAM_A7_MSK  |
					  SRAM_A6_MSK  | SRAM_A5_MSK  | SRAM_A4_MSK  | SRAM_A3_MSK  | SRAM_A2_MSK  | SRAM_A1_MSK  | SRAM_A0_MSK);
	REG_PIOA_SODR |= ((((address >> 18) & 1) << SRAM_A18_Pos) | (((address >> 17) & 1) << SRAM_A17_Pos) | (((address >> 16) & 1) << SRAM_A16_Pos)
					|  (((address >> 15) & 1) << SRAM_A15_Pos) | (((address >> 14) & 1) << SRAM_A14_Pos) | (((address >> 13) & 1) << SRAM_A13_Pos)
					|  (((address >> 12) & 1) << SRAM_A12_Pos) | (((address >> 11) & 1) << SRAM_A11_Pos) | (((address >> 10) & 1) << SRAM_A10_Pos)
					|  (((address >> 9) & 1)  << SRAM_A9_Pos)  | (((address >> 8) & 1)  << SRAM_A8_Pos)  | (((address >> 7) & 1)  << SRAM_A7_Pos)
					|  (((address >> 6) & 1)  << SRAM_A6_Pos)  | (((address >> 5) & 1)  << SRAM_A5_Pos)  | (((address >> 4) & 1)  << SRAM_A4_Pos)
					|  (((address >> 3) & 1)  << SRAM_A3_Pos)  | (((address >> 2) & 1)  << SRAM_A2_Pos)  | (((address >> 1) & 1)  << SRAM_A1_Pos)
					|  ((address & 1) << SRAM_A16_Pos));
		
	// SET DATA LINES
	REG_PIOA_CODR |= (SRAM_IO3_MSK | SRAM_IO2_MSK | SRAM_IO1_MSK | SRAM_IO0_MSK);
	REG_PIOA_SODR |= ( (((data >> 3) & 1) << SRAM_IO3_Pos) | (((data >> 2) & 1) << SRAM_IO2_Pos) |
					   (((data >> 1) & 1) << SRAM_IO1_Pos) | (((data >> 0) & 1) << SRAM_IO0_Pos) );
	
	REG_PIOB_CODR |= (SRAM_IO13_MSK | SRAM_IO11_MSK | SRAM_IO10_MSK |
					  SRAM_IO7_MSK  | SRAM_IO6_MSK | SRAM_IO5_MSK | SRAM_IO4_MSK );
	REG_PIOB_SODR |= ( (((data >> 13) & 1) << SRAM_IO13_Pos)  |
						(((data >> 11) & 1) << SRAM_IO11_Pos) | (((data >> 10) & 1) << SRAM_IO10_Pos) |  
						(((data >> 7) & 1) << SRAM_IO7_Pos)   | (((data >> 6) & 1) << SRAM_IO6_Pos) |
						(((data >> 5) & 1) << SRAM_IO5_Pos)   | (((data >> 4) & 1) << SRAM_IO4_Pos) );
	
	REG_PIOC_CODR |= ( SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK | SRAM_IO8_MSK );
	REG_PIOC_SODR |= ( (((data >> 15) & 1) << SRAM_IO15_Pos) | (((data >> 14) & 1) << SRAM_IO14_Pos) |
					   (((data >> 9) & 1) << SRAM_IO9_Pos)   | (((data >> 8) & 1) << SRAM_IO8_Pos)   |
					   (((data >> 12) & 1) << SRAM_IO12_Pos));
	
		
	// CONFIGURE SRAM TO WRITE MODE
	REG_PIOC_CODR |= SRAM_nWE_MSK;
	
	// WAIT FOR CONVERSION TO COMPLETE
//	delay_hundred_ns(1);
	
	// EXIT SRAM WRITE MODE
	REG_PIOC_SODR |= SRAM_nWE_MSK;
}

void uP_sram_read_config(void) {
	// DISABLE FPGA ACCESS TO SRAM
//	REG_PIOC_PER  |= nFPGA_SRAM_EN_MSK;
//	REG_PIOC_OER  |= nFPGA_SRAM_EN_MSK;
	REG_PIOC_SODR |= nFPGA_SRAM_EN_MSK;
	
	// ENABLE PIO CONTROL OF ADDRESS LINES
	REG_PIOA_PER |= SRAM_A18_MSK | SRAM_A17_MSK | SRAM_A16_MSK | SRAM_A15_MSK | SRAM_A14_MSK | SRAM_A13_MSK |
					SRAM_A12_MSK | SRAM_A11_MSK | SRAM_A10_MSK | SRAM_A9_MSK  | SRAM_A8_MSK  | SRAM_A7_MSK  |
					SRAM_A6_MSK  | SRAM_A5_MSK  | SRAM_A4_MSK  | SRAM_A3_MSK  | SRAM_A2_MSK  | SRAM_A1_MSK  | SRAM_A0_MSK;
	
	// CONFIGURE ADDRESS PINS AS OUTPUTS
	REG_PIOA_OER |= SRAM_A18_MSK | SRAM_A17_MSK | SRAM_A16_MSK | SRAM_A15_MSK | SRAM_A14_MSK | SRAM_A13_MSK |
					SRAM_A12_MSK | SRAM_A11_MSK | SRAM_A10_MSK | SRAM_A9_MSK  | SRAM_A8_MSK  | SRAM_A7_MSK  |
					SRAM_A6_MSK  | SRAM_A5_MSK  | SRAM_A4_MSK  | SRAM_A3_MSK  | SRAM_A2_MSK  | SRAM_A1_MSK  | SRAM_A0_MSK;
	
	// ENABLE PIOA PIOB PIOC CLK
	REG_PMC_PCER0 |= PMC_PCER0_PID13 | PMC_PCER0_PID12 | PMC_PCER0_PID11;
	
	// ENABLE PIO CONTROL OF IO LINES
	REG_PIOA_PER |= SRAM_IO3_MSK  | SRAM_IO2_MSK  | SRAM_IO1_MSK  | SRAM_IO0_MSK;
	REG_PIOB_PER |= SRAM_IO13_MSK | SRAM_IO11_MSK | SRAM_IO10_MSK | SRAM_IO7_MSK  | SRAM_IO6_MSK  | SRAM_IO5_MSK  | SRAM_IO4_MSK;
	REG_PIOC_PER |= SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK  | SRAM_IO8_MSK;
	
	// CONFIGURE IO PINS AS INPUTS
	REG_PIOA_ODR |= SRAM_IO3_MSK  | SRAM_IO2_MSK  | SRAM_IO1_MSK  | SRAM_IO0_MSK;
	REG_PIOB_ODR |= SRAM_IO13_MSK | SRAM_IO11_MSK | SRAM_IO10_MSK | SRAM_IO7_MSK  | SRAM_IO6_MSK  | SRAM_IO5_MSK  | SRAM_IO4_MSK;
	REG_PIOC_ODR |= SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK  | SRAM_IO8_MSK;
	
	// DISABLE PULL DOWN RESISTORS FOR IO LINES
	REG_PIOA_PPDDR |= SRAM_IO3_MSK  | SRAM_IO2_MSK  | SRAM_IO1_MSK  | SRAM_IO0_MSK;
	REG_PIOB_PPDDR |= SRAM_IO13_MSK | SRAM_IO11_MSK | SRAM_IO10_MSK | SRAM_IO7_MSK  | SRAM_IO6_MSK  | SRAM_IO5_MSK  | SRAM_IO4_MSK;
	REG_PIOC_PPDDR |= SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK  | SRAM_IO8_MSK;
	
	// ENABLE PULL UP RESISTORS FOR IO LINES
	REG_PIOA_PUER |= SRAM_IO3_MSK  | SRAM_IO2_MSK  | SRAM_IO1_MSK  | SRAM_IO0_MSK;
	REG_PIOB_PUER |= SRAM_IO13_MSK | SRAM_IO11_MSK | SRAM_IO10_MSK | SRAM_IO7_MSK  | SRAM_IO6_MSK  | SRAM_IO5_MSK  | SRAM_IO4_MSK;
	REG_PIOC_PUER |= SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK  | SRAM_IO8_MSK;
}

uint32_t uP_sram_read(uint32_t address) {
	// SET ADDRESS LINES
	REG_PIOA_CODR |= (SRAM_A18_MSK | SRAM_A17_MSK | SRAM_A16_MSK | SRAM_A15_MSK | SRAM_A14_MSK | SRAM_A13_MSK |
					  SRAM_A12_MSK | SRAM_A11_MSK | SRAM_A10_MSK | SRAM_A9_MSK  | SRAM_A8_MSK  | SRAM_A7_MSK  |
					  SRAM_A6_MSK  | SRAM_A5_MSK  | SRAM_A4_MSK  | SRAM_A3_MSK  | SRAM_A2_MSK  | SRAM_A1_MSK  | SRAM_A0_MSK);
	REG_PIOA_SODR |= ((((address >> 18) & 1) << SRAM_A18_Pos) | (((address >> 17) & 1) << SRAM_A17_Pos) | (((address >> 16) & 1) << SRAM_A16_Pos)
				   |  (((address >> 15) & 1) << SRAM_A15_Pos) | (((address >> 14) & 1) << SRAM_A14_Pos) | (((address >> 13) & 1) << SRAM_A13_Pos)
				   |  (((address >> 12) & 1) << SRAM_A12_Pos) | (((address >> 11) & 1) << SRAM_A11_Pos) | (((address >> 10) & 1) << SRAM_A10_Pos)
				   |  (((address >> 9) & 1)  << SRAM_A9_Pos)  | (((address >> 8) & 1)  << SRAM_A8_Pos)  | (((address >> 7) & 1)  << SRAM_A7_Pos)
				   |  (((address >> 6) & 1)  << SRAM_A6_Pos)  | (((address >> 5) & 1)  << SRAM_A5_Pos)  | (((address >> 4) & 1)  << SRAM_A4_Pos)
				   |  (((address >> 3) & 1)  << SRAM_A3_Pos)  | (((address >> 2) & 1)  << SRAM_A2_Pos)  | (((address >> 1) & 1)  << SRAM_A1_Pos)
				   |  ((address & 1) << SRAM_A16_Pos));
	
	
	// CONFIGURE SRAM TO READ MODE
	REG_PIOC_CODR |= SRAM_nOE_MSK;
	
	// WAIT FOR CONVERSION TO COMPLETE
//	delay_hundred_ns(1);
	
	// PARSE IO LINES AND SAVE DATA
	uint32_t dataA = REG_PIOA_PDSR;
	uint32_t dataB = REG_PIOB_PDSR;
	uint32_t dataC = REG_PIOC_PDSR;
	
	uint32_t data =
		(((dataC >> SRAM_IO15_Pos) & 1) << 15) | (((dataC >> SRAM_IO14_Pos) & 1) << 14) | (((dataB >> SRAM_IO13_Pos) & 1) << 13) |
		(((dataC >> SRAM_IO12_Pos) & 1) << 12) | (((dataB >> SRAM_IO11_Pos) & 1) << 11) | (((dataB >> SRAM_IO10_Pos) & 1) << 10) |
		(((dataC >> SRAM_IO9_Pos) & 1) << 9)   | (((dataC >> SRAM_IO8_Pos) & 1) << 8)   | (((dataB >> SRAM_IO7_Pos) & 1) << 7)   |
		(((dataB >> SRAM_IO6_Pos) & 1) << 6)   | (((dataB >> SRAM_IO5_Pos) & 1) << 5)   | (((dataB >> SRAM_IO4_Pos) & 1) << 4)   |
		(((dataA >> SRAM_IO3_Pos) & 1) << 3)   | (((dataA >> SRAM_IO2_Pos) & 1) << 2)   | (((dataA >> SRAM_IO1_Pos) & 1) << 1)   |
		((dataA >> SRAM_IO0_Pos) & 1);
		
	
	// EXIT SRAM READ MODE
	REG_PIOC_SODR |= SRAM_nOE_MSK;
	
	return data;
}

void fpga_sram_read_config(void) {
	// ENABLE FPGA ACCESS TO SRAM
	REG_PIOC_PER  |= nFPGA_SRAM_EN_MSK;
	REG_PIOC_OER  |= nFPGA_SRAM_EN_MSK;
	REG_PIOC_CODR |= nFPGA_SRAM_EN_MSK;
	
	// ENABLE PIO CONTROL OF ADDRESS LINES
	REG_PIOA_PER |= SRAM_A18_MSK | SRAM_A17_MSK | SRAM_A16_MSK | SRAM_A15_MSK | SRAM_A14_MSK | SRAM_A13_MSK |
	SRAM_A12_MSK | SRAM_A11_MSK | SRAM_A10_MSK | SRAM_A9_MSK  | SRAM_A8_MSK  | SRAM_A7_MSK  |
	SRAM_A6_MSK  | SRAM_A5_MSK  | SRAM_A4_MSK  | SRAM_A3_MSK  | SRAM_A2_MSK  | SRAM_A1_MSK  | SRAM_A0_MSK;
	
	// CONFIGURE ADDRESS PINS AS INPUTS
	REG_PIOA_ODR |= SRAM_A18_MSK | SRAM_A17_MSK | SRAM_A16_MSK | SRAM_A15_MSK | SRAM_A14_MSK | SRAM_A13_MSK |
					SRAM_A12_MSK | SRAM_A11_MSK | SRAM_A10_MSK | SRAM_A9_MSK  | SRAM_A8_MSK  | SRAM_A7_MSK  |
					SRAM_A6_MSK  | SRAM_A5_MSK  | SRAM_A4_MSK  | SRAM_A3_MSK  | SRAM_A2_MSK  | SRAM_A1_MSK  | SRAM_A0_MSK;
	
	// ENABLE PIOA PIOB PIOC CLK
	//REG_PMC_PCER0 |= PMC_PCER0_PID13 | PMC_PCER0_PID12 | PMC_PCER0_PID11;
	
	// ENABLE PIO CONTROL OF IO LINES
	REG_PIOA_PER |= SRAM_IO3_MSK  | SRAM_IO2_MSK  | SRAM_IO1_MSK  | SRAM_IO0_MSK;
	REG_PIOB_PER |= SRAM_IO13_MSK | SRAM_IO11_MSK | SRAM_IO10_MSK | SRAM_IO7_MSK  | SRAM_IO6_MSK  | SRAM_IO5_MSK  | SRAM_IO4_MSK;
	REG_PIOC_PER |= SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK  | SRAM_IO8_MSK;
	
	// CONFIGURE IO PINS AS INPUTS
	REG_PIOA_ODR |= SRAM_IO3_MSK  | SRAM_IO2_MSK  | SRAM_IO1_MSK  | SRAM_IO0_MSK;
	REG_PIOB_ODR |= SRAM_IO13_MSK| SRAM_IO11_MSK  | SRAM_IO10_MSK | SRAM_IO7_MSK  | SRAM_IO6_MSK  | SRAM_IO5_MSK  | SRAM_IO4_MSK;
	REG_PIOC_ODR |= SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK  | SRAM_IO8_MSK;
	
	// DISABLE PULL DOWN RESISTORS FOR IO LINES
//	REG_PIOA_PPDDR |= SRAM_IO3_MSK  | SRAM_IO2_MSK  | SRAM_IO1_MSK  | SRAM_IO0_MSK;
//	REG_PIOB_PPDDR |= SRAM_IO13_MSK | SRAM_IO11_MSK | SRAM_IO10_MSK | SRAM_IO7_MSK  | SRAM_IO6_MSK  | SRAM_IO5_MSK  | SRAM_IO4_MSK;
//	REG_PIOC_PPDDR |= SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK  | SRAM_IO8_MSK;
	
	// ENABLE PULL UP RESISTORS FOR IO LINES
//	REG_PIOA_PUER |= SRAM_IO3_MSK  | SRAM_IO2_MSK  | SRAM_IO1_MSK  | SRAM_IO0_MSK;
//	REG_PIOB_PUER |= SRAM_IO13_MSK | SRAM_IO11_MSK | SRAM_IO10_MSK | SRAM_IO7_MSK  | SRAM_IO6_MSK  | SRAM_IO5_MSK  | SRAM_IO4_MSK;
//	REG_PIOC_PUER |= SRAM_IO15_MSK | SRAM_IO14_MSK | SRAM_IO12_MSK | SRAM_IO9_MSK  | SRAM_IO8_MSK;

	// CONFIGURE SRAM TO READ MODE
	REG_PIOC_CODR |= SRAM_nOE_MSK;
}

void enable_sysio(void){
	REG_CCFG_SYSIO &= ~(CCFG_SYSIO_SYSIO12 | CCFG_SYSIO_SYSIO11 | CCFG_SYSIO_SYSIO10);
}

void disable_sysio(void){
	REG_CCFG_SYSIO |= CCFG_SYSIO_SYSIO12 | CCFG_SYSIO_SYSIO11 | CCFG_SYSIO_SYSIO10;
}

void enable_buffers(void){
	REG_PIOC_PER  |= nFPGA_SRAM_EN_MSK;
	REG_PIOC_OER  |= nFPGA_SRAM_EN_MSK;
	REG_PIOC_CODR |= nFPGA_SRAM_EN_MSK;
}

#endif