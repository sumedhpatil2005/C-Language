#include<stdio.h>
void main(){
	int rows;
	int num=1;
	printf("Enter No. of rows");
	scanf("%d",&rows);

	for(int i =1;i<=rows;i++){
		num = i;
		for(int j=1;j<=i;j++){
			
			printf("%d",num);
			num = num+i;
		}
		printf("\n");
	}
}

