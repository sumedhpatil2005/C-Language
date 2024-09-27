#include<stdio.h>
void main()
{
	int x=10;
	int ans;
	printf("Before Increment value of X %d\n",x);
	ans = x++ + ++x;
	printf("Value of ans %d\n",ans);
	printf("value of x %d\n",x);
}


