#include<stdio.h>
void main(){
	int num;
	char c;
	printf("Enter the no. of rows");
	scanf("%d",&num);
        
	for(int i=1;i<=num;i++){
	        c = 64+num;
		for(int j=1;j<=num;j++){
			printf("%c\t",c);
			c--;
		}
		printf("\n");
	
	}
}

