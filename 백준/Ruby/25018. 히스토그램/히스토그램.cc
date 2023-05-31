#include "histogram.h"
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
ll h[500010];
pll a[500010];
vector<ll> vec[500010];
ll cc;
vector<ll> ans;

struct segtree
{
	ll seg[2000010];
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no] = s;
			return;
		}
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
		
		if(h[seg[no << 1]] < h[seg[no << 1 | 1]])
			seg[no] = seg[no << 1];
		else
			seg[no] = seg[no << 1 | 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
			return -1;
		
		if(l <= s && e <= r)
			return seg[no];
		
		ll L = query(no << 1, s, (s + e) >> 1, l, r);
		ll R = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		
		if(L == -1)
			return R;
		
		if(R == -1)
			return L;
		
		if(h[L] < h[R])
			return L;
		
		return R;
	}
}segt;

void f(ll s, ll e, ll pa)
{
	if(s > e)
		return;
	
	cc++;
	
	ll w = segt.query(1, 1, n, s, e);
	
	a[cc].fi = e - s + 1;
	a[cc].se = h[w];
	
	if(pa)
	{
		vec[pa].push_back(cc);
		vec[cc].push_back(pa);
	}
	
	ll tmp = cc;
	
	f(s, w - 1, tmp);
	f(w + 1, e, tmp);
}

vector<ll> max_area(vector<int> H)
{
    n = (ll)H.size();
    
    for(ll i = 1 ; i <= n ; i++)
    	h[i] = H[i - 1];
    
    segt.init(1, 1, n);
    
    f(1, n, 0);
    
    ans.push_back(0);
    
    for(ll i = 1 ; i <= n ; i++)
    	ans[0] = max(ans[0], a[i].fi * a[i].se);
    
    return ans;
}