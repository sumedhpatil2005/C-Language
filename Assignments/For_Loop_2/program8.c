#include<stdio.h>
void main(){
	int val=66;
	for(int i =1;i<10;i++){
		if(i%2==0){
			printf("%c",val);
			val+=2;
		}
		else{
			printf("%d",i);
		}
	}
}

