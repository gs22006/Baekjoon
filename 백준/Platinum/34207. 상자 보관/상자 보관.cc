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
pll a[400010];
vector<ll> zip;

struct lazysegtree
{
	ll seg[1600010];
	ll lazy[1600010];
	
	void prop(ll no, ll s, ll e)
	{
		seg[no] += lazy[no];
		
		if(s != e)
		{
			lazy[no << 1] += lazy[no];
			lazy[no << 1 | 1] += lazy[no];
		}
		
		lazy[no] = 0;
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			lazy[no] += v;
			prop(no, s, e);
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		seg[no] = max(seg[no << 1], seg[no << 1 | 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		
		zip.push_back(a[i].fi);
		zip.push_back(a[i].se);
	}
	
	compress(zip);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		a[i].fi = lower_bound(zip.begin(), zip.end(), a[i].fi) - zip.begin() + 1;
		a[i].se = lower_bound(zip.begin(), zip.end(), a[i].se) - zip.begin() + 1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		segt.update(1, 1, n * 2, a[i].se, a[i].fi - 1, 1);
		cout << segt.query(1, 1, n * 2, 1, n * 2) en;
	}
	
	return 0;
}