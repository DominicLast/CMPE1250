#include <hidef.h>
#include "derivative.h"
#include "sci.h"
#include <stdio.h> 
#include <stdlib.h>

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
    while (!SCI0SR1_TDRE /*&& SWL_Transition (SWL_CTR)*/);
   SCI0DRL = data;
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

int sci0_Peek (void){
    if(SCI0SR1 & SCI0SR1_RDRF_MASK){
        return 1;
    }
    else{
        return 0;
    }
}

// I can now use sprint f to concat strings together and now that i can do that i think i can do anything that is required of me for this section of the exam
void sci0_GotoXY (int iCol, int iRow){
    char string[8] = "\x1b[2;0H";
    //string[0] = ('\\');
    //string[1] = ('x');
    //string[2] = ('1');
    //string[3] = ('b');
    //string[4] = ('[');
    string[5] = ((char)iCol);
    //string[6] = (';');
    string[7] = ((char)iRow);
    //string[8] = ('H');
    sci0_txStr(string);
}