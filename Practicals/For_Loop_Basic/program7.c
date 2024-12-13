#include<stdio.h>
void main(){
	int num;
	int count=0;
	printf("Enter the value...foreg- 10");
	scanf("%d",&num);

	for(int i=2;i<=num;i++){
		if(num%i==0){
                       count++;
		}
	}
	printf("%d",count);
}

