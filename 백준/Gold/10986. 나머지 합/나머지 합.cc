#include<bits/stdc++.h>

using namespace std;

long long n, m;
long long a[1000010];
long long na[1000010];
long long b[1000010];
long long ans;

int main(void)
{
	scanf("%lld %lld", &n, &m);
	
	for(long long i = 0 ; i < n ; i++)
		scanf("%lld", &a[i]);
	
	b[0] = a[0] % m;
	
	for(long long i = 1 ; i < n ; i++)
		b[i] = (b[i - 1] + a[i]) % m;
	
	for(long long i = 0 ; i < n ; i++)
		na[b[i] % m]++;
	
	for(long long i = 0 ; i < n ; i++)
	{
		if(b[i] % m == 0)
			ans++;
	}
	
	for(long long i = 0 ; i < n ; i++)
		ans += na[i] * (na[i] - 1) / 2;
	
	printf("%lld", ans);
	return 0;
}