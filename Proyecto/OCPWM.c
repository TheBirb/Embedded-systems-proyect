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


//Función para imprimir por pantalla el valor del servomotor
/*
void imprimir_motor(){
    unsigned char result[4];
    unsigned int valor = OC1RS;
    
    dec_a_hex(valor, result ,4);
    
    Ventana_LCD[0][11]=result[3];
    Ventana_LCD[0][12]=result[2];
    Ventana_LCD[0][13]=result[1];
    Ventana_LCD[0][14]=result[0];


}*/
