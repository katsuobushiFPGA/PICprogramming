/************************************
16F84A HI-TECH C v.9.83
RA0??????RA2,RA3?LED?????
************************************/
#define _LEGACY_HEADERS
#include <pic.h>
#define _XTAL_FREQ 20000000 //20MHz

__CONFIG(HS & WDTDIS & PWRTDIS & UNPROTECT);

main(void){

TRISA = 0b00011;??????????//RA0?RA1????????
PORTA = 0b00000;?????????//????LED???????

while(1){
while(RA0 == 1){ ? //RA0??????OFF????????
NOP();
}
RA2 = 0;??//RA2???
RA3 = 1;??//RA3???
while(RA0 == 0){	?//RA0??????ON????????
NOP();
}
__delay_ms(20); //????????

while(RA0 == 1){	?//RA0??????OFF????????
NOP();
}
RA2 = 1;
RA3 = 0;
while(RA0 == 0){	?//RA0??????ON????????
NOP();
}
__delay_ms(20); ?? //????????

}
}