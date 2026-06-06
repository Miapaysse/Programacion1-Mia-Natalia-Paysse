#include <stdio.h>
#include <stdlib.h>

const unsigned int N = 3;

void imprimir_matriz(double * mat, unsigned int n);
double* crear_matriz(unsigned int n);
//void liberar_matriz(double*mat);

int main(void){
	double* matriz = crear_matriz(N);
	if (matriz!=NULL){
		imprimir_matriz(matriz, N);
	
		//liberar_matriz(mat);
		free(matriz);
		return 0;
	}
	else{
	return 1;
	}
}

void imprimir_matriz(double * mat, unsigned int n){
	int i,j;
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
		
			printf("%.0f ", mat[i*n+j]);
		
		}
		
		printf("\n");
	}
		

}

double* crear_matriz(unsigned int n){
	double *mat;
	int i,j;
	mat=(double*) calloc(N,sizeof(double)*N);
	if (mat==NULL){
		printf("ERROR");
		return mat;
	}
		
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			
			if(i==j){
		
				mat[i*n+j]=1;
			}
		
		}
		
	}
	
	return mat;
}
/*
void liberar_matriz(double* mat){
	free(mat);
}
*/
