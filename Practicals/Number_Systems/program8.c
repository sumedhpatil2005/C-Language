#include<stdio.h>
void main(){
	int num,sum=0;
	printf("Enter the number ");
	scanf("%d",&num);

	for(int i=1;i<=num/2;i++){
		if(num%i==0){
			sum+=i;
		}
	}
	if(sum == num){
		printf("%d is a perfect number",num);
	}

	else {
		printf("%d is not a perfect number",num);
	}
}

