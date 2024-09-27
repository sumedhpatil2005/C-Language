#include<stdio.h>
void main()
{
	int size;

	printf("Enter the size of array");
        scanf("%d",&size);
	
	int arr[size];
	printf("Enter elements of array");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	int search;

	printf("Enter which element you want to search");
	scanf("%d",&search);

	for(int i=0;i<size;i++)
	{
		if(arr[i]== search)
		{
			printf("Element found!!");
		}
		else
		{
			printf("Element Not found!!");
		}
	}
}

