#include<stdio.h>
void main()
{
    int a;
    printf("Enter the first three digit number\n hint 100 :");
    scanf("%d",&a);
    for(int i=1;i<=10;i++)
    {
	    printf("%d\n",a);
	    a++;
    }
}

