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

pos = 0;
count = 0;
pass = 0;
hex =0;
dec=0;
pushed = 0;
up=0;down=0;left=0;right=0;ctr=0;a=0;b=0;c=0;d=0;
Segs_Normal(0,a,Segs_DP_ON);
      Segs_Normal(1,b,Segs_DP_OFF);
      Segs_Normal(2,c,Segs_DP_OFF);
      Segs_Normal(3,d,Segs_DP_OFF);
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
     else if(SWL_Pushed(SWL_LEFT)){
      left=1;pushed=1;
     }
     else if(SWL_Pushed(SWL_RIGHT)){
      right=1;pushed=1;
     }

     if(pushed == 0){
        if(left == 1&& pos > 0){
          pos--;
          left = 0;
        }
        else if(right == 1 && pos < 3){
          pos++;
          right = 0;
        }
        switch (pos)
     {
     case 0: // edditing the a value leftmoast value
      if(up ==1){
          a++;
          if(a == 10){
            a = 0;
          }
          up = 0;
        }
        else if(down == 1){
          if(a == 0){
            a = 10;
          }
          a--;
          down = 0;
        }
      break;
     case 1: // edit the b value
     if(up ==1){
          b++;
          if(b == 10){
            b = 0;
          }
          up = 0;
        }
        else if(down == 1){
          if(b == 0){
            b = 10;
          }
          up = 0;
          b--;
          down = 0;
        }
      break;
     case 2: // edit the c value
     if(up ==1){
          c++;
          if(c == 10){
            c = 0;
          }
          up = 0;
        }
        else if(down == 1){
          if(c == 0){
            c = 10;
          }
          c--;
          down = 0;
        }
      break;
     case 3: // edit the d value
     if(up ==1){
          d++;
          if(d == 10){
            d = 0;
          }
          up = 0;
        }
        else if(down == 1){
          if(d == 0){
            d = 10;
          }
          d--;
          down = 0;
        }
      break;
     default:
      break;
     }
     }
      pushed = 0;
     // a method might be needed to put the decimal point on the digit
     switch (pos)
     {
     case 0:
      Segs_Normal(0,a,Segs_DP_ON);
      Segs_Normal(1,b,Segs_DP_OFF);
      Segs_Normal(2,c,Segs_DP_OFF);
      Segs_Normal(3,d,Segs_DP_OFF);
      break;
     case 1:
      Segs_Normal(0,a,Segs_DP_OFF);
      Segs_Normal(1,b,Segs_DP_ON);
      Segs_Normal(2,c,Segs_DP_OFF);
      Segs_Normal(3,d,Segs_DP_OFF);
      break;
      case 2:
      Segs_Normal(0,a,Segs_DP_OFF);
      Segs_Normal(1,b,Segs_DP_OFF);
      Segs_Normal(2,c,Segs_DP_ON);
      Segs_Normal(3,d,Segs_DP_OFF);
      break;
      case 3:
      Segs_Normal(0,a,Segs_DP_OFF);
      Segs_Normal(1,b,Segs_DP_OFF);
      Segs_Normal(2,c,Segs_DP_OFF);
      Segs_Normal(3,d,Segs_DP_ON);
      break;
     default:
      break;
     }
     
     dec = ((a*1000)+(b*100)+(c*10)+d);
    Segs_16H(dec,Segs_LineBottom);
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

