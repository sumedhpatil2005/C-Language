#include<stdio.h>
void main(){
	int num1=10;
	int num2=20;

	int temp;
	 temp=num1;
	num1=num2;
	num2=temp;

	printf("num1 %d",num1);
	printf("num2 %d",num2);

}
