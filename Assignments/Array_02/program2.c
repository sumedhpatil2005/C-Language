#include<stdio.h>

void main(){
	int size;
	printf("Enter the Size of Array :");
	scanf("%d",&size);

	char  arr[size];

	printf("Enter the Array Elements \n");
	for(int i=1;i<=size;i++){
		scanf(" %c",&arr[i]);
	}
	printf("\nAscii Values of Following are :\n");
	for(int i=1;i<=size;i++){
		printf("%d\n",arr[i]);
}
}


