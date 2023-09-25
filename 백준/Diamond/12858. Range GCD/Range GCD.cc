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
ll a[100010];
ll q;
ll all, bll, cll;

struct fenwicktree
{
	ll bit[100010];
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= n ; i += (i & (-i)))
			bit[i] += v;
	}
	
	ll query(ll X)
	{
		ll ret = 0;
		
		for(ll i = X ; i > 0 ; i -= (i & (-i)))
			ret += bit[i];
		
		return ret;
	}
}BIT;

struct segtree
{
	ll seg[500010];
	
	void update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return;
		
		if(s == e)
		{
			seg[no] = v;
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, w, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, w, v);
		
		seg[no] = __gcd(seg[no << 1], seg[no << 1 | 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s || l > r)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		ll L = query(no << 1, s, (s + e) >> 1, l, r);
		ll R = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		
		return __gcd(L, R);
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		
		BIT.update(i, a[i]);
		BIT.update(i + 1, -a[i]);
	}
	
	for(ll i = 2 ; i <= n ; i++)
		segt.update(1, 2, n, i, abs(a[i] - a[i - 1]));
	
	cin >> q;
	
	while(q--)
	{
		cin >> all >> bll >> cll;
		
		if(all == 0)
		{
			ll ans = segt.query(1, 2, n, bll + 1, cll);
			ans = __gcd(ans, BIT.query(bll));
			
			cout << ans en;
		}
		
		else
		{
			BIT.update(bll, all);
			BIT.update(cll + 1, -all);
			
			if(bll >= 2)
				segt.update(1, 2, n, bll, abs(BIT.query(bll) - BIT.query(bll - 1)));
			
			if(cll < n)
				segt.update(1, 2, n, cll + 1, abs(BIT.query(cll + 1) - BIT.query(cll)));
		}
	}
	
	return 0;
}