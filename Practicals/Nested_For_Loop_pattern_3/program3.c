#include<stdio.h>
void main(){
	int rows;
	int num = 0;
	printf("Enter the number of rows ");
	scanf("%d",&rows);
	for(int i =1;i<=rows;i++){
		num = i;
		for(int j=1;j<=rows;j++){
			printf("%d\t",num);
			num++;
		}

		
			printf("\n");
	}
}

