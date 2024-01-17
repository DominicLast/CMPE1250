/********************************************************************/
// HC12 Program:  ICA01 - documentation of code
// Processor:     MC9S12XDP512
// Bus Speed:     16 MHz
// Author:        Dominic Lastauskas
// Details:       this program will make the red led on the board light on and off         
// Date:          1/12/2024
// Revision History :
//  1/12/2024: started this ICA



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
#define RED_LED 0b10000000 // sets the color of the led to red/ sets the varable so that it is assigned to the red led on the board
#define INDEX_MAX 10 // sets the maximum value for the intex to 10
/********************************************************************/
// Local Prototypes
/********************************************************************/

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned int counter, index; // creates the ingerer variables for counter and index
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
PT1AD1 |= RED_LED; // // assigned to the red led
DDR1AD1 |= RED_LED; // used to switch the red led on and off
counter = 0; // assigns counter with the value of 0 counter is used as a clock which is what activates the loop that determins if the led should activate or turn off
index = 0; // assigns index with a value of 0 index is the value that is used to determin whether the led should switch on or off


/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {
    if(++counter == 0) // acts as the clock for the program
{
if(++index >= INDEX_MAX)
{
index = 0;
PT1AD1 ^= RED_LED;
}
}
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
