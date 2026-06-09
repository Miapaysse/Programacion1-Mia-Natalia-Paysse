
#ifndef MANEJOLEDS_H
#define MANEJOLEDS_H

#include "simuladorPuertos.h"

typedef struct{
    char* value_path;
    char* direction_path;
    char* number;
    char value;
}pin_t;

int mostrarLED(pin_t pin);
void mostrarLEDS(puertoUsuario_t puertoUsado);


#endif