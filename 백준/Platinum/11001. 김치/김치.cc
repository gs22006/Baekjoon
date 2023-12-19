#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, d;
ll T[100010], V[100010]; 
ll ans;

void dnc(ll s, ll e, ll L, ll R)
{
	ll mid = (s + e) / 2;
	ll st = max(mid - d, max(L, 1LL));
	ll ed = min(mid, R);
	ll w = 0, maxx = 0;
	
	if(s > e)
		return;
	
	for(ll i = st ; i <= ed ; i++)
	{
		if((mid - i) * T[mid] + V[i] > maxx)
		{
			maxx = (mid - i) * T[mid] + V[i];
			w = i;
		}
	}
	
	ans = max(ans, maxx);
	
	dnc(s, mid - 1, L, w);
	dnc(mid + 1, e, w, R);
}

int main(void)
{
	scanf("%lld %lld", &n, &d);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &T[i]);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &V[i]);
	
	dnc(1, n, 1, n);
	
	printf("%lld", ans);
	return 0;
}