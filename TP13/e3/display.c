#include <stdio.h>
#include "display.h"

void saludo(void){
	printf("Hola soy ");
}

void nombre(char* nombre){
	printf("%s.", nombre);
}

void edad(int edad){
	printf("Tengo %d años.\n", edad);
}
