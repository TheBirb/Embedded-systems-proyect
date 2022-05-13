/*
Funciones para utilizar el sensor de distancia

Autoras/es:Iker Fernandez y Jon Moriñigo

Fecha:01/04/22
*/


#include "i2c_funciones.h"
unsigned int distancia;
unsigned int inic_medicion_dis (unsigned char dirI2C)
 // Puesta en marcha de una medicion
 // Parametro dirI2C corresponde a la direccion I2C del sensor
{
   unsigned int error = LDByteWriteI2C_1(dirI2C, 0, 81);
   
   return error;
}

unsigned int leer_medicion (unsigned char dirI2C, unsigned char *dis) 
 // Funcion para leer la distancia medida
 // Parametro dirI2C corresponde a la direccion I2C del sensor
 // Parametro dis proporciona la direccion de un array en el que devolver la medicion
 // Cada medicion 2 bytes
{
   unsigned int error = LDByteReadI2C_1(dirI2C, 2, dis, 2);
   
   return error;
}

