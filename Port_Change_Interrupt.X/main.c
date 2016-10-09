/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#define _XTAL_FREQ 4000000L

#if defined(__XC)
#include <xc.h>         
#elif defined(HI_TECH_C)
#include <htc.h>       
#endif

#include <stdint.h>       
#include <stdbool.h>       

#include "system.h"        
#include "user.h"          

/**
 * Main method.
 */
void main(void) {
    /**
     * Configure oscillator
     */
    ConfigureOscillator();
    /**
     * Init application config.
     */
    InitApp();
    /**
     * Continous loop.
     */
    while (true);
}

/**
 * Interrupt method.
 */
void interrupt isr(void) {
    /**
     *  Check that interrupt was caused by pin change.
     */
    if (INTCONbits.GPIF) {
        /**
         * Set output high.
         */
        GPIObits.GP0 = 1;
        /**
         * Wait two seconds.
         */
        __delay_ms(2000);
        /**
         * Rest interrupt.
         */
        INTCONbits.GPIF = 0;
        /**
         * Set output low.
         */
        GPIObits.GP0 = 0;
    }
}