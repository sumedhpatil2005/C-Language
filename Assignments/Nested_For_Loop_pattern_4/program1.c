#include<stdio.h>
void main(){
	int rows,temp;
	printf("Enter Number Of Rows");
	scanf("%d",&rows);
	temp = rows;
	int dop=1;
	for(int i = 1;i<=rows;i++){
		temp = i;
		for(int j=1;j<=rows;j++){
			printf("%d\t",temp );
			temp +=i;
			
		}

		printf("\n");
		
	}

}

