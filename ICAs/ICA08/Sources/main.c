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
#include "sci.h"
#include "misc.h"
#include "rti.h"

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/
unsigned char data;
unsigned char ReadData;
unsigned char * pData = &ReadData;
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
sci0_Init9600();
/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {
    RTI_Delay_ms(50);
  data = GetRandom (0, 26) + 'A';
    // if the transmitter buffer is empty, load a new byte to send (TX)
 sci0_txByte (data);
  SWL_TOG(SWL_RED);
 // if a byte has been received, pull it!
 ReadData = sci0_rxByte(&ReadData);
  
if(ReadData=='A' ||ReadData=='E' ||ReadData=='I' ||ReadData=='O' ||ReadData=='U'){
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

