#include<stdio.h>
void main()
{
	char arr[]={'a','b','c','d','e','f'};

	char *ptr=&arr[4];

	char *ptr1=&arr[5];

	printf("%c\n",*(ptr+2));

	printf("%c\n",*(ptr1+1));

}

