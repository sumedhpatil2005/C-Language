#include<stdio.h>
void main(){
	int size;
	printf("Enter the Array Size : ");
	scanf("%d",&size);
	int arr[size];
	for(int i=1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n\n\n\n");
	int product=1;
	for(int i=1;i<=size;i++){
		if(arr[i]%2!=0){
			product = product * arr[i];
		}
	}
	printf("The Product of odd Number is \n %d \n",product);
}
