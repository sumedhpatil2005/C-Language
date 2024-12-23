#include<stdio.h>
void main(){
        char ch=65;
	char CH=97;
	int row;
	printf("Enter no. of rows");
	scanf("%d",&row);
	for(int i=1;i<=row;i++){
		char ch=65;
        char CH=97;

		for(int j=1;j<=row;j++){
			if(i%2==0){
				printf("%c\t",CH);
   				CH++;
			}
			else{
				printf("%c\t",ch);
			        ch++;
			}
		
		}
		printf("\n");
	}
}
