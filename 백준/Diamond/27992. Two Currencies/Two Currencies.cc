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

struct gujo
{
	ll S, T, X, Y;
};

ll n, m, q;
ll all, bll;
pll edg[100010];
pll cost[100010];
vector<ll> vec[100010];
gujo qry[100010];
ll l[100010], r[100010], mid[100010];
ll IN[100010], OUT[100010], cc;
ll spa[100010][21], dep[100010];
ll ans[100010];

struct fenwicktree
{
	ll bit[100010];
	
	void init(void)
	{
		for(ll i = 1 ; i <= n ; i++)
			bit[i] = 0;
	}
	
	void update(ll w, ll v)
	{
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

void dfs0(ll here, ll pa)
{
	IN[here] = ++cc;
	spa[here][0] = pa;
	dep[here] = dep[pa] + 1;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
	}
	
	OUT[here] = cc;
}

ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if(cha >= (1LL << i))
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

int main(void)
{
	fastio
	
	cin >> n >> m >> q;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		edg[i] = {all, bll};
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		cost[i] = {bll, all};
	}
	
	sort(cost + 1, cost + 1 + m);
	
	for(ll i = 1 ; i <= q ; i++)
		cin >> qry[i].S >> qry[i].T >> qry[i].X >> qry[i].Y;
	
	dfs0(1, 0);
	
	for(ll i = 1 ; i < n ; i++)
	{
		if(dep[edg[i].fi] < dep[edg[i].se])
			swap(edg[i].fi, edg[i].se);
	}
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i <= q ; i++)
		l[i] = 1, r[i] = m;
	
	for(ll o = 0 ; o <= 20 ; o++)
	{
		vector<pll> Q;
		
		for(ll i = 1 ; i <= q ; i++)
		{
			mid[i] = (l[i] + r[i]) >> 1;
			
			if(l[i] <= r[i])
				Q.push_back({mid[i], i});
		}
		
		if(Q.empty())
			break;
		
		BIT.init();
		sort(Q.begin(), Q.end());
		
		ll p = 0;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			pll V = edg[cost[i].se];
			
			BIT.update(IN[V.fi], cost[i].fi);
			BIT.update(OUT[V.fi] + 1, -cost[i].fi);
			
			while(p < (ll)Q.size() && Q[p].fi <= i)
			{
				ll num = Q[p].se;
				ll gap = 0;
				
				gap = BIT.query(IN[qry[num].S]) + BIT.query(IN[qry[num].T]) - 2 * BIT.query(IN[LCA(qry[num].S, qry[num].T)]);
				
				if(gap > qry[num].Y)
					r[num] = mid[num] - 1;
				else
					l[num] = mid[num] + 1;
				
				p++;
			}
		}
	}
	
	vector<pll> Q;
	
	for(ll i = 1 ; i <= q ; i++)
		Q.push_back({r[i], i});
	
	sort(Q.begin(), Q.end());
	BIT.init();
	
	ll p = 0;
	
	while(p < (ll)Q.size() && Q[p].fi <= 0)
	{
		ll num = Q[p].se;
		ll gap = 0;
		
		ans[num] -= BIT.query(IN[qry[num].S]) + BIT.query(IN[qry[num].T]) - 2 * BIT.query(IN[LCA(qry[num].S, qry[num].T)]);
		p++;
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		pll V = edg[cost[i].se];
		
		BIT.update(IN[V.fi], 1);
		BIT.update(OUT[V.fi] + 1, -1);
		
		while(p < (ll)Q.size() && Q[p].fi <= i)
		{
			ll num = Q[p].se;
			ll gap = 0;
			
			ans[num] -= BIT.query(IN[qry[num].S]) + BIT.query(IN[qry[num].T]) - 2 * BIT.query(IN[LCA(qry[num].S, qry[num].T)]);
			p++;
		}
	}
	
	for(ll i = 1 ; i <= q ; i++)
		ans[i] += BIT.query(IN[qry[i].S]) + BIT.query(IN[qry[i].T]) - 2 * BIT.query(IN[LCA(qry[i].S, qry[i].T)]);
	
	for(ll i = 1 ; i <= q ; i++)
	{
		if(ans[i] > qry[i].X)
			cout << -1 en;
		else
			cout << qry[i].X - ans[i] en;
	}
	
	return 0;
}