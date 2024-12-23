#include<stdio.h>
void main(){
	int rows;
	char c ='A';
	printf("Enter no. of rows");
	scanf("%d",&rows);
	for(int i=1;i<=rows;i++){
		for(int j=1;j<=rows;j++){
			printf("%c\t",c);
		}
		printf("\n");
		c++;
	}
}

