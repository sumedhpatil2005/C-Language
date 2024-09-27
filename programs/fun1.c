#include<stdio.h>
int a=10;
void fun()
{
	int x=20;
	printf("in fun function\n");
}
void main()
{
	int y=30;
	printf("In main function\n");
        fun();
	printf("End Main Function\n");
}


