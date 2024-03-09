#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "sw_led.h"
void main(void)
{
// main entry point
_DISABLE_COP();
SWL_Init();
RTICTL = 0b10010111;
for (;;)
{
    int i=0;
    while(i<10){
        i++;
    }
if (CRGFLG_RTIF) // RTI period over?
{
CRGFLG = CRGFLG_RTIF_MASK; //clear flag, VERY IMPORTANT
SWL_TOG (SWL_RED);
}
}
}