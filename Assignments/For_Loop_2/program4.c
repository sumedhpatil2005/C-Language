#include<stdio.h>
void main(){
	int start ,End ,sum=0;
	printf("Enter the Start and End Range\n");
	scanf("%d%d",&start,&End);
	for(int i=start;i<=End;i++){
		sum =sum+i;
	}
	printf("sum is %d\n",sum);
}

