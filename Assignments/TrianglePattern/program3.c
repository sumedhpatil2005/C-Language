#include<stdio.h>
void main(){
	int row,j,i;
	printf("Enter the number of rows");
	scanf("%d",&row);
       int ch = 63;
	for(int  i =1;i<=row;i++){
	
		for(int j = 1;j<=i;j++){
		printf("%c\t",ch+i+j);
	
		}

		
		printf("\n");
		
	}
}


