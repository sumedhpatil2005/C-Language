#include<stdio.h>
void main()
{
	int x=7;
	int ans;

	printf("Before Increment value of x %d\n",x);
	ans=++x + ++x + ++x + ++x;
	printf("value of ans %d\n",ans);
	printf("value of x %d\n",x);
}

