#include<stdio.h>
void main()
{
	int num;
	char chr;
	float rs;
	double crMoney;
	printf("Enter an integer value:\n");
	scanf("%d",&num);
	printf("enter an character:\n");
	scanf(" %c",&chr);
	printf("enter an float value:\n");
	scanf("%f",&rs);
	printf("Enter an Double value:\n");
	scanf("%le",&crMoney);


	printf("%d and Size is %ld\n",num,sizeof(num));
	printf(" %c and Size is %ld\n",chr,sizeof(chr));
		printf("%f and Size is %ld\n",rs,sizeof(rs));
			printf("%f and size is %ld\n",crMoney,sizeof(chr));
		
}



		
