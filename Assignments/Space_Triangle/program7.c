#include<stdio.h>
void main(){
	int rows;
	printf("Enter the No. of Rows:");
	scanf("%d",&rows);
	int temp=rows;
	for(int i=1;i<=rows;i++){
		for(int j=1;j<=i;j++){
			printf(" ");
		}
		for(int j=1;j<=rows-i+1;j++){
			printf("%d",temp);
		}
		temp--;
		printf("\n");
	}
}


