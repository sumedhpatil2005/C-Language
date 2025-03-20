#include<stdio.h>
void main(){
	int size;
	printf("Enter the size of array");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the array Elements");
	for(int i=1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	int num=0;
	int sum=0;
	for(int i=1;i<=size;i++){
		num = arr[i];
		sum+=num*num;
	}
	printf("%d",sum);
}

