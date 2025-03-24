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

ll n, m;
ll a[300010];
ll now[300010];
ll ans;

struct fenwicktree
{
	ll bit[300010];
	
	void update(ll w, ll v)
	{
		if(!w)
			return;
		
		for(ll i = w ; i <= n ; i += (i & (-i)))
			bit[i] += v;
	}
	
	ll query(ll w)
	{
		ll ret = 0;
		
		for(ll i = w ; i >= 1 ; i -= (i & (-i)))
			ret += bit[i];
		
		return ret;
	}
}BIT;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!now[a[i]])
			ans += m - 1;
		
		else
		{
			ans += BIT.query(i) - BIT.query(now[a[i]]);
			BIT.update(now[a[i]], -1);
		}
		
		BIT.update(i, 1);
		now[a[i]] = i;
	}
	
	cout << ans;
	return 0;
}