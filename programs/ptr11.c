#include<stdio.h>
void main()
{
	char ch1='A';
	char ch2='B';

	char *ptr1=&ch1;

	printf("%c\n",*ptr1);
	printf("%p\n",ptr1);

 	printf("%p\n",(ptr1+'A'));
	printf("%p\n",*(ptr1+'A'));

}

