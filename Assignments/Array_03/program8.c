#include<stdio.h>

void main(){
	int i;
	int arr1size;
	printf("Enter the size of !st array");
	scanf("%d",&arr1size);
	int arr1[arr1size];
	printf("\nEnter the Elements of !st array :\n");
	for(int i=0;i<arr1size;i++){
		scanf("%d",&arr1[i]);
	}
	int arr2size;
	printf("\nEnter the size of 2nd array\n");
	scanf("%d",&arr2size);

	int arr2[arr2size];
	printf("\nEnter The Elements of 2nd array\n");
	for(int i=0;i<arr2size;i++){
		scanf("%d",&arr2[i]);
	}
	int arr3size = arr1size + arr2size;
		for(int i=0;i<arr2size;i++){

		printf("\n%d",arr1[i]);
		printf("\n%d",arr2[i]);
		}
	
}
