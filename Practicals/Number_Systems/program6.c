#include<stdio.h>
void main(){
	int remainder=0;
	int num;
	int num2=0;
	printf("Enter the number");
	scanf("%d",&num);
         while(num!=0){ 
	remainder= num%10;
	 num2 = num2*10+remainder;
	 num/=10;
	 }
     
   	printf("%d",num2);
}
