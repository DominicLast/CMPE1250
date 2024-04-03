/********************************************************************/
// HC12 Program:  ICA09
// Processor:     MC9S12XDP512
// Bus Speed:     16 MHz
// Author:        Dominic Lastauskas
// Details:       second lab exam           
// Date:          4/3/2024
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "sw_led.h"
#include "clock.h"
#include "sci.h"
#include "misc.h"
#include "rti.h"

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned char c;
unsigned int long iterations;
unsigned int i;
unsigned char color;
unsigned char ReadData;
unsigned char * pData = &ReadData;
/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  //Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
  
/********************************************************************/
  // one-time initializations
/********************************************************************/
SWL_Init();
Clock_Set20MHZ();
sci0_Init(38400,20000000);
RTI_Init();
c = '.';
color='r';
sci0_txStr("\x1b[3;0H");
iterations = 0;
sci0_txStr("\x1b[0;0H");
sci0_txStr("\x1b[2K");

/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {
    i = iterations%80;
    // Preperation
   RTI_Delay_ms(10);
   //SWL_TOG(SWL_RED);
   // sci0_txByte ('D');          
    
   // part A
/*
iterations++;

  if (iterations%10 == 1){
    sci0_txByte (c);
    SWL_TOG(SWL_RED);
  }
  if(SWL_Pushed(SWL_UP)){
    c = '!';
  }
  if(SWL_Pushed(SWL_DOWN)){
    c = '?';
  }
  if(SWL_Pushed(SWL_CTR)){
    c = '.';
  }
*/
  // Part B
  
  
  iterations++;


  if (iterations%80 == 1){
    sci0_txStr("\x1b[3;0H");
  }
  //sci0_txByte (c);

  ReadData = sci0_rxByte(&ReadData);
  color = ReadData;
  if(color == 'r'){
    sci0_txStr("\x1b[31m.");
  }
  if(color == 'g'){
    sci0_txStr("\x1b[32m.");
  }
  if(color == 'b'){
    sci0_txStr("\x1b[34m.");
  }
  if(color='n'){
    sci0_txStr("\x1b[39m.");
  }
}

}

/********************************************************************/
// Functions
/********************************************************************/
int isVowel(char a){
  if(a=='A' ||a=='E' ||a=='I' ||a=='O' ||a=='U'){
    return 1;
  }
    return 0;
}
/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

