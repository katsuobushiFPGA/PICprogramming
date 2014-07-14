#include <stdio.h>
#include <xc.h>            // for __delay_ms
#include <pic.h>
#include <pic16f877a.h>

#define _XTAL_FREQ 20000000 // 20Mhz
#pragma __CONFIG(_FOSC_HS & _WDTE_ON & _PWRTE_ON & _BODEN_OFF & _LVP_ON & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF)
#define LED RA0
void main( void )
{
    TRISA = 0x00; //output

    while ( 1 ) {
            LED = 0xff;
            __delay_ms(500);
            LED = 0x00;
            __delay_ms(500);
        }
}
