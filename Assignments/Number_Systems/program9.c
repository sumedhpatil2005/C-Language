#include<stdio.h>
void main(){
	int num,sum=0,fact,temp,digit;

	printf("Enter a number");
	scanf("%d",&num);

	temp = num;

	while(temp >0){
		digit = temp%10;
		fact=1;
		for(int i=1;i<=digit;i++){
			fact *=i;
		}
		sum +=fact;
		temp/=10;
	}
	if(num == sum){
		printf("Number is strongnumber");
	}
	else{
		printf("number is not strong number");
	}
}



