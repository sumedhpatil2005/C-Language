#include<stdio.h>
void main(){
	int rows;
	int temp=1;
	printf("Enter the number of rows:");
	scanf("%d",&rows);
	for(int i=1;i<=rows;i++){
		for(int j=1;j<=rows-i;j++){
			printf(" ");
		}
		temp=i;
		for(int j=1;j<=i;j++){
			printf("%d",temp);
			temp+=i;
		}
		printf("\n");
	}
}

