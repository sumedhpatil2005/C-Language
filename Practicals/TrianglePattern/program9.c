#include<stdio.h>
void main(){
	int rows;
	printf("Enter the number of rows");
	scanf("%d",&rows);
	int num=rows;

	for(int i=rows;i>=1;i--){
		num = rows;
		for(int j=i;j>=1;j--){
			printf("%c\t",64+num);
			num--;
		}
		printf("\n");
	}

	
}
