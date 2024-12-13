#include<stdio.h>
void main(){
	int angle1;
	int angle2;
	int angle3;

	printf("Enter the angle of triangle");
	scanf("%d%d%d",&angle1,&angle2,&angle3);
	int sum =angle1+angle2+angle3;
	if(sum==180){
		printf("The triangle is valid");
	}
	else{
		printf("the triangle is not valid");
	}
}

