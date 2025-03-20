#include<stdio.h>
void main(){
	int rows;
	printf("Enter the number of Rows:");
	scanf("%d",&rows);

	for(int i=1;i<=rows;i++){
		for(int j=1;j<=rows-i;j++){
			printf(" ");
		}
		int temp = 64+rows;
		for(int j=1;j<=i;j++){
			printf("%c",temp);
			temp--;
		}
		printf("\n");
	}
}

