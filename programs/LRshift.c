#include<stdio.h>
void main()
{
	int x=15;
	int y=78;
	int ans;

	ans = x<<3;
	printf("value of ans = %d\n",ans);
printf("%d",x);
	ans = y>>2;
	printf("value of ans = %d\n",ans);

	ans = x-- <<3;
	printf("value of ans = %d\n\n",ans);
	printf("......value of x = %d\n",x);

	ans = y>>2;

	printf("value of ans = %d\n",ans);

}


