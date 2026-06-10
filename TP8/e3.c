#include <stdio.h>
int main(void)
{
int a = 5;
void *p = &a;
void **pp = &p;


printf("pp / &p: %p\n", pp);
printf("*pp  / &a: %p\n", (void*)(*pp));
printf("**pp / a: %d", *((int*)((void*)(*pp))));
return 0;
}