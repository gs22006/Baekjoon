#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fi first
#define se second

ll ss = 1000000007;
ll n;
vector< pair<ll, ll> > vec[250010];
ll IN[250010], OUT[250010];
ll siz[250010];
ll gap[250010], nu[250010];
ll tp[250010];
ll cc;
ll deg[250010];
ll spa[250010][21];
ll dep[250010], dist1[250010];
ll st;
ll ans;

void dfs(ll here, ll pa)
{
	siz[here] = 1;
	
	for(ll i = 0 ; i < (ll)vec[here].size() ; i++)
	{
		ll nxt = vec[here][i].fi;
		
		if(nxt == pa)
			continue;
		
		dfs(nxt, here);
		siz[here] += siz[nxt];
		
		if(siz[vec[here][0].fi] < siz[vec[here][i].fi] || vec[here][0].fi == pa)
			swap(vec[here][0], vec[here][i]);
	}
}

void dfs2(ll here, ll pa)
{
	IN[here] = ++cc;
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		if(i == vec[here][0])
			tp[i.fi] = tp[here];
		else
			tp[i.fi] = i.fi;
		
		dep[i.fi] = dep[here] + 1;
		dist1[i.fi] = (dist1[here] + i.se) % ss;
		dfs2(i.fi, here);
		gap[IN[i.fi] - 1] = i.se;
	}
	
	OUT[here] = cc;
}

struct node
{
	ll minn, sminn, sum, mcnt;
};

struct segtree
{
	node seg[1000010];
	
	void init(ll no, ll s, ll e)
	{
		if(s == e)
		{
			seg[no].minn = 0;
			seg[no].sminn = (1LL << 50);
			seg[no].sum = 0;
			seg[no].mcnt = gap[s];
			
			return;
		}
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
		
		seg[no].mcnt = (seg[no << 1].mcnt + seg[no << 1 | 1].mcnt) % ss;
	}
	
	void prop(ll no, ll s, ll e)
	{
		if(s == e)
			return;
		
		if(seg[no << 1].minn < seg[no].minn)
		{
			seg[no << 1].sum = (seg[no << 1].sum + (seg[no].minn - seg[no << 1].minn) * seg[no << 1].mcnt % ss) % ss;
			seg[no << 1].minn = seg[no].minn;
		}
		
		if(seg[no << 1 | 1].minn < seg[no].minn)
		{
			seg[no << 1 | 1].sum = (seg[no << 1 | 1].sum + (seg[no].minn - seg[no << 1 | 1].minn) * seg[no << 1 | 1].mcnt % ss) % ss;
			seg[no << 1 | 1].minn = seg[no].minn;
		}
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s || v <= seg[no].minn)
			return;
		
		if(l <= s && e <= r && v < seg[no].sminn)
		{
			seg[no].sum = (seg[no].sum + (v - seg[no].minn) * seg[no].mcnt % ss) % ss;
			seg[no].minn = v;
			prop(no, s, e);
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		if(s == e)
			return; //??
		
		if(seg[no << 1].minn == seg[no << 1 | 1].minn)
		{
			seg[no].minn = seg[no << 1].minn;
			seg[no].mcnt = (seg[no << 1].mcnt + seg[no << 1 | 1].mcnt) % ss;
			seg[no].sminn = min(seg[no << 1].sminn, seg[no << 1 | 1].sminn);
		}
		
		else if(seg[no << 1].minn < seg[no << 1 | 1].minn)
		{
			seg[no].minn = seg[no << 1].minn;
			seg[no].mcnt = seg[no << 1].mcnt;
			seg[no].sminn = min(seg[no << 1].sminn, seg[no << 1 | 1].minn);
		}
		
		else if(seg[no << 1].minn > seg[no << 1 | 1].minn)
		{
			seg[no].minn = seg[no << 1 | 1].minn;
			seg[no].mcnt = seg[no << 1 | 1].mcnt;
			seg[no].sminn = min(seg[no << 1 | 1].sminn, seg[no << 1].minn);
		}
		
		seg[no].sum = (seg[no << 1].sum + seg[no << 1 | 1].sum) % ss;
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no].sum;
		
		ll LL = query(no << 1, s, (s + e) >> 1, l, r);
		ll RR = query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
		
		return (LL + RR) % ss;
	}
}segt;

ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if((1LL << i) <= cha)
		{
			cha -= (1LL << i);
			X = spa[X][i];
		}
	}
	
	if(X == Y)
		return X;
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(spa[X][i] != spa[Y][i])
		{
			X = spa[X][i];
			Y = spa[Y][i];
		}
	}
	
	return spa[X][0];
}

ll dist(ll X, ll Y)
{
	return (dist1[X] + dist1[Y] - dist1[LCA(X, Y)] * 2 % ss) % ss;
}

void update1(ll X, ll Y, ll v)
{
	while(tp[X] != tp[Y])
	{
		if(dep[tp[X]] < dep[tp[Y]])
			swap(X, Y);
		
		segt.update(1, 1, cc - 1, max(1LL, IN[tp[X]] - 1), IN[X] - 1, v);
		X = spa[tp[X]][0];
	}
	
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	if(IN[Y] <= IN[X] - 1)
		segt.update(1, 1, cc - 1, IN[Y], IN[X] - 1, v);
}

ll query1(ll X, ll Y)
{
	ll ret = 0;
	
	while(tp[X] != tp[Y])
	{
		if(dep[tp[X]] < dep[tp[Y]])
			swap(X, Y);
		
		ret = (ret + segt.query(1, 1, cc - 1, max(1LL, IN[tp[X]] - 1), IN[X] - 1)) % ss;
		X = spa[tp[X]][0];
	}
	
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	if(IN[Y] <= IN[X] - 1)
		ret = (ret + segt.query(1, 1, cc - 1, IN[Y], IN[X] - 1)) % ss;
	
	return ret;
}

int maintenance_costs_sum(vector<int> U, vector<int> V, vector<int> W)
{
	n = (ll)U.size() + 1;
	
	for(ll i = 0 ; i < n - 1 ; i++)
	{
		U[i]++, V[i]++;
		
		vec[U[i]].push_back({V[i], W[i]});
		vec[V[i]].push_back({U[i], W[i]});
	}
	
	dfs(1, -1);
	tp[1] = 1;
	dfs2(1, -1);
	
	for(ll i = 1 ; i <= cc ; i++)
		nu[i] = (nu[i - 1] + gap[i]) % ss;
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	segt.init(1, 1, cc - 1);
	
	for(ll i = 2 ; i <= n ; i++)
	{
		ll S = i - 1;
		ll E = i;
		
		ll gye = dist(S, E) * (i - 1) % ss;
		gye = (gye - query1(S, E)) % ss;
		
		ans = (ans + gye * (n - i + 1) % ss) % ss;
		update1(S, E, i - 1);
	}
	
	ans = ans % ss < 0 ? ans % ss + ss : ans % ss;
	return (int)ans;
}