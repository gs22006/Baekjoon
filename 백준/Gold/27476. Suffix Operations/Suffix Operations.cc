#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll t;
ll n;
ll a[200010];

int main(void)
{
	scanf("%lld", &t);
	
	while(t--)
	{
		scanf("%lld", &n);
		
		for(ll i = 1 ; i <= n ; i++)
			scanf("%lld", &a[i]);
		
		vector<ll> vec, vec2;
		
		ll gap = 0;
		
		for(ll i = 2 ; i <= n ; i++)
		{
			gap += abs(a[i] - a[i - 1]);
			vec.push_back(abs(a[i] - a[i - 1]));
		}
		
		for(ll i = 3 ; i <= n ; i++)
			vec2.push_back(abs(a[i] - a[i - 2]));
		
		ll ans = min(gap - abs(a[2] - a[1]), gap - abs(a[n] - a[n - 1]));
		
		for(ll i = 2 ; i < n ; i++)
			ans = min(ans, gap - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[i - 1]));
		
		printf("%lld\n", ans);
	}
	
	return 0;
}