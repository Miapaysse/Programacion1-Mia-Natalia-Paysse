#include <stdio.h>
#define N 5
void flip_arr(double arr[], int n);
void print_array(double arr[], int n);

int main (void){
double arr[N]= {1, 2, 3, 4, 5};
print_array(arr, N);
flip_arr(arr, N);
print_array(arr, N);

return 0;
}

void flip_arr(double arr[], int n){
	if (n>0){
		if(n==1){//Caso base: un solo elemento
			return;
		}
		
		else{//Paso indusctivo
			double * p1 = arr;
			double * p2 = p1 + n -1;
			
			double aux = *p1;
			*p1=*p2;
			*p2=aux;
	
			flip_arr(p1+1, n-2);
			return;
		}
	}
}

void print_array(double arr[], int n){
	int i;
	for(i=0;i<n;i++){
	
		printf("%.2f ", arr[i]);

	}
	
	printf("\n");
}