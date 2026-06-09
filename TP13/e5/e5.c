/*
5. Sea un programa de un menú de acceso mediante teclado, que se implementa con
una lookup table, permite vincular el ingreso de una tecla con una acción. Para el
mismo se pide:
a) Declarar una estructura, con su alias menu_t, que posea los campos tecla
(tipo char) y action (tipo puntero a función que no recibe nada y devuelve
un int).
b) Definir e inicializar un arreglo llamado menu_list de tipo menu_t de 2
elementos: el primer elemento es el carácter asterisco con la función
borrar y el segundo es el carácter numeral (hashtag) con la función
aceptar. Suponer que ya se encuentra escrita la definición y el prototipo
de ambas funciones. 
*/
#include <stdio.h>
#define ACEPTAR 1
#define BORRAR 2
#define ACCIONES 2

typedef struct{
	char tecla;
	int (*accion)(void);
}menu_t;


int aceptar(void){
	printf("ACEPTAR\n");
	return ACEPTAR;
}

int borrar(void){
	printf("BORRAR\n");
	return BORRAR;
}

int main(void){
menu_t acciones[ACCIONES];
char ingreso;
int i;
menu_t accion1 = {'*', borrar};
menu_t accion2 = {'#', aceptar};

acciones[0] = accion1;
acciones[1] = accion2;

printf("Menú de acciones: \n");
printf("BORRAR: * \n");
printf("ACEPTAR: # \n");
printf("Ingrese la accion que quiere ejecutar: ");
scanf(" %c", &ingreso);

for(i=0; i<ACCIONES; i++){
	if(ingreso==(acciones[i]).tecla){
		((acciones[i]).accion)();
	}
}


return 0;
}
