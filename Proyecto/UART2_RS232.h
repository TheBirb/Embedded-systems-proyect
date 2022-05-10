/* Funciones para trabajar con el modulo UART2_RS232.h
================================================

Autorxs: 
Fecha:
*/
extern unsigned int flag_reini_crono;
// funciones que se utilizan desde otros modulos
void inic_UART2 ();
void enviar_UART2_ventana ();
void recibir_teclas (unsigned char num);
unsigned char recibir_tecla();
void enviar_UART2_ventana_lineax(int linea);
