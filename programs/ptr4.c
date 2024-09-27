#include<stdio.h>
void main()
{
	double x=35.5;
	char a='A';

	double *ptr1=&x;
	char *ptr2=&a;

	printf("%lf\n",x);
	printf("%c\n",a);
	printf("%lf\n",ptr1);
	printf("%c",ptr2);

}

