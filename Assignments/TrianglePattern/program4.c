#include<stdio.h>
void main(){
	int rows;
	printf("Enter the No. of rows");
	scanf("%d",&rows);
	int num=rows;
	for(int i =1;i<=rows;i++){
		num =rows;
		for(int j=1;j<=i;j++){
			printf("%d",num);
			num +=rows;
		}
	printf("\n");
	}
}

