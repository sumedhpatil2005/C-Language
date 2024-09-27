#include<stdio.h>
void main()
{       int sum=0;
	int row,col;
	printf("enter rows and cols");
	scanf("%d%d",&row,&col);
	int arr[row][col];
	printf("Enter Elements ");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{

			scanf("%d",&arr[i][j]);
			sum=sum+arr[i][j];

		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}

printf("%d",sum);
}

