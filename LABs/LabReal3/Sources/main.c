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
//#define tier2

/********************************************************************/
// Local Prototypes
/********************************************************************/
void carrot(unsigned char);
/********************************************************************/
// Global Variables
/********************************************************************/
unsigned int count,pos,del,pass,hex,dec,pushed,up,down,left,right,ctr,a,b,c,d;
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

// tier 1
/*
Segs_Normal(4,'3',Segs_DP_OFF);
Segs_8H(0,0x40);
Segs_8H(6,0x0E);
Segs_Custom(1,0b01001010);
Segs_Custom(2,0b11110000);
Segs_Custom(5,0b10001011);
Segs_Custom(6,0b10110001);
*/

pos = 4;
count = 0;
pass = 0;
hex =0;
dec=0;
pushed = 0;
up=0;down=0;left=0;right=0;ctr=0;a=0;b=0;c=0;d=0;
/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {
     RTI_Delay_ms(50);
     //SWL_TOG(SWL_RED);
     

     if(SWL_Pushed(SWL_UP)){
      up=1;pushed=1;
     }
     else if(SWL_Pushed(SWL_DOWN)){
      down=1;pushed=1;
     }
     else if(SWL_Pushed(SWL_CTR)){
      ctr=1;pushed=1;
     }
     else if(SWL_Pushed(SWL_LEFT)){
      left=1;pushed=1;
     }
     else if(SWL_Pushed(SWL_RIGHT)){
      right=1;pushed=1;
     }
     

}
}

/********************************************************************/
// Functions
/********************************************************************/
void carrot(unsigned char loc){
  unsigned int i,c;
    
  unsigned char pos[] = {0b11000000, 0b10100000, 0b10010000 ,0b10000001, 0b10001000, 0b10000010};
  c = 0;
  //while(c < 1){
    for(i = 0; i < 6; i++){
      
      Segs_Custom(loc,pos[i]);
      RTI_Delay_ms(100);
      
    }
   // c++;
  //}
  

}
/********************************************************************/
// Interrupt Service Routines
/********************************************************************/

