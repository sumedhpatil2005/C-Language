#include<stdio.h>
void main(){
	int num;
	int count=0;
	printf("Enter the number to check whether it is prime or not : ");
        scanf("%d",&num);

        for(int i=1;i<=num;i++){
	 if(num%i==0){
	 count++;
		}
         }
if(count >2){
printf("number is not  prime");
}
else{
	printf("number is prime");
}
}

