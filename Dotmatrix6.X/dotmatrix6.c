/*
 * File:   dotmatrix6.c
 * Author: horiba
 *
 * Created on 2014/07/03, 16:16
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
void scroll(unsigned int w[16],unsigned int w2[16]);
void word(unsigned int a1,unsigned int a2,unsigned int a3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7,unsigned int a8,unsigned int a9,unsigned int a10,unsigned int a11,unsigned int a12,unsigned int a13,unsigned int a14,unsigned int a15,unsigned int a16);
void word2(unsigned int a[16]);
line(unsigned char line,unsigned char data1,unsigned char data2);
void copy(unsigned int origin[16],unsigned int copy[16]);
///*cons*/
/*
 * PORTB:デコーダー1,2: p~i:PORTB 7~4 RB7:C RB6:B RB5:A RB4:G1  H~A:8~0 RB3:C RB2:B RB1:A RB0:G1
 * PORTD:16~9 Anode: RD7~RD0
 * PORTC:8~1  Anode: RC7~RC0
 */
void main( )
{
    TRISB = 0x00;//PORTB output
    TRISC = 0x00;//PORTC output
    TRISD = 0x00;//PORTD output
    
    PORTB = 0x00;//portb init
    PORTC = 0x00;//portc init
    PORTD = 0x00;//portd init
    //メモリ足りない;配列は使えない。
    unsigned int w1[16]={0x1024,0x0c24,0x0324,0xfffe,0x0122,0x8623,0xc0c1,0x6078,0x3800,0x0f00,0x01ff,0x0f00,0x3840,0x6070,0xc01c,0x8000};
    unsigned int w2[16];
    unsigned int tmp[16];
    while(1){
        copy(w1,tmp);
        copy(w1,w2);
        for(int i=0;i<30;i++){
            word2(w2);
        }
                    scroll(w2,tmp);

    }
}
void copy(unsigned int origin[16],unsigned int copy[16]){
    for(int i=0;i<16;i++){
        copy[i]=origin[i];
    }
}
void scroll(unsigned int w[16],unsigned int w2[16]){
    for(int i=0;i<15;i++){
        w[i]=w[i+1];
    }
    w[15]=w2[0];
    for(int j=0;j<15;j++){
        w2[j]=w2[j+1];
    }
    w2[15]=0x00;
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
        case 1:PORTB=0x00;
        PORTB=0b00010000;
        PORTD=data1;
        PORTC=data2;
        break;
        case 2:PORTB=0b00110000;
        PORTD=data1;
        PORTC=data2;
        break;
        case 3:PORTB=0b01010000;
        PORTD=data1;
        PORTC=data2;
        break;
        case 4:PORTB=0b01110000;
        PORTD=data1;
        PORTC=data2;
        break;
        case 5:PORTB=0b10010000;
        PORTD=data1;
        PORTC=data2;
        break;
        case 6:PORTB=0b10110000;
        PORTD=data1;
        PORTC=data2;
        break;
        case 7:PORTB=0b11010000;
        PORTD=data1;
        PORTC=data2;
        break;
        case 8:PORTB=0b11110000;
        PORTD=data1;
        PORTC=data2;
        break;
        case 9:PORTB=0x00;
        PORTB=0b00000001;
        PORTD=data1;
        PORTC=data2;
        break;
        case 10:PORTB=0b00000011;
        PORTD=data1;
        PORTC=data2;
        break;
        case 11:PORTB=0b00000101;
        PORTD=data1;
        PORTC=data2;
        break;
        case 12:PORTB=0b00000111;
        PORTD=data1;
        PORTC=data2;
        break;
        case 13:PORTB=0b00001001;
        PORTD=data1;
        PORTC=data2;
        break;
        case 14:PORTB=0b00001011;
        PORTD=data1;
        PORTC=data2;
        break;
        case 15:PORTB=0b00001101;
        PORTD=data1;
        PORTC=data2;
        break;
        case 16:PORTB=0b00001111;
        PORTD=data1;
        PORTC=data2;
        break;

     }
}


