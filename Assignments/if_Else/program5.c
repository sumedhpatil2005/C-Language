#include<stdio.h>
void main(){
	char char1;
	printf("Enter Charater");
	scanf("%c",&char1);

	if(char1>65 && char1<90){
		printf("Character is Upper case");
	}
	else{
		printf("Character is lowerCase");
	}

}

