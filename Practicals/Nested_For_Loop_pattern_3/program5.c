#include<stdio.h>
void main(){
	int rows;
	printf("Enter the Number of rows");
	scanf("%d",&rows);
	for(int i =1;i<=rows;i++){
		for(int j=1;j<=rows;j++){
			if(j%2!=0){
				printf("%d\t",i*i);
			}
			else{
				printf("%d\t",i*i*i);
			}
		}
		printf("\n");
	}
}
