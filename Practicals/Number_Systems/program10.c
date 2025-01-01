#include<stdio.h>
void main(){
	int num,sum=0;
	printf("Enter number");
	scanf("%d",&num);
	
	for(int i=1;i<=num/2;i++){
		if(num%i==0){
			sum+=i;
			}
		}
	if(sum<num){
		printf("Number is deficient");
		}
	else{
		printf("Number is not deficient");
		}
}	
