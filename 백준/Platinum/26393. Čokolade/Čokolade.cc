#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n, q;
ll a[100010];
ll nu[100010];
ll k, m;
ll l, r;
ll w;

ll solve(ll X)
{
	ll ret = 0;
	
	if(X < w)
		ret += nu[X];
	
	else
	{
		ret += nu[w - 1];
		ret += k * (X - w + 1);
		ret -= (nu[X] - nu[w - 1]) - k * (X - w + 1);
	}
	
	ll nam = m - X;
	ll st = n + 1 - nam;
	
	if(w <= st)
	{
		ret += k * (n - st + 1);
		ret -= (nu[n] - nu[st - 1]) - k * (n - st + 1);
	}
	
	else
	{
		ret += nu[w - 1] - nu[st - 1];
		ret += k * (n - w + 1);
		ret -= (nu[n] - nu[w - 1]) - k * (n - w + 1);
	}
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
		nu[i] = nu[i - 1] + a[i];
	
	while(q--)
	{
		cin >> k >> m;
		
		l = 1;
		r = n;
		
		while(l <= r)
		{
			ll mid = (l + r) / 2;
			
			if(a[mid] > k)
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		w = l;
		
		l = 1;
		r = m;
		
		while(l <= r)
		{
			ll mid1 = (l * 2 + r) / 3;
			ll mid2 = (l + r * 2) / 3;
			ll gap1 = solve(mid1);
			ll gap2 = solve(mid2);
			
			if(gap1 < gap2)
				r = mid2 - 1;
			else
				l = mid1 + 1;
		}
		
		ll ans = INF;
		
		for(ll i = l - 5 ; i <= l + 5 ; i++)
		{
			if(0 <= i && i <= m)
				ans = min(ans, solve(i));
		}
		
		cout << ans en;
	}
	
	return 0;
}