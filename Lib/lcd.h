/////////////////////////////////////////////////////////////////////////////
// Processor:     MC9S12XDP512
// Bus Speed:     20 MHz (Requires Active PLL)
// Author:        Simon Walker
// Details:       LCD Library
// Revision History :
// Created : Unknown
//  Dec 07 2020 - Modified Documentation
//  Dec    2020 - Modified names, modified to use timer for delays
//  Nov 2021, Added PIT Timer for delays, by Carlos
/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////
// 8-Bit interface init on LCD
// LCD is wired to PTH for data, PK0:2 for control :
// 2     1     0     PTK 
// A     R/W*  E     LCD 
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// LCD Address Scheme (HEX):
// 00 01 ... 12 13
// 40 41 ... 52 53
// 14 15 ... 26 27
// 54 55 ... 66 67
////////////////////////////////////////////////////
#define LCD_WIDTH 20
#define LCD_ROW0 0
#define LCD_ROW1 64
#define LCD_ROW2 20
#define LCD_ROW3 84

#define null 0

#define SHIFT_CUR 0
#define SHIFT_SCR (1<<3)

// macros only apply to library, not for public consumption
// gotta be inputs, set R/W* high
#define lcd_RWUp DDRH = 0; PORTK |= 2;
// set R/W* low, // gotta be outputs
#define lcd_RWDown PORTK &= (~2); DDRH = 0xFF;
// this is *snug*, datasheet says PW_EH must be at least 450ns. (P49 + P58)
// but &= probably implemented as a BCLR instruction (@ 50ns bus, 4 cycles, around 200ns per instruction)
// measured on scope at ~300ns (which would make sense (6 cycles up/down instructions),
// not exactly sure when pin changes state in instruction pair)
// this is actually too short, but appears to work. Either the device is better than expected, or does
//not match datasheet!
// other LCDs may require a small delay be added to E strobe operations, or data setup time during read.
#define lcd_EUp PORTK |= 1;
#define lcd_EDown PORTK &= (~1);
#define lcd_RSUp PORTK |= 4;
#define lcd_RSDown PORTK &= (~4);

#define lcd_MicroDelay { char __x = 10; while (--__x); } // 20MHz Version
#define lcd_Latch {PORTK_PK0 = 1;lcd_MicroDelay;PORTK_PK0 = 0;}

/////////////////////////////////////////////////////////////////////////////
// Library Prototypes
/////////////////////////////////////////////////////////////////////////////

void lcd_Init (void);
void lcd_Inst (unsigned char); //LCD_Inst
void lcd_Busy (void); //LCD_Inst
char lcd_GetAddr(void);
void lcd_Data (unsigned char val);
void lcd_Addr (unsigned char row);
void lcd_AddrXY (unsigned char ix, unsigned char iy);
void lcd_String (char const * straddr);
void lcdSmartString(char const * straddr, unsigned int delay);
void lcd_StringXY (unsigned char ix, unsigned char iy, char const * const straddr);

void lcd_DispControl (unsigned char curon, unsigned char blinkon);
void lcd_Clear (void);
void lcd_Home (void);
void lcd_ShiftL (char);
void lcd_ShiftR (char);
void lcd_CGAddr (unsigned char addr);
void lcd_CGChar (unsigned char cgAddr, unsigned const char* cgData, int size);