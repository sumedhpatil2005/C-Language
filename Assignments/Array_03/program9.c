#include<stdio.h>

void main(){
	int size;
	printf("Enter the array size: ");
	scanf("%d",&size);

	int arr1[size];
	printf("\nEnter the array elements:\n");
	for(int i=0;i<size;i++){
		scanf("%d",&arr1[i]);
	}
	int arr2[size];
	printf("\n Enter the array2 elements:\n");
	for(int i=0;i<size;i++){
		scanf("%d",&arr2[i]);
	}

	int temp[size];
	for(int i=0;i<size;i++){
		temp[i]=arr1[i];
		arr1[i]=arr2[i];
		arr2[i]=temp[i];
	}
	for(int i=0;i<size;i++){
		printf("%d\n",arr1[i]);
	}
	for(int i=0;i<size;i++){
		printf("%d\n",arr2[i]);
	}
}


