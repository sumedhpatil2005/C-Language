#include<stdio.h>
void main(){
	char char1;
	printf("Enter the character");
	scanf("%c",&char1);
	if(             char1=='A' 
			&& char1=='a' 
			&& char1 =='e' 
			&& char1 =='E' 
			&& char1 =='i' 
			&& char1 =='I' 
			&& char1 =='o' 
			&& char1 =='O'
		        && char1 =='u'
		        && char1 =='U'
	  ){
	printf("The character is a Vowel");
	}
	else{
	printf("The character is a consonant");	
	}
}

