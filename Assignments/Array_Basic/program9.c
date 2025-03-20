#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of Array\n");
	scanf("%d",&size);
	int arr[size];

	printf("Enter Array Elements\n");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
		
	}
	for(int i =0;i<size;i++){
		if(arr[i]%5==0){
			printf("%d  %d\n",arr[i],i);
			break;
		}
		
	}
	}

