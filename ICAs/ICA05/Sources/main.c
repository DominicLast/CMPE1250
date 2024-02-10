/********************************************************************/
// HC12 Program:  YourProg - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Dominic Lastauskas
// Details:       A more detailed explanation of the program is entered here               
// Date:          2/9/2024
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "sw_led.h"

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
unsigned int WhoOn[] = {0, 0, 0};
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
/********************************************************************/
  // main program loop
/********************************************************************/

  for (;;)
  {

    /* 
    // Part 1
    if(SWL_Pushed(SWL_LEFT) > 0){
      SWL_ON(SWL_RED);
    }
    else{
      SWL_OFF(SWL_RED);
    }
    if(SWL_Pushed(SWL_CTR) > 0){
      SWL_ON(SWL_YELLOW);
    }
    else{
      SWL_OFF(SWL_YELLOW);
    }
    if(SWL_Pushed(SWL_RIGHT) > 0){
      SWL_ON(SWL_GREEN);
    }
    else{
      SWL_OFF(SWL_GREEN);
    }  
    */

   /* 
   // Part 2
   if(SWL_Pushed(SWL_LEFT) > 0){
      SWL_ON(SWL_RED);
    }
    if(SWL_Pushed(SWL_CTR) > 0){
      SWL_ON(SWL_YELLOW);
    }
    if(SWL_Pushed(SWL_RIGHT) > 0){
      SWL_ON(SWL_GREEN);
    }
    if((SWL_Pushed(SWL_DOWN) > 0) || (SWL_Pushed(SWL_UP) > 0)){
      SWL_OFF(SWL_ALL);
    }
    */
    

    // Part 3
    if((SWL_Pushed(SWL_LEFT) > 0) && (WhoOn[0] + WhoOn[1] + WhoOn[2]) < 2){
      SWL_TOG(SWL_RED);
      WhoOn[0] ^= 1;
    }
    if((SWL_Pushed(SWL_CTR) > 0) && (WhoOn[0] + WhoOn[1] + WhoOn[2]) < 2){
      SWL_TOG(SWL_YELLOW);
      WhoOn[1] ^= 1;
    }
    if((SWL_Pushed(SWL_RIGHT) > 0) && (WhoOn[0] + WhoOn[1] + WhoOn[2]) < 2){
      SWL_TOG(SWL_GREEN);
      WhoOn[2] ^= 1;
    }
    if((SWL_Pushed(SWL_DOWN) > 0) || (SWL_Pushed(SWL_UP) > 0)){
      SWL_OFF(SWL_ALL);
      WhoOn[0] = 0;
      WhoOn[1] = 0;
      WhoOn[2] = 0;
    }
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

