#include<stdio.h>
void main(){
	int num;
	printf("Enter number");
	scanf("%d",&num);
	if(num%3==0){
		printf("Number is divisible by 3");
	}
	else{
		printf("Number is not divisible by 3");
	}
}

