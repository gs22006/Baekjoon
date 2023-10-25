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

string s;
ll n;
ll a[1000010];
ll q;
ll all, bll, cll, dll;
ll ss = 998244353;
ll inv[20];
ll tenn[1000010];
ll tmp[20];
ll tmp2[20];

struct lazysegtree
{
	ll seg[4000010][10];
	int lazy[4000010][10];
	
	void init(ll no, ll s, ll e)
	{
		for(ll i = 0 ; i <= 9 ; i++)
			lazy[no][i] = i;
		
		if(s == e)
		{
			seg[no][a[s]] = 1;
			return;
		}
		
		ll mid = (s + e) >> 1;
		
		init(no << 1, s, mid);
		init(no << 1 | 1, mid + 1, e);
		
		for(ll i = 0 ; i <= 9 ; i++)
			seg[no][i] = (seg[no << 1][i] * tenn[e - mid] % ss + seg[no << 1 | 1][i]) % ss;
	}
	
	void prop(ll no, ll s, ll e)
	{
		for(ll i = 0 ; i <= 9 ; i++)
			tmp2[i] = 0;
		
		for(ll i = 0 ; i <= 9 ; i++)
			tmp2[lazy[no][i]] = (tmp2[lazy[no][i]] + seg[no][i]) % ss;
		
		for(ll i = 0 ; i <= 9 ; i++)
			seg[no][i] = tmp2[i];
		
		if(s != e)
		{
			for(ll i = 0 ; i <= 9 ; i++)
			{
				lazy[no << 1][i] = lazy[no][lazy[no << 1][i]];
				lazy[no << 1 | 1][i] = lazy[no][lazy[no << 1 | 1][i]];
			}
		}
		
		for(ll i = 0 ; i <= 9 ; i++)
			lazy[no][i] = i;
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v, ll v2)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			for(ll i = 0 ; i <= 9 ; i++)
				tmp[i] = i;
			
			tmp[v] = v2;
			
			for(ll i = 0 ; i <= 9 ; i++)
				tmp2[i] = 0;
			
			for(ll i = 0 ; i <= 9 ; i++)
				tmp2[tmp[i]] = (tmp2[tmp[i]] + seg[no][i]) % ss;
			
			for(ll i = 0 ; i <= 9 ; i++)
				seg[no][i] = tmp2[i];
			
			if(s != e)
			{
				for(ll i = 0 ; i <= 9 ; i++)
				{
					lazy[no << 1][i] = tmp[lazy[no << 1][i]];
					lazy[no << 1 | 1][i] = tmp[lazy[no << 1 | 1][i]];
				}
			}
			
			return;
		}
		
		ll mid = (s + e) >> 1;
		
		update(no << 1, s, mid, l, r, v, v2);
		update(no << 1 | 1, mid + 1, e, l, r, v, v2);
		
		for(ll i = 0 ; i <= 9 ; i++)
			seg[no][i] = (seg[no << 1][i] * tenn[e - mid] % ss + seg[no << 1 | 1][i]) % ss;
	}
	
	pair<ll, pll> query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return {0, {0, -1}};
		
		if(l <= s && e <= r)
		{
			ll ret = 0;
			
			for(ll i = 0 ; i <= 9 ; i++)
				ret = (ret + seg[no][i] * i % ss) % ss;
			
			return {ret, {s, e}};
		}
		
		ll mid = (s + e) >> 1;
		pair<ll, pll> L = query(no << 1, s, mid, l, r);
		pair<ll, pll> R = query(no << 1 | 1, mid + 1, e, l, r);
		pair<ll, pll> ret;
		
		if(mid < l || r < s)
			return R;
		
		if(e < l || r < mid + 1)
			return L;
		
		ret.fi = (L.fi * tenn[R.se.se - R.se.fi + 1] % ss + R.fi) % ss;
		ret.se.fi = L.se.fi;
		ret.se.se = R.se.se;
		
		return ret;
	}
}segt;

int main(void)
{
	fastio
	
	cin >> s;
	
	for(auto &i : s)
		a[++n] = i - '0';
	
	tenn[0] = 1;
	
	for(ll i = 1 ; i < 1000010 ; i++)
		tenn[i] = tenn[i - 1] * 10 % ss;
	
	segt.init(1, 1, n);
	
	cin >> q;
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll >> cll >> dll;
			segt.update(1, 1, n, all, bll, cll, dll);
		}
		
		else
		{
			ll gap = 0;
			
			cin >> all >> bll;
			
			gap = segt.query(1, 1, n, all, bll).fi;
			gap = (gap + ss) % ss;
			
			cout << gap en;
		}
	}
	
	return 0;
}