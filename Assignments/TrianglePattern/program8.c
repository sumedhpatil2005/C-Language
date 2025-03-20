#include<stdio.h>
void main(){
	int rows;
	printf("Enter No. of Rows");
	scanf("%d",&rows);
	int num=1,temp=1;


	for(int i =rows;i>=1;i--){
		num = temp;
		for(int j = i;j>=1;j--){
			printf("%d\t",num);
			num++;
			
		}
		temp++;
		
		

		printf("\n");
	}
}

