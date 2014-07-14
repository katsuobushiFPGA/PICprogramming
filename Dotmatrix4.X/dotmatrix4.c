/*
 * File:   dotmatrix4.c
 * Author: horiba
 *
 * Created on 2014/07/01, 10:24
 */
#include <stdio.h>      //standard_i/o
#include <xc.h>         // for __delay_ms
#include <pic16f877a.h> //pic16f877 include
#define _XTAL_FREQ 20000000 // 20MHz
/*configuration bits*/
#pragma config BOREN=OFF//4V blown_out_reset OFF
#pragma config FOSC =HS //4MHz~20MHz High OS
#pragma config WDTE =OFF//watch_dog_timer off
#pragma config PWRTE=ON//power watch reset ON
#pragma config LVP  =OFF//low voltage programming OFF
#pragma config CPD  =OFF//code protection OFF
#pragma config CP   =OFF//flash bot off
#pragma config WRT  =OFF//flash memory write
#pragma config DEBUG=OFF//debug OFF
/* function prototype */
dynamic1();
dynamic2();
///*cons*/
#define LDA  RB0 //LineDecorder:A
#define LDB  RB1 //LineDecorder:B
#define LDC  RB2 //LineDecorder:C
#define LDG1 RB3 //LineDecorder;G1
#define LDG2 RB4 //LineDecorder:G2AB
#define LD2A RD7 //LD2:A
#define LD2B RD6 //LD2:B
#define LD2C RD5 //LD2:C
#define LD2G1 RD4 //LD2:G1
#define LD2G2 RD3 //LD2:G2AB
void main( )
{
    TRISA = 0x00;//PORTA output
    TRISB = 0x00;//PORTB output
    TRISC = 0x00;//PORTC output
    TRISD = 0x00;//PORTD output
    PORTA = 0x00;//porta init
    PORTB = 0x00;//portb init
    PORTC = 0x00;//portc init
    PORTD = 0x00;//portd init
    while(1){
        dynamic1();
        dynamic2();   
    }
}
//decorder1
dynamic1(){
    PORTB=0b00001000;
    __delay_ms(1);
    PORTB=0b00001001;
    __delay_ms(1);
    PORTB=0b00001010;
    __delay_ms(1);
    PORTB=0b00001011;
    __delay_ms(1);
    PORTB=0b00001100;
    __delay_ms(1);
    PORTB=0b00001101;
    __delay_ms(1);
    PORTB=0b00001110;
    __delay_ms(1);
    PORTB=0b00001111;
    __delay_ms(1);
    PORTB=0b00000000;
}
dynamic2(){
    PORTD=0b00010000;
    __delay_ms(1);
    PORTD=0b10010000;
    __delay_ms(1);
    PORTD=0b01010000;
     __delay_ms(1);
    PORTD=0b11010000;
     __delay_ms(1);
    PORTD=0b00110000;
    __delay_ms(1);
    PORTD=0b10110000;
    __delay_ms(1);
    PORTD=0b01110000;
    __delay_ms(1);
    PORTD=0b11110000;
    __delay_ms(1);
    PORTD=0b00000000;
}
//void clear_dec(){
//   RB3=0;
//   RB4=1;
//}
//========PIC-initialize========

//========3to8decorder==========
//RA0:A RA1:B RA2:C RA3:G1 RA4:G2AB

//TRANSISTA ARRAY

//========dynamic========


