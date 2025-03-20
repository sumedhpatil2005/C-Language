#include<stdio.h>
#include<stdbool.h>
void main(){
	int arr1size;
	int arr2size;
	printf("Enter the size of Array:\n");
	scanf("%d",&arr1size);
	int arr1[arr1size];
	printf("Enter the array elements:\n");
	for(int i=1;i<=arr1size;i++){
		scanf("%d",&arr1[i]);
	}
	printf("Enter the array 2 Size\n");
	scanf("%d",&arr2size);
	int arr2[arr2size];
	for(int i=1;i<=arr2size;i++){
		scanf("%d",&arr2[i]);
		}
	bool flag=0;
	for(int i=1;i<=arr1size;i++){
		for(int j=1;j<=arr2size;j++){
			if(arr1[i] ==arr2[j]){
				flag=1;
			}
			else{
				flag=0;
				break;
			}
		
	}
}

if(flag){
	printf("elements are equal ");
}
else{
	printf("Elements are not equal");
}
}

	
