#include<stdio.h>
void main()
{
	int x=1;
	printf("start code\n");

	if(--x)
	{
		printf("In first if \n");
	}
	if(x++ || --x)
	{
		printf("In second if\n ");
	}
	printf("%d\n",x);
}

