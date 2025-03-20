#include<stdio.h>
void main(){
	int rows,num=1;
	printf("Enter number of rows");
	scanf("%d",&rows);
	
	for(int i =1;i<=rows;i++){
		for(int j=1;j<=rows;j++){
			printf("%d\t",num);
			num++;
		}
		printf("\n");
	}
}

