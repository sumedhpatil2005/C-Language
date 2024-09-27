#include<stdio.h>
void main(){
	int arr1[]={1,2,3,4,5,6};
	int x=10;
	char ch='A';

	printf("%d\n",x);
	printf("%c\n",ch);

	printf("%p\n",&x);
	printf("%p\n",&ch);

	printf("%d",arr1);
	printf("%p",&arr1);

}

