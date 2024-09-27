#include<stdio.h>
void main()
{
	int a;
	int product=1;
	printf("enter 10 numbers");
	for(int i=1;i<=10;i++)
	{
		scanf("%d",&a);
		product=product*a;
	}
	printf("product of first ten numbers is %d",product);
}

