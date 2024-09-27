#include<stdio.h>
void main(){
	int arr[5];
	for(int i=1;i<=5;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=5;i++)
	{
		if(arr[i]%2==0)
		{
			printf("%d\n",arr[i]);
		}
	}
}

