#include <stdio.h>
int main(void)
{
char a = 'h';
void *p;
p = &a;
//-----------

//OPCION1
/*char *paux = (char*)p;
printf("a: %c\n", *paux);
*/

//OPCION2 
//printf("a: %c\n", *((char*)p));

return 0;
}
