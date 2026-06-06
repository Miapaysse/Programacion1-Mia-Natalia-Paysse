#include <stdio.h>
void fun1(void);
extern void fun2(void);
extern int var;
int main(void)
{
 	{
 		int var=2;
 		printf("S1: %d\n", var);
 		fun1();
 	}
 
 var++;
 printf("S2: %d\n", var);
 fun1();
 fun2();
 return(0);
}

void fun1(void)
{
 static int var=8;
 printf("S3: %d\n", ++var);
}
