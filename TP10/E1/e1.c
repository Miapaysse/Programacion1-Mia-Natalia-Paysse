/*
*1. Escribir un programa que dado un número ingresado por el usuario, cree un arreglo
que guarde exactamente esa cantidad de elementos enteros utilizando malloc o
calloc, reciba del usuario esa cantidad de números en el arreglo creado, y luego los
imprima.
*/

#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */

int main (void)
{
  int len, i;
  int * arr;

  printf ("Cuantos elementos queres guardar?\n");
  scanf ("%d", &len);
  arr = (int*) calloc (len, sizeof(int));
  if (arr!=NULL) { //Valido el heap
  
    printf ("Arreglo:\n");
    for (i=0; i<len; i++){
        printf("%d, ", arr[i]);
    }
    printf ("\n");
    
    printf ("Indique elementos a guardar:\n");
    for (i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }
    
    printf ("Arreglo:\n");
    
    for (i=0; i<len; i++){
        printf("%d, ", arr[i]);
    }
    printf ("\n");
    
    free (arr);
  }
  return 0;
}
