#include<stdio.h>
void main()
{
	char c;
	printf("Enter A");
	scanf("%c",&c);
	for(int i=1;i<=10;i++)
	{
		printf("%c\n",c);
		c++;
	}
}
