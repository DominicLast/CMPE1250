#include <hidef.h>
#include "derivative.h"
#include "clock.h"

// implementation file for the clock

void Clock_Set20MHZ(void)
{

 SYNR = 4;
 REFDV = 3;
 PLLCTL = PLLCTL_PLLON_MASK | PLLCTL_AUTO_MASK;//PLL ON and AUTO
 while(!(CRGFLG & CRGFLG_LOCK_MASK));//Wait for PLL to lock
 CLKSEL |= 0b10000000;// Select PLL as clock source


}

void Clock_Set24MHZ(void){
    SYNR = 5; //0x5, set multiplier to: 5+1 = 6
    REFDV = 3; //0x3, set divider to: 3+1 = 4
    PLLCTL = PLLCTL_PLLON_MASK | PLLCTL_AUTO_MASK;//PLL ON and AUTO
    while(!(CRGFLG & CRGFLG_LOCK_MASK));//Wait for PLL to lock
    CLKSEL |= 0b10000000;// Select PLL as clock source

}

void Clock_Set8MHZ(void){

    CLKSEL |= 0b00000000;// Select CLK as clock source
    // this should reset it to 8MHZ
}

unsigned long Clock_GetBusSpeed(void){
    if (CLKSEL > 0){
        return(((SYNR + 1) / (REFDV + 1)) * 2 * 16);
    }
    else{
        return 8;
    }
}

void Clock_EnableOutput(void){
    ECLKCTL &= ~ECLKCTL_NECLK_MASK; //Activate clock output
}


