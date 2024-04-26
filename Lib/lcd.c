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

    PORTK|=0b00000001;
    PORTK&=0b11111000;

    lcd_MicroDelay

    PORTK|=0b00000001;
    PORTK&=0b11111000;

    lcd_MicroDelay

    PORTK|=0b00000001;
    PORTK&=0b11111000;

    lcd_MicroDelay

    LCD_Ctrl(0b00111000);
    LCD_Ctrl(0b00001110);
    LCD_Ctrl(0b00000001);
    LCD_Ctrl(0b00000110);

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

void LCD_inst(unsigned char cCommand){
    while(lcd_Busy() !=0);
    
        PTH=cCommand;
    

    PORTK|=0b00000001;
    PORTK&=0b11111000;

    lcd_Latch;
}

void lcd_Data(unsigned char data){
    while (lcd_Busy());
    PTH = data;
    PORTK &= ~PORTK_PK1_MASK;
    PORTK |= PORTK_PK2_MASK;

    // latch data

    PORTK |= PORTK_PK0_MASK;
    RTI_Delay_ms(5);
    PORTK &= ~PORTK_PK0_MASK;
}