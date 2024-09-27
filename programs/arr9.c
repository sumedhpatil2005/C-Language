#include<stdio.h>
void main()
{
	int flag;
	printf("Enter the size of array");
	int size;
	scanf("%d",&size);
	int arr[size];
	printf("etner array elements");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("enter search element");
	int search;
	scanf("%d",&search);
	
	for(int i=0;i<size;i++)
	{
		if(search==arr[i])
		{
			flag=1;
		}
		else{
			flag==0;
		}
	}
	if(flag==1)
	{
		printf("element found");
	}
	else{
		printf("element not found");
	}
}

