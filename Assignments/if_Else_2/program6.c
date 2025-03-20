#include<stdio.h>
void main(){
	int marks;
	printf("Enter marks of student");
	scanf("%d",&marks);
	if(marks>85 && marks <100){
		printf("Suggested : Medical field");
	}
	else if(marks<85 && marks >75){
		printf("suggested: Engineering");
	}
	else if(marks<75){
		printf("suggested: Arts and commerce ");
	}
}

