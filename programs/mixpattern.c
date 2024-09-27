#include<stdio.h>
void main()
{
	int row;
	printf("Enter rows");
	scanf("%d",&row);
	for(int i=1;i<=row;i++)
	{
		for(int sp=row-1;sp>=i;sp--)
		{
			printf("-");
		}
		for(int j=1;j<=1;j++)
		{
			printf("* ");
		}
                     printf("\n");
	}

}

