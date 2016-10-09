
#if defined(__XC)
    #include <xc.h>         
#elif defined(HI_TECH_C)
    #include <htc.h>        
#endif

#include <stdint.h>         
#include <stdbool.h>        

#include "user.h"


void InitApp(void)
{   
    /**
     * Turn off comparator.
     */
    CMCONbits.CM0 = 1;
    CMCONbits.CM1 = 1;
    CMCONbits.CM2 = 1;
    /**
     * Setting bit 0 as low as output.
     */
    TRISIObits.TRISIO0 = 0;
    /**
     * Setting bit 5 high as input.
     */
    TRISIObits.TRISIO5 = 1;
    /**
     * Enable interrupt on GPIO pin change.
     */
    INTCONbits.GPIE = 1;
    /**
     * The global interrupt is set high. 
     */
    INTCONbits.GIE = 1;
    /**
     * Interrupt on input GP5.
     */
    IOCBbits.IOC5 = 1;
}

