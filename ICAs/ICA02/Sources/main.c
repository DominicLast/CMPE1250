/********************************************************************/
// HC12 Program:  YourProg - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        This B. You
// Details:       A more detailed explanation of the program is entered here               
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes



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
static unsigned short uiMainLoopCount = 0;
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
    ++uiMainLoopCount;
    RED(uiMainLoopCount);
    GREEN(uiMainLoopCount);

  }                   
}

/********************************************************************/
// Functions
/********************************************************************/
static void RED (bOn)
        {
            if (bOn < 0x1000)
                PT1AD1 |= (byte)(((unsigned int)1 << (7)));
            else
            {
                PT1AD1 &= 0x7F;
            }

        }

        static void GREEN(bOn)
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
