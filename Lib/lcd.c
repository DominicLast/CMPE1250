#include <hidef.h>
#include "derivative.h"
#include "lcd.h"
#include "rti.h"

void LCD_Init(void){
    PTH = 0x00;
    DDRH = 0xFF;

    PORTK&=0b11111000;

    DDRK |= 0b00111000;

    RTI_Delay_ms(45);

    PTH = 0b00111000;

    

}

char lcd_Busy(void){
    char busyState;

    DDRH = 0x00;
    PORTK_PK1 = 1;
    PORTK_PK2 = 0;

    busyState=PTH&0b10000000;

    DDRH = 0b11111111;

    return busyState;
}

void LCD_Ctrl(unsigned char cCommand){
    while(lcd_Busy() !=0)
    {
        PTH=cCommand;
    }

    PORTK|=0b00000001;
    PORTK&=0b11111000;
}