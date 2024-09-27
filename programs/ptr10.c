#include<stdio.h>
void main()
{
	char x='A';
	char y='B';
        char z='C';

	char *ptr1=&x;

	printf("%c\n",*ptr1);
	printf("%p\n",ptr1);

	printf("%c\n",*(ptr1+1));
	printf("%p\n",ptr1);

	printf("%c\n",*(ptr1+2));
	printf("%c\n",ptr1);



}

