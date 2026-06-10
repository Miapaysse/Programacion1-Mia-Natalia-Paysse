#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "e9.h"
/////////////////////////////////////////

/////////////////////////////////////////
static puertos_t contenido_puertos = {.x16b.D = 0x0000};



/////////////////////////////////////////
uint8_t * getPuertoA(void){
	return &(contenido_puertos.x8b.A);
}

uint8_t * getPuertoB(void){
	return (&contenido_puertos.x8b.B);
}

uint16_t * getPuertoD(void){
	return &(contenido_puertos.x16b.D);
}

////////////////////////////////////////////

