#include<stdio.h>
void main(){
	int num;
	printf("Enter Number ");
	scanf("%d",&num);
	if(num%3==0 && num%7==0){
		printf("Number is Divisible");
	}
	else{
		printf("Number is not divisible");
	}
}

