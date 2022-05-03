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
void inic_PWM_duty ()
{ 
    duty0=3250;
    duty1=3250;
    duty2=3250;
    duty3=3250;
}

