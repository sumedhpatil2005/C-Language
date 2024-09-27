#include<stdio.h>
void main()
{	
	int arr[2][3];
	printf("enter elements");
	for(int rows=0;rows<2;rows++)
	{
		for(int cols=0;cols<3;cols++)
		{
			scanf("%d",&arr[rows][cols]);
		}
	}
	printf("elements entered        \n\n");
	for(int rows=0;rows<2;rows++)
	{
		for(int cols=0;cols<3;cols++)
		{
			printf("%d ",arr[rows][cols]);
		}
		printf("\n");
	}
	printf("the addresses are \n\n");
	for(int i=0;i<6;i++)
	{
		printf("%p\n",arr[i]);
	}
}

	
