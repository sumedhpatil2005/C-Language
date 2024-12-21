#include<stdio.h>
void main(){
	int num;
	printf("Enter a number");
	scanf("%d",&num);
	if(num%2==0){
		for(int i=1;i<=10;i++){
			printf("%d\n",i*num);
		}
	}
	else{
		for(int i=10;i>=1;i--){
			printf("%d\n",i*num);
		}
	}
}

