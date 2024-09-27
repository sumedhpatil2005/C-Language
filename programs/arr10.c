


//ERROR PROGRAM


#include<stdio.h>
void main()
{
	int arr[3];
	arr[0]=1;
	arr[1]=2;
	arr[2]=3;

	for(int i=0;i<3;i++);
	{
		printf("%d",arr[i]);
	}
	int arr2=arr;
	for(int i=0;i<3;i++)
	{
		printf("%d",arr2[i]);
	}
	
}

