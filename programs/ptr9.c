#include<stdio.h>
void main()
{
	int x=10;
	

	int  *ptr1=&x;
int y=20;
	printf("%d",*ptr1);

	printf("%d",*(ptr1+1));

}

