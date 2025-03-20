#include<stdio.h>
void main(){
	int start,end;
	printf("Enter the start value");
	scanf("%d",&start);
	printf("Enter the end value");
	scanf("%d",&end);
	for(int i =start ;i<=end;i++){
		if(i%2==0){
			printf("%d\n",i);
		}
	}
}

