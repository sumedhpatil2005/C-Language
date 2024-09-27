#include<stdio.h>
void main()
{
	int arr[]={10,20,30,40,50,60};
	int *ptr1 =&(arr[0]);

	printf("%d\n",*ptr1);

	ptr1++;

	*ptr1=70;
	
	for(int i=0;i<6;i++)
	{
		printf("%d\n",arr[i]);
	}
}
