#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of Array");
	scanf("%d",&size);
	int arr[size];
	printf("\nEnter Child's Age");
	for(int i=1;i<=size;i++){	
			scanf("%d",&arr[i]);
			if(arr[i]>5){
				printf("Age greater than 5...Re-enter Age");
				i--;
			}
			
	}
	for(int i =1;i<=size;i++){
		printf("%d\n",arr[i]);
	}
	
}

