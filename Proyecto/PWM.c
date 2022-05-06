/*
Funciones relacionadas con el modulo OC para generar pulsos PWM

Comentarios!!!!!!!!!!!!!!

Autorxs:
Fecha:
*/

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "memoria.h"
#include "utilidades.h"
unsigned int DUTY_MIN=1500;	// valor minimo de DUTY= T20ms/20 * MINPWM
unsigned int DUTY_MAX=5500;	// valor maximo de DUTY= T20ms/20 * MAXPWM
unsigned int duty0,duty1,duty2,duty3;
void inic_PWM_servos ()
{ 
     TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    LATDbits.LATD0 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;
    LATDbits.LATD3 = 0;
    duty0=3250;
    duty1=3250;
    duty2=3250;
    duty3=3250;
}

