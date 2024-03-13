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
#include "clock.h"

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/
unsigned char data;
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
Clock_Set20MHZ();
SCI0BD = 130; // sets the rate

    SCI0CR2_TE = 1;
    SCI0CR2_RE = 1; // turn on TX/RX // 11.3.2.6
/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {
    

    // if the transmitter buffer is empty, load a new byte to send (TX)
 if (SCI0SR1_TDRE /*&& SWL_Transition (SWL_CTR)*/)
 {
   SCI0DRL = 'A';
 }

 // if a byte has been received, pull it!
 if (SCI0SR1_RDRF){
  SWL_ON(SWL_RED);
 }
  


                   

}
}
/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

