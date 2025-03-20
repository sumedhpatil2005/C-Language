#include<stdio.h>
void main(){
	int rows,temp=0;
	printf("Enter the no. of Rows:");
	scanf("%d",&rows);

	for(int i=1;i<=rows;i++){
		temp=i;
		for(int j=1;j<=rows;j++){
			printf("%d\t",temp);
			temp++;
			if(temp>rows){
				temp=1;
			}
		}
		printf("\n");
	}
}

