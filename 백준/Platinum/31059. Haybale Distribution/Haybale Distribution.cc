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

ll n;
ll a[200010];
ll q;
ll A, B;
ll nu[200010];
ll idx[1000010];

ll f(ll X)
{
	ll ret = 0;
	
	ret += (X * idx[X] - nu[idx[X]]) * A;
	ret += (nu[n] - nu[idx[X]] - X * (n - idx[X])) * B;
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
		nu[i] = nu[i - 1] + a[i];
	
	ll p = 1;
	
	for(ll i = 0 ; i <= 1000000 ; i++)
	{
		while(a[p] <= i)
			p++;
		
		idx[i] = p - 1;
	}
	
	cin >> q;
	
	while(q--)
	{
		cin >> A >> B;
		
		ll l = 0, r = 1000000;
		
		while(l <= r)
		{
			ll mid1 = (l * 2 + r) / 3;
			ll mid2 = (l + r * 2) / 3;
			ll gap1 = f(mid1);
			ll gap2 = f(mid2);
			
			if(gap1 <= gap2)
				r = mid2 - 1;
			else
				l = mid1 + 1;
		}
		
		ll ans = INF;
		
		for(ll i = -5 ; i <= 5 ; i++)
		{
			if(0 <= l + i && l + i <= 1000000)
				ans = min(ans, f(l + i));
		}
		
		cout << ans en;
	}
	
	return 0;
}