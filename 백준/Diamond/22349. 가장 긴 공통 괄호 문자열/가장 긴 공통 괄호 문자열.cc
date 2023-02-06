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
char a[500010], b[500010];
ll n, m;

struct lazysegtree
{
	ll seg[2000010], lazy[2000010];
	
	void init(ll no, ll s, ll e)
	{
		seg[no] = lazy[no] = 0;
		
		if(s == e)
			return;
		
		init(no * 2, s, (s + e) / 2);
		init(no * 2 + 1, (s + e) / 2 + 1, e);
	}
	
	void prop(ll no, ll s, ll e)
	{
		seg[no] += lazy[no];
		
		if(s != e)
		{
			lazy[no * 2] += lazy[no];
			lazy[no * 2 + 1] += lazy[no];
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
			seg[no] += v;
			
			if(s != e)
			{
				lazy[no * 2] += v;
				lazy[no * 2 + 1] += v;
			}
			
			return;
		}
		
		update(no * 2, s, (s + e) / 2, l, r, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
		
		seg[no] = min(seg[no * 2], seg[no * 2 + 1]);
	}
	
	ll query(ll no, ll s, ll e)
	{
		prop(no, s, e);
		
		if(s == e)
			return s;
		
		prop(no * 2, s, (s + e) / 2);
		prop(no * 2 + 1, (s + e) / 2 + 1, e);
		
		if(seg[no * 2] < 0)
			return query(no * 2, s, (s + e) / 2);
		
		return query(no * 2 + 1, (s + e) / 2 + 1, e);
	}
	
	ll query2(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return MAX;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return min(query2(no * 2, s, (s + e) / 2, l, r), query2(no * 2 + 1, (s + e) / 2 + 1, e, l, r));
	}
	
	ll query3(ll no, ll s, ll e)
	{
		prop(no, s, e);
		
		if(s == e)
			return s;
		
		prop(no * 2, s, (s + e) / 2);
		prop(no * 2 + 1, (s + e) / 2 + 1, e);
		
		if(seg[no * 2 + 1] == 0)
			return query3(no * 2 + 1, (s + e) / 2 + 1, e);
		
		return query3(no * 2, s, (s + e) / 2);
	}
}segt;

void opr(ll X)
{
	if(a[X] == '(')
		segt.update(1, 0, n - 1, X, n - 1, -1);
	else
		segt.update(1, 0, n - 1, X, n - 1, 1);
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> a >> b;
		
		n = strlen(a);
		m = strlen(b);
		
		segt.init(1, 0, n - 1);
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(a[i] == '(')
				segt.update(1, 0, n - 1, i, n - 1, 1);
			else
				segt.update(1, 0, n - 1, i, n - 1, -1);
		}
		
		ll ans = 0;
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(segt.query2(1, 0, n - 1, i, i) <= 0)
			{
				opr(i);
				continue;
			}
			
			if(segt.query2(1, 0, n - 1, i, n - 1) > 0)
			{
				opr(i);
				continue;
			}
			
			if(segt.query2(1, 0, n - 1, i, n - 1) >= 0)
			{
				ll w = segt.query3(1, 0, n - 1);
				ans = max(ans, w - i + 1);
				opr(i);
				continue;
			}
			
			if(segt.query2(1, 0, n - 1, i, n - 1) >= 0 && segt.query2(1, 0, n - 1, n - 1, n - 1) == 0)
			{
				ans = max(ans, n - i);
				opr(i);
				continue;
			}
			
			ll w = segt.query(1, 0, n - 1);
			
			ans = max(ans, w - i);
			opr(i);
		}
		
		cout << ans en;
	}
	
	return 0;
}