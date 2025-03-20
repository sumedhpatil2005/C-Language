#include<stdio.h>
void main(){
	int i,arr1size;
	printf("Enter the size of first array:");
	scanf("%d",&arr1size);
	int arr1[arr1size];
	printf("Enter Array Elements:");
	for(int i=0;i<arr1size;i++){
		scanf("%d",&arr1[i]);
	}
	int arr2size;
	printf("\nenter the size of second array");
	scanf("%d",&arr2size);

	int arr2[arr2size];
	printf("Enter array elements :");
	for(int i=0;i<arr2size;i++){
		scanf("%d",&arr2[i]);
	}
	int arr3size = arr1size+arr2size;
	int arr3[arr3size];
	for(int i=0;i<arr1size;i++){
		arr3[i] = arr1[i];
		
	}
	for(int j=0;j<arr2size;j++){
		arr3[arr1size+j]=arr2[j];
	}
	printf("\n\n\n");
	for(int i=0;i<arr3size;i++){
		printf("%d\n",arr3[i]);
	}

}



	
