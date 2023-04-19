#include <bits/stdc++.h>

using namespace std;

long long n;
long long ss;

int main(void)
{
	scanf("%lld", &n);
	
	ss = sqrt(n);
	
	if(ss * ss >= n)
		printf("%lld", ss);
	else
		printf("%lld", ss + 1);
	
	return 0;
}