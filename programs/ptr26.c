#include<stdio.h>
void main()
{
	int size=0;
	int arr[size];
	printf("enter the size of array");
	scanf("%d",&size);
	printf("enter array elements");	
	for(int i=0;i<=size;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<=size;i++)
	{
		printf("%d\n",arr[i]);
		printf("%d\n",*(arr+i));
	}
}




