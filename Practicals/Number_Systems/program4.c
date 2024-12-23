#include<stdio.h>
void main(){
	int num;
	int comp=0;
	printf("Enter the number ");
	scanf("%d",&num);
	for(int i=2;i<=num/2;i++){
		if(num%i==0){
		comp =1;
			break;
	}
	}
	if(comp==1){
		printf("number is composite");
}
else{
	printf("Number is not composite");
}
}


