#include<stdio.h>
void main(){
	int num;
	printf("Enter Number ");
	scanf("%d",&num);

	if(num%7==0){
		printf("number is a multiple of 7");
	}
	else{
		printf("Number is not a multiple of 7");
	}
	if(num > 21){
		printf("Numer is greater than 21");
	}
	else{
		printf("Number is less than 21");
	}
}

