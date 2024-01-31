/********************************************************************/
// HC12 Program:  ICA02 - transfering C# code to C 
// Processor:     MC9S12XDP512
// Bus Speed:     12 MHz
// Author:        Dominic Lastauskas
// Details:       the program will alternate the red and green led to blink in an alternating pattern           
// Date:          1/17/2024
// Revision History :
//  1/17/2024 - started the transitioning between C# and C
//  1/19/2024 - finishin the comments on the program



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/
# define RED_LED 0b10000000
/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned int LoopAmount = 0;
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
PT1AD1 &= 0x1F;
DDR1AD1 = 0xE0; 

/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    PT1AD1 ^= RED_LED;
    for (LoopAmount = 0; LoopAmount <= 1000; LoopAmount++);
    
    

  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
