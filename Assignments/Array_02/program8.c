#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of Array");
	scanf("%d",&size);
	char arr[size];
	for(int i=1;i<=size;i++){
		scanf(" %c",&arr[i]);
	}

	for(int i =1;i<=size;i++){
		printf("%c | ",arr[i]);
		i++;
	}
}
