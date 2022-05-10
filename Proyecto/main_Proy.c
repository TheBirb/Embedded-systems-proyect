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
#include "CN.h"
#include "GPIO.h"

int main(void) {
    
    
    unsigned int ms,ds,s,min;
    inic_oscilator();
    inic_UART2();
    
    inic_Timer7();
    inic_Timer3();
    inic_Timer4();
    Init_LCD();
    
    inic_pulsadores();
    inic_Timer5();
    inic_CN();
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
    inic_PWM_servos();
    inic_Timer2_PWM();
    while(1){
        cronometro(&ms,&ds,&s,&min);
        if(flag_media==1){
            m_poten=calcular_media(muestras_poten);
            m_temp=calcular_media(muestras_temp);
            m_joy_x=calcular_media(muestras_j_x);
            m_joy_y=calcular_media(muestras_j_y);
            m_joy_z=calcular_media(muestras_j_z);
            m_mini_joy_x=calcular_media(muestras_mini_j_x);
            m_mini_joy_y=calcular_media(muestras_mini_j_y);
            
            imprimir_decimal(&LCD_Pantalla[3][12], m_poten, 4);
            imprimir_decimal(&LCD_Pantalla[4][13], m_temp, 3);
            imprimir_decimal(&LCD_Pantalla[5][12], m_joy_x, 4);
            imprimir_decimal(&LCD_Pantalla[6][12], m_joy_y, 4);
            imprimir_decimal(&LCD_Pantalla[7][12], m_joy_z, 4);
            imprimir_decimal(&LCD_Pantalla[8][12], m_mini_joy_x, 4);
            imprimir_decimal(&LCD_Pantalla[9][12], m_mini_joy_y, 4);
            if(flag_control==1){
                if(m_joy_x<430){
                    if(duty0>1500){
                        duty0-=20;
                    }else{
                        duty0 = 1500;
                    }
                }else if(m_joy_x> 490){
                    if(duty0<5500){
                        duty0+=20;
                    }else{
                        duty0 = 5500;
                    }
                }
                if(m_joy_y>490){
                    if(duty1<5500){
                        duty1+=20;
                    }else{
                        duty1 = 5500;
                    }
                }else if(m_joy_y<400){
                    if(duty1>1500){
                        duty1-=20;
                    }else{
                        duty1 = 1500;
                    }
                }
                if(m_mini_joy_y>520){
                    if(duty2<5500){
                        duty2+=20;
                    }else{
                        duty2=5500;
                    }
                }else if(m_mini_joy_y<480){
                    if(duty2>1500){
                        duty2-=20;
                    }else{
                        duty2=1500;
                    }
                }
                duty3 = DUTY_MIN+(unsigned int)((float)m_joy_z*3.98);
            }
            flag_media=0;
        }
        imprimir_decimal(&LCD_Pantalla[11][12],duty0,4);
        imprimir_decimal(&LCD_Pantalla[12][12],duty1,4);
        imprimir_decimal(&LCD_Pantalla[13][12],duty2,4);
        imprimir_decimal(&LCD_Pantalla[14][12],duty3,4);
        imprimir_decimal(&LCD_Pantalla[15][12],duty4,4);
    }
}
