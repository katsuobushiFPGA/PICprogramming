/*
 * File:   dotmatrix8.c
 * Author: horiba
 *
 * Created on 2014/07/07, 16:52
 */
#include <stdio.h>      //standard_i/o
#include <xc.h>         // for __delay_ms
#include <pic16f877.h> //pic16f877 include
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
dynamic();
    /* interrupt function*/
static void interrupt count_up(void);

/* cons */
unsigned int counter = 0;

/*
 * PORTB:RB7~RB0 デコーダー
 * RB3~0 decorder1 G1,C,B,A
 * RB7~4 decorder2 G1,C,B,A
 */
void main( )
{
    TRISB = 0x00;//PORTB RB7~RB1:output,RB0:Input
    PORTB = 0x00;
    //ダイナミック制御
    while(1){
        dynamic();
    }
}
dynamic(){
    PORTB = 0b10000000;//G1 on C,B,A = 0,0,0
    __delay_ms(1);
    PORTB = 0b10010000;//G1 on C,B,A = 0,0,1
    __delay_ms(1);
    PORTB = 0b10100000;//G1 on C,B,A = 0,1,0
    __delay_ms(1);
    PORTB = 0b10110000;//G1 on C,B,A = 0,1,1
    __delay_ms(1);
    PORTB = 0b11000000;//G1 on C,B,A = 1,0,0
    __delay_ms(1);
    PORTB = 0b11010000;//G1 on C,B,A = 1,0,1
    __delay_ms(1);
    PORTB = 0b11100000;//G1 on C,B,A = 1,1,0
    __delay_ms(1);
    PORTB = 0b11110000;//G1 on C,B,A = 1,1,1
    __delay_ms(1);
    PORTB=0x00;
            
    PORTB = 0b00001000;//G1 on C,B,A = 0,0,0
    __delay_ms(1);
    PORTB = 0b00001001;//G1 on C,B,A = 0,0,1
    __delay_ms(1);
    PORTB = 0b00001010;//G1 on C,B,A = 0,1,0
    __delay_ms(1);
    PORTB = 0b00001011;//G1 on C,B,A = 0,1,1
    __delay_ms(1);
    PORTB = 0b00001100;//G1 on C,B,A = 1,0,0
    __delay_ms(1);
    PORTB = 0b00001101;//G1 on C,B,A = 1,0,1
    __delay_ms(1);
    PORTB = 0b00001110;//G1 on C,B,A = 1,1,0
    __delay_ms(1);
    PORTB = 0b00001111;//G1 on C,B,A = 1,1,1
    __delay_ms(1);
    PORTB=0x00;
}

