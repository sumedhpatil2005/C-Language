#include<stdio.h>
void main(){
	int num,count=0;
	printf("Enter number");
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		if(num%i==0){
			count ++;
		}
	}
	if(count>=3){
		printf("\nthe number is composite\n");
	}
	else{
		printf("the number is not composite\n");
	}

}

