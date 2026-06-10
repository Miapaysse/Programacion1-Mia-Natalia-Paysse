#include<stdio.h>
#include<stdlib.h>
#define CANT_ELEM 5
int asc (const void *pa, const void *pb);
int desc (const void *pa, const void *pb);

int main(void){

	int arr[CANT_ELEM]={1,2,0,4,-1};
	int i;
	for(i=0; i< CANT_ELEM; i++){
		printf("%d, ", arr[i]);
	}
	printf("\n");
	qsort( arr, (sizeof(arr)/sizeof(int)), (sizeof(int)), asc);
	for(i=0; i< CANT_ELEM; i++){
		printf("%d, ", arr[i]);
	}
	printf("\n");
	return 0;
}

/*  callback  */ 
int asc (const  void *pa, const void *pb) 
{ 
    return ( *(int*)pa - *(int*)pb ); 
} 


/*  callback  */ 
int desc (const void *pa, const void *pb) 
{ 
    return ( *(int*)pb - *(int*)pa ); 
} 