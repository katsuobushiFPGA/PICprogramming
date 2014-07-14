/*
 * File:   dotmatrix6.c
 * Author: horiba
 *
 * Created on 2014/07/07, 16:52
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
dynamic3();
dynamic4();
static void interrupt count_up(void);

/* cons */
unsigned int counter = 0;

/*
 * PORTC:デコーダー1,2: p~i:PORTC 7~4 RB7:C RB6:B RB5:A RB4:G1  H~A:8~0 RB3:C RB2:B RB1:A RB0:G1
 * PORTD:16~9 Anode: RD7~RD0
 * PORTC:8~1  Anode: RC7~RC0
 */
void main( )
{
    TRISB = 0b00000001;//PORTB RB7~RB1:output,RB0:Input
    TRISC = 0x00;//PORTC output
    TRISD = 0x00;//PORTD output


    PORTC = 0x00;//portc init
    PORTD = 0x00;//portd init
    INTEDG = 1;	// 割込み条件を立上がりエッジにする
    INTF = 0;	// RB0/INT外部割込みフラグをクリア
    INTE = 1;	 // RB0/INT外部割込み許可
    GIE = 1;	 // すべての割り込み許可
    while(1){
        dynamic1();
        PORTC=0x00;
        dynamic2();
        PORTC=0x00;
        dynamic3();
        PORTD=0x00;
        dynamic4();
        PORTD=0x00;
    }
}
static void interrupt count_up(void){ //割り込みcount
    counter++;
    INTF=0;//割り込みフラグクリア
}
dynamic1(){
    switch(counter){
        case 1:PORTC=0b00000001;
               __delay_us(800);
               break;
        case 2:PORTC=0b00000011;
               __delay_us(800);
               break;
        case 3:PORTC=0b00000101;
               __delay_us(800);
               break;
        case 4:PORTC=0b00000111;
               __delay_us(800);
               break;
        case 5:PORTC=0b00001001;
               __delay_us(800);
               break;
        case 6:PORTC=0b00001011;
               __delay_us(800);
               break;
        case 7:PORTC=0b00001101;
                __delay_us(800);
                break;
        case 8:PORTC=0b00001111;   
               __delay_us(800);
               break;
    }
}
dynamic2(){
    switch(counter){
        case 9: PORTC=0b00010000;
                __delay_us(800);
                break;
        case 10:PORTC=0b00110000;
               __delay_us(800);
               break;
        case 11:PORTC=0b01010000;
                __delay_us(800);
                break;
        case 12:PORTC=0b01110000;
                __delay_us(800);
                break;
        case 13:PORTC=0b10010000;
                __delay_us(800);
                break;
        case 14:PORTC=0b10110000;
                __delay_us(800);
                break;
        case 15:PORTC=0b11010000;
                __delay_us(800);
                break;
        case 16:PORTC=0b11110000;
                __delay_us(800);
                break;
    }
}
dynamic3(){
    switch(counter){
        case 17:PORTD=0b00000001;
                __delay_us(800);
                break;
        case 18:PORTD=0b00000011;
                __delay_us(800);
                break;
        case 19:PORTD=0b00000101;
                __delay_us(800);
                break;
        case 20:PORTD=0b00000111;
                __delay_us(800);
                break;
        case 21:PORTD=0b00001001;
                __delay_us(800);
                break;
        case 22:PORTD=0b00001011;
                __delay_us(800);
                break;
        case 23:PORTD=0b00001101;
                __delay_us(800);
                break;
        case 24:PORTD=0b00001111;
                __delay_us(800);
                break;
    }
}
dynamic4(){
    switch(counter){
        case 25:PORTD=0b00010000;
                __delay_us(800);
                break;
        case 26:PORTD=0b00110000;
                __delay_us(800);
                break;
        case 27:PORTD=0b01010000;
                __delay_us(800);
                break;
        case 28:PORTD=0b01110000;
                __delay_us(800);
                break;
        case 29:PORTD=0b10010000;
                __delay_us(800);
                break;
        case 30:PORTD=0b10110000;
                __delay_us(800);
                break;
        case 31:PORTD=0b11010000;
                __delay_us(800);
                break;
        case 32:PORTD=0b11110000;
                __delay_us(800);
                counter=0;
                break;        
    }
}
