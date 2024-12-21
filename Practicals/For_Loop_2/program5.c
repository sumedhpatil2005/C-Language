#include<stdio.h>
void main(){
	int start ,end ,product=1;
	printf("enter the start and end range ");
	scanf("%d%d",&start,&end);
	for(int i=start;i<=end;i++){
		if(i%2==0){
			product=product*i;
		}
	}
	printf("your product is %d\n",product);
}

