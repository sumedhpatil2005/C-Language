#include<stdio.h>
void main(){
	int arr1size;
	printf("Enter the size of Array 1 :\n");
	scanf("%d",&arr1size);
	int arr1[arr1size];
	printf("Enter the Array Elements:\n");
	for(int i=1;i<=arr1size;i++){
		scanf("%d",&arr1[i]);
	}
	int arr2size;
	printf("Enter the size of Array 2:\n");
	scanf("%d",&arr2size);
	int arr2[arr2size];
	printf("Enter the Array Elements:\n");
	for(int i=1;i<=arr2size;i++){
		scanf("%d",&arr2[i]);
	}

	if(arr1size == arr2size){
		printf("The Arrays have Equal Lengths");
	}
	else{
		printf("The Arrays Lengths are not Equals");
	}
}

