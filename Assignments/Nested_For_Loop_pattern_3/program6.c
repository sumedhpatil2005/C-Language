#include<stdio.h>
void main(){
	int num;
	printf("Enter Number of Rows");
	scanf("%d",&num);

	if(num%2!=0){
		for(int i=1;i<=num;i++){
			for(int j=1;j<=num;j++){
				printf("%c\t",64+j);
			}
			printf("\n");

		}
	}
	else{
		for(int i=1;i<=num;i++){
			for(int j =1;j<=num;j++){
				if(j%2!=0){
					printf("%d\t",64+j);
				}
				else{
					printf("%c\t",64+j);
				}
			}
			printf("\n");
		}
}
}

