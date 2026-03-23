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

ll t;
ll a, b, c;
ll K;
pll ans;

bool comp(pll X, pll Y)
{
	return X.fi * Y.se > Y.fi * X.se;
}

bool chk(ll X, ll Y, ll Z)
{
	if(!X || !Y || !Z)
		return false;
	
	if(X >= K || Y >= K || Z >= K)
		return true;
	
	if(X * Y >= (K + Z - 1) / Z)
		return true;
	
	return false;
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> a >> b >> c;
		cin >> K;
		
		ll l, r;
		
		ans = {0, 1};
		
		l = 1, r = 1000000000;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(chk(mid, b * mid / a, c * mid / a))
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		if(comp(make_pair(a, l), ans))
			ans = {a, l};
		
		l = 1, r = 1000000000;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(chk(a * mid / b, mid, c * mid / b))
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		if(comp(make_pair(b, l), ans))
			ans = {b, l};
		
		l = 1, r = 1000000000;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(chk(a * mid / c, b * mid / c, mid))
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		if(comp(make_pair(c, l), ans))
			ans = {c, l};
		
		ll G = __gcd(ans.fi, ans.se);
		
		ans.fi /= G;
		ans.se /= G;
		
		cout << ans.fi sp << ans.se en;
	}
	
	return 0;
}