/*
 * Módulo UART2
 * ==================
 * Autores:
 * Jon Moríñigo
 * Iker Fernández
 */

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "timers.h"

unsigned int flag_T9=0;


void inic_Timer9 (int period, int scale){

    TMR9 = 0 ; 	// Inicializar el registro de cuenta
    PR9 =  period-1;	// Periodo del temporizador
		// Queremos que cuente period timepo.
		// Fosc= 40 MHz (vease Inic_oscilator()) de modo que
		// Fcy = 20 MHz (cada instruccion dos ciclos de reloj)
		// Por tanto, Tcy= 50 ns para ejecutar una instruccion
		// Para contar 1 us se necesitan 20 ciclos.
    T9CONbits.TCKPS = scale;	// escala del prescaler 1:1
    T9CONbits.TCS = 0;	// reloj interno
    T9CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    IEC3bits.T9IE = 1;
    IFS3bits.T9IF = 0;
    T9CONbits.TON = 1;	// puesta en marcha del temporizador
}	

void Delay_us(int time){
    
    int period,scale=0;
    if(time>3276){  //si el tiempo es mayo que 2^16/(1000/50), lo que buscamos con esto es encontrar el limite para que el prescaler sea 0. Siendo 1e3 los us a ns , 50 el Tcy y 2^16 los 16 bits del registro del temporizador
        scale=1;
        time=time/8; //si no se utiliza prescaler 1
    }
    period=time * 20; //establecemos el periodo
    inic_Timer9(period, scale); //inicializamos el timer
    while(!flag_T9){}
    flag_T9=0;
}
void Delay_ms(int time){
    int period,scale;
    if(time<3){ //el funcionamiento es el mismo que delay_us pero esta vez de ms a ns son 1e6
        scale=0;
        period = time * 20000;
    }else if(time<27){
        scale=1;
        period= time * 2500; 
    }else{
        scale=2;
        period = time * 313;
    }
    inic_Timer9(period, scale);
    while(!flag_T9){}
    flag_T9=0;
}

void _ISR_NO_PSV _T9Interrupt(){
    flag_T9=1;
    T9CONbits.TON = 0; //apagamos el timer
    IFS3bits.T9IF=0;
}