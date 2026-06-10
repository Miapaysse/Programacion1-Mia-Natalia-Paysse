/*
 * main.c
 *
 *  Created on: May 9, 2026
 *      Author: progra
 */

#include <stdio.h>
#include "backend.h"

int main(int argc, char * argv[]){
	int i;
	char* parametros[argc];
	char* opciones[argc];
	char* valores[argc];

	for(i = 0; i < argc; i++) { //Setteo los arreglos en NULL
	        parametros[i] = NULL;
	        opciones[i] = NULL;
	        valores[i] = NULL;
	}

	funcion(argc,argv,parametros,opciones,valores); //Separo los argumentos del main segun los criterios incdicados

	//IMPRESION OPCIONES
	for(i=0;(i<argc && opciones[i]!=NULL);i++){
		printf("Opcion %d: %s: %s\n",i+1,opciones[i],valores[i]);
	}

	//IMPRESION PARÁMETROS
	for(i=0;(i<argc && parametros[i]!=NULL);i++){
		printf("Parámetro %d: %s \n",i+1,parametros[i]);
	}



return 0;
}
