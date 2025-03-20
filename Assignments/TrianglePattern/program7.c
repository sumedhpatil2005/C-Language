#include<stdio.h>
void main(){
	int rows,num=1;
	printf("Enter the Number of Rows");
	scanf("%d",&rows);
	for(int i = rows;i>=1;i--){
		num = 1;
		for(int j=i;j>=1;j--){
			
			printf("%d",num);
			num++;
		}
		printf("\n");
	}
}

