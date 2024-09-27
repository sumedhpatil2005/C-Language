#include<stdio.h>
void main()
{
	int x=5;
	int y=6;
	int ans;

	ans =++x || ++y;
	printf("value of ans %d\n",ans);
	printf("value of x %d\n",x);
	printf("value of y %d\n",y);

	ans = ++x && y++;
	printf("value of ans %d\n",ans);
	printf("value of x %d\n",x);
	printf("value of y %d\n",y);

}

