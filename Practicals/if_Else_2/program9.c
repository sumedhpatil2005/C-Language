#include<stdio.h>
void main(){
	int a,b,c;
	printf("Enter the length of Sides of a triangle\n");
	scanf("%d%d%d",&a,&b,&c);

         if(a*a + b*b == c*c){
		 printf("The above are the pythagorean triplets");
	 }
	 else{
		 printf("the above are not pythagorean triplets");
	 }

}

