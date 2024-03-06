#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "SW_led.h"
#include "clock.h"
#include "rti.h"




void main(void)
{
// main entry point
_DISABLE_COP();
EnableInterrupts;
SWL_Init();
RTI_Init();
for (;;)
{
    RTI_Delay_ms(10);
    SWL_TOG(SWL_RED);
}

}