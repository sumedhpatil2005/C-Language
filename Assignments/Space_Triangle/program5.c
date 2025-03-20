#include<stdio.h>
void main(){
	int rows;
	printf("Enter the No. of Rows:");
	scanf("%d",&rows);

	for(int i=1;i<=rows;i++){
		for(int j=1;j<=rows-i;j++){
			printf(" ");
		}
		for(int j=1;j<=i;j++){
			printf("%d",rows*j);
		}
		printf("\n");
	}
}

