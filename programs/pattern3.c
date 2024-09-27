#include<stdio.h>
void main()
{
	char ch='A';
	for(int i=0;i<=3;i++)
	{
		for(int j=0;j<=3;j++)
		{
			printf("%c",ch);
		        ch++;
		}
		printf("\n");
	}
}

