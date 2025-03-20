
#include<stdio.h>
void main(){
	int row;
	printf("Enter no. of rows");
	scanf("%d",&row);
	for(int i=1;i<=row;i++){
                if(i%2==0){
		for(int j=1;j<=row;j++){
		    printf("%d\t",j);
		
		}
		printf("\n");
		}
		else{
			for(int j=row;j>=1;j--){
				printf("%d\t",j);
		}
			printf("\n");

		}
	}
	
	}


