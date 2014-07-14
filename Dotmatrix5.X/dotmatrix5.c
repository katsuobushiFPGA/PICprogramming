/*
 * File:   dotmatrix5.c
 * Author: horiba
 *
 * Created on 2014/07/01, 11:38
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
void word(unsigned int a1,unsigned int a2,unsigned int a3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7,unsigned int a8,unsigned int a9,unsigned int a10,unsigned int a11,unsigned int a12,unsigned int a13,unsigned int a14,unsigned int a15,unsigned int a16);
void word2(unsigned int a[16]);
void scroll(unsigned int a[16]);
void copy(unsigned int a[16],unsigned int b[16]);
line(unsigned char line,unsigned char data1,unsigned char data2);
int is_scrollEnd(unsigned int a[16]);
///*cons*/
/*
 * PORTC:デコーダー1
 * PORTA:デコーダー2
 * PORTB:16~9
 * PORTD:8~1
 */
/*
 * RC0~2:A~C RC3:G1,RC4:G2
 * RA0~2:A~C RC3:G1,RC4:G2
 * RD0~7:1~8
 * RB0~7:9~16
 */
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
    //メモリ足りない;配列は使えない。
//    unsigned int chara1[16] = {0xbfff,0xbfff,0xbffd,0xbf7d,0xbf7d,0xbf7d,0xbf7d,0xbf7d,0xbf7d,0xbf7d,0xbf7d,0xbf7d,0xbf7d,0xbffd,0xbfff,0xbfff};
//    unsigned int chara2[16] = {0x8fff,0xe001,0x7fdd,0xbfed,0xfe05,0xc1f9,0x14ed,0xd505,0x1550,0xd555,0x9555,0x5505,0xc151,0x5f55,0x1f55,0xdf7d};
//    unsigned int chara3[16] = {0x8fff,0xf801,0xcb6d,0xfb6d,0xc801,0xfb6d,0x4b6d,0x3b6d,0x83fd,0x7fff,0x8001,0xff7d,0xf87d,0xc37d,0x1f01,0x7fff};
//    unsigned int chara4[16] = {0xffff,0xffff,0xc007,0x9ff1,0xefff,0xffff,0xe3ff,0xcff7,0xdff7,0xdff7,0xdff7,0xdff7,0xdff7,0xdff7,0xdfff,0xffff};
//    unsigned int chara5[16] = {0xfdef,0xfce7,0xfe73,0x0039,0xff9c,0xffff,0xffbf,0xffbd,0xffbd,0xffbd,0x7fbd,0x7fbd,0x003d,0xffbd,0xffbd,0xffbf};
//    unsigned int chara6[16] = {0xffff,0xffff,0xffff,0xff7f,0xfe3f,0xfcbf,0xf9df,0xf3cf,0xe7e7,0xcff3,0x9ff9,0x3ffc,0xffff,0xffff,0xffff,0xffff};
    unsigned int chara[16]={0xffff,0xdfff,0xcfff,0xe3ff,0xf803,0xffff,0xffff,0xffff,0xffff,0xc001,0xcfff,0xe7ff,0xf3ff,0xf9ff,0xfcff,0xfe7f};
    unsigned int chara2[16]={0xffff,0xdfff,0xcfff,0xe3ff,0xf803,0xffff,0xffff,0xffff,0xffff,0xc001,0xcfff,0xe7ff,0xf3ff,0xf9ff,0xfcff,0xfe7f};
    while(1){
        for(int i=0;i<20;i++){
                  word2(chara);
        }
//            word(0xffff,0xdfff,0xcfff,0xe3ff,0xf803,0xffff,0xffff,0xffff,0xffff,0xc001,0xcfff,0xe7ff,0xf3ff,0xf9ff,0xfcff,0xfe7f);
                  scroll(chara);
//        for(int i=0;i<50;i++){
//            word(0xdfff,0xcfff,0xe3ff,0xf83f,0xff87,0xffff,0xffff,0xffff,0xffff,0xffe7,0xff8f,0xfe3f,0xf0e7,0xc7db,0xffdb,0xffe7);
//        }
//        for(int i=0;i<50;i++){
//            word(0xffff,0xffff,0xdffb,0xdff3,0xdff7,0xcfe7,0xefef,0xe7ff,0xf7ff,0xf3ff,0xf9ff,0xfcff,0xfe7f,0xff3f,0xff9f,0xffff);
//        }
//        for(int i=0;i<50;i++){
//            word(0xffff,0xc007,0x9ff1,0xefff,0xffff,0xc7ef,0xbbef,0xbbef,0xbbef,0x9bef,0xc001,0xf7ef,0xe7ef,0xcfef,0xdfef,0xffff);
//        }
//        for(int i=0;i<50;i++){
//            word(0xdfff,0xdfff,0xdffb,0xdffb,0xdffb,0xdffb,0xdffb,0xdffb,0xdffb,0xdffb,0xdffb,0xdffb,0xdffb,0xdffb,0xdfff,0xdfff);
//        }
//        for(int i=0;i<50;i++){
//            word(0xbfff,0x8fff,0xe003,0x7ffb,0x7ddb,0x7ddb,0x31db,0xa50b,0x8d58,0xdd5b,0x8d5b,0xa50b,0x31db,0x7fdb,0x7fdb,0x7ffb);
//        }
//
//        for(int i=0;i<50;i++){
//            word(0x7dfd,0x3cfd,0x9e3d,0xce81,0xe4ed,0xf1ed,0xfc6d,0xff0d,0xfffd,0x8001,0x3f7d,0x7f3d,0x7fbd,0x7f9d,0x3fdd,0x9ffd);
//        }
//        for(int i=0;i<50;i++){
//            word(0xffff,0xc1ff,0xbc63,0xbf0f,0x9c5f,0xc9cf,0xe3ef,0xc86f,0xff00,0xcfef,0xb7ef,0xb7cf,0x97df,0xcf1f,0x907f,0xbfff);
//        }

    }
}
void copy(unsigned int origin[16],unsigned int copy[16]){
    for(int i=0;i<16;i++){
        origin[i]=copy[i];
    }
}
void scroll(unsigned int a[16]){
    a[16]=0xffff;
    for(int i=0;i<16;i++){
        a[i]=a[i+1];
    }
}
void word(unsigned int a1,unsigned int a2,unsigned int a3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7,unsigned int a8,unsigned int a9,unsigned int a10,unsigned int a11,unsigned int a12,unsigned int a13,unsigned int a14,unsigned int a15,unsigned int a16){
        line(1,a1 >> 8,a1 & 0x00ff);
        __delay_ms(1);
        line(2,a2 >> 8,a2 & 0x00ff);
        __delay_ms(1);
        line(3,a3 >> 8,a3 & 0x00ff);
        __delay_ms(1);
        line(4,a4 >> 8,a4 & 0x00ff);
        __delay_ms(1);
        line(5,a5 >> 8,a5 & 0x00ff);
        __delay_ms(1);
        line(6,a6 >> 8,a6 & 0x00ff);
        __delay_ms(1);
        line(7,a7 >> 8,a7 & 0x00ff);
        __delay_ms(1);
        line(8,a8 >> 8,a8 & 0x00ff);
        __delay_ms(1);
        line(9,a9 >> 8,a9 & 0x00ff);
        __delay_ms(1);
        line(10,a10 >> 8,a10 & 0x00ff);
        __delay_ms(1);
        line(11,a11 >> 8,a11 & 0x00ff);
        __delay_ms(1);
        line(12,a12 >> 8,a12 & 0x00ff);
        __delay_ms(1);
        line(13,a13 >> 8,a13 & 0x00ff);
        __delay_ms(1);
        line(14,a14 >> 8,a14 & 0x00ff);
        __delay_ms(1);
        line(15,a15 >> 8,a15 & 0x00ff);
        __delay_ms(1);
        line(16,a16 >> 8,a16 & 0x00ff);
        __delay_ms(1);
}
void word2(unsigned int a[16]){
    for(int i=0;i<16;i++){
        line(i,a[i] >> 8,a[i] & 0x00ff);
        __delay_ms(1);
    }
}
line(unsigned char line,unsigned char data1,unsigned char data2){
    switch(line){
        case 1:PORTA=0x00;
        PORTC=0b00001000;//portC点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 2:PORTC=0b00001001;//portC点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 3:PORTC=0b00001010;//portC点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 4:PORTC=0b00001011;//portC点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 5:PORTC=0b00001100;//portC点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 6:PORTC=0b00001101;//portC点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 7:PORTC=0b00001110;//portC点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 8:PORTC=0b00001111;//portC点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 9:PORTC=0x00;
        PORTA=0b00001000;//portA点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 10:PORTA=0b00001001;//portA点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 11:PORTA=0b00001010;//portA点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 12:PORTA=0b00001011;//portA点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 13:PORTA=0b00001100;//portA点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 14:PORTA=0b00001101;//portA点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 15:PORTA=0b00001110;//portA点灯
        PORTD=data1;
        PORTB=data2;
        break;
        case 16:PORTA=0b00001111;//portA点灯
        PORTD=data1;
        PORTB=data2;
        break;
    }
}


