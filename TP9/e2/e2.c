#include <stdio.h>
#include <stdint.h>
#define MAX_CARACTERES 20
#define ISUPPER(c) (((c)>'A')&&((c)<'Z'))

typedef struct
{
	char nombre[MAX_CARACTERES];
	char apellido[MAX_CARACTERES];
	float promedio;
}alumno_t;

void swap(alumno_t * p_alumno1, alumno_t * p_alumno2);
void bubblesort(alumno_t alumnos[], int cant_alumnos);
void imprimir_alumnos(alumno_t alumnos[], int cant_alumnos);
int comparar_alfabeticamente(alumno_t * alumno);
char toLower(char c);
//////////////////////////////////////////////////////


int main (void){
alumno_t alumno1 = {"Mia", "Paysse", 7.4};
alumno_t alumno2 = {"Facundo", "Maletta", 8};
alumno_t alumno3 = {"Mia", "Aranda", 7.4};
alumno_t alumno4 = {"Mio", "Paysse", 7.4};
alumno_t alumno5 = {"Mia", "Paysse", 7.4};

alumno_t alumnos[5]={alumno1, alumno2, alumno3, alumno4, alumno5};

imprimir_alumnos(alumnos,5);
bubblesort(alumnos, 5);
printf("\n");
imprimir_alumnos(alumnos,5);

return 0;
}

/////////////////////////////////////////////////////////
void swap(alumno_t * p_alumno1, alumno_t * p_alumno2){

	alumno_t aux;
	
	aux = *(p_alumno1);
	*(p_alumno1) = *(p_alumno2);
	*(p_alumno2) = aux;
	
}

void bubblesort(alumno_t alumnos[], int cant_alumnos){
	int i;


		for (i = 0; i < cant_alumnos-1; i++) { // Itera sobre el arreglo
			if (alumnos[i].promedio < alumnos[i+1].promedio) { //Compara los promedios de dos alumnos cosecutivos
				swap(alumnos+i, alumnos+i+1); // Si el anterior es mayor, los intercambia
			}
			else if(alumnos[i].promedio == alumnos[i+1].promedio){
				if(comparar_alfabeticamente(&(alumnos[i]))){
					swap(alumnos+i, alumnos+i+1);
				}
			}
		}

}

int comparar_alfabeticamente(alumno_t * alumno){
	int i,flag;
	//SI los apellidos son distintos comparo por apellido
		for(i=0; i<MAX_CARACTERES; i++){
			
			if (('a'<=toLower(((*(alumno)).apellido)[i]) && toLower(((*(alumno)).apellido)[i])<='z')&&('a'<=toLower(((*(alumno+1)).apellido)[i]) && toLower(((*(alumno+1)).apellido)[i])<='z')){
				if(((*(alumno)).apellido)[i] != ((*(alumno+1)).apellido)[i]){ //Si los apellidos son distintos
					if(toLower(((*(alumno)).apellido)[i])>toLower(((*(alumno+1)).apellido)[i])){
						flag = 1;
					}
				}
			}
		}
	
	if (flag == 0){//Los apellidos son iguales
		for(i=0; i<MAX_CARACTERES; i++){
			if (('a'<=toLower(((*(alumno)).nombre)[i]) && toLower(((*(alumno)).nombre)[i])<='z')&&('a'<=toLower(((*(alumno+1)).nombre)[i]) && toLower(((*(alumno+1)).nombre)[i])<='z')){
				if(((*(alumno)).nombre)[i] != ((*(alumno+1)).nombre)[i]){
					if(toLower(((*(alumno)).nombre)[i])>toLower(((*(alumno+1)).nombre)[i])){
					flag = 1;
					}
				}
			}
		}
	}
	
	
	if (flag == 0){
		printf("ERROR, ALUMNO REPETIDO, Nombre: %s %s",(*(alumno)).nombre, (*(alumno)).apellido );
		flag = 0;
	}
	
	return flag;
}

char toLower(char c){
char k;
	if (ISUPPER(c)){

		k = c - 'A' + 'a';
		return k;
	}

	else{
	return c;
	}

}

void imprimir_alumnos(alumno_t alumnos[], int cant_alumnos){
	int i;
	for (i=0; i<cant_alumnos; i++){
		printf("Alumno%d: Nombre: %s, Apellido: %s, Promedio: %.2f\n", i+1, alumnos[i].nombre, alumnos[i].apellido, alumnos[i].promedio);
	}
}
