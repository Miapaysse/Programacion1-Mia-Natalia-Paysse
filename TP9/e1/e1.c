#include <stdio.h>
#include <stdint.h>

typedef struct
{
	char nombre[20];
	char apellido[20];
	float notaPromedio;
}alumno_t;

void swap(alumno_t * p_alumno1, alumno_t * p_alumno2);

//////////////////////////////////////////////////////


int main (void){
alumno_t alumno1 = {"Mia", "Paysse", 7.4};
alumno_t alumno2 = {"Facundo", "Maletta", 8};

alumno_t * p_alumno1  = &(alumno1);
alumno_t * p_alumno2  = &(alumno2);

printf("Alumno1: Nombre: %s, Apellido: %s, Promedio: %.2f\n", alumno1.nombre, alumno1.apellido, alumno1.notaPromedio);	
printf("Alumno2: Nombre: %s, Apellido: %s, Promedio: %.2f\n", alumno2.nombre, alumno2.apellido, alumno2.notaPromedio);

swap(p_alumno1, p_alumno2);

printf("Alumno1: Nombre: %s, Apellido: %s, Promedio: %.2f\n", alumno1.nombre, alumno1.apellido, alumno1.notaPromedio);
printf("Alumno2: Nombre: %s, Apellido: %s, Promedio: %.2f\n", alumno2.nombre, alumno2.apellido, alumno2.notaPromedio);

	return 0;
}

/////////////////////////////////////////////////////////
void swap(alumno_t * p_alumno1, alumno_t * p_alumno2){

	alumno_t aux;
	
	aux = *(p_alumno1);
	*(p_alumno1) = *(p_alumno2);
	*(p_alumno2) = aux;
	
}
