#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of element");
	scanf("%d",&size);
	
	if(size<0){
		printf("Invalid Size Enter Again");
		scanf("%d",&size);
	}
	
	int arr[size];
	
	
	printf("Enter Array Elements");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}

	for(int i=0;i<size;i++){
		printf("%d\n",arr[size-i-1]);
	}


}


