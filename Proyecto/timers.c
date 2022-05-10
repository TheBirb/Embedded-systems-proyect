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
#include "utilidades.h"
#include "memoria.h"
#include "LCD.h"
#include "ADC1.h"
#include "PWM.h"
unsigned int flag_T9=0;
unsigned int flag_crono=0;
unsigned int estado_LCD=0;
unsigned int L5=0;
unsigned int Tac=0;
unsigned int estadoPWM=0;
unsigned int scroll=0;
unsigned int estado_posicion_segura=0;
unsigned int fin_programa=0;
////////////////////
//Inicializaciones
////////////////////
void inic_Timer2_PWM ()
{
    TMR2 = 0 ; 	// Inicializar el registro de cuenta
    PR2 =  duty0-1;	// Periodo del temporizador
		// Queremos que cuente 20 ms.
		// Fosc= 40 MHz (vease Inic_oscilator()) de modo que
		// Fcy = 20 MHz (cada instruccion dos ciclos de reloj)
		// Por tanto, Tcy= 50 ns para ejecutar una instruccion
		// Para contar 20 ms se necesitan 400000 ciclos.
    T2CONbits.TCKPS = 1;	// escala del prescaler 1:8
    T2CONbits.TCS = 0;	// reloj interno
    T2CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    IEC0bits.T2IE = 1;  //Activamos las interrupciones
    IFS0bits.T2IF = 0;  //Puesta del flag IF a 0
    T2CONbits.TON = 1;	// puesta en marcha del temporizador
}
void inic_Timer3 ()
{

    TMR3 = 0 ; 	// Inicializar el registro de cuenta
    PR3 =  10000-1;	// Periodo del temporizador
		// Queremos que cuente 0,5 ms.
		// Fosc= 40 MHz (vease Inic_oscilator()) de modo que
		// Fcy = 20 MHz (cada instruccion dos ciclos de reloj)
		// Por tanto, Tcy= 50 ns para ejecutar una instruccion
		// Para contar 0.5 ms se necesitan 10000 ciclos.
    T3CONbits.TCKPS = 0;	// escala del prescaler 1:1
    T3CONbits.TCS = 0;	// reloj interno
    T3CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    IEC0bits.T3IE =1;
    IFS0bits.T3IF =0;
    T3CONbits.TON = 1;	// puesta en marcha del temporizado
}
void inic_Timer4 ()
{

    TMR4 = 0 ; 	// Inicializar el registro de cuenta
    PR4 =  25000-1;	// Periodo del temporizador
		// Queremos que cuente 20 ms.
		// Fosc= 40 MHz (vease Inic_oscilator()) de modo que
		// Fcy = 20 MHz (cada instruccion dos ciclos de reloj)
		// Por tanto, Tcy= 50 ns para ejecutar una instruccion
		// Para contar 0.5 ms se necesitan 10000 ciclos.
    T4CONbits.TCKPS = 1;	// escala del prescaler 1:1
    T4CONbits.TCS = 0;	// reloj interno
    T4CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    IEC1bits.T4IE =1;
    IFS1bits.T4IF =0;
    T4CONbits.TON = 1;	// puesta en marcha del temporizado
}
void inic_Timer5 ()
{

    TMR5 = 0 ; 	// Inicializar el registro de cuenta
    PR5 =  40000-1;	// Periodo del temporizador
		// Queremos que cuente 2 ms.
		// Fosc= 40 MHz (vease Inic_oscilator()) de modo que
		// Fcy = 20 MHz (cada instruccion dos ciclos de reloj)
		// Por tanto, Tcy= 50 ns para ejecutar una instruccion
		// Para contar 2 ms se necesitan 40000 ciclos.
    T5CONbits.TCKPS = 0;	// escala del prescaler 1:1
    T5CONbits.TCS = 0;	// reloj interno
    T5CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    IEC1bits.T5IE =1;
    IFS1bits.T5IF =0;
    T5CONbits.TON = 1;	// puesta en marcha del temporizado
}

