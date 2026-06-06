#include <stdio.h>
#include <stdlib.h>

const unsigned int N = 6;

void imprimir_matriz(double (* mat) [N], unsigned int n);
double* crear_matriz(unsigned int n);

int main(void){
	double* buffer_mat1 = crear_matriz(N);
	if (buffer_mat1!=NULL){
		double (* matriz) [N] = (double (*) [N])(buffer_mat1);
		imprimir_matriz(matriz, N);
		free(buffer_mat1);
		return 0;
	}
	else{
	return 1;
	}
}

void imprimir_matriz(double (* mat) [N], unsigned int n){
	int i,j;
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
		
			printf("%.0f ", mat[i][j]);
		
		}
		
		printf("\n");
	}
		

}

double* crear_matriz(unsigned int n){
	double *buffer;
	int i,j;
	buffer=(double*) calloc(N,sizeof(double)*N);
	if (buffer==NULL){
		printf("ERROR");
		return buffer;
	}
	/*
	//OPCION1: El buffer es un arreglo de n*n elementos, pero lo recorro como matriz
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			
			if(i==j){
		
				buffer[i*n+j]=1; 
			}
		
		}
		
	}
	*/
	
	//OPCION2: creo una matriz y casteo el buffer para poder recorrerlo como matriz
	
	double (* matriz) [N] = (double (*) [N])(buffer);
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			if(i==j){
				matriz[i][j]=1;
			}
		
		}
		
	}
	
		
	//
	
	
	return buffer;
}
