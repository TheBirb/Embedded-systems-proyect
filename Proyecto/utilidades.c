/*
Komentarioak!!!
Egileak eta data!!!
*/

#include "p24HJ256GP610A.h"
//#include "ADC1.h"

// Funcion para obtener los caracteres de un valor de dos digitos (<100)
// Parametros:
// val, valor numerico del que se quieren obtener los caracteres ASCII
// dir, direccion a partir de la cual queremos que la funcion devuelva los codigos ASCII
// En dir estara el caracter de mas peso y en dir+1 el de menos peso


unsigned char tabla_carac[16]="0123456789";
void conversion_tiempo (unsigned char *dir, unsigned int val)
{
    unsigned char dig;
    if (val>99) {
        while(1);    
    } else {
        dig=val/10;
        dig=tabla_carac[dig];
        *dir=dig;
        dir++;
        dig=val%10;
        dig=tabla_carac[dig];
        *dir=dig;
    }
}

void imprimir_decimal(unsigned char *dir, unsigned int val, unsigned int n_dig){
    unsigned char dig;
    unsigned int i=0;
    while(i<n_dig){
        dig = val %10;
        dir[(n_dig-1)-i]=tabla_carac[dig];
        val = val /10;
        i++;
    }
}
//Función para pasar un numero de decima a hexadecimal 
void dec_a_hex(unsigned int dec, unsigned char *hex,unsigned int longitud) {
    
	unsigned int j=0, conv,remainder;
    conv = dec;

    while (conv != 0)
    {
        remainder = conv % 16;
        if (remainder < 10)
            hex[j++] = 48 + remainder;
        else
            hex[j++] = 55 + remainder;
        conv = conv / 16;
    }
    int i =j;
    while(i<sizeof(unsigned char)*longitud){
        hex[i]='0';
        i++;
    }
}

unsigned int calcular_distancia(unsigned char *vec){
    unsigned int dist =0;
    dist = vec[0];
    dist <<= 8;
    dist |= vec[1];
    
    return dist;
}

//Función para calcular medias de las muestras analogicas
unsigned int calcular_media(unsigned char *vec){
    int i;
    unsigned int media=0, resultado=0;
    
    for (i=0; i < 8; i++){
        media += vec[i];
    }
    
    resultado = media/8;
    return resultado;
}