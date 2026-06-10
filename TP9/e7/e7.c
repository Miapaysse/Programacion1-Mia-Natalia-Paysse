#include <stdio.h>
#include <stdlib.h>
/////////////////////////////////////
#define MAX_OPERATORS 15
/////////////////////////////////////
int add_operation(char operator, float (*funcion) (float, float));
float calc_res(float x, float y, char op);

float suma(float a, float b);
float resta(float a, float b);
float producto(float a, float b);
float cociente(float a, float b);
float potenciacion(float a, float b);
/////////////////////////////////////
char operators[MAX_OPERATORS];
float (* operations[MAX_OPERATORS])(float, float)={NULL};
/////////////////////////////////////
int main(void){
float x, y;
char op;
add_operation('+', &suma);
printf("Operacion a realizar:\n");
scanf("%f %c %f", &x, &op, &y);
printf("%.2f\n", calc_res(x, y, op));
add_operation('-', &resta);
add_operation('*', &producto);
printf("Operacion a realizar:\n");
scanf("%f %c %f", &x, &op, &y);
printf("%.2f\n", calc_res(x, y, op));
printf("Operacion a realizar:\n");
scanf("%f %c %f", &x, &op, &y);
printf("%.2f\n", calc_res(x, y, op));

return 0;
}
////////////////////////////////////
int add_operation(char operator, float (*funcion) (float, float)){
int i;
for (i=0; operations[i]!=NULL && i<MAX_OPERATORS; i++){}
operations[i]=funcion;
operators[i]=operator;

return 0;
	
}

float calc_res(float x, float y, char op){
int i;
for (i=0; operators[i]!=op && i<MAX_OPERATORS; i++){}
return (*(operations[i]))(x,y);

}


////OPERACIONES//////////////////////

float suma(float a, float b){
return a + b;
}

float resta(float a, float b){
return a - b;
}

float producto(float a, float b){
return a*b;
}

float cociente(float a, float b){
return a/b;
}

float potenciacion(float a, float b){
return a*a;
}

