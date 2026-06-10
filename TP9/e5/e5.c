#include <stdio.h>
#include <stdlib.h>
#define CANT_ELEM 3

int alfabetico(const void*a , const void*b);

int main(void){
char * arr[CANT_ELEM]={"Holo", "Hola", "Aia"};
int i;

for(i=0; i< CANT_ELEM; i++){
	printf("%s, ", arr[i]);
}
printf("\n");

qsort(arr, sizeof(arr)/sizeof(char*), sizeof(char*), alfabetico);

for(i=0; i< CANT_ELEM; i++){
	printf("%s, ", arr[i]);
}
printf("\n");

return 0;
}

int alfabetico(const void* a , const void* b){

char * s1 = *((char**)a);
char * s2 = *((char**)b);
int i;
for(i=0;s1[i]!='\0'; i++){
	if(s1[i]!=s2[i]){
		return (s1[i]-s2[i]);
	}
}
return 0;

}