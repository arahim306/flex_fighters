#ifndef GAME_DRIVER_H
#define GAME_DRIVER_H

#include "sam.h"
#include "array_handling.h"

void punch(int channelNum, circularBuf *circBufX, uint32_t strength) {
	// within each channel: 
	// 1) check timer counter for recent punch (individual TC per arm)
	// 2) toggle GPIO to change image
	// 3) remove health from opposite health bar
	// 4) clear out buffer
	if (channelNum == 0) {
		circBufFlush(circBufX,1);
		REG_PIOC_SODR |= PIO_PC7; // LEFT PUNCH LEFT BOXER
		allowPunch = 0;
		counter = 0;
		REG_TC0_CCR0 |= TC_CCR_CLKEN;
		REG_TC0_CCR0 |= TC_CCR_SWTRG;
	}
	else if (channelNum == 1) {
		circBufFlush(circBufX,1);
		REG_PIOC_SODR |= PIO_PC7; // RIGHTT PUNCH LEFT BOXER
		allowPunch = 0;
		counter = 0;
		REG_TC0_CCR0 |= TC_CCR_CLKEN;
		REG_TC0_CCR0 |= TC_CCR_SWTRG;
	}
	else if (channelNum == 2) {
		circBufFlush(circBufX,1);
		REG_PIOC_SODR |= PIO_PC9; // LEFT PUNCH RIGHT BOXER
		allowPunch = 0;
		counter = 0;
		REG_TC0_CCR0 |= TC_CCR_CLKEN;
		REG_TC0_CCR0 |= TC_CCR_SWTRG;
	}
	else if (channelNum == 3) {
		circBufFlush(circBufX,1);
		REG_PIOC_SODR |= PIO_PC9; // RIGHT PUNCH RIGHT BOXER
		allowPunch = 0;
		counter = 0;
		REG_TC0_CCR0 |= TC_CCR_CLKEN;
		REG_TC0_CCR0 |= TC_CCR_SWTRG;
	}	
	// 
}









#endif /* INCFILE2_H_ */