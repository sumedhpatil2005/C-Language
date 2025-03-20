#include<stdio.h>
void main(){
	int num1;
	int num2;

	printf("Enter the two numbbers");
	scanf("%d%d",&num1,&num2);

	if(num1<num2){
		printf("%d is greater among %d and %d",num2,num1,num2);
	}
	else
	{
		printf("%d is greater among %d and %d ",num1,num1,num2);
	}
}

