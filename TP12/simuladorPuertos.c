#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "simuladorPuertos.h"
/////////////////////////////////////////

static uint8_t * getPuertoA(void);
static uint8_t * getPuertoB(void);
static uint16_t * getPuertoD(void);

/////////////////////////////////////////
static puertos_t contenido_puertos = {.x16b.D = 0x0000};

/////////////////////////////////////////
static uint8_t * getPuertoA(void){
	return &(contenido_puertos.x8b.A);
}

static uint8_t * getPuertoB(void){
	return (&contenido_puertos.x8b.B);
}

static uint16_t * getPuertoD(void){
	return &(contenido_puertos.x16b.D);
}
////////////////////////////////////////////
void imprimir_LEDS(puertoUsuario_t puertoUsado){

	switch (puertoUsado){
		case A:
			int i;
			printf("LEDS: \n");
			for(i=7; i>=0; i--){
				printf("%d",bitGet(puertoUsado,i));
			}
			printf("\n");
		break;
		
		case B:
			printf("LEDS: \n");
			for(i=7; i>=0; i--){
				printf("%d",bitGet(puertoUsado,i));
			}
			printf("\n");

		break;
		
		case D:
			
			printf("LEDS: \n");
			for(i=15; i>=0; i--){
				printf("%d",bitGet(puertoUsado,i));
			}
			printf("\n");

		break;
	}

}
////////////////////////////////////////////

void bitSet(puertoUsuario_t puertoUsado, int bit){
	switch (puertoUsado){
		case A:
			uint8_t * puertoA = getPuertoA();
			(*(puertoA))|= (1u<<(bit));
		break;
		
		case B:
			uint8_t * puertoB = getPuertoB();
			(*(puertoB))|= (1u<<(bit));
		break;
		
		case D:
			uint16_t * puertoD = getPuertoD();
			(*(puertoD))|= (1u<<(bit));
		break;
	}
}

void bitClr(puertoUsuario_t puertoUsado, int bit){
	switch (puertoUsado){
		case A:
			uint8_t * puertoA = getPuertoA();
			(*(puertoA)) &= ~(1u<<(bit));
		break;
		
		case B:
			uint8_t * puertoB = getPuertoB();
			(*(puertoB)) &= ~(1u<<(bit));
		break;
		
		case D:
			uint16_t * puertoD = getPuertoD();
			(*(puertoD)) &= ~(1u<<(bit));
		break;
	}
}

int bitGet(puertoUsuario_t puertoUsado, int bit){
	switch (puertoUsado){
		case A:
			uint8_t * puertoA = getPuertoA();
			return ((*(puertoA))>>(bit)) & (1u);
		break;
		
		case B:
			uint8_t * puertoB = getPuertoB();
			return ((*(puertoB))>>(bit)) & (1u);
		break;
		
		case D:
			uint16_t * puertoD = getPuertoD();
			return ((*(puertoD))>>(bit)) & (1u);
		break;
	}
	
	return 0;
}

void bitToggle(puertoUsuario_t puertoUsado, int bit){
	switch (puertoUsado){
		case A:
			uint8_t * puertoA = getPuertoA();
			(*(puertoA)) ^= (1u<<(bit));
		break;
		
		case B:
			uint8_t * puertoB = getPuertoB();
			(*(puertoB)) ^= (1u<<(bit));
		break;
		
		case D:
			uint16_t * puertoD = getPuertoD();
			(*(puertoD)) ^= (1u<<(bit));
		break;
	}
}

void maskOn(puertoUsuario_t puertoUsado, int mask){
	switch (puertoUsado){
		case A:
			uint8_t * puertoA = getPuertoA();
			(*(puertoA)) |= (mask);
		break;
		
		case B:
			uint8_t * puertoB = getPuertoB();
			(*(puertoB)) |= (mask);
		break;
		
		case D:
			uint16_t * puertoD = getPuertoD();
			(*(puertoD)) |= (mask);
		break;
	}
}

void maskOff(puertoUsuario_t puertoUsado, int mask){
	switch (puertoUsado){
		case A:
			uint8_t * puertoA = getPuertoA();
			(*(puertoA))^=((*(puertoA))&(mask));
		break;
		
		case B:
			uint8_t * puertoB = getPuertoB();
			(*(puertoB))^=((*(puertoB))&(mask));
		break;
		
		case D:
			uint16_t * puertoD = getPuertoD();
			(*(puertoD))^=((*(puertoD))&(mask));
		break;
	}
}

void maskToggle(puertoUsuario_t puertoUsado, int mask){
	switch (puertoUsado){
		case A:
			uint8_t * puertoA = getPuertoA();
			(*(puertoA)) ^= (mask);
		break;
		
		case B:
			uint8_t * puertoB = getPuertoB();
			(*(puertoB)) ^= (mask);
		break;
		
		case D:
			uint16_t * puertoD = getPuertoD();
			(*(puertoD)) ^= (mask);
		break;
	}
}

