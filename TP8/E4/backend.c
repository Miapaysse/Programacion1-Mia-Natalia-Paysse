/*
 *  Created on: May 9, 2026
*/
/***************************************************************************//**
  @file     +Nombre del archivo+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor +
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

// +Incluir el header propio (ej: #include "template.h")+
#include <stdio.h>
#include "backend.h"

/*******************************************************************************
 * CONSTANTS, MACROS, ENUMERATIONS, STRUCTURES AND TYPEDEFS
 ******************************************************************************/



/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static void falta_envido (int);+


/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static const int temperaturas_medias[4] = {23, 26, 24, 29};+


/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static int temperaturas_actuales[4];+


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
void funcion(int argc , char * argv[],char* parametros[], char* opciones[], char* valores[]){
	int i, cont_op=0, cont_par=0;

		for (i=1; i < argc; i++){ //Recorro argumentos del main

			if (argv[i][0]=='-'){ //Encontré una clave de opción
				cont_op++;
				opciones[cont_op-1]=&(argv[i][1]); // apunto el puntero de opciones al comienzo del nombre de la opcion

			}

			else if (argv[i-1][0]=='-'){ //Antes hubo una opcion, ahora es el valor

				valores[cont_op-1]=&(argv[i][0]); // apunto el puntero de valores al comienzo del valor de la opcion
			}

			else{
				cont_par++;
				parametros[cont_par-1]=&(argv[i][0]); // apunto el puntero de parametros al comienzo del parametro
			}



		}

}




/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/



/******************************************************************************/

