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
unsigned int count,pos,del,pass,hex,dec,pushed,up,down,left,right,ctr,a,b,c,d,random;
unsigned char data;
unsigned char ReadData, OldData;
unsigned char * pData = &ReadData;
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
//sci0_Init9600(); // used for question D
sci0_Init(38400, 20000000); // used for Question A
// sci0_Init(19200, 20000000); // Used for Question C
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
sci0_txStr("Lastauskas");
/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {
    /* Question D
    random = GetRandom(0,9999);
    RTI_Delay_ms(100);
    Segs_16D(random,Segs_LineTop);
    while(count < 4){
    ReadData = sci0_rxByte(&ReadData);
    if(ReadData != OldData){
      OldData = ReadData;
      sci0_txByte (ReadData);
      Segs_Normal(4+count,ReadData,Segs_DP_OFF);
      
      if(count == 0){
        a = (int)ReadData;
      }
      if(count == 1){
        b = (int)ReadData;
      }
      if(count == 2){
        c = (int)(ReadData);
      }
      if(count == 3){
        d = (int)ReadData;
      }
      count++;
    }
    }
    //((a*1000)+(b*100)+(c*10)+d) == random
    //((int)(a*1000)+(int)(b*100)+(int)(c*10)+(int)d) == (random)
    if (((a*1000)+(b*100)+(c*10)+d) == random){
      SWL_ON(SWL_GREEN);
    }
    else{
      SWL_ON(SWL_RED);
    }
    count = 0;
    RTI_Delay_ms(2000);
    SWL_OFF(SWL_GREEN);
    SWL_OFF(SWL_RED);
    Segs_ClearLine(Segs_LineBottom);
    */

   //Question A
   RTI_Delay_ms(100);
   pass++;
      pass = 0;
     dec++;
     if(dec > 9999)
     {
        dec = 0;
      }
    Segs_16D(dec,Segs_LineTop);

    // Question C
    /*
    ReadData = sci0_rxByte(&ReadData);
    if(ReadData != OldData){
      OldData = ReadData;
      sci0_txByte (ReadData);
      count++;
    }
    Segs_16D(count,Segs_LineTop);
    */
    
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

