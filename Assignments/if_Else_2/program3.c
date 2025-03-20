//leap year program
#include<stdio.h>
void main(){
	int year;
	printf("Enter the year");
	scanf("%d",&year);
	if(year%4==0){
		if(year%100){
			if(year%400){
				printf("It is a leap year");
			}
			else{
				printf("it is not a leap year");
			}

		}
		else{
			printf("it is not a leap yaer");
		}
	}
	else{
		printf("it is not a leap year");
	}
}

