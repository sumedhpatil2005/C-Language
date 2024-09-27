#include<stdio.h>

void main()
{
	int arr1[4]={1,2,3,4};

	int *ptr=&arr1[1];

	printf("%d\n",*ptr);

	printf("%d\n",*(ptr+1));
			}
