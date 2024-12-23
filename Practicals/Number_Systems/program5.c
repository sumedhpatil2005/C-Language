#include<stdio.h>
void main(){
	int count=0;
	int num;
	
	printf("Enter the number ");
	scanf("%d",&num);
        int number = num;
	while(num!=0){
		num/=10;
			count++;
		
	}
	printf("%d is the length of %d",count,number);
}

