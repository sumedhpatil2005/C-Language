#include<stdio.h>
void main(){
	int size;
	printf("Enter the Size of Character Array");
	scanf("%d",&size);
	char  arr[size];
	printf("Enter the Characters of an Array:\n");
	for(int i=0;i<size;i++){
		scanf(" %c",&arr[i]);
	}
	printf("\n\n");
	for(int i=0;i<size;i++){
		if(arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U' ||arr[i] == 'a'  || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
			printf("\n%c  %d\n",arr[i],i);
		}
	}
}

