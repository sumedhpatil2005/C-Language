#include<stdio.h>
void main(){
	int rows;
	printf("Enter Number of Rows");
	scanf("%d",&rows);

	for(int  i = rows;i>=1;i--){
		for(int j = i;j>=1;j--){
			printf("%d",i);
		}
		printf("\n");
	}
}

