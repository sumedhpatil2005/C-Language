#include<stdio.h>
void main()
{
	int x=1;
	int y=5;
	int ans;

	ans = --x || --x;
	printf("%d\n",ans);
	printf("%d\n",x);
	printf("%d\n",y);

	ans = ++x && --y;
	printf("%d\n",ans);
	printf("%d\n",x);
	printf("%d\n",y);

}

