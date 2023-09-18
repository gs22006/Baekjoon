#include <stdio.h>

using namespace std;

int a;

int main(void)
{
	scanf("%d", &a);
	
	for(int i = 1 ; i <= a ; i++)
	{
		for(int j = 1; j <= a; ++j) {
			printf("%c", j > a - i ? '*' : ' ');
		}
		printf("\n");
	}
	
	return 0;
}