#include<stdio.h>
void main(){
	int x=19;
  

	printf("The first Answer =  %d",x++ + --x - x++);
	printf("The Second Answer = %d",--x + x-- - x++  + ++x);
}
