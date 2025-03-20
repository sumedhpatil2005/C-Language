#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of Array");
	scanf("%d",&size);
	int arr[size];
	for(int i =1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	int product=1;
	for(int i=1;i<=size;i+=2){
		if(arr[i]%2!=0){
		product = product * arr[i];
		}
	}
	printf("%d",product);
}

			 

