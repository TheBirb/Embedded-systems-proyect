/*
Funciones relacionadas con el modulo OC para generar pulsos PWM

Autorxs: Iker Fernandez y Jon Mori�igo
Fecha: 15 may 2022
*/

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "memoria.h"
#include "utilidades.h"
unsigned int DUTY_MIN=1500;	// valor minimo de DUTY= T20ms/20 * MINPWM
unsigned int DUTY_MAX=5500;	// valor maximo de DUTY= T20ms/20 * MAXPWM
//Valores de la posici�n segura de cada servo
unsigned int POS_SEG_0= 3750;
unsigned int POS_SEG_1= 5500;
unsigned int POS_SEG_2= 5450;
unsigned int POS_SEG_3= 2350;
unsigned int POS_SEG_4= 6200;

unsigned int duty0,duty1,duty2,duty3,duty4;

//Funci�n para inicializar los servomotores
void inic_PWM_servos ()
{ 
    //Establecemos los bits donde conectaremos los servos como salida.
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    TRISBbits.TRISB11 = 0;
    //Apagamos los servos
    LATDbits.LATD0 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;
    LATDbits.LATD3 = 0;
    LATBbits.LATB11 = 0;
    //Inicializamos los dutys de cada servo en un valor medio
    duty0=3250;
    duty1=3250;
    duty2=3250;
    duty3=3250;
    duty4 =3250;
}

