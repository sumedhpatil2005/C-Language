#include<stdio.h>
void main()
{
	int n;
	printf("enter 1 to get even numbers between 1 to 100");
	scanf("%d",&n);
	for(int i=1;i<=100;i++)
	{
		if(n%2==0)
		{
			printf("%d\n",n);
		}
		n++;
	}
}

