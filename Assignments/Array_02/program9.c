#include<stdio.h>
void main(){
	int size;
	printf("Enter the size of array:");
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int index=0;
	printf("Enter the index upto you want to print");
	scanf("%d",&index);
	
	if(index>size){

		printf("Invalid Index");
	}


	for(int i=0;i<index;i++){
		printf("%d",arr[i]);
	}
}

