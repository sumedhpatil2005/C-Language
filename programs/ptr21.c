#include<stdio.h>
void main()
{
	int x=10;
	
	int *ptr=&x;

	void *vptr=&x;

	printf("%p\n",ptr);

	printf("%p\n",vptr);

	printf("%d\n",*ptr);
 
	printf("%d\n",*vptr);

}

