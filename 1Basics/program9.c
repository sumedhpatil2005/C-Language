#include<stdio.h>
void main()
{
	int sum;

	for(int i =1;i<=20;i++)
	{
		if(i%2!=0)
		{
			printf("%d\n",i);
	                 sum =sum+i;
		}
		
	}
	printf("\n sum = %d ",sum);
	
}
