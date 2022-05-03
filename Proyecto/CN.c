
#include "p24HJ256GP610A.h"
#include "commons.h"
#include "timers.h"
#include "UART2_RS232.h"

unsigned int flag_control=0;
// Funcion para inicializar el modulo CN
//==================
void inic_CN(){

	CNEN1bits.CN15IE=1;     // habilitacion de la interrupcion del pin CN15 (S3)
    CNEN2bits.CN16IE=1;     // habilitacion de la interrupcion del pin CN16 (S6)
    CNEN2bits.CN23IE=1;     // habilitacion de la interrupcion del pin CN23 (S5)
	CNEN1bits.CN5IE=1;      // habilitacion de la interrupcion del pin CN5 (Pusador Mini Joystick)
    
    
    IEC1bits.CNIE = 1;      // habilitacion de la interrupcion general de CN
    
	IFS1bits.CNIF = 0;      // Puesta a 0 del flag IF del modulo

}
// RUTINA DE ATENCION A LA INTERRUPCION DE CN
//==============================
void _ISR_NO_PSV _CNInterrupt()
{   
    if (!PORTDbits.RD6){ //S3
		if(scroll!=7){
            scroll++;
        }  
	}
    if (!PORTDbits.RD7){ //S6
        if(scroll!=0){
            scroll--;
        }
    }
    if(!PORTAbits.RA7){
        flag_control=!flag_control;     //Pulsador S5 cambia el control del servo mediante el teclado o el potenciometro 
    }
    if(!PORTBbits.RB3){
        Nop();
    }
    Nop();
    Nop();
 
    IFS1bits.CNIF = 0;
}