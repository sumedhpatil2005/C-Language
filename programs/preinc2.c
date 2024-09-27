#include<stdio.h>
int a=10;
void fun()
{
	int b=20;
	int ans;
	ans=++a + ++b;
	printf("%d\n",ans);

}
void main()
{
	printf("%d\n",a);
	fun();
	printf("%d\n",a);
}

