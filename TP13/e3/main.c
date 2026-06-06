#include <stdio.h>
#include "mensajes.h"
#include "display.h"


int main (void){
	int ed = get_edad();
	char* nom = get_nombre();
	
	saludo();
	nombre(nom);
	edad(ed);
	
	printf(MENSAJE);
	
return 0;
}

int get_edad(void){
	int edad;
	printf("Ingrese su edad: ");
	scanf(" %d", &edad);
	return edad;
}

char* get_nombre(void){

	static char nombre[100];
	printf("Ingrese su nombre: ");
	scanf(" %s", nombre);
	return nombre;
	
}
