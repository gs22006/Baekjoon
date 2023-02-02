#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ll;
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

ll n, q;
vector<ll> vec[500010];
ll all, bll, cll;
ll dep[500010], siz[500010], tp[500010], par[500010];
ll IN[500010], OUT[500010], cc;

struct lazyseg
{
	ll seg[2000010];
	pair<ll, ll> lazy[2000010];
	
	void init(ll no, ll s, ll e)
	{
		lazy[no] = {1, 0};
		
		if(s == e)
			return;
		
		init(no * 2, s, (s + e) / 2);
		init(no * 2 + 1, (s + e) / 2 + 1, e);
	}
	
	void prop(ll no, ll s, ll e)
	{
		seg[no] = (seg[no] * lazy[no].fi  + lazy[no].se * (e - s + 1) ) ;
		
		if(s != e)
		{
			lazy[no * 2].se = (lazy[no * 2].se * lazy[no].fi  + lazy[no].se) ;
			lazy[no * 2].fi = lazy[no * 2].fi * lazy[no].fi ;
			lazy[no * 2 + 1].se = (lazy[no * 2 + 1].se * lazy[no].fi  + lazy[no].se) ;
			lazy[no * 2 + 1].fi = lazy[no * 2 + 1].fi * lazy[no].fi ;
		}
		
		lazy[no] = {1, 0};
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, pair<ll, ll> F)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			seg[no] = (seg[no] * F.fi  + F.se * (e - s + 1) ) ;
			
			if(s != e)
			{
				lazy[no * 2].se = (lazy[no * 2].se * F.fi  + F.se) ;
				lazy[no * 2].fi = lazy[no * 2].fi * F.fi ;
				lazy[no * 2 + 1].se = (lazy[no * 2 + 1].se * F.fi  + F.se) ;
				lazy[no * 2 + 1].fi = lazy[no * 2 + 1].fi * F.fi ;
			}
			
			return;
		}
		
		update(no * 2, s, (s + e) / 2, l, r, F);
		update(no * 2 + 1, (s + e) / 2 + 1, e, l, r, F);
		
		seg[no] = (seg[no * 2] + seg[no * 2 + 1]) ;
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return (query(no * 2, s, (s + e) / 2, l, r) + query(no * 2 + 1, (s + e) / 2 + 1, e, l, r)) ;
	}
}segt;

void dfs1(ll here, ll pa)
{
	siz[here] = 1;
	dep[here] = dep[pa] + 1;
	par[here] = pa;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs1(i, here);
		siz[here] += siz[i];
		
		if(siz[i] > siz[vec[here][0]])
			swap(i, vec[here][0]);
	}
}

void dfs2(ll here, ll pa)
{
	IN[here] = ++cc;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		if(i == vec[here][0])
			tp[i] = tp[here];
		else
			tp[i] = i;
		
		dfs2(i, here);
	}
	
	OUT[here] = cc;
}

void query1(ll X, ll V)
{
	segt.update(1, 1, cc, IN[X], OUT[X], {1, V});
}

void query2(ll X, ll Y, ll V)
{
	while(tp[X] != tp[Y])
	{
		if(dep[tp[X]] < dep[tp[Y]])
			swap(X, Y);
		
		segt.update(1, 1, cc, IN[tp[X]], IN[X], {1, V});
		X = par[tp[X]];
	}
	
	if(dep[X] > dep[Y])
		swap(X, Y);
	
	segt.update(1, 1, cc, IN[X], IN[Y], {1, V});
}

void query3(ll X, ll V)
{
	segt.update(1, 1, cc, IN[X], OUT[X], {V, 0});
}

void query4(ll X, ll Y, ll V)
{
	while(tp[X] != tp[Y])
	{
		if(dep[tp[X]] < dep[tp[Y]])
			swap(X, Y);
		
		segt.update(1, 1, cc, IN[tp[X]], IN[X], {V, 0});
		X = par[tp[X]];
	}
	
	if(dep[X] > dep[Y])
		swap(X, Y);
	
	segt.update(1, 1, cc, IN[X], IN[Y], {V, 0});
}

ll query5(ll X)
{
	return segt.query(1, 1, cc, IN[X], OUT[X]);
}

ll query6(ll X, ll Y)
{
	ll ret = 0;
	
	while(tp[X] != tp[Y])
	{
		if(dep[tp[X]] < dep[tp[Y]])
			swap(X, Y);
		
		ret = (ret + segt.query(1, 1, cc, IN[tp[X]], IN[X])) ;
		X = par[tp[X]];
	}
	
	if(dep[X] > dep[Y])
		swap(X, Y);
	
	ret = (ret + segt.query(1, 1, cc, IN[X], IN[Y])) ;
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs1(1, 0);
	dfs2(1, 0);
	segt.init(1, 1, cc);
	
	while(q--)
	{
		cin >> all;
		
		if(all == 1)
		{
			cin >> all >> bll;
			query1(all, bll);
		}
		
		else if(all == 2)
		{
			cin >> all >> bll >> cll;
			query2(all, bll, cll);
		}
		
		else if(all == 3)
		{
			cin >> all >> bll;
			query3(all, bll);
		}
		
		else if(all == 4)
		{
			cin >> all >> bll >> cll;
			query4(all, bll, cll);
		}
		
		else if(all == 5)
		{
			cin >> all;
			cout << query5(all) en;
		}
		
		else if(all == 6)
		{
			cin >> all >> bll;
			cout << query6(all, bll) en;
		}
	}
	
	return 0;
}