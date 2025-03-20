#include<stdio.h>
void main(){
	int temp=1,num,row;
	printf("Enter the No. of Rows:");
	scanf("%d",&row);
	
	for(int i=1;i<=row;i++){
		num=temp;
		for(int j=1;j<=row;j++){
		
			printf("%d\t",num);
			num+=temp;
		}
		temp+=row;
		printf("\n");
	}
}

