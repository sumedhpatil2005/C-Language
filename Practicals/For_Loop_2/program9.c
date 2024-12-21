#include<stdio.h>
void main(){
	for(char ch='a';ch<='z';ch++){
		if(ch%2!=0){
			printf("%c ",ch);
		}
		else{
			printf("%c ",ch-32);
		}
	}
}

