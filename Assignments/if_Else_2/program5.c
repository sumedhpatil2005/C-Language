#include<stdio.h>
void main(){
	int units;
	printf("Enter the Bill unit");
	scanf("%d",&units);
	int bill;

	if(units <100){
                bill=units*5;;
		printf("the bill is %d",bill);

	}
	else if(units >=100 && units<300){
		bill=(100*5)+(units-100)*7;
		printf("The bill is %d",bill);
	}
	else{
		bill = (100*5)+(200*7)+(units-300)*10;
		printf("The bill is %d",bill);
	}
}

