#include<stdio.h>
void main(){
	int row,num=0;
	printf("Enter the number of rows");
	scanf("%d",&row);

	for(int i=1;i<=row;i++){
		for(int j=1;j<=row;j++){
			num+=row;
			printf("%d\t",num);
		}
	printf("\n");
	}
}


