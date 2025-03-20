#include<stdio.h>
void main(){
	int rows;
	printf("Enter the number of rows ");
	scanf("%d",&rows);
	int num=1;
	for(int i =1;i<=rows;i++){
		for(int j=1;j<=rows;j++){
			if(num<=9){
			printf("%d",num);
			num++;
			}
			else{
				num=1;
				printf("%d",num);
				num++;
			}

		}
		printf("\n");
	}
}

