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
#include "CN.h"
#include "srf08.h"
unsigned int estado=0;
unsigned int indice=0;
unsigned int fila_datos=0;
unsigned int columna_datos=0;
unsigned int final = 0;
unsigned char dato_recibido=' ';
unsigned int flag_reini_crono=0;


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
            flag_reini_crono=1;
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
    }
    if(flag_control==0 && pos_segura==0){
        switch(dato_recibido){
             
        case 'a':                       //Pulsando la tecla a se aumenta en 10 el valor del servomotor 1 (izquierda))
            if((duty0+50)<DUTY_MAX){    //Si no es el valor máximo se aumenta en 100, sino se pone al valor máximo
                duty0+=50;
            }else{
                 duty0=DUTY_MAX;
            }
            break;
        case 'd':                       //Pulsando la tecla d se reduce en 10 el valor del servomotor 1 (derecha))
            if((duty0-50)>DUTY_MIN){    //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty0-=50;
            }else{
                duty0=DUTY_MIN;
            }
            break;
        case 'w':                       //Pulsando la tecla w se aumenta en 10 el valor del servomotor 2 (arriba)
            if((duty1+50)<DUTY_MAX){    //Si no es el valor máximo se aumenta en 100, sino se pone al valor máximo
                duty1+=50;
            }else{
                 duty1=DUTY_MAX;
            }
            break;
        case 's':                       //Pulsando la tecla s se reduce en 10 el valor del servomotor 2 (abajo))
            if((duty1-50)>DUTY_MIN){    //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty1-=50;
            }else{
                duty1=DUTY_MIN;
            }
            break;
        case 'r':                           //Pulsando la tecla r se aumenta en 10 el valor del servomotor 3 (arriba)
            if(distancia > 5){              //Primero comprobamos que no este a 5 cm de distancia del suelo, si es el caso no lo movemos
                if((duty2+50)<DUTY_MAX){    //Si no es el valor máximo se aumenta en 100, sino se pone al valor máximo
                    duty2+=50;
                }else{
                    duty2=DUTY_MAX;
                }
            }     
            break;
        case 'f':                       //Pulsando la tecla f se reduce en 10 el valor del servomotor 3 (abajo)
            if((duty2-50)>DUTY_MIN){    //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty2-=50;
            }else{
                duty2=DUTY_MIN;
            }
            break;
        case 'y':                       //Pulsando la tecla y se aumenta en 10 el valor del servomotor 4 (arriba)
            if((duty3+50)<DUTY_MAX){    //Si no es el valor máximo se aumenta en 100, sino se pone al valor máximo
                duty3+=50;
            }else{
                 duty3=DUTY_MAX;
            }
            break;
        case 'h':                       //Pulsando la tecla h se reduce en 10 el valor del servomotor 4 (abajo))
            if((duty3-50)>DUTY_MIN){    //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty3-=50;
            }else{
                duty3=DUTY_MIN;
            }
            break;
        case 'g':                       //Pulsando la tecla g se aumenta en 10 el valor del servomotor 5 pinzas
            if((duty4+50)<6200){        //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty4+=50;
            }else{
                duty4=6200;
            }
            break;
        case 'j':                       //Pulsando la tecla j se reduce en 10 el valor del servomotor 5 (pinzas)
            if((duty4-50)>3100){        //Si no es el valor mínimo se reduce en 100, sino se pone al valor mínimo
                duty4-=50;
            }else{
                duty4=3100;
            }
            break;
        default:
            break;
        }
    }
           
       
    IFS1bits.U2RXIF=0;
}

void _ISR_NO_PSV _U2TXInterrupt(){
    if(estado==0){              //En el estado 0 mandamos los 3 comandos del home
        U2TXREG=home[indice];
        indice++;
        if(indice==3){
            indice=0;
            estado++;
        }
    }else{                      //En el estado 1 vamos imprimiendo cada caracter por interrupcion linea a linea 
        U2TXREG=LCD_Pantalla[fila_datos][columna_datos];
        columna_datos++;
        if(fila_datos!=17 && columna_datos==18){        //Cuando llega a 18 salta de fila
            fila_datos++;
            columna_datos=0;
        }else if(fila_datos==17 && columna_datos==18){  //Cuando llega al final vuelve al estado 0
            estado=0;
            columna_datos=0;
            fila_datos=0;
        }
    }
    IFS1bits.U2TXIF=0;  //bajamos el flag de interrupcion 
}