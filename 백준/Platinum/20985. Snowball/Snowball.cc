#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, q;
ll a[200010];
ll b[200010];
ll nu[200010];
ll maxx[200010], minn[200010];
ll ans[200010];

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= q ; i++)
	{
		cin >> b[i];
		nu[i] = nu[i - 1] + b[i];
	}
	
	for(ll i = 1 ; i <= q ; i++)
	{
		maxx[i] = maxx[i - 1];
		minn[i] = minn[i - 1];
		
		if(nu[i] > 0)
			maxx[i] = max(maxx[i], nu[i]);
		
		if(nu[i] < 0)
			minn[i] = max(minn[i], -nu[i]);
	}
	
	a[0] = -INF;
	a[n + 1] = INF;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll dist = a[i] - a[i - 1];
		ll l = 1, r = q;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(maxx[mid] + minn[mid] >= dist)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		if(l == q + 1)
		{
			ans[i] += minn[q];
			continue;
		}
		
		if(nu[l] > 0)
			ans[i] += minn[l];
		else
			ans[i] += dist - maxx[l];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll dist = a[i + 1] - a[i];
		ll l = 1, r = q;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(maxx[mid] + minn[mid] >= dist)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		if(l == q + 1)
		{
			ans[i] += maxx[q];
			continue;
		}
		
		if(nu[l] > 0)
			ans[i] += dist - minn[l];
		else
			ans[i] += maxx[l];
	}
	
	for(ll i = 1 ; i <= n ; i++)
		cout << ans[i] en;
	
	return 0;
}