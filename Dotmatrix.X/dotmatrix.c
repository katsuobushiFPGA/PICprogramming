#include <stdio.h>      //standard_i/o
#include <stdlib.h>     //standard_library
#include <xc.h>         // for __delay_ms
#include <pic.h>        //pic include
#include <pic16f877a.h> //pic16f877 include

#define _XTAL_FREQ 20000000 // 20MHz
#define enableG1 RA0
#define enableG2 RA1
#define inputA RA2
#define inputB RA3
#define inputC RA4
//#pragma config CP=0b11,DEBUG=0b1,WRT=0b1,CPD=0b1,LVP=0b1,CP=0b11,PWRTE=0b0,WDTE=0b1,FOSC=0b10;
//#pragma config FOSC=0b11,WDTE=0b1,PWRTE=0b0,LVP=0b1,CPD=0b0,WRT=0b1,CP=0b11 //configulation_bits
void main( void )
{
    TRISA = 0x00;//PORTA output
    TRISB = 0x00;//PORTB output
    TRISC = 0x00;//PORTC output
    TRISD = 0x00;//PORTD output
    TRISE = 0x00;//PORTE output
    while(1){
        RA0=1;
        RA1=0;
        RA2=1;
        RA3=0;
        RA4=0;
    }
        
}
//========PIC-initialize========
//========3to8decorder==========
//RA0:G1 RA1:G2AB RA2:A RA3:B RA4:C

//========dynamic========


