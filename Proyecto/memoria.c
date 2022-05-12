/*
 * Memoria
 * ==================
 * Autores:
 * Jon Moríñigo
 * Iker Fernández
 */

#include "p24HJ256GP610A.h"

unsigned char LCD_Pantalla[16][18] = {
    //0123456789ABCDEF
    ("- DSE 2021-22 --""\x0D\x0A"),
    ("Tiempo: --:--:- ""\x0D\x0A"),
    ("- INFO PIC24H --""\x0D\x0A"),
    ("Poten:      ----""\x0D\x0A"),
    ("Tempe:       ---""\x0D\x0A"),
    ("Joystick X: ----""\x0D\x0A"),
    ("Joystick Y: ----""\x0D\x0A"),
    ("Joystick Z: ----""\x0D\x0A"),
    ("Mini Joy X: ----""\x0D\x0A"),
    ("Mini Joy Y: ----""\x0D\x0A"),
    ("-- INFO BRAZO --""\x0D\x0A"),
    ("Servo 1:    ----""\x0D\x0A"),
    ("Servo 2:    ----""\x0D\x0A"),
    ("Servo 3:    ----""\x0D\x0A"),
    ("Servo 4:    ----""\x0D\x0A"),
    //("Servo 5:    ----""\x0D\x0A"),
    ("Distancia:   ---""\x0D\x0A")
};

