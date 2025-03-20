#include<stdio.h>
void main(){
	int size;

	
	printf("Enter The Size of Array\n");
	scanf("%d",&size);
		int arr[size];
	printf("Enter the Array Elements\n");
	for(int i=1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n\n\n");
	int product=1;
	for(int i=1;i<=size;i++){
		if(arr[i] % 2 ==0){
			product = product * arr[i];
		}
	}
	printf("\n The Product of Even Elements is : %d \n",product);
}

