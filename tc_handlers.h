#ifndef _TC_HANDLER_H_
#define _TC_HANDLER_H_

void tc0_init(){
	//Setup for TC0 - ID 23
	
	//enable interrupts in NVIC for TC0
	NVIC_EnableIRQ(TC0_IRQn);
	
	//PMC setup
	//enable peripheral clock for timer counter channel0
	REG_PMC_PCER0 |= PMC_PCER0_PID23;
	
	//Interrupt Setup
	REG_TC0_CMR0 |= TC_CMR_TCCLKS_TIMER_CLOCK1; //mainclock div 2
	REG_TC0_IER0 |= TC_IER_COVFS; //enable couter overflow interrupt
	REG_TC0_IER0 |= TC_IER_CPCS; //enable RC compare interrupt
//	REG_TC0_IER0 |= TC_IER_COVFS;
	//REG_TC0_CMR0 |= TC_CMR_CPCTRG; //compare resets counter and clock
	REG_TC0_RC0 = 65535;
//	REG_TC0_CCR0 |= TC_CCR_CLKEN; //enable tc clock
	
	//PIO setup (not necessary) because we won't use the pins
}

// void tc1_init(){
// 	//Setup for TC1 - ID 23
// 	
// 	//enable interrupts in NVIC for TC0
// 	NVIC_EnableIRQ(TC1_IRQn);
// 	
// 	//PMC setup
// 	//enable peripheral clock for timer counter channel0
// 	REG_PMC_PCER0 |= PMC_PCER0_PID24;
// 	
// 	//Interrupt Setup
// 	REG_TC1_CMR0 |= TC_CMR_TCCLKS_TIMER_CLOCK1; //mainclock div 2
// //	REG_TC1_IER0 |= TC_IER_COVFS; //enable couter overflow interrupt
// 	REG_TC1_IER0 |= TC_IER_CPBS; //enable RC compare interrupt
// 	//REG_TC1_CMR0 |= TC_CMR_CPCTRG; //compare resets counter and clock
// 	REG_TC1_RC0 = 65535;
// 	REG_TC0_CCR0 &= ~TC_CCR_CLKDIS; //enable tc clock
// 	
// 	//PIO setup (not necessary) because we won't use the pins
// }

// void delay_hundred_ns(uint32_t delayInHundredNs){
// 
// 	REG_TC0_RC0 = 1000; //1 second / 120mhz * 12 = 100ns
// 	//enable tc clock
// 	REG_TC0_CCR0 |= TC_CCR_CLKEN;
// 	//start timer
// 	REG_TC0_CCR0 |= TC_CCR_SWTRG;
// 
// 	while (counter <= delayInHundredNs){}
// 
// 	//disable tc clock
// 	REG_TC0_CCR0 |= TC_CCR_CLKDIS;
// 	//reset counter
// 	counter = 0;
// }

void TC0_Handler(void){
	//read status register - this clears interrupt flags
	uint32_t status = REG_TC0_SR0;
	if ((status & TC_SR_CPCS)>=1){
		//increment counter
		if (counter >= 10) {
			REG_PIOC_CODR |= PIO_PC7;
			REG_PIOC_CODR |= PIO_PC9;
			allowPunch = 1;
			REG_TC0_CCR0 |= TC_CCR_CLKDIS;
			REG_TC0_CCR0 &= ~TC_CCR_SWTRG;
		}
		else {
			counter+=1;
		}
	}
}

// void TC1_Handler(void){
// 	//read status register - this clears interrupt flags
// 	uint32_t status = REG_TC1_SR0;
// 	if ((status & TC_SR_CPBS)>=1){
// 		//increment counter
// 		if (counter >= 20) {
// 			REG_PIOC_CODR |= PIO_PC9; 
// 			allowPunch = 1;
// 			REG_TC1_CCR0 |= TC_CCR_CLKDIS;
// 			REG_TC1_CCR0 &= ~TC_CCR_SWTRG;
// 		}
// 		else {
// 			counter+=1;
// 		}
// 	}
// }


#endif