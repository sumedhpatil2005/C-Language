#include<stdio.h>
void main(){
	int rows;
	printf("Enter your number");
	scanf("%d",&rows);

	for(int i = 1 ; i<=rows;i++){
		int num = rows;
		for(int j = 1;j<=i;j++){
			printf("%d\t",num);
			num--;
		}
		printf("\n");
	}
}

