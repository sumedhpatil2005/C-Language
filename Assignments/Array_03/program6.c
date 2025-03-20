#include<stdio.h>
void main(){
	int flag=0;
	printf("Enter the size of Array1:");
	int arr1size;
	scanf("%d",&arr1size);
	int arr1[arr1size];
	printf("Enter the Array elements");
	for(int i=1;i<=arr1size;i++){
		scanf("%d",&arr1[i]);
	}

	printf("Enter the size of Array2:");
	int arr2size;
	scanf("%d",&arr2size);
	int arr2[arr2size];
	printf("Enter the array elements");
	for(int i=1;i<=arr2size;i++){
		scanf("%d",&arr2[i]);
	}


	for(int i=1;i<=arr1size;i++){
		for(int j=1;j<=arr2size;j++){
			if(arr1[i] != arr2[i]){
				flag =1;
				break;
			}
		
		}
	
	}
	if(flag == 0){
		printf("The arrays are nnot equal ");
	}
	else{
		printf("arrays are equal");
	}

	
}
