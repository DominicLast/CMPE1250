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
#include "segs.h"
#include "rti.h"

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/
unsigned int up,down,max;
/********************************************************************/
// Local Prototypes
/********************************************************************/
void carrot(unsigned char);
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
Segs_Init();
Segs_Normal(4,'3',Segs_DP_OFF);
Segs_8H(0,0x40);
Segs_8H(6,0x0E);
Segs_Custom(1,0b01001010);
Segs_Custom(2,0b11110000);
Segs_Custom(5,0b10001011);
Segs_Custom(6,0b10110001);
up = 0;
max = 0xFFFF;
down = max;
/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {
    /* // tier 1
    if(SWL_Pushed(SWL_CTR)){
      Segs_16H(up,Segs_LineTop);
      Segs_16H(down,Segs_LineBottom);
      up++;
      down = max - up;
      RTI_Delay_ms(100);
    }
    */
    
    // tier 2
  carrot(0);

}
}

/********************************************************************/
// Functions
/********************************************************************/
void carrot(unsigned char loc){
  unsigned int i;
  
  unsigned char pos[] = {0b11000000, 0b10100000, 0b10010000 ,0b10000001, 0b10001000, 0b10000010};
  while(1 > 0){
    for(i = 0; i < 6; i++){
      Segs_Custom(loc,pos[i]);
      RTI_Delay_ms(100);
    }
  
  }
  

}
/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

