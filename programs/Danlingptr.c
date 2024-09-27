#include<stdio.h>
int a=10;
int h;
int *ptr=0;

void fun()
{
	int x=30;
	printf("%d\n",a);
	printf("%d\n",h);

	ptr=&x;

	printf("%p\n",ptr);
	printf("%d\n",*ptr);

}
void main()
{
	int y=10;
	printf("%d\n",a);
	printf("%d\n",h);

	fun();

	printf("%dc\n",*ptr);

}
