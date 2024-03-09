#include <hidef.h>
#include "derivative.h"
#include "rti.h"

void RTI_Delay_ms(unsigned int ms){
    unsigned int i;
    RTICTL = 0;
    if((CRGFLG_RTIF)){
        CRGFLG = CRGFLG_RTIF_MASK;
    }
    RTICTL = 0b10010111;
        
    for(i = 0; i<ms;i++){
        while(!CRGFLG_RTIF);
        CRGFLG = CRGFLG_RTIF_MASK;
    }
    
    
    RTICTL = 0;
}

void RTI_Init(void){
    CRGINT |= CRGINT_RTIE_MASK; //0b10000000, Enable RTI
}