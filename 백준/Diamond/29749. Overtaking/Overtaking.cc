#pragma GCC optimize ("O3")
 
#include "overtaking.h"
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
 
ll n, m, x;
int LL;
int w[2010];
ll S[2010][2010];
int spd[2010];
ll siz;
vector<pll> qry;
vector<ll> zip;
ll QRY[8000010];
 
struct lazysegtree
{
	ll lazy[8000010];
	ll seg[8000010];
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no] = zip[s - 1];
			return;
		}
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
		
		seg[no] = max(seg[no << 1], seg[no << 1 | 1]);
	}
	
	void prop(ll no, ll s, ll e)
	{
		if(!lazy[no])
			return;
		
		seg[no] = max(seg[no], lazy[no]);
		
		if(s != e)
		{
			lazy[no << 1] = max(lazy[no << 1], lazy[no]);
			lazy[no << 1 | 1] = max(lazy[no << 1 | 1], lazy[no]);
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
			seg[no] = max(seg[no], v);
			
			if(s != e)
			{
				lazy[no << 1] = max(lazy[no << 1], v);
				lazy[no << 1 | 1] = max(lazy[no << 1 | 1], v);
			}
			
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
			return -INF;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return max(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
}segt;
 
int num(ll X)
{
	return lower_bound(zip.begin(), zip.end(), X) - zip.begin() + 1;
}
 
void init(int L, int N, vector<ll> T, vector<int> W, int X, int M, vector<int> SS)
{
	x = X, LL = L;
	
	for(ll i = 0 ; i < N ; ++i)
	{
		if(W[i] <= X)
			continue;
		
		spd[++n] = W[i] - X;
		S[1][n] = T[i];
	}
	
	for(ll i = 0 ; i < M ; ++i)
		w[++m] = SS[i];
	
	for(ll i = 1 ; i < m ; ++i)
	{
		vector< pair< pair<ll, int>, int> > vv;
		
		for(ll j = 1 ; j <= n ; j++)
			vv.push_back({{S[i][j], spd[j]}, j});
		
		sort(vv.begin(), vv.end());
		
		ll maxx = 0;
		ll dist = w[i + 1] - w[i];
		
		for(auto &j : vv)
		{
			S[i + 1][j.se] = max(S[i][j.se] + dist * spd[j.se], maxx);
			maxx = max(maxx, S[i + 1][j.se]);
		}
	}
	
	for(ll i = 1 ; i < m ; ++i)
	{
		vector<pll> vv;
		
		for(ll j = 1 ; j <= n ; ++j)
			vv.push_back({S[i][j], S[i + 1][j]});
		
		sort(vv.begin(), vv.end());
		
		for(ll j = n - 1 ; j >= 0 ; --j)
			qry.push_back(vv[j]);
	}
	
	for(auto &i : qry)
	{
		zip.push_back(i.fi + 1);
		zip.push_back(i.se);
	}
	
	zip.push_back(0);
	compress(zip);
	
	for(auto &i : qry)
	{
		i.fi = num(i.fi + 1);
		i.se = num(i.se);
	}
	
	siz = (ll)zip.size();
	
	segt.init(1, 1, siz);
	
	ll siz2 = (ll)qry.size() - 1;
	
	for(ll i = siz2 ; i >= 0 ; --i)
	{
		ll gap = segt.query(1, 1, siz, qry[i].se, qry[i].se);
		segt.update(1, 1, siz, qry[i].fi, qry[i].se, gap);
	}
	
	for(ll i = 1 ; i <= siz ; ++i)
		QRY[i] = segt.query(1, 1, siz, i, i);
}
 
ll arrival_time(ll Y)
{
	ll idx = upper_bound(zip.begin(), zip.end(), Y) - zip.begin();
	ll gap = QRY[idx];
	
	if(gap == zip[idx - 1])
		return Y + x * LL;
	
	return gap + x * LL;
}