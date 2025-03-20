#include<stdio.h>
void main(){
	int rows,temp=1;
	printf("Enter the Number of Rows:");
	scanf("%d",&rows);

	for(int i=1;i<=rows;i++){
		for(int j=1;j<=rows-i;j++){
			printf(" ");
		}
		temp=1;
		for(int j=1;j<=i;j++){
			printf("%d",temp);
			temp++;
		}
		printf("\n");
	}

}

	
