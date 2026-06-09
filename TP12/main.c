#include <stdlib.h>
#include <stdio.h>
#include "simuladorPuertos.h"
#define ISLETTER(c) (  ( ('a'<=(c)) && ((c)<='z') )||( ('A'<=(c)) && ((c)<='Z') )  )
#define ISNUMBER(c) ( ('0'<=(c)) && ((c)<='9') )

/*
Escribir un programa que utilice la librería escrita en el ejercicio 5 para simular que se
tienen 8 LEDs conectados al puerto A. Se debe usar la librería creada en el ejercicio 1,
y mostrar el estado de los LEDs en pantalla.
• Por teclado, el usuario ingresará el número (del 0 al 7) del LED que se desea prender, en tiempo real.
• Con la letra 't', todos los LEDs deben cambiar al estado opuesto (si están encendidos
apagarse y si están apagados encenderse).
• Con la letra 'c', se deberán apagar todos, y con 's', prender.
• Con la letra 'q', el programa finalizará.
*/

int main(void){

char accion;

puertoUsuario_t puertoA = A;

imprimir_LEDS(puertoA);

while (accion != 'q'){


	printf("Ingrese acción: \n");
	scanf(" %c", &accion);

	if (ISLETTER(accion)){

		switch(accion){
	
			case 't':
				maskToggle(puertoA,0xFF);
				mostrarLEDS(puertoA);
			break;
	
			case 'c':
				maskOff(puertoA, 0xFF);
				mostrarLEDS(puertoA);
			break;
	
			case 's':
				maskOn(puertoA, 0xFF);
				mostrarLEDS(puertoA);
			break;
			
			default:
			break;
	
		}
	
	}

	else if (ISNUMBER(accion) && (int)(accion-'0') < 8 && (int)(accion-'0') >= 0){
		bitSet(puertoA, (int)(accion-'0'));
		mostrarLEDS(puertoA);
	}
	
	else {
		printf("CARACTER INVÁLIDO\n");
	}

}

return 0;

}
