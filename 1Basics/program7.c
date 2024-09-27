#include<stdio.h>
void main()
{
	int x;
	printf("enter the value you want table of ");
	scanf("%d",&x);

	for(int i=1;i<=10;i++)
	{
		printf("%d\n",x*i);
	}
}
