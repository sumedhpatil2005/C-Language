#include<stdio.h>
void main()
{
	char character;
	printf("enter character");
	scanf("%c",&character);

	if(character>='a' && character<='z')
	{
		printf("You Entered Small Case %c ",character);
	}
	if (character>='A' && character<='Z')
	{
		printf("You Entered Upper Case %c ",character);
	}
}

