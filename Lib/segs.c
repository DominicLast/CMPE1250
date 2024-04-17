#include <hidef.h>
#include "derivative.h"
#include <stdio.h> 
#include <stdlib.h>
#include "segs.h"

#define Segs_WLATCH PORTA &= (~0x01); PORTA |= 0x01;
#define Segs_ML PORTA &= (~0x02);
#define Segs_MH PORTA |= 0x02;

// setup ports to speak with 7-segs
void Segs_Init(void){
    PORTA |= 0x03;
    DDRA |= 0x03;
    DDRB = 0xff;

    Segs_Custom(0,0b10000000);
    Segs_Custom(1,0b10000000);
    Segs_Custom(2,0b10000000);
    Segs_Custom(3,0b10000000);
    Segs_Custom(4,0b10000000);
    Segs_Custom(5,0b10000000);
    Segs_Custom(6,0b10000000);
    Segs_Custom(7,0b10000000);
}
unsigned int HexToBCD(  unsigned int Hex){
    unsigned char i;
    unsigned int result = 0, pow = 1;

    for(i=0;i<4;i++){
        result += (Hex % 10) * pow;
        Hex /= 10;
        pow *= 16;
    }
    return result;
}
// show HEX decoding (changes all of display to HEX, w/wo dp)
/* Params: (address, data, dp) */
void Segs_Normal(unsigned char a, unsigned char d, Segs_DPOption dp){
    a &= 0x07;

    a |= 0b01011000;

    if(dp)
    d &= (~0x80);
    else 
    d |= 0x80;

    PORTB = a;
    Segs_MH
    Segs_WLATCH

    PORTB = d;
    Segs_ML

    Segs_WLATCH
}

// control segs manually
/* Params: (address, data) */
void Segs_Custom(unsigned char a, unsigned char d){
    a &= 0x07;

    a |= 0b01111000;

    PORTB = a;
    Segs_MH
    Segs_WLATCH

    PORTB = d;
    Segs_ML

    Segs_WLATCH
}

// show a decimal value on the first or second line of the 7-segs
/* Params: (value, line) */
void Segs_16H (unsigned int value, Segs_LineOption line){
    unsigned char i, offset;
    unsigned int cDisplay;

    if(line == Segs_LineTop){
        offset = 0;
    }
    else if (line == Segs_LineBottom){
        offset = 4;
    }

    for(i = 0; i< 4; i++){
        cDisplay = (value >> (unsigned char)((3-i) * 4)) & 0xf;
        Segs_Normal(offset +i, (unsigned char)cDisplay, Segs_DP_OFF);
        
    }
}

void Segs_16D (unsigned int value, Segs_LineOption line){
    Segs_16H(HexToBCD(value),line);
}



// show the 8-bit value starting on the digit as addr (0-6)
/* Params: (addr, value) */
void Segs_8H (unsigned char addr, unsigned char value){

    unsigned char hChar,lChar;

    addr &= 0x7;
    hChar = value>>4;
    lChar = value & 0x0F;

    Segs_Normal(addr, hChar,Segs_DP_OFF);
    if (addr < 7){
            Segs_Normal(addr+1, lChar,Segs_DP_OFF);
        }
    else{
            Segs_Normal(0, lChar,Segs_DP_OFF);
        }
}