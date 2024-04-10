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
sci0_txStr("Dominic Lastauskas");
sci0_txStr("\x1b[2;0H");
sci0_txStr("Simple Binary Calculator");
sci0_GotoXY(4,4);
/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {
    if(sci0_Peek() > 0){
      RTI_Delay_ms(200);
      SWL_TOG(SWL_RED);
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

