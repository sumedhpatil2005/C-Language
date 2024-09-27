#include<stdio.h>
void main()
{
	int income;
	printf("enter the income");
	scanf("%d",&income);
	
	if(income>=0 && income<=500000)
	{
		printf(" your income is %d no need to pay tax\n",income);
	}
	if(income>=500000 && income<=1000000)
	{
		printf("your income is %d  need to pay 10percent tax %d \n",income,income*10/100);
	}
	if(income>=1000000 && income<=1500000)
	{
		printf("your income is %d need to pay  20percent tax  that is %d \n",income,income*20/100);
	}
}

