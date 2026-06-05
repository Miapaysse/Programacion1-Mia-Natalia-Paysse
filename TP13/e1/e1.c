#include <stdio.h>
#include <stdlib.h>
#define N 2

int main(void){
	double **mat;
	mat=(double**) calloc(N,8*N);
	if (mat!=NULL){
		int i;
		for(i=0;i<N;i++){
			mat[i][i]=1;
		}
		
		for(i=0;i<N;i++){
			for(i=0;i<N;i++){
				printf("%.2f ",mat[i][i]);
				
			}
			printf("\n");
		}
		
		
	}
	
	printf("ERROR");
	
	free(mat);

return 0;
}