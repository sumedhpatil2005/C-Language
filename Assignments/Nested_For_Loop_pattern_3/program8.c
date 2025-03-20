#include<stdio.h>
void main(){
	int rows,num;
	printf("Enter The Number of Rows");
	scanf("%d",&rows);
        num = rows+63;
	for(int i =1;i<=rows;i++){
		   num = rows+63;
		for(int j=1;j<=rows;j++){
			if(i%2!=0){
				printf("%c\t",num+j);
			}
			else{
			printf("%c\t",1+num+rows);
			num--;
			}

		}
		printf("\n");
	
}
}

