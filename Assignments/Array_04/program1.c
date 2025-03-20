#include<stdio.h>

int isprime(int num){
	for(int i=2;i*i<=num;i++){
		if(num<0)return 0 ;
		if(num%i==0){
			return 0;
		}
		
}return 1;
}



void main(){

	int size;
	printf("Enter the Size of Array :");
	scanf("%d",&size);
	int arr[size];
	printf("\nEnter the Array Elements :\n");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	printf("The Prime Numbers are \n");	
	for(int i=0;i<size;i++){
		if(isprime(arr[i])){
				printf("%d\n",arr[i]);
		}
	}
		
}



