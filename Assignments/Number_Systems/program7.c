#include<stdio.h>
void main(){
	int num;
	int rev=0;
	printf("Enter number");
	scanf("%d",&num);
         int ip_num = num;
	while(num!=0){
	int remainder = num%10;
	rev = rev*10+remainder;
	num/=10;
	}
	if(rev == ip_num){
		printf("the number is palindrome");
	}
	else{
		printf("the number is not palindrome");
	}
}

