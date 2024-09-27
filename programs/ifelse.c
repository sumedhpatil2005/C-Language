#include<stdio.h>
void main()
{
	int speed;
	printf("***WELCOME TO COP PORTAL***\n");
	printf("Enter The Speed Of Car");
	scanf("%d",&speed);
	if(speed>=10 &&speed<=120)
	{
		printf("\nfollowing the driving protocol\n");
	}
	else
	{
		printf("Not Following the driving protocol");
	}
}