void inic_Timer7 ()
{

    TMR7 = 0 ; 	// Inicializar el registro de cuenta
    PR7 =  25000-1;	// Periodo del temporizador
		// Queremos que cuente 10 ms.
		// Fosc= 40 MHz (vease Inic_oscilator()) de modo que
		// Fcy = 20 MHz (cada instruccion dos ciclos de reloj)
		// Por tanto, Tcy= 50 ns para ejecutar una instruccion
		// Para contar 10 ms se necesitan 200000 ciclos.
    T7CONbits.TCKPS = 1;	// escala del prescaler XXX
    T7CONbits.TCS = 0;	// reloj interno
    T7CONbits.TGATE = 0;	// Deshabilitar el modo Gate
    IEC3bits.T7IE = 1;  //Activamos las interrupciones
    IFS3bits.T7IF = 0;  //Puesta del flag IF a 0
    T7CONbits.TON = 1;	// puesta en marcha del temporizador
}
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

//////////////////
//Funciones
//////////////////
void inic_crono(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min)	
// inicializacion de las variables del cronometro
{
    (*mili)=0;
    (*deci)=0;
    (*seg)=0;
    (*min)=0;
}

void reinic_crono(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min)	
// Reiniciar las variables del cronometro
{
    (*mili)=0;
    (*deci)=0;
    (*seg)=0;
    (*min)=0;
    
    LATAbits.LATA1=0;
    LATAbits.LATA3=0;
    LATAbits.LATA5=0;
    
}

void cronometro(unsigned int *mili,unsigned int *deci,unsigned int *seg,unsigned int *min)	// control del tiempo mediante el temporizador 7
{   
    unsigned char tiempo[2];
    //LCD
    
    if(flag_crono==1 && T7CONbits.TON){// espera a que pasen 10 milisegundos 10ms
        flag_crono=0;                       //Volvemos lvemos a bajar el flag
        (*mili)+=10;    //sumamos 10 segundos 
        if((*mili)==100) {                      //Si milisegundos llega a 100
            LATAbits.LATA1=!LATAbits.LATA1;     //Conmutamos el led D4
            (*mili)=0;                          //Reseteamos los milisegundos
            (*deci)++;  
            if((*deci)==10) {                       //si las decimas llegan a a 100
                LATAbits.LATA3=!LATAbits.LATA3;     //Conmutamos el led D6
                (*deci)=0;                          //Reseteamos los decimales
                (*seg)++;                           //Incrementamos los sergundos
                conversion_tiempo(tiempo, (*deci));
                LCD_Pantalla[1][14]=tiempo[1]; 
                if((*seg)==60 ) {                       //Si segundos llega a 60
                    LATAbits.LATA5=!LATAbits.LATA5;     //Conmutamos el led D8
                    (*seg)=0;                           //Reseteamos los segundos
                    (*min)++; 
                    conversion_tiempo(tiempo, (*seg));
                    LCD_Pantalla[1][11]=tiempo[0]; 
                    LCD_Pantalla[1][12]=tiempo[1];
                    conversion_tiempo(tiempo, (*min));
                    LCD_Pantalla[1][8]=tiempo[0]; 
                    LCD_Pantalla[1][9]=tiempo[1];//Incrementamos los minutos
                }else{
                    conversion_tiempo(tiempo, (*seg));
                    LCD_Pantalla[1][11]=tiempo[0]; 
                    LCD_Pantalla[1][12]=tiempo[1];
                }//Incrementamos los segundos
            }else{
                conversion_tiempo(tiempo, (*deci));    
                LCD_Pantalla[1][14]=tiempo[1];
            }    
        } 
        
    }  
    
} 




