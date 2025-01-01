#include<stdio.h>
void main(){
	int rows;
	printf("Enter Number Of Rows");
	scanf("%d",&rows);
	int num =  rows*rows;	
	for(int i =1;i<=rows;i++){
		for(int j=1;j<=rows;j++){
			if(j%2!=0){
				printf("%c\t",64+num);
			}
			else{
				printf("%d\t",num);
			}
			num --;
		}
		printf("\n");
	}
}

