#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <time.h>   


int main (void){
  int len, i;
  float * numeros;
  float n,m;
  char c;
  /* initialize random seed: */
  srand (time(NULL));
  
  printf ("Cuantos numeros random queres guardar?\n");
  scanf ("%d", &len);
  numeros = (float*) calloc (len+1, sizeof(int));
  
  printf ("Entre que rango n-m queres que varíen estos numeros?\n");
  scanf ("%f %c %f", &m,&c,&n);
  
  if (numeros!=NULL) { //Valido el heap
  	for(i=0; i<len; i++){
  		numeros[i] = n + ((float)rand() / (float)RAND_MAX)*(m-n); 
	}
	
    	printf ("Numeros:\n");
    	for (i=0; i<len; i++){
        	printf("%.2f, ", numeros[i]);
    	}
    	printf ("\n");
    
    	free (numeros);
  }
  
return 0;

}
