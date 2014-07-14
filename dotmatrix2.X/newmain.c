#include <stdio.h>      //standard_i/o
#include <xc.h>         // for __delay_ms
//#include <pic.h>        //pic include
//#include <pic16f877a.h> //pic16f877 include
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
set_dec(unsigned char c,unsigned char b,unsigned char a);

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
#define LD2G2 RC7 //LD2:G2AB
void main( )
{
    TRISB = 0x00;//PORTA output
    TRISC=0x00;
    TRISD=0x00;
    PORTB = 0x00;//portb init
    PORTC=0x00;
    PORTD=0x00;
    while(1){
        LDC=0;
        LDB=0;
        LDA=0;
        LDG1=1;
        LDG2=0;
        __delay_ms(300);
        LDC=0;
        LDB=0;
        LDA=1;
        LDG1=1;
        LDG2=0;
        __delay_ms(300);
        LDC=0;
        LDB=1;
        LDA=0;
        LDG1=1;
        LDG2=0;
        __delay_ms(300);
        LDC=0;
        LDB=1;
        LDA=1;
        LDG1=1;
        LDG2=0;
        __delay_ms(300);
        LDC=1;
        LDB=0;
        LDA=0;
        LDG1=1;
        LDG2=0;
        __delay_ms(300);
        LDC=1;
        LDB=0;
        LDA=1;
        LDG1=1;
        LDG2=0;
        __delay_ms(300);
        LDC=1;
        LDB=1;
        LDA=0;
        LDG1=1;
        LDG2=0;
        __delay_ms(300);
        LDC=1;
        LDB=1;
        LDA=1;
        LDG1=1;
        LDG2=0;
        __delay_ms(300);
        LDG1=0;
        LDG2=0;
        
        LD2C=0;
        LD2B=0;
        LD2A=0;
        LD2G1=1;
        LD2G2=0;
        __delay_ms(300);
        LD2C=0;
        LD2B=0;
        LD2A=1;
        LD2G1=1;
        LD2G2=0;
        __delay_ms(300);
        LD2C=0;
        LD2B=1;
        LD2A=0;
        LD2G1=1;
        LD2G2=0;
        __delay_ms(300);
        LD2C=0;
        LD2B=1;
        LD2A=1;
        LD2G1=1;
        LD2G2=0;
        __delay_ms(300);
        LD2C=1;
        LD2B=0;
        LD2A=0;
        LD2G1=1;
        LD2G2=0;
        __delay_ms(300);
        LD2C=1;
        LD2B=0;
        LD2A=1;
        LD2G1=1;
        LD2G2=0;
        __delay_ms(300);
        LD2C=1;
        LD2B=1;
        LD2A=0;
        LD2G1=1;
        LD2G2=0;
        __delay_ms(300);
        LD2C=1;
        LD2B=1;
        LD2A=1;
        LD2G1=1;
        LD2G2=0;
        __delay_ms(300);
        LD2G1=0;
        LD2G2=0;

    }
}
//decorder1
set_dec(unsigned char c,unsigned char b,unsigned char a){
    PORTBbits.RB0=a;
    PORTBbits.RB1=b;
    PORTBbits.RB2=c;
    PORTBbits.RB3=1;
    PORTBbits.RB4=0;
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


