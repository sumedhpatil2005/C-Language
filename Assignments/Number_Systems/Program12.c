#include<stdio.h>
void main(){
	int num,temp,rem=0;
	printf("Enter a number");
	scanf("%d",&num);

	temp = num;

	while(num!=0){
	      rem = num % 10;

	      if(rem == 0){
		      printf("Number is Duck number");
	     		break;
	      }
			num = num/10;
	}
}

