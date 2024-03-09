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
#include "rti.h"
#include "clock.h"

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
RTI_Init();
/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {
    if(SWL_Pushed(SWL_RIGHT)){
      SWL_ON(SWL_GREEN);
      SWL_OFF(SWL_RED);
    }
    else{
      SWL_OFF(SWL_GREEN);
      if(SWL_Pushed(SWL_LEFT)){
      SWL_ON(SWL_RED);
      RTI_Delay_ms(1);
      SWL_OFF(SWL_RED);
      RTI_Delay_ms(9);
      
    }
    else{
      if(SWL_Pushed(SWL_DOWN) && SWL_Pushed(SWL_UP)){
      RTI_Delay_ms(10);
      SWL_TOG(SWL_RED);
    }
    else{
      if(SWL_Pushed(SWL_UP)){
      RTI_Delay_ms(8);
      SWL_TOG(SWL_RED);
    }
    if(SWL_Pushed(SWL_DOWN)){
      RTI_Delay_ms(12);
      SWL_TOG(SWL_RED);
    }
    
    
    if(!SWL_Pushed(SWL_ANY)){
      RTI_Delay_ms(10);
      SWL_TOG(SWL_RED);
    }
    }
      
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

