#include<stdio.h>
void main(){
	int row;
        printf("Enter no. of rows");
	scanf("%d",&row);

	for(int i=1;i<=row;i++){
		for(int j=1;j<=row;j++){
			if(j%2==0){
				printf("%c\t",64+j);
			}
			else{
				printf("%d\t",j);
			}
		}
		printf("\n");
	}
}

