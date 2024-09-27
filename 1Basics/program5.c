#include<stdio.h>
void main()
{
        int i;
	printf("enter 0 to start ");
	scanf("%d",&i);
	for(i;i<=127;i++)
	{
		printf("%d=%c\n",i,i);
	}
}
