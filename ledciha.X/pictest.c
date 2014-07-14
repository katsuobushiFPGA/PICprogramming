#include <stdio.h>
#include <xc.h>            // for __delay_ms
#include <pic.h>
#include <pic16f677.h>

#define _XTAL_FREQ 4000000 // 4Mhz?????????????

void main( void )
{
    TRISB = 0x00;

    while ( 1 ) {
            RB7 = 0xff;
            RB6 = 0x00;
            RB5 = 0x00;
            __delay_ms(500);
            RB7 = 0x00;
            RB6 = 0xff;
            RB5 = 0x00;
            __delay_ms(500);
            RB7 = 0x00;
            RB6 = 0x00;
            RB5 = 0xff;
            __delay_ms(500);
        }
}
