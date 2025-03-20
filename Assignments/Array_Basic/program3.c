#include<stdio.h>
void main(){
	int size;
	int arr[size];

	printf("Enter the Size of array");

	scanf("%d",&size);
	printf("Enter the Array Elements");
	for(int i=1;i<=size;i++){
		scanf("%d",&arr[i]);
	}

	for(int i=1;i<=size;i++){
		if(arr[i]%2==0){
			printf("%d\n\n\n",arr[i]);
		}
	}
}

		
