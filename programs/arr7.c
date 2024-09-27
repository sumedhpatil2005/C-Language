#include<stdio.h>
void main()
{
	int sum=0;
	int arr[5];
	printf("enter array Elements");
	for(int i=0;i<5;i++)
	{

	scanf("%d",&arr[i]);
	}
	for(int i=0;i<5;i++)
	{
	 sum=sum+arr[i];
	}
	printf("%d",sum);
}

