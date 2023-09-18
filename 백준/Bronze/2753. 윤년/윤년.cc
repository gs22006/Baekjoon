#include <stdio.h>

using namespace std;

int a;

int main(void)
{
	scanf("%d", &a);
	printf("%d", a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
	return 0;
}