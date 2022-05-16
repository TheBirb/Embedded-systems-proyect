/*
Funciones de inicializacion y tratamiento de pulsadores y leds

Egileak: Iker Fernandez y Jon Moriñigo
Data: Febrero 2020
*/


#include "p24HJ256GP610A.h"
#include "commons.h"

void inic_leds()
{
  TRISA = 0xff00; // Definir como salidas los 8 pines conectados a leds: RA7-RA0		  
                  // El resto como entradas: 1 = In; 0 = Out
  Nop();	
  Nop();
  LATA=LATA & 0xff00; 	// Apagar los leds
	
}

void inic_pulsadores()
{
    AD1PCFGH = 0xffff;      //Definir todos los pulsadores como entrada    
    TRISDbits.TRISD6=1;     //Establecemos S3 como entrada.
    TRISDbits.TRISD7=1;     //Establecemos S6 como entrada.
    TRISDbits.TRISD13=1;    //Establecemos S4 como entrada.
    TRISAbits.TRISA7=1;     //Establecemos S5 como entrada
    TRISBbits.TRISB3=1;     //Establecemos RB3 como entrada (Pulsador Mini Joystick)
}

      
