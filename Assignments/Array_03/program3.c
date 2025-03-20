#include<stdio.h>
void main(){
	int arr1size;
	int arr1sum=0;
	printf("Enter the Size of Array 1:\n");
	scanf("%d",&arr1size);
	int arr1[arr1size];
	printf("Enter the Array Elements:\n");
	for(int i=1;i<=arr1size;i++){
		scanf("%d",&arr1[i]);
		arr1sum+=arr1[i];
	}
	int arr2size;
	int arr2sum=0;
	printf("Enter the Size of Array 2:\n");
	scanf("%d",&arr2size);
	int arr2[arr2size];
	printf("Enter the Array Elements:\n");
	for(int i=1;i<=arr2size;i++){
		scanf("%d",&arr2[i]);
		arr2sum+=arr2[i];
	}
	if(arr1sum == arr2sum){
		printf("The Sums of Array1 and Array2 is %d and they are equals\n",arr1sum);
	}
	else{
		printf("The sums of Array1 is %d and Array2 is %d and they are not equal\n",arr1sum,arr2sum);
	}
}

