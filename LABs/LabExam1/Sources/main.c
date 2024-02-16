/********************************************************************/
// HC12 Program:  LabExam1
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Dominic Lastauskas
// Details:       first lab exam           
// Date:          2/16/2024
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
unsigned long LoopAmount = 0;
unsigned int WhoOn[] = {0, 0, 0, 0, 0, 0, 0}; // this would hold values that determin which switch is being pressed
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
    SWL_ON(SWL_YELLOW);
    SWL_ON(SWL_GREEN);
    SWL_ON(SWL_RED);
  for (;;)
  {
    
    // Part 1
      SWL_TOG(SWL_RED);
      for (LoopAmount = 0; LoopAmount<= 850; LoopAmount++); // found data values using calculations from previous ica and used that logic here
      SWL_TOG(SWL_RED);
      for (LoopAmount = 0; LoopAmount <= 2550; LoopAmount++);
    
    // Part 2
    // checks to see which switches ar pushed if pushed change that array value to 1 indicating pressed
      if(SWL_Pushed(SWL_LEFT) > 0){
        WhoOn[0] = 1;
       }
       else{
        WhoOn[0] = 0;
       }
    if(SWL_Pushed(SWL_CTR) > 0){
      WhoOn[1] = 1;
    }
    else{
        WhoOn[1] = 0;
       }
    if(SWL_Pushed(SWL_RIGHT) > 0){
      WhoOn[2] = 1;
    }
    else{
        WhoOn[2] = 0;
       }
    if(SWL_Pushed(SWL_DOWN) > 0){
      WhoOn[3] = 1;
    }
    else{
        WhoOn[3] = 0;
       }
    if(SWL_Pushed(SWL_UP) > 0){
      WhoOn[4] = 1;
    }
    else{
        WhoOn[4] = 0;
       }

      // checks to see that only 2 switches are being pressed if so turns on/off the leds according to the instructions
       if(WhoOn[0] + WhoOn[1] + WhoOn[2] + WhoOn[3] + WhoOn[4] ==2){
        SWL_ON(SWL_GREEN);
        SWL_OFF(SWL_YELLOW);
    }
    else{
      SWL_ON(SWL_YELLOW);
      SWL_OFF(SWL_GREEN);
    }
       
    }

    
    
  }
                   


/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

