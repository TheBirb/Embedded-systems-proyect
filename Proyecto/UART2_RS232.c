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

unsigned int estado=0;
unsigned int indice=0;
unsigned int fila_datos=0;
unsigned int columna_datos=0;
unsigned int final = 0;



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
        if(fila_datos!=0 && columna_datos==18){
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