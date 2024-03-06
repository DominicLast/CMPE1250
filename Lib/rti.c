#include <hidef.h>
#include "derivative.h"
#include "rti.h"

void RTI_Delay_ms(unsigned int ms){
    unsigned int i;
    i = 0;

    CRGFLG = CRGFLG_RTIF_MASK; //clear flag, VERY IMPORTANT

    
    for( i < ms * 100; i++;){
    
    RTICTL = 0b10010111;
        if (CRGFLG_RTIF) // RTI period over?
        {
            CRGFLG = CRGFLG_RTIF_MASK; //clear flag, VERY IMPORTANT
        }
    }
}

void RTI_Init(void){
    CRGINT |= CRGINT_RTIE_MASK; //0b10000000, Enable RTI
}