/*
 * M�dulo UART2
 * ==================
 * Autores:
 * Jon Mor��igo
 * Iker Fern�ndez
 */

///////////
//Funciones
///////////
void inic_Timer9 ();
void inic_Timer7();
void Delay_us(int time);
void Delay_ms(int time);

void cronometro(unsigned int *mili,unsigned int *deci,unsigned int *seg,unsigned int *min);
void inic_crono(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min);
void reinic_crono(unsigned int *mili,unsigned int *deci,
                unsigned int *seg,unsigned int *min);
