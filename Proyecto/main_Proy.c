/*
 * File:   main_Proy.c
 * Author: jonmorinigo
 *
 * Created on April 28, 2022, 9:52 AM
 */


#include "commons.h"
#include "LCD.h"
#include "memoria.h"
#include "oscilator.h"
#include "timers.h"
#include "utilidades.h"
#include "UART2_RS232.h"

int main(void) {
    unsigned int ms,ds,s,min;
    inic_oscilator();
    inic_UART2();
    U2TXREG=0;
    while(1){
        cronometro(&ms,&ds,&s,&min);
    }
}
