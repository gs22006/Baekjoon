#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n;
ll a[1000010];
priority_queue<ll> pq;
ll ans, mv;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	pq.push(a[1]);
	
	for(ll i = 2 ; i <= n ; i++)
	{
		mv++;
		
		ll qq = pq.top();
		qq += mv;
		
		if(qq >= a[i])
		{
			pq.pop();
			pq.push(a[i] - mv);
			ans += qq - a[i];
		}
		
		pq.push(a[i] - mv);
	}
	
	printf("%lld", ans);
	return 0;
}