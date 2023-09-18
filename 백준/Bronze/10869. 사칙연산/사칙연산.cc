#include <stdio.h>

using namespace std;

int a, b;

int main(void)
{
	scanf("%d %d", &a, &b);
	
	printf("%d\n%d\n%d\n%d\n%d\n", a + b, a - b,
	a * b, a / b, a % b);
	
	return 0;
}