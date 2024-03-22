/********************************************************************/
// HC12 Program:  ICA09
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Dominic Lastauskas
// Details:       first lab exam           
// Date:          3/22/2024
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
unsigned int i;
char str[];
/********************************************************************/
// Local Prototypes
/********************************************************************/
int isVowel(char);
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
//sci0_Init(19200,20000000); // THIS IS THE PROBLEM
//sci0_Init9600();
SCI0BD = 65; // sets the rate

    SCI0CR2_TE = 1;
    SCI0CR2_RE = 1;
/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {
    
    RTI_Delay_ms(250);

  for(i = 0; i < 20; i++){
    data = GetRandom (0, 26);
  if(SWL_Pushed(SWL_CTR)){
    data = data + 'A';
  }
  else{
    data = data + 'a';
  }
  }
  
  
    // if the transmitter buffer is empty, load a new byte to send (TX)
    sci0_txStr("Hello World!! ");
 //sci0_txByte('A');
  SWL_TOG(SWL_RED);
 // if a byte has been received, pull it!
 //ReadData = sci0_rxByte(&ReadData);
  
//if(isVowel(ReadData)){
 // SWL_ON(SWL_GREEN);
 // SWL_OFF(SWL_YELLOW);
//}
//else{
 // SWL_ON(SWL_YELLOW);
 // SWL_OFF(SWL_GREEN);
//}

                   

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

