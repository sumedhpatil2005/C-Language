#include<stdio.h>
void main(){
	int num;
	printf("Enter the Number");
	scanf("%d",&num);
	if(num>1 && num<1000){
		printf("Number is within the range\n");
	}
	else{
		printf("Number is not within the range\n");
	}
}

