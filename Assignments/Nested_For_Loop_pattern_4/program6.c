#include<stdio.h>
void main(){
	int rows;
	printf("Enter the No. of rows\n");
	scanf("%d",&rows);

	int num = (rows == 3) ? 1 : 2;

	for(int i=1;i<=rows;i++){
		for(int j=1;j<=rows;j++){
			int is_prime=0;
			while(!is_prime){
				is_prime=1;
				if(num < 2){
					is_prime=0;
				}
				for(int k=2;k*k<=num;k++){
					if(num%k==0){
						is_prime= 0;
						break;
					}
				}
				if(!is_prime){
					num++;
				}
			}
			printf("%d\t",num);
			num++;
		}
		printf("\n");
	}
	
}

					
