#include<stdio.h>
void main(){
	int rows;
	printf("Enter number of rows\n");
	scanf("%d",&rows);

	for(int i=1;i<=rows;i++){
		for(int j=1;j<=i;j++){
			printf("%d",j);
		}
		printf("\n");

	}
}


