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

/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
static unsigned short uiMainLoopCount; // will be incremented to determine which led should be on creating the alternating pattern
void RED(int);
void GREEN(int);
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
uiMainLoopCount = 0;
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    ++uiMainLoopCount; // increments the count of the loop
    RED(uiMainLoopCount); // runs the function to determine if the red led should be on
    GREEN(uiMainLoopCount); // runs the function to determine if the green led should be on

  }                   
}

/********************************************************************/
// Functions
/********************************************************************/
void RED (int bOn)
        {
            if (bOn < 0x1000)
                PT1AD1 |= (byte)(((unsigned int)1 << (7)));
            else
            {
                PT1AD1 &= 0x7F;
            }

        }

void GREEN(int bOn)
        {
            if (bOn >= 0x1000)
            {
                PT1AD1 |= 0x20;
            }
            else
            {
                PT1AD1 &= 0b11011111;
            }
                            
        }
/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
