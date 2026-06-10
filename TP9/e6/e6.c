#include <stdlib.h>
#include<stdio.h>

#define ISLETTER(c) (  ( ('a'<=(c)) && ((c)<='z') )||( ('A'<=(c)) && ((c)<='Z') )  )
#define ISUPPER(c) (((c)>'A')&&((c)<'Z'))
#define SIZEL(x) (sizeof(*x))
#define SIZEARR(v) (sizeof(v)/SIZEL(v))

#define MAX_CARACTERES 20
#define CANT_ALUMNOS 8

typedef struct
{
	char nombre[MAX_CARACTERES];
	char apellido[MAX_CARACTERES];
	float promedio;
	
}alumno_t;

int alfabetico(char * s1 , char * s2);
int orden_alumnos(const void * p_alumno1 , const void * p_alumno2);
void imprimir_alumnos(alumno_t alumnos[], int cant_alumnos);

////////////////////////////////////////////////////////////
/*
alumno_t alumno1 = {"Mia", "Paysse", 7.4};
alumno_t alumno2 = {"Facundo", "Maletta", 8};
alumno_t alumno3 = {"Mia", "Aranda", 7.4};
alumno_t alumno4 = {"Mio", "Paysse", 7.4};
alumno_t alumno5 = {"Mia", "Paysse", 7.4};
*/

////////////////////////////////////////////////////////////

int main(void){

alumno_t alumnos[CANT_ALUMNOS]={
{"Facundo", "Maletta", 8},
{"Matias", "Areco", 7.4},
{"Miranda", "Plato", 8.5},
{"Mia", "Ar!nda", 8.55},
{"Mio", "Paysse", 7.4},
{"Mia", "Paysse", 7.4},
{"Julieta", "Perez", 10},
{"Mia", "Paysse", 7.4}
};

imprimir_alumnos(alumnos,CANT_ALUMNOS);

qsort(alumnos, SIZEARR(alumnos), SIZEL(alumnos), orden_alumnos);

printf("\n");

imprimir_alumnos(alumnos,CANT_ALUMNOS);


return 0;
}


////////////////////////////////////////////////////////////////////////////
int orden_alumnos(const void * p_alumno1 , const void * p_alumno2){
	
	alumno_t alumno1 = *((alumno_t *)p_alumno1);
	alumno_t alumno2 = *((alumno_t *)p_alumno2);

			if (alumno1.promedio != alumno2.promedio) { //Compara los promedios de dos alumnos cosecutivos
				if (alumno1.promedio < alumno2.promedio){
					return 1 ; // Si el siguiente es mayor, los intercambia 
				}
				else {
					return -1;
				}
				 
			}
			else if(alumno1.promedio == alumno2.promedio){


						if(alfabetico(alumno1.apellido, alumno2.apellido)){
							return alfabetico(alumno1.apellido, alumno2.apellido);
						}
						else if (alfabetico(alumno1.nombre, alumno2.nombre)){
						
							return alfabetico(alumno1.nombre, alumno2.nombre);
						
						}
						
						else{

							printf("\nATENCION, ALUMNO REPETIDO, Nombre: %s %s \n",alumno1.nombre, alumno1.apellido);
							return 1;
						}
						
				
			}
			
			printf("\nERROR con %s %s y %s %s \n ",alumno1.nombre, alumno1.apellido, alumno2.nombre, alumno2.apellido);
			return 0;
	

}

int alfabetico(char * s1 , char * s2){

int i;
	for(i=0;s1[i]!='\0'; i++){
		if (  ISLETTER(s1[i]) && ISLETTER(s2[i]) ){
			if(s1[i]!=s2[i]){
				return (s1[i]-s2[i]);
			}
		}
		
		else {
			
	        	printf("\nERROR, CARACTER INVÁLIDO EN ALGUNA DE ESTAS CADENAS: %s %s \n",s1,s2);
	        	return 0;
		}
	}
	
	return 0;

}

void imprimir_alumnos(alumno_t alumnos[], int cant_alumnos){
	int i;
	for (i=0; i<cant_alumnos; i++){
		printf("Alumno%d: Nombre: %s, Apellido: %s, Promedio: %.2f\n", i+1, alumnos[i].nombre, alumnos[i].apellido, alumnos[i].promedio);
	}
}

