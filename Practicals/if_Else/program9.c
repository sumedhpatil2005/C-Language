#include<stdio.h>
void main(){
	int marks;
	printf("Enter marks");
	scanf("%d",&marks);
	if(marks >90 && marks <100){
		printf("you have scored A grade");
	}
	else if(marks >80 && marks <90){
		printf("you have scored B grade");
	}
	else if(marks >70 && marks <80){
		printf("you have scored c grade");
	}
	else if(marks >60 && marks <70){
		printf("you have scored D grade");
	}
	else{
		printf("score is ver y less");
	}
}

