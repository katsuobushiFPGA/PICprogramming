#include <htc.h>
_CONFIG(FOSC_INTOSCIO & WDTE_OFF & PWRTE_ON & BOREN_ON & MCLRE_OFF & CP_OFF & IESO_OFF &FCMEN_OFF);
#define _XTAL_FREQ 1000000
void main()
{
    OSCCON = 0x40;
    ANSEL = 0;
    CMCON0 = 0x07;
    TRISIO = 0x08;
    while(1)
    {
        GP2=1;
        _delay_ms(300);
        GP2=0;
        _delay_ms(300);
    }
}