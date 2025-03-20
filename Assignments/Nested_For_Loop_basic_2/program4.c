#include<stdio.h>
void main(){
	int row,num=1;
	printf("Enter no. of rows");
	scanf("%d",&row);
	for(int i=1;i<=row;i++){
		for(int j=1;j<=row;j++){
			printf("%d\t",num);
			num++;
		}
		printf("\n");
	}
}

