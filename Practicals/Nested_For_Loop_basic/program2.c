#include<stdio.h>
void main(){
	int rows;
	printf("enter no. of rows");
	scanf("%d",&rows);
	for(int i=1;i<=rows;i++){
		for(int j=1;j<=rows;j++){
			printf("1 ");
		}
		printf("\n");
	}
}

