#ifndef _SPI_H_
#define _SPI_H_

void spi_setMode(uint8_t mode){	
    /*
    Mode		CPOL	NCPHA
    Mode0		0		1
    Mode1		0		0
    Mode2		1		1
    Mode3		1		0
    */
    if (mode == 0){
        REG_SPI_CSR &= ~SPI_CSR_CPOL;
        REG_SPI_CSR |= SPI_CSR_NCPHA;
    }
    else if (mode == 1){
        REG_SPI_CSR &= ~SPI_CSR_CPOL;
        REG_SPI_CSR &= ~SPI_CSR_NCPHA;
    }
    else if (mode == 2){
        REG_SPI_CSR |= SPI_CSR_CPOL;
        REG_SPI_CSR |= SPI_CSR_NCPHA;
    }
    else if (mode == 3){
        REG_SPI_CSR |= SPI_CSR_CPOL;
        REG_SPI_CSR &= ~SPI_CSR_NCPHA;
    }
}

void spi_selectPeripheral(uint8_t peripheral){
	//chose peripheral
	//this only works if SPI_MR.PS = 0
	//if SPI_MR.PS = 1 then peripheral selection is done in SPI_THR.PCS
	if (peripheral == 0){
		//choose NPCS0
		REG_SPI_MR |= SPI_MR_PCS(0b1110);
	}
	else if (peripheral ==1){
		//choose NPCS1
		REG_SPI_MR |= SPI_MR_PCS(0b1101);
	}
	else if (peripheral ==2){
		//choose NPCS2
		REG_SPI_MR |= SPI_MR_PCS(0b1011);
	}
	else if (peripheral ==3){
		//choose NPCS3
		REG_SPI_MR |= SPI_MR_PCS(0b0111);
	}
}

void SPI_deselect_span(){
	//wait for transmit register to be empty
	while (!(REG_SPI_SR & SPI_SR_TDRE));
	//send data to transmit register
	REG_SPI_TDR |= SPI_TDR_LASTXFER;
	//wait for received data to be ready to be read
	while (!(REG_SPI_SR & SPI_SR_RDRF));
}

void spi_init(){
	//enable peripheral clock
	REG_PMC_PCER0 |= PMC_PCER0_PID21;
	//set spi master mode
	REG_SPI_MR |= SPI_MR_MSTR;
	//set fixed peripheral select(peripheral chosen in SP_MR.PCS instead of SPI_THR.PCS)
	//REG_SPI_MR &= ~SPI_MR_PS;
	
	// set variable peripheral select
	REG_SPI_MR |= SPI_MR_PS;
	
	//set polarity and clock phase
	spi_setMode(0);
	//set clock generator (1 = peripheral clock rate), otherwise a divisor
	//SCBR = peripheral clock / SPCK Bit Rate
	REG_SPI_CSR |= SPI_CSR_SCBR(1);
	//chip select remains low after transfer
	REG_SPI_CSR &= ~SPI_CSR_CSNAAT;
	//REG_SPI_CSR |= SPI_CSR_CSAAT;
	//give peripheral control of pins (Chip select pins are optional)
	REG_PIOA_PDR |= PIO_PDR_P11; //NPCS0
	//REG_PIOA_PDR |= PIO_PDR_P31; //NPCS1
	REG_PIOA_PDR |= PIO_PDR_P12; //MISO
	REG_PIOA_PDR |= PIO_PDR_P13; //MOSI
	REG_PIOA_PDR |= PIO_PDR_P14; //SCK
	//enable SPI
	REG_SPI_CR |= SPI_CR_SPIEN;
}

// slave select
void spi_ss(){
	REG_PIOA_CODR |= PIO_CODR_P11; //set PA11 low
}

// slave de-select
void spi_ss_n(){
	//wait for transmit register to be empty
	while (!(REG_SPI_SR & SPI_SR_TDRE));
	//send data to transmit register
	REG_SPI_TDR |= SPI_TDR_LASTXFER;
	//wait for received data to be ready to be read
	while (!(REG_SPI_SR & SPI_SR_RDRF));
	REG_PIOA_SODR |= PIO_SODR_P31; //set PA11 high
}

// note: assumes spi configured in variable peripheral select mode
// requires PCS(peripheral chip select) to know which spi periphal to configure
// requires LASTXFER (last transfer) to know whether this is the last byte in transfer (to disable PCS)
uint8_t spi_byte_exchange(uint8_t data, uint8_t PCS, uint8_t LASTXFER){
//	REG_PIOC_CODR |= PIO_PC25; // enable flash SS
	//wait for transmit register to be empty
	while (!(REG_SPI_SR & SPI_SR_TDRE));
	//send data to transmit register, append PCS, append LASTXFER if necessary
	if(LASTXFER > 0)
		REG_SPI_TDR = data | SPI_TDR_PCS(PCS) | SPI_TDR_LASTXFER;
	else
		REG_SPI_TDR = (data | SPI_TDR_PCS(PCS)) & (~SPI_TDR_LASTXFER);
	//wait for received data to be ready to be read
	while (!(REG_SPI_SR & SPI_SR_RDRF));
//	REG_PIOC_SODR |= PIO_PC25; // enable flash SS
	//read received data
	return REG_SPI_RDR;
}

#endif