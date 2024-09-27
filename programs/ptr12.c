#include<stdio.h>
void main()
{
	int arr1[5]={1,2,3,4,5,6};

	int *ptr1=&arr1[1];

	printf("%d\n",*ptr1);
}

