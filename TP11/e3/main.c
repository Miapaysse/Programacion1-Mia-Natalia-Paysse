#include <stdio.h>

int suma_digitos(int n1);

int main (void){

return 0;
}

int suma_digitos(int n1){
 return ((n1 % 10) + digitos(n1 / 10)); //caso recursivo
}