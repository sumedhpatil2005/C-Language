#include<stdio.h>
void main(){
	int size;
	printf("Enter Size of database");
	scanf("%d",&size);
	int arr[size];
	printf("Enter Student Id's");
	for(int i =0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int search=0;
	printf("Enter Student Id to  Search ");
	scanf("%d",&search);
	for(int i =0;i<size;i++){
		if(arr[i]==search){
			printf("id %d found at %d",search,i);
		}
	}
}

