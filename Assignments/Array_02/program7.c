#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of Array:");
	scanf("%d",&size);
	int arr[size];
	
	printf("Enter the Array Elements");
	for(int i=1;i<=size;i++){
		
		scanf("%d",&arr[i]);
		if(arr[i] %2==0){
			arr[i] = arr[i]*arr[i];

		}
		else{
			arr[i]=arr[i]*arr[i]*arr[i];
		}
	}

	for(int i =1;i<=size;i++){
		printf("%d\n",arr[i]);
	}
}

