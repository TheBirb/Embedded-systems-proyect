/*
 * Módulo UART2
 * ==================
 * Autores:
 * Jon Moríñigo
 * Iker Fernández
 */

extern unsigned int duty0,duty1,duty2,duty3;
///////////
//Funciones
///////////
void inic_Timer2_PWM();
void inic_Timer3();
void inic_Timer5();
void inic_Timer7();
void inic_Timer9 ();
void Delay_us(int time);
void Delay_ms(int time);

void cronometro(unsigned int *mili,unsigned int *deci,unsigned int *seg,unsigned int *min);
void inic_crono(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min);
void reinic_crono(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min);
