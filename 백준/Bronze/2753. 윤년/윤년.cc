#include <stdio.h>

using namespace std;

int a;

int main(void)
{
	scanf("%d", &a);
	
	if(a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
		printf("1");
	else
		printf("0");
	
	return 0;
}