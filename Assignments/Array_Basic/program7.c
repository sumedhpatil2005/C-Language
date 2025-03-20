#include<stdio.h>
void main(){
	int size;
	int oddsum=0;
	int evensum = 0;
	printf("Enter the Size of Array:\n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the Elements of Array\n");
	for(int i=1;i<=size;i++){
	scanf("%d",&arr[i]);
	}
	for(int i=1;i<=size;i++){
		if(arr[i]%2==0){
			evensum = evensum + arr[i];
		}
		else{
			oddsum = oddsum + arr[i];
		}
	}

	printf("The sum of even numbers %d\n",evensum);
	printf("The sum of odd numbers is %d\n",oddsum);
	
	int diff = evensum - oddsum;

	printf("The Difference between evensum and oddsum :%d",diff);
}



