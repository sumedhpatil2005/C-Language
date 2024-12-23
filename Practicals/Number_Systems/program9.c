#include<stdio.h>
void main(){
        int num;

        int sum=0;
        int num2=0;
        printf("Enter number::");
        scanf("%d",&num);
         int num1=num;
        for(int i=1;i<num;i++){
                if(num%1==0){
                     sum = sum*10+i;
                }
        }
        while(num2!=0){
         sum += num2%10;
        }
        if(sum = num1){
                printf("number is strong number");
        }
        else{
                printf("number is not strong number");
        }
}


