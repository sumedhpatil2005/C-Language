#include<stdio.h>
void main()
{
	int money;
	printf("Enter your Pocket Money:\n");
	scanf("%d",&money);

	if(money>=2500)
	{
		printf("5star");
	}
	else if(money>=2000)
	{
		printf("3star");
	}
	else if(money>=1500)
	{
		printf("2 star");
	}
	else if(money>=1000)
	{
		printf("1 star");
	}
	else
	{
		printf("sit home");
	}

}


