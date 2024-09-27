#include<stdio.h>
void main()
{
	int x=10;
	int *ptr=x;
	int *ptr1=&x;

	printf("%p\n",ptr);
	printf("%p\n",ptr1);
}
