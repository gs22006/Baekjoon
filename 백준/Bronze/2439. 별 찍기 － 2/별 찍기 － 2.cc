#include <stdio.h>

using namespace std;

int a;

int main(void)
{
	scanf("%d", &a);
	
	for(int i = 1 ; i <= a ; i++)
	{
		for(int j = 0 ; j < a - i ; j++)
			printf(" ");
		
		for(int j = 0 ; j < i ; j++)
			printf("*");
		
		printf("\n");
	}
	
	return 0;
}