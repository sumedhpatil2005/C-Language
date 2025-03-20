#include<stdio.h>

void main(){
	printf("Enter arr Size: ");
	int size;
	int sum1=0;
	int sum2 = 0;
	scanf("%d",&size);
	int arr1[size];
	printf("\nEnter the arr1 elements:\n ");
	for(int i=1;i<=size;i++){
		scanf("%d",&arr1[i]);
		if(i%2==0){
			sum1 += arr1[i];
		}	
	}
	int arr2[size];
	printf("\nEnter the arr2 elements:\n");
			for(int i=1;i<=size;i++){
				scanf("%d",&arr2[i]);
				if(i%2!=0){
					sum2 += arr2[i];
				}
			}

			printf("Sum of even index %d\n",sum1);
			printf("Sum of odd index %d \n",sum2);
}



