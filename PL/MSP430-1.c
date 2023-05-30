#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1OUT = BIT0;
    P1DIR  = BIT0+BIT6;

    while(1){
        P1OUT ^= BIT0^BIT6;
        __delay_cycles(100000);
    }

    return 0;
}
