#include<stdio.h>
void main(){
	int input;
	printf("Enter the name you want table  of ");
	scanf("%d",&input);
	for(int i=1;i<=10;i++){
		printf("%d * %d = %d\n",input,i,i*input);
	}
}


