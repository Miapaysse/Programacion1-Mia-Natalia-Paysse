#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	srand(time(NULL));
 	int dado, i;
 	for (i=1 ; i<=5 ; ++i){
 	dado = rand()%6 + 1;
 	printf("%d\n", dado);
 	}
 	return 0;
}
