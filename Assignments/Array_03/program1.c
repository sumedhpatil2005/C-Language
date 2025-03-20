#include<stdio.h>
void main(){
	int size;
	printf("Enter The Size of Array");
	scanf("%d",&size);

	int arr1[size];
	int arr2[size];
	printf("Enter The Array Elements:\n ");
	for(int i=1;i<=size;i++){
		scanf("%d",&arr1[i]);
		arr2[i]=arr1[i];
	}
	printf("Second Array Elements Are:\n");
	for(int i=1;i<=size;i++){
		printf("%d\n",arr2[i]);
	}
}

