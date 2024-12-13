#include<stdio.h>
void main(){
	int Age;
	printf("Enter your Age");
	scanf("%d",&Age);
	if(Age<18){
		printf("You can't vote ");
	}
	else{
		printf("you can vote");
	}
}

