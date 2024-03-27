#include <hidef.h>
#include "derivative.h"
#include "sci.h"

void sci0_Init9600 (void){
    SCI0BD = 130; // sets the rate

    SCI0CR2_TE = 1;
    SCI0CR2_RE = 1;
}

unsigned char sci0_rxByte(unsigned char * pData){ //reads
    if(SCI0SR1 & SCI0SR1_RDRF_MASK) //Check if a character has been received
    {
    *pData = SCI0DRL;
    }
    return *pData;
}

void sci0_txByte (unsigned char data){ // sends
    if (SCI0SR1_TDRE /*&& SWL_Transition (SWL_CTR)*/)
 {
   SCI0DRL = data;
 }
}

void sci0_txStr (char const * straddr)
{
for (; *straddr; ++straddr){
sci0_txByte (*straddr);
}

}

void sci0_Init(unsigned long ulBaudRate, unsigned long ulBusClock){
    SCI0BD = (int)(ulBusClock / (ulBaudRate*16.0));

    SCI0CR2_TE = 1;
    SCI0CR2_RE = 1;
}