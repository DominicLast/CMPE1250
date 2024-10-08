#include <hidef.h>
#include "derivative.h"
#include "lcd.h"
#include "rti.h"



//void LCD_Ctrl(unsigned char cCommand){
  //  while(lcd_Busy() != 0);
    //PTH=cCommand;

    //PORTK|=0b00000001;
    //PORTK&=0b11111000;
//}

//void Lcd_String(char * cString){
  //  while(*cString!=0)
    //    Lcd_Char(*cString++);

//}

/*

void Lcd_Init(void){
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

void Lcd_inst(unsigned char cCommand){
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
*/

void lcd_Busy (void){
    unsigned char inVal = 0;
    lcd_RSDown // instruction
    lcd_RWUp // reading

    do
    {
        lcd_EUp
        lcd_MicroDelay


        inVal = PTH;
        lcd_EDown
    } while (inVal & 0x80);
    
}

// send a byte to the inst reg of LCD on custom port
void lcd_Inst (unsigned char val){
    lcd_Busy();

    lcd_RWDown
    lcd_RSDown

    PTH = val;

    lcd_EUp
    lcd_EDown

}

void lcd_Init (void){
    PTH=0x38;
    lcd_EDown
    lcd_RWDown
    lcd_RSDown
    DDRK|=0b00000111;
    RTI_Delay_ms(100);
    lcd_EUp
    lcd_EDown
    RTI_Delay_ms(15);
    lcd_EUp
    lcd_EDown
    RTI_Delay_ms(1);
    lcd_Inst(0x38);
    lcd_Inst(0x0C);
    lcd_Inst(0x01);
    lcd_Inst(0x06);


}

void lcd_Data (unsigned char val){
    lcd_Busy();

    lcd_RWDown
    lcd_RSUp

    PTH = val;

    lcd_EUp
    lcd_EDown

}

void lcd_Clear (void){

    lcd_Inst(0x38);
    lcd_Inst(0x0C);
    lcd_Inst(0x01);
    lcd_Inst(0x06);

}

void lcd_Addr (unsigned char row){
    unsigned char address;

    // Calculate the address based on row and column
    if (row == 0) {
        address = 0x00; // First row
    } else if (row == 1) {
        address = 0x40 ; // Second row
    } else if (row == 2) {
        address = 0x14; // Third row (if applicable)
    } else if (row == 3) {
        address = 0x54; // Fourth row (if applicable)
    } else {
        return; // Invalid row
    }

    // Send the command to set the cursor position
    lcd_Inst(0x80 | address); // Set DDRAM address
}

void lcd_AddrXY (unsigned char ix, unsigned char iy){
    unsigned char address;

    // Calculate the address based on row and column
    if (ix == 0) {
        address = 0x00 + iy; // First row
    } else if (ix == 1) {
        address = 0x40 + iy; // Second row
    } else if (ix == 2) {
        address = 0x14 + iy; // Third row (if applicable)
    } else if (ix == 3) {
        address = 0x54 + iy; // Fourth row (if applicable)
    } else {
        return; // Invalid row
    }

    // Send the command to set the cursor position
    lcd_Inst(0x80 | address); // Set DDRAM address
}


void lcd_StringXY (unsigned char ix, unsigned char iy, char const * const straddr){
    lcd_AddrXY(ix,iy);
    lcd_String(straddr);
}

void lcd_String (char const * straddr){
    for (; *straddr; ++straddr){
 lcd_Data(*straddr);}
}