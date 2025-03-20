#include<stdio.h>
void main(){
	int rows;
	printf("Enter the Number of rows");
	scanf("%d",&rows);
	int ch = 65;
	int temp = ch;
	if(rows%2==0){

	for(int i = rows;i>=1;i--){
		ch = temp;
		for(int j=i;j>=1;j--){
		if(j%2!=0){
		printf("%c\t",ch);
		}
		else{
		printf("%d\t",ch);
		}
		ch++;
		}
		temp++;
		

		printf("\n");
	}

	}
	else{
		        for(int i = rows;i>=1;i--){
                		ch = temp;
				for(int j=i;j>=1;j--){
                if(j%2==0){
                printf("%d\t",ch);
                }
                else{
                printf("%c\t",ch);
                }
		ch++;
                }
				temp++;
                printf("\n");
	    }

	}

}
