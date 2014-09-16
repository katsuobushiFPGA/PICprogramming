
/*
 * File:   dotmatrix6.c
 * Author: horiba
 *
 * Created on 2014/07/03, 16:16
 */
#include <stdio.h>      //standard_i/o
#include <xc.h>         // for __delay_ms
#include <pic16f873.h> //pic16f873 include
#include <i2c.h>
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

unsigned int w_chara[16]={0x0000,0x0040,0x60c0,0x39c0,0x3fc0,0x1fe0,0x0ff8,0x07fe,0x0ff8,0x1fe0,0x3fc0,0x39c0,0x60c0,0x0040,0x0000,0x0000};//★
/* prototype declare*/
void word(unsigned int data);
void word2(unsigned int a[16]);
void word_clear();
///*cons*/

void main( )
{
    TRISA = 0x00;//PORTA output
    TRISB = 0x00;//PORTB output
    TRISC = 0x00;//PORTC output

    PORTA = 0x00;//porta init
    PORTB = 0x00;//portb init
    PORTC = 0x00;//portc init
    //PORTB~C data
    word2(w_chara);
}
/*
void word(unsigned int data){
    PORTB= data >> 8;
    PORTC= data & 0xff;
}
 * */
void word2(unsigned int a[16]){
    for(int i=0;i<16;i++){
        PORTB=a[i] >> 8;
        PORTC=a[i] & 0xff;
        __delay_ms(1);
    }
}
void word_clear(){
    for(int i=0;i<16;i++){
        PORTB=0x00;
        PORTC=0x00;
        __delay_us(800);
    }
}

