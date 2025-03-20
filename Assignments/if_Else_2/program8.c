#include<stdio.h>
void main(){
	int marks;
	printf("Enter Marks");
	scanf("%d",&marks);
	if(marks>75 && marks<100){
		printf("You have got first class dist..");
	}
	else if(marks<75 && marks >65){
		printf("You have got firstclass ");
	}
	else if (marks <65 && marks >55){
		printf("You have Passed");
	}
	else if (marks <55 ){
		printf("you didn't make it");
	}
}

