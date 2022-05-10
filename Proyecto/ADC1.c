/*
 * Módulo ADC1
 * ==================
 * Autores:
 * Jon Moríñigo
 * Iker Fernández
 */

#include <p24HJ256GP610A.h>
#include "commons.h"
#include "ADC1.h"

unsigned int n_muestras=0;
unsigned int muestras_poten[8];
unsigned int muestras_temp[8];
unsigned int muestras_j_x[8];
unsigned int muestras_j_y[8];
unsigned int muestras_j_z[8];
unsigned int muestras_mini_j_x[8];
unsigned int muestras_mini_j_y[8];
unsigned int flag_media=0;
unsigned int m_poten, m_temp, m_joy_x, m_joy_y, m_joy_z, m_mini_joy_x, m_mini_joy_y;
void inic_ADC1 (void)
{
// Inicializacion registro control AD1CON1
AD1CON1 = 0;       // todos los campos a 0

// Salida de 12 bits o 10 bits
//AD1CON1bits.AD12B = 0;  

// Comienzo digitalizacion automatico
// 111=Auto-convert / 010=TMR3 ADC1 y TMR5 ADC2 / 001=INT0 / 000= SAMP 
AD1CON1bits.SSRC=7;    		

// Muestreo simultaneo o secuencial
//AD1CON1bits.SIMSAM = 0; 
             
// Comienzo muestreo automÃ¡tico o por programa (SAMP=1) 		
//AD1CON1bits.ASAM = 0;

                    
// Inicializacion registro control AD1CON2
AD1CON2= 0 ;  // todos los campos a 0


// Inicializacion registro control AD1CON3
AD1CON3=0;    // todos los campos a 0
// Reloj con el que funciona el ADC:  0= reloj CPU; 1= RC erlojua 
//AD1CON3bits.ADRC = 0;  // 
AD1CON3bits.SAMC=31;   // Tiempo muestreo = numero de Tad 
AD1CON3bits.ADCS=3;   // Relacion entre TAD y Tcy TAD = Tcy(ADCS+1)


// Inicializacion registro control AD1CON4
AD1CON4=0;


// Inicializacion registro AD1CHS123
AD1CHS123=0;	//seleccion del canal 1,2 eta 3


// Inicializacion registro AD1CHS0
AD1CHS0=0;
AD1CHS0bits.CH0SA=0; // elige la entrada analogica conectada

//AD1CHS0bits.CH0SB = 0;


// Inicializacion registros AD1CSS 
// Si escaneo secuencial 1, si no 0

AD1CSSH = 0;   // 16-31 
AD1CSSL = 0;   // 0-15 

// Inicializacion registros AD1PCFG. Inicialmente todas AN como digitales
AD1PCFGH = 0xFFFF;      // 1= digital / 0= Analog
AD1PCFGL = 0xFFFF;      // Puerto B, todos digitales
// Inicializar como analogicas solo las que vayamos a usar
AD1PCFGLbits.PCFG5=0;   // potenciometro
AD1PCFGLbits.PCFG4=0;   // sensor temperatura
AD1PCFGLbits.PCFG0=0;   // Joystic eje X (Tiene la entrada an. 0, pin RB0)
AD1PCFGLbits.PCFG1=0;   // Joystic eje Y (Tiene la entrada an. 1, pin RB1)
AD1PCFGLbits.PCFG2=0;   // Joystic eje Z (palanca) (Tiene la entrada an. 2, pin RB2)
AD1PCFGLbits.PCFG8=0;   // Mini Joystic eje X (Tiene la entrada an. 8, pin RB8)
AD1PCFGLbits.PCFG9=0;   // Mini Joystic eje Y (Tiene la entrada an. 9, pin RB9)

// Bits y campos relacionados con las interrupciones
IFS0bits.AD1IF=0;    
IEC0bits.AD1IE=1;    
//IPC3bits.AD1IP=xx;    

//AD1CON
AD1CON1bits.ADON=1;  // Habilitar el modulo ADC
}


// comienzo del muestreo por programa
void comienzo_muestreo ()
{
    AD1CON1bits.SAMP=1; 
}

void _ISR_NO_PSV _ADC1Interrupt(){
    
    if(flag_media==0){
        
        switch (AD1CHS0bits.CH0SA) {
            case 0 :
                muestras_j_x[n_muestras]=ADC1BUF0;
                AD1CHS0bits.CH0SA=1; 
                break;
            case 1 :
                muestras_j_y[n_muestras]=ADC1BUF0;
                AD1CHS0bits.CH0SA=2; 
                break;
            case 2 :
                muestras_j_z[n_muestras]=ADC1BUF0;
                AD1CHS0bits.CH0SA=4; 
                break;
            case 4 :
                muestras_temp[n_muestras]=ADC1BUF0;
                AD1CHS0bits.CH0SA=5;    //Cambiamos al muestreo del potenciometro
                break;
            case 5:
                muestras_poten[n_muestras]=ADC1BUF0;
                AD1CHS0bits.CH0SA=8;
                break;
            case 8:
                muestras_mini_j_x[n_muestras]=ADC1BUF0;
                AD1CHS0bits.CH0SA=9;
                break;
            case 9:
                muestras_mini_j_y[n_muestras]=ADC1BUF0;
                if (n_muestras!=7){   
                    n_muestras++;      //Aumentamos las muestras por cada interrupción del conversor
                }else{
                    n_muestras=0;
                    flag_media=1;
                }
                AD1CHS0bits.CH0SA=0;
                break;
        }
    }
    IFS0bits.AD1IF=0;           //Bajamos el flag de la interrupción
}


