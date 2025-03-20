#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of Array:\n ");
	scanf("%d",&size);
	printf("Enter the Array Elements:\n");
	int arr[size];
	for(int i =1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	int sum=0;
	for(int i = 1;i<=size;i+=2){
		sum = sum+arr[i];
	}
	printf("The sum of Digits is  %d :\n",sum);
}


