#include<stdio.h>
void main(){
	int rows;
	printf("Enter No. of Rows:");
	scanf("%d",&rows);
       int temp=rows;
	for(int i=1;i<=rows;i++){
		for(int j=1;j<=rows-i;j++){
			printf(" ");

		}
		temp=rows;
		for(int j=1;j<=i;j++){
			printf("%d",temp);
			temp--;

		}
		printf("\n");
	}
}