//////////////////
//Interrupciones
//////////////////
void _ISR_NO_PSV _T2Interrupt(){     
    switch(estadoPWM){
        case 0:
            LATDbits.LATD0 = 1;
            PR2 = duty0;
            Tac = PR2;
            estadoPWM++;
            break;
        case 1:
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 1;
            PR2 = duty1;
            Tac += PR2;
            estadoPWM++;
            break;
        case 2:
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 1;
            PR2 = duty2;
            Tac += PR2;
            estadoPWM++;
            break;
        case 3:
            LATDbits.LATD2 = 0;
            LATDbits.LATD3 = 1;
            PR2 = duty3;
            Tac += PR2;
            estadoPWM++;
            break;
        case 4:
            LATDbits.LATD3 = 0;
            LATBbits.LATB11=1;
            PR2 = duty4;
            Tac+=PR2;
            estadoPWM++;
            break;
        case 5:
            LATBbits.LATB11=0;
            Tac=PR2;
            PR2 = 50000 - Tac -1;
            Tac=0;
            estadoPWM=0;
            break;
    }
    IFS0bits.T2IF = 0;      
}
void _ISR_NO_PSV _T3Interrupt(){
    comienzo_muestreo();
    IFS0bits.T3IF = 0;
}
void _ISR_NO_PSV _T4Interrupt(){
    
    switch (estado_posicion_segura){
        case 0:
            if(duty0>POS_SEG_0+10){
                duty0 = duty0 - 10;
            }else if (duty0<POS_SEG_0+10){
                duty0 = duty0 + 10;
            }else{
                estado_posicion_segura=1;
            }
            break;
        case 1:
            if(duty1>POS_SEG_1+10){
                duty0 = duty0 - 10;
            }else if (duty1<POS_SEG_1+10){
                duty1 = duty1 + 10;
            }else{
                estado_posicion_segura=2;
            }
            break;
        case 2:
            if(duty2>POS_SEG_2+10){
                duty2 = duty2 - 10;
            }else if (duty2<POS_SEG_2+10){
                duty2 = duty2 + 10;
            }else{
                estado_posicion_segura=3;
            }
            break;
        case 3:
            if(duty3>POS_SEG_3+10){
                duty3 = duty3 - 10;
            }else if (duty3<POS_SEG_3+10){
                duty3 = duty3 + 10;
            }else{
                estado_posicion_segura=4;
            }
            break;
        case 4:
            if(duty4>POS_SEG_4+10){
                duty4 = duty4 - 10;
            }else if (duty4<POS_SEG_4+10){
                duty4 = duty4 + 10;
            }else{
                estado_posicion_segura=5;
            }
            break;
        case 5:
            estado_posicion_segura=0;
            fin_programa=1;
            T4CONbits.TON = 0;
            break;            
    }
    IFS1bits.T4IF=0;
    
}
void _ISR_NO_PSV _T5Interrupt(){
    
    switch (estado_LCD) {       //segun en que estado estemos haremos una cosa u otras
        case 0 :            //en el estado 0 nos colocamos en la linea 1
            lcd_cmd(0x80);
            estado_LCD++;
            break;
        case 1:             //en el estado 1 vamos recorriendo todos los caracteres de la linea 0 por cada interrupcion 
            lcd_data(LCD_Pantalla[scroll][L5]);
            L5++;
            if (L5==16){
                L5=0;
                estado_LCD++;
            }
            break;
        case 2:             //en el estado 2 nos colocamos en la linea 2
            lcd_cmd(0xC0);
            estado_LCD++;
            break;
        case 3:             //en el estado 3 vamos recorriendo todos los caracteres de la linea 1 por cada interrupcion
            lcd_data(LCD_Pantalla[scroll+1][L5]);
            L5++;
            if (L5==16){
                L5=0;
                estado_LCD=0;
            }
            break;       
    }
    IFS1bits.T5IF=0;    //bajamos el flag de la interrupcion
}

void _ISR_NO_PSV _T7Interrupt(){
    flag_crono=1;       //Subimos el flag del contador cronometro
    IFS3bits.T7IF=0;    //Ponemos el flag T7IF a 0
}

void _ISR_NO_PSV _T9Interrupt(){
    flag_T9=1;
    T9CONbits.TON = 0; //apagamos el timer
    IFS3bits.T9IF=0;
}
