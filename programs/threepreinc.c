#include<stdio.h>
void main()
{
	int x=12;
	int ans;
	printf("Before value of X %d\n",x);

	ans =++x + ++x + ++x;
	printf("value of ans %d\n",ans);
	printf("value of x %d\n",x);
}


