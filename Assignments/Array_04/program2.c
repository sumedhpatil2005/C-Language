#include<stdio.h>
int isnotprime(int num){

	for(int i=2;i*i <num;i++){
		if(num<2){
			return 0;
		if(num%i==0){
			return 1;
		}
		return 0;

}
}
}

void main(){
	int size;
	printf("Enter Size of Array:\n");
	scanf("%d",&size);

	int arr[size];


	printf("Enter the array Elements:\n ");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<size;i++){
		if(arr[i] >2 && isnotprime(arr[i])){
			printf("%d",i);
		}
	}
}

