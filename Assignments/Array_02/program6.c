#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of Array");
	scanf("%d",&size);
	float height[size];
	printf("Enter the Heights");
	for(int i=1;i<=size;i++){
		scanf("%f",&height[i]);
		if(height[i]<5.5 || height[i]>6){
			printf("Enter the height between 5.5ft and 6ft\n");
			i--;
		}
	}

	for(int i =1;i<=size;i++){
		printf("%f",height[i]);
	}
	
}
