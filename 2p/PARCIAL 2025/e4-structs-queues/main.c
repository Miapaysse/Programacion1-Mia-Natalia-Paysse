#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int len;
	int first;
	int last;
	int *buff;
}queue_t;

queue_t * queue_create(int len);


int main(void){
	
	return 0;
}

queue_t * queue_create(int len){

if(len>0){
	int* fila = (int*) calloc(len,sizeof(int));
	if(fila==NULL)
	return fila;
	
	queue_t* qp = (queue_t *)malloc(sizeof(queue_t));
	if(qp==NULL){
		free(fila);
		return qp;
	}
	
	(*qp).len=len;
	(*qp).first=0;
	(*qp).last=0;
	(*qp).buff=fila;
	
	return qp;
}
else{
return NULL;
}
}
