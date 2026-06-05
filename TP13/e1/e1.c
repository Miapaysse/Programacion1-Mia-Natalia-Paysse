#include <stdio.h>
#include <stdlib.h>
#define N 2

int main(void){
	double ** mat;
	int i,j;
	mat=(double**) calloc(N,sizeof(double*)); //reservamos un espacio para un arreglo de N punteros a double
	if(mat==NULL){
		printf("ERROR");
		return 1;	
	}
		
		for(i=0;i<N;i++){
			mat[i]=(double*) calloc(N,sizeof(double));
				
			if(mat[i]==NULL){
				printf("ERROR");
				return 1;
			}
			
		}
		
		for(i=0;i<N;i++){
				mat[i][i]=1;
		}
		
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				printf("%.0f ",mat[i][j]);
				
			}
			printf("\n");
		}
		
		for(i=0;i<N;i++){
			free(mat[i]);
		}
		free(mat);

return 0;
}