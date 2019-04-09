#ifndef _CLK_H_
#define _CLK_H_

void clock_init(){
	//enable external crystal
	REG_CKGR_MOR |= CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCXTEN;
	//wait for crystal to become ready
	while (!(REG_PMC_SR & PMC_SR_MOSCXTS));
	//select crystal for main clock
	REG_CKGR_MOR |= CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCSEL;
	//master clock source selection - choose main clock
	REG_PMC_MCKR |= PMC_MCKR_CSS_MAIN_CLK;
	//wait until main clock ready
	while (!(REG_PMC_SR & PMC_SR_MCKRDY));
	//select processor prescaler (0 - no divisor)
	REG_PMC_MCKR |= PMC_MCKR_PRES_CLK_1;
	//wait until main clock ready
	while (!(REG_PMC_SR & PMC_SR_MCKRDY));
	//12MHz / 1 = 12MHz, 12MHz * (5+1) = 60MHz
	REG_CKGR_PLLBR |= CKGR_PLLBR_MULB(5);
	REG_CKGR_PLLBR |= CKGR_PLLBR_DIVB(1);
	//select PLLB as the master clock
	//master clock source selection - choose main clock
	REG_PMC_MCKR |= PMC_MCKR_CSS_PLLB_CLK;
	//wait until main clock ready

	while (!(REG_PMC_SR & PMC_SR_MCKRDY));
}

#endif