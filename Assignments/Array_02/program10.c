#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of Array");
	scanf("%d",&size);
	int arr[size];
	for(int i=1;i<=size;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=size;i>=1;i--){
		printf("%d | ",arr[i]);
		i--;
		}
}


