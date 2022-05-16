/*
 * File:   main_Proy.c
 * Author: Iker Fernandez y Jon Moriñigo
 *
 * Created on April 28, 2022
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
#include "srf08.h"
#include "i2c_funciones.h"

int main(void) {
    
    
    unsigned int ms,ds,s,min;       //Variables del cronometro
    unsigned char dir[2];           //Array donde se guardará la dirección del sensor
    
    //Inicializaciones
    inic_oscilator();
    inic_UART2();
    InitI2C_1();
    inic_Timer7();
    inic_Timer3();
    Init_LCD();
    inic_pulsadores();
    inic_Timer5();
    inic_CN();
    inic_crono(&ms,&ds,&s,&min);
    inic_ADC1();
    
    //Imprimimos 0 en pantalla en el timer
    unsigned char zeros[2];
    conversion_tiempo(zeros,0);
    LCD_Pantalla[1][8]=zeros[0];
    LCD_Pantalla[1][9]=zeros[0];
    LCD_Pantalla[1][11]=zeros[0];
    LCD_Pantalla[1][12]=zeros[0];
    LCD_Pantalla[1][14]=zeros[0];
    
    //Inicializaciones
    U2TXREG=0;
    comienzo_muestreo();
    inic_PWM_servos();
    inic_Timer2_PWM();
    inic_Timer1();
    inic_medicion_dis(0xE6);
    inic_Timer6();
    
    //Programa principal
    while(1){
        cronometro(&ms,&ds,&s,&min);        //Ejecutamos la funcion cronometro cada veulta
        
        //Cuando se activa el flag se reinicia el cronometro
        if(flag_reini_crono==1){
            LCD_Pantalla[1][8]=zeros[0];
            LCD_Pantalla[1][9]=zeros[0];
            LCD_Pantalla[1][11]=zeros[0];
            LCD_Pantalla[1][12]=zeros[0];
            LCD_Pantalla[1][14]=zeros[0];
            reinic_crono(&ms,&ds,&s,&min);  //Reinicializamos las variables del cronometro
            Nop();
            Nop();
            T7CONbits.TON = 1;              
            flag_reini_crono=0;
        }
        
        //Si han recogido 8 muestras de cada señal analogica se calcula la media y se imprime por pantalla
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
            
            //Si el control es mediante las entradas analógicas y no esta activada la posición segura se calcula la posición de cada servo (actualizando el duty)
            if(flag_control==1 && pos_segura == 0){
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
                    if(distancia > 5){
                        if(duty2<5500){
                            duty2+=20;
                        }else{
                            duty2=5500;
                        }
                    }
                    
                }else if(m_mini_joy_y<480){
                    if(duty2>1500){
                        duty2-=20;
                    }else{
                        duty2=1500;
                    }
                }
                 if(m_mini_joy_x>500){
                    if(duty4<6200){
                        duty4+=40;
                    }else{
                        duty4=6200;
                    }
                }else if(m_mini_joy_x<480){
                    if(duty4>3200){
                        duty4-=40;
                    }else{
                        duty4=3200;
                    }
                }
                objetivo = DUTY_MIN+(unsigned int)((float)m_joy_z*3.98);
            }
            flag_media=0;
            
        }
        
        //Si se activa este flag se calcula la distancia del sensor
        if(ultraSonicFlag==1){
            leer_medicion(0xE6,dir);
            distancia=calcular_distancia(dir);
            imprimir_decimal(&LCD_Pantalla[16][13],distancia,3);
            inic_medicion_dis(0xE6);
            inic_Timer6();
            ultraSonicFlag=0;
        }
        
        //Se imprimer los valores de cada servomotor por pantalla
        imprimir_decimal(&LCD_Pantalla[11][12],duty0,4);
        imprimir_decimal(&LCD_Pantalla[12][12],duty1,4);
        imprimir_decimal(&LCD_Pantalla[13][12],duty2,4);
        imprimir_decimal(&LCD_Pantalla[14][12],duty3,4);
        imprimir_decimal(&LCD_Pantalla[15][12],duty4,4);
        
        //Si se activa fin programa se acaba el bucle
        if(fin_programa)break;
    }
    return 0;
}
