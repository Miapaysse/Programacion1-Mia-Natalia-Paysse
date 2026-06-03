
/*
• El primer argumento debe ser un string que deberá mostrarse en pantalla.
• El usuario podrá agregar argumentos adicionales con variables a imprimir
en pantalla, que podrán ser enteros o caracteres.
• El especificador “%d” en el string, indicará un entero signado a imprimir en
decimal.
• El especificador “%x” en el string, indicará un entero no signado a imprimir
en hexadecimal.
• El especificador “%c” en el string, indicará un carácter a imprimir.
• No hace falta que los especificadores tengan sub-especificadores de ancho,
precisión o modificadores, solo se pide una implementación básica.
• Solo se podrá escribir a la pantalla usando la función putchar().
• No usar librerías para realizar la conversión de entero a string.
*/

#include <stdarg.h>
#include <stdio.h>
void imprimirHexa(unsigned int x);
void imprimirEntero(int n);
void my_printf(char* str, ...);

int main(void){
my_printf("Inicial: %c, Edad: %d, Legajo: %x", 'M', 19, 230);
return 0;
}


void my_printf(char* str, ...){
	va_list paramList;
	va_start(paramList, str);
	
	
	int i, cantParam;
	char c;
	for (i=0; (c = str[i])!='\0'; i++){
		if(c =='%'){
			cantParam++;
			switch(str[i+1]){
			
				case 'c':
					char c = (char)va_arg(paramList, int); //Me piden imprimir un char, por lo que le digo a va_arg q el parametro es entero y lo casteo a char 
					putchar(c);
				break;

				case 'd':
					int n = va_arg(paramList,int); //Me piden imprimir un entero, por lo que le digo a va_arg q el parametro es entero
					imprimirEntero(n);
				break;
				
				case 'x':
					int x = va_arg(paramList, unsigned int);
					imprimirHexa(x);
				break;
			
			}
			
			i+=2;
		}
		
		else{
			putchar(c);
		}
	}
	
}

void imprimirEntero(int n){
	if (n<0){
		putchar('-');
		imprimirEntero(-n);
	}

	if(n/10 == 0){
		
			putchar('0'+(n%10));
			return;
	}
	
	else{
		imprimirEntero(n/10);
		putchar('0'+n%10);
		
	}
	
}

void imprimirHexa(unsigned int x){

	char digitos[]="0123456789ABCDEF";
	
	if(x<16){
			putchar(digitos[x]);
			return;
	}
	
	else{
	
		imprimirHexa(x/16);
		putchar(digitos[x%16]);
	
	}

}