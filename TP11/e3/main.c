#include <stdio.h>

int suma_digitos(int n1);

int main (void){

printf("%d\n", suma_digitos(10));

return 0;
}

int suma_digitos(int n1){
	if(n1/10==0){
		return n1%10;
	}
	else{	
 		return ((n1 % 10) + suma_digitos(n1 / 10)); //caso recursivo
 	}
}