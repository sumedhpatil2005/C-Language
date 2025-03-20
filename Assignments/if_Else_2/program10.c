#include<stdio.h>
void main(){

	int choice;
	printf("The skills you know\n");
	printf("1. C language\n");
	printf("2. C language,Java\n");
	printf("3. C language,java,python\n");
	printf("4. C language,java,python,Flutter\n\n");

	printf("Enter the number skills you have\n");
        scanf("%d",&choice);
	if(choice==1){
		printf("3.2 LPA\n");
	}
	else if(choice ==2){
		printf("4.5 LPA\n");
	}
	else if(choice == 3){
		printf("6 LPA\n");
	}
	else if(choice ==4){
		printf("10 LPA\n");
	}
}


