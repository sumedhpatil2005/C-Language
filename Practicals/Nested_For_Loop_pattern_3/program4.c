#include<stdio.h>
void main(){
	int rows,num;
	printf("Enter The Number of rows");
	scanf("%d",&rows);
        num=1;
	for(int i = 1;i<=rows;i++){
		for(int j=1;j<=rows;j++){
			printf("%d\t",i*i);
		}
		
		printf("\n");
		
	}
}

