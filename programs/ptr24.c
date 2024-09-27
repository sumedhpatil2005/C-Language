#include<stdio.h>
void main()
{
	int x=10;

	printf("%d\n",x);

	int *ptr=&x;

	printf("%d\n",*ptr);
	
	*ptr=30;

	printf("%d\n",*ptr);
	printf("%d\n",x);
}

