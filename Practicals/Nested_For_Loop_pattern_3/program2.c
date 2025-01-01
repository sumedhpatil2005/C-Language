#include<stdio.h>
void main(){
	int rows;
	int ch = 64;
	printf("Enter the number of rows:");
	scanf("%d",&rows);

	for(int i =1;i<=rows;i++){
		ch=64;
		for(int j =1;j<=rows;j++){
			if(j%2!=0){
				printf("%c\t",ch+rows);
				ch --;
			}
			else{
				printf("%d\t",i);
			}
		}
		printf("\n");
	}
}

