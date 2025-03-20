#include<stdio.h>
void main(){
	int size;
	printf("Enter The Size of Array:\n");
	scanf("%d",&size);
	int arr[size];

	printf("Enter the array Elements:\n");
	for(int  i =1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	printf("Entered Elements Successfully\n\n");
	for(int i = 1;i<=size;i+=2){
		printf("%d\n",arr[i]);
	}
}

