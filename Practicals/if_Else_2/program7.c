#include<stdio.h>
void main(){
	int cost;
	int selling;

	printf("Enter the Selling price");
	scanf("%d",&selling);
	printf("Enter the Cost price");
	scanf("%d",&cost);

	printf("the profit after sales is %d",selling-cost);
}

