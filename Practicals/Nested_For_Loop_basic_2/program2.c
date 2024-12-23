#include<stdio.h>
void main(){
	int row;
	printf("Enter the number of rows");
	scanf("%d",&row);
	for(int i=row;i>=1;i--){
		for(int j=row;j>=1;j--){
			printf("%d\t",j);
	               
		}
		printf("\n");
	}
}

