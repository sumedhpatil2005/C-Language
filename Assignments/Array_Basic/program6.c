#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of Array\n");
	scanf("%d",&size);
	int sum=0;
	int arr[size];
	printf("Enter the Elements of array");
	for(int i =1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int i=1;i<=size;i++){
		sum = sum + arr[i];
	}

	printf("%d",sum);
}


