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

unsigned int w_chara[16]={0x0000,0x0000,0x0c00,0x1804,0x1004,0x3004,0x2004,0x2004,0x2004,0x2004,0x2004,0x2004,0x2004,0x2000,0x0000,0x0000};
unsigned int w_chara2[16]={0x0000,0x6000,0x3c00,0x0780,0x02f0,0x011c,0x0087,0x0080,0x0080,0x3f00,0x4000,0x4000,0x6000,0x3000,0x1800,0x0000};
unsigned int w_chara3[16]={0x0000,0x0000,0x3ff8,0x600e,0x1000,0x0000,0x1c00,0x3008,0x2008,0x2008,0x2008,0x2008,0x2008,0x2008,0x2000,0x0000};
unsigned int w_chara4[16]={0x0000,0x0008,0x0208,0x0308,0x0188,0x40e8,0x40b8,0x408f,0x4088,0x4088,0x6088,0x2088,0x3108,0x1e08,0x0000,0x0000};
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
    while(1){
        for(int i=0;i<40;i++){
            word2(w_chara4);
            word2(w_chara3);
        }
        for(int i=0;i<40;i++){
            word2(w_chara2);
            word2(w_chara);
        }
    }
}
/*
void word(unsigned int data){
    PORTB= data >> 8;
    PORTC= data & 0xff;
}
 * */
void word2(unsigned int a[16]){
    for(int i=0;i<16;i++){
        RA0=1;
        PORTB=a[i] >> 8;
        PORTC=a[i] & 0xff;
        RA0=0;
        __delay_us(800);
    }
}
void word_clear(){
    for(int i=0;i<16;i++){
        RA0=1;
        PORTB=0x00;
        PORTC=0x00;
        RA0=0;
        __delay_us(800);
    }
}

