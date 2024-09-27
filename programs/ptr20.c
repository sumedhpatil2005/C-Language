#include<stdio.h>
void main()
{
	char ch='A';
	int *iptr=&ch;
	char *cptr=&ch;

	printf("%d\n",*iptr);
	printf("%d\n",*cptr);
}

