#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
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
ll n, m;
ll a[100010];
ll w[100010];

struct segtree
{
	ll seg[1000010];
	
	void init(ll no, ll s, ll e)
	{
		seg[no] = 0;
		
		if(s == e)
			return;
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
	}
	
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
		
		seg[no] = seg[no << 1] + seg[no << 1 | 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return query(no << 1, s, (s + e) >> 1, l, r) + query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
	}
}segt;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		for(ll i = 1 ; i <= m ; i++)
			cin >> a[i];
		
		segt.init(1, 0, 200010);
		
		for(ll i = 1 ; i <= n ; i++)
		{
			w[i] = n - i + 1;
			segt.update(1, 0, 200010, i, 1);
		}
		
		ll cc = n;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cout << segt.query(1, 0, 200010, w[a[i]] + 1, 200010) sp;
			
			segt.update(1, 0, 200010, w[a[i]], 0);
			w[a[i]] = ++cc;
			segt.update(1, 0, 200010, w[a[i]], 1);
		}
		
		cout en;
	}
	
	return 0;
}