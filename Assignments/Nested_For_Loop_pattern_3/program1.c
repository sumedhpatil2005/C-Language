#include<stdio.h>
void main(){
	int rows;
	printf("enter the Number of rows you want");
	scanf("%d",&rows);
	for(int i = 1;i<=rows;i++){
		for(int j = 1;j<=rows;j++){
			printf("%c%d\t",64+rows,rows);
		}
		printf("\n");
	}
}


