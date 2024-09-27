#include<stdio.h>
void main()
{
	char ch;
	printf("Are you Alive  : ");
	printf("Enter Y or N");
	scanf("%c",&ch);
	if(ch=='y' || ch=='Y')
	{
		printf("Nice");
	}
	else
	{
		printf("User Died");
	}
}


