#include <stdio.h>
#include <stdlib.h>

#define ISLETTER(c) (  ( (c)>='a' && (c)<='z' ) || ( (c)>='A' && (c)<='Z' ) )

int compLetras(const void* p1, const void* p2);

int main(int argc, char* argv[]){
	int i;
	qsort(argv+1, argc-1, sizeof(char*), compLetras);
	for(i=1; i<argc; i++){
		printf("%s ", argv[i]);
	}
	printf("\n");

return 0;
}

int compLetras(const void* p1, const void* p2){
	char* a1 = *(char**)p1;
	char* a2 = *(char**)p2;
	
	int i, letras1=0, letras2=0;
	
	for(i=0;a1[i]!='\0';i++){
		if(ISLETTER(a1[i])){
			letras1++;
		}
	}
	
	for(i=0;a2[i]!='\0';i++){
		if(ISLETTER(a2[i])){
			letras2++;
		}
	}
	
	return letras1-letras2;
}