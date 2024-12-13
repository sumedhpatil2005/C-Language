#include<stdio.h>
void main(){
	int num;
	printf("Enter Numbers");
	scanf("%d",&num);
	int num2;
	scanf("%d",&num2);

	if(num==num2){
		printf("Number are equal");
	}
	else if(num<num2){
		printf("Num is less than num2");
	}
	else{
		printf("Num is Greater than num2");
	}
}


