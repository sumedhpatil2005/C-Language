#include<stdio.h>
void main()
{
	int arr1[3]={1,2,3};
	int arr2[3]={1,4,3};

	for(int i=0;i<3;i++)
	{
		if(arr1[i]==arr2[i])
		{
			printf("Arrays are equal");
		}
		else {
			printf("arrays are not equal");
		}
	}
}

