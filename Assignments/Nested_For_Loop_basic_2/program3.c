#include<stdio.h>
void main(){
	int row;
	char c;
	printf("Enter no. of rows");
	scanf("%d",&row);
	c =64+row;
	for(int i=1;i<=row;i++){
		
		for(int j=1;j<=row;j++){
			printf("%c\t",c);
		}
		c--;
		printf("\n");
	}
}

