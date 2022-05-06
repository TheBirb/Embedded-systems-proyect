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
#include "memoria.h"
#include "PWM.h"
unsigned int estado=0;
unsigned int indice=0;
unsigned int fila_datos=0;
unsigned int columna_datos=0;
unsigned int final = 0;
unsigned char dato_recibido=' ';


void inic_UART2(){
    // Velocidad de transmision
    // Hay que hacer solo una de las dos asignaciones siguientes
	U2BRG = BAUD_RATEREG_2_BRGH1;
	//U2BRG = BAUD_RATEREG_2_BRGH0; 

     // U2MODE: habilitar el modulo (UARTEN), 8 bits, paridad par (PDSEL),
     // 1 bit de stop (STSEL), BRGH ...
	U2MODE = 0; //el registroe nteroa  0 los 16 bits

	U2MODEbits.BRGH=1; //el registro BRGH hemos decidido ponerlo a 1
	U2MODEbits.PDSEL=2; //PARIDAD PAR (QUE ES LA QUE VAMOS A USAR)
     // U2STA: modo de interrupcion en el envio (UTXISEL), habilitacion del
     // envio (UTXEN), modo de interrupcion en la recepcion (URXISEL)
	U2STA = 0; //TODO EL REGISTRO A 0

     // inicializacion de los bits IE e IF relacionados (IP si se quiere modificar) //0 encuentas o 1 interrupcion
	IFS1bits.U2RXIF=0;
    IFS1bits.U2TXIF=0;
	IEC1bits.U2RXIE=1;
    IEC1bits.U2TXIE=1;

     	//IPC7bits.U2RXIP=xx;
	//IPC7bits.U2TXIP=xx;

     // interrupciones debidas a errores + bug
	IEC4bits.U2EIE=0; 
	U2STAbits.OERR=0;

     // Habilitar el modulo y la linea TX.
     // Siempre al final y en ese orden!!!

	U2MODEbits.UARTEN=1;    // habilitar UART2
	U2STAbits.UTXEN=1;      // habilitar transmision tras habilitar modulo

	Delay_us(T_1BIT_US); 	// Esperar tiempo de 1 bit 
}

void _ISR_NO_PSV _U2RXInterrupt(){
    dato_recibido = U2RXREG;
    switch(dato_recibido){
        case 'i':                   //Pulsando la tecla i se reinicia el cronometro
            T7CONbits.TON = 0;
            //flag_reini_crono=1;
            break;
        case 'o':                   //Pulsando la tecla o se pausa el cronómetro
            if(T7CONbits.TON==1){
                T7CONbits.TON=0;
            }
            break;
        case 'p':                   //Pulsando la tecla p se continúa el cronometro
            if(T7CONbits.TON==0){
                T7CONbits.TON=1;
            }
            break;
        case 'a':                   //Pulsando la tecla m se aumenta en 10 el valor del servomotor
            if((duty0+50)<DUTY_MAX){    //Si no es el valor máximo se aumenta en 100, sino se pone al valor máximo
                duty0+=50;
            }else{
                 duty0=DUTY_MAX;
            }
            break;
        case 'd':                   //Pulsando la tecla n se reduce en 10 el valor del servomotor
            if((duty0-50)>DUTY_MIN){    //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty0-=50;
            }else{
                duty0=DUTY_MIN;
            }
            break;
        case 'w':                   //Pulsando la tecla m se aumenta en 10 el valor del servomotor
            if((duty1+50)<DUTY_MAX){    //Si no es el valor máximo se aumenta en 100, sino se pone al valor máximo
                duty1+=50;
            }else{
                 duty1=DUTY_MAX;
            }
            break;
        case 's':                   //Pulsando la tecla n se reduce en 10 el valor del servomotor
            if((duty1-50)>DUTY_MIN){    //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty1-=50;
            }else{
                duty1=DUTY_MIN;
            }
            break;
        case 'r':                   //Pulsando la tecla m se aumenta en 10 el valor del servomotor
            if((duty2+50)<DUTY_MAX){    //Si no es el valor máximo se aumenta en 100, sino se pone al valor máximo
                duty2+=50;
            }else{
                 duty2=DUTY_MAX;
            }
            break;
        case 'f':                   //Pulsando la tecla n se reduce en 10 el valor del servomotor
            if((duty2-50)>DUTY_MIN){    //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty2-=50;
            }else{
                duty2=DUTY_MIN;
            }
            break;
        case 'y':                   //Pulsando la tecla m se aumenta en 10 el valor del servomotor
            if((duty3+50)<DUTY_MAX){    //Si no es el valor máximo se aumenta en 100, sino se pone al valor máximo
                duty3+=50;
            }else{
                 duty3=DUTY_MAX;
            }
            break;
        case 'h':                   //Pulsando la tecla n se reduce en 10 el valor del servomotor
            if((duty3-50)>DUTY_MIN){    //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty3-=50;
            }else{
                duty3=DUTY_MIN;
            }
            break;
        case 'g':
            if((duty4+50)<6200){    //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty4+=50;
            }else{
                duty4=6200;
            }
            break;
        case 'j':
            if((duty4-50)>3100){    //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty4-=50;
            }else{
                duty4=3100;
            }
            break;
        default:
            break;
    }
    IFS1bits.U2RXIF=0;
}

void _ISR_NO_PSV _U2TXInterrupt(){
    if(estado==0){
        U2TXREG=home[indice];
        indice++;
        if(indice==3){
            indice=0;
            estado++;
        }
    }else{
        U2TXREG=LCD_Pantalla[fila_datos][columna_datos];
        columna_datos++;
        if(fila_datos!=15 && columna_datos==18){
            fila_datos++;
            columna_datos=0;
        }else if(fila_datos==15 && columna_datos==18){
            estado=0;
            columna_datos=0;
            fila_datos=0;
        }
    }
    IFS1bits.U2TXIF=0;  //bajamos el flag de interrupcion 
}