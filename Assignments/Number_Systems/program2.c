#include<stdio.h>
void main(){
	int num,fact=1;
	printf("Enter the number you want factorial of");
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
               fact = fact*i;
	       
	}
	printf("Factorial of %d is %d",num,fact);
}

