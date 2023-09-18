#include <stdio.h>

using namespace std;

double a, b;

int main(void)
{
	scanf("%lf %lf", &a, &b);
	printf("%.9lf", a / b);
	return 0;
}