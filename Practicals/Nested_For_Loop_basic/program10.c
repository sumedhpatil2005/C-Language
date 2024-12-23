#include<stdio.h>
void main(){
int rows;
char c;
printf("Enter the number of rows");
scanf("%d",&rows);


for(int i=1;i<=rows;i++){
        c =65;
	for(int j=1;j<=rows;j++){
		printf("%c1\t",c);
                 c++;
	}

     printf("\n");
}
}

