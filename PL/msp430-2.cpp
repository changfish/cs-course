#include <msp430.h> 



int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR = BIT0 + BIT6;
    P1DIR &= ~BIT3;
    P1REN |= BIT3;
    P1OUT = BIT3;

    while(1){
        if(!(P1IN & BIT3)){
            P1OUT |= BIT0;                  //BIT3 OR BIT0
            __delay_cycles(100000);
            P1OUT &= ~BIT0;
            P1OUT |= BIT6;
            __delay_cycles(100000);
            P1OUT &= ~BIT6;
        }else{
//            P1OUT ^= (BIT0 ^ BIT6);
            P1OUT = BIT3;
        }
    }
    return 0;
}
