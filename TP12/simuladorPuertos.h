#ifndef SIMULADORPUERTOS_H
#define SIMULADORPUERTOS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

//////////////////////////////////////////////////
/*
• bitSet: Dado un puerto y un número de bit, debe cambiar su estado a 1.
• bitClr: Dado un puerto y un número de bit, debe cambiar su estado a 0.
• bitGet: Dado un puerto y un número de bit, debe devolver su valor.
• bitToggle: Dado un puerto y un número de bit, debe cambiar al estado
opuesto en el que está (si está en 0 pasar a 1, y si está en 1 pasar a 0).

• maskOn: Dado un puerto y una máscara, debe prender todos aquellos bits que
estén prendidos en la máscara, sin cambiar el estado de los restantes. Por
ejemplo, dado el puerto A, que originalmente se encuentra en el estado 0x01,
al aplicarle la máscara 0x0A, el resultado será 0xB.

• maskOff: Dado un puerto y una máscara, debe apagar todos aquellos bits que
estén prendidos en la máscara, sin cambiar el estado de los restantes. Por
ejemplo, dado el puerto A, que originalmente se encuentra en el estado 0x0A,
al aplicarle la máscara 0x02, el resultado será 0x08.

• maskToggle: Dado un puerto y una máscara, debe cambiar el estado de todos
aquellos bits que estén prendidos en la máscara al opuesto, sin cambiar el
estado de los restantes. Por ejemplo, dado el puerto A, que originalmente se
encuentra en el estado 0x02, al aplicarle la máscara 0x03, el resultado será
0x01.

*/

typedef enum { A, B, D} puertoUsuario_t;

//void imprimir_LEDS(puertoUsuario_t puertoUsado);

void bitSet(puertoUsuario_t puertoUsado, int bit);
void bitClr(puertoUsuario_t puertoUsado, int bit);
int bitGet(puertoUsuario_t puertoUsado, int bit);
void bitToggle(puertoUsuario_t puertoUsado, int bit);

void maskOn(puertoUsuario_t puertoUsado, int mask);
void maskOff(puertoUsuario_t puertoUsado, int mask);
void maskToggle(puertoUsuario_t puertoUsado, int mask);

typedef struct{

uint8_t B;
uint8_t A;

}bytes_t;

typedef struct{

uint16_t D;

}word_t;


typedef union{
bytes_t x8b;
word_t x16b;
}puertos_t;


#endif