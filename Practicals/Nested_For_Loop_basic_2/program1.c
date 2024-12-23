#include<stdio.h>
void main(){
	int row;
	char ch=65;

	printf("Enter the no. of rows");
	scanf("%d",&row);
	for(int i=1;i<=row;i++){
		for(int j=1;j<=row;j++){
			printf("%c\t",ch);
			ch++;
		}
		printf("\n");
	}
}

