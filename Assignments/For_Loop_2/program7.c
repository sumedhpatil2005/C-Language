#include<stdio.h>
void main(){
	int start,end;
	printf("Enter the start and end values");
	scanf("%d%d",&start,&end);
	for(int i=start;i<=end;i++){
		if(i%2!=0){
			printf("%d\n",i*i*i);
		}
	}
}


