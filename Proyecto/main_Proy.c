/*
 * File:   main_Proy.c
 * Author: jonmorinigo
 *
 * Created on April 28, 2022, 9:52 AM
 */

#include "p24HJ256GP610A.h"
#include "commons.h"
#include "LCD.h"
#include "memoria.h"
#include "oscilator.h"
#include "timers.h"
#include "utilidades.h"
#include "UART2_RS232.h"
#include "ADC1.h"
#include "PWM.h"

int main(void) {
    
    unsigned int m_poten, m_temp, m_joy_x, m_joy_y, m_joy_z;
    unsigned int ms,ds,s,min;
    inic_oscilator();
    inic_UART2();
    inic_PWM_duty();
    inic_Timer_PWM();
    inic_Timer7();
    inic_Timer3();
    inic_crono(&ms,&ds,&s,&min);
    inic_ADC1();
    unsigned char zeros[2];
    conversion_tiempo(zeros,0);
    LCD_Pantalla[1][8]=zeros[0];
    LCD_Pantalla[1][9]=zeros[0];
    LCD_Pantalla[1][11]=zeros[0];
    LCD_Pantalla[1][12]=zeros[0];
    LCD_Pantalla[1][14]=zeros[0];
    U2TXREG=0;
    comienzo_muestreo();
    while(1){
        cronometro(&ms,&ds,&s,&min);
        if(flag_media==1){
            m_poten=calcular_media(muestras_poten);
            m_temp=calcular_media(muestras_temp);
            m_joy_x=calcular_media(muestras_j_x);
            m_joy_y=calcular_media(muestras_j_y);
            m_joy_z=calcular_media(muestras_j_z);
            
            imprimir_decimal(&LCD_Pantalla[3][12], m_poten, 4);
            imprimir_decimal(&LCD_Pantalla[4][13], m_temp, 3);
            imprimir_decimal(&LCD_Pantalla[5][12], m_joy_x, 4);
            imprimir_decimal(&LCD_Pantalla[6][12], m_joy_y, 4);
            imprimir_decimal(&LCD_Pantalla[7][12], m_joy_z, 4);
            
            flag_media=0;
        }
       
    }
}
