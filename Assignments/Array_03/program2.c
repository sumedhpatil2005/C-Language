#include<stdio.h>
void main(){
	int size;
	printf("Enter The Size of Array");
	scanf("%d",&size);
	int arr1[size];
	int arr2[size];
	printf("Enter The Elements in Array");
	for(int i=1;i<=size;i++){
		scanf("%d",&arr1[i]);
		
	}
	for(int i=1;i<=size;i++){
		for(int j=size;j>=1;j--){
			arr2[j]=arr1[i];
			i++;
		}
	}
	for(int i =1;i<=size;i++){
		printf("%d\n",arr2[i]);
	}

}

	
