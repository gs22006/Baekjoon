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

ll n, N;
ll all, bll;
vector<ll> vec[600010];
ll m;
ll dep[600010], spa[600010][21];
vector<pll> a[600010];
vector<pll> pre[600010], suf[600010];
vector< pair<pll, ll> > qry, qry2[600010];
pll Q[600010];
ll siz[600010];
ll ans[600010];
ll cc;
ll qans[600010];
ll rdist[600010], sub[600010], R[600010];

void dfs0(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs0(i, here);
	}
}

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
	return dep[X] + dep[Y] - 2 * dep[LCA(X, Y)];
}

ll moveK(ll X, ll Y, ll K)
{
	ll LC = LCA(X, Y);
	ll V = -1, T = 0;
	
	if(dep[X] - dep[LC] >= K)
	{
		T = K;
		V = X;
	}
	
	else
	{
		K -= dep[X] - dep[LC];
		T = dep[Y] - dep[LC] - K;
		V = Y;
	}
	
	for(ll i = 20 ; i >= 0 ; i--)
	{
		if((1LL << i) <= T)
		{
			T -= (1LL << i);
			V = spa[V][i];
		}
	}
	
	return V;
}

pll merge(pll X, pll Y)
{
	if(X.se < Y.se)
		swap(X, Y);
	
	ll D = dist(X.fi, Y.fi);
	
	if(X.se + Y.se < D)
		return {0, -1};
	
	if(X.se >= Y.se + D)
		return Y;
	
	ll ret1 = moveK(X.fi, Y.fi, (D + X.se - Y.se) / 2);
	ll ret2 = (X.se + Y.se - D) / 2;
	
	return {ret1, ret2};
}

ll maxx;
ll sum[600010];
ll col[600010];
vector<ll> vv;
vector< pair<pll, ll> > qnow;

void dfs(ll here, ll pa)
{
	sub[here] = 1;
	
	for(auto &i : qry2[here])
		qnow.push_back(i);
	
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		dfs(i, here);
		sub[here] += sub[i];
	}
}

ll get_centroid(ll here, ll pa, ll SIZ)
{
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		if(sub[i] * 2 > SIZ)
			return get_centroid(i, here, SIZ);
	}
	
	return here;
}

ll maxx2;

void dfs2(ll here, ll pa)
{
	rdist[here] = rdist[pa] + 1;
	maxx2 = max(maxx2, rdist[here]);
	
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		dfs2(i, here);
	}
}

void dfs3(ll here, ll pa, ll C)
{
	maxx = max(maxx, rdist[here]);
	col[here] = C;
	vv.push_back(here);
	
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		dfs3(i, here, C);
	}
}

void f(ll here)
{
	qnow.clear();
	maxx2 = 0;
	
	dfs(here, 0);
	
	ll cent = get_centroid(here, 0, sub[here]);
	
	rdist[0] = -1;
	dfs2(cent, 0);
	
	ll CC = 0;
	vector< vector<ll> > nu;
	vector<ll> nu2;
	
	for(ll i = 0 ; i <= maxx2 ; i++)
		nu2.push_back(0);
	
	if(cent <= N)
		nu2[0]++;
	
	for(auto &i : vec[cent])
	{
		if(R[i])
			continue;
		
		maxx = 0, vv.clear();
		dfs3(i, cent, CC);
		
		vector<ll> tmp;
		
		for(ll j = 0 ; j <= maxx ; j++)
			tmp.push_back(0);
		
		nu.push_back(tmp);
		
		for(auto &j : vv)
		{
			if(j <= N)
			{
				nu[CC][rdist[j]]++;
				nu2[rdist[j]]++;
			}
		}
		
		for(ll j = 1 ; j <= maxx ; j++)
			nu[CC][j] += nu[CC][j - 1];
		
		CC++;
	}
	
	for(ll i = 1 ; i <= maxx2 ; i++)
		nu2[i] += nu2[i - 1];
	
	for(auto &i : qnow)
	{
		if(i.fi.fi == cent)
		{
			ll idx = min((ll)nu2.size() - 1, i.fi.se);
			qans[i.se] += nu2[idx];
		}
		
		else
		{
			if(rdist[i.fi.fi] > i.fi.se)
				continue;
			
			ll idx1 = min((ll)nu2.size() - 1, i.fi.se - rdist[i.fi.fi]);
			ll idx2 = min((ll)nu[col[i.fi.fi]].size() - 1, i.fi.se - rdist[i.fi.fi]);
			
			qans[i.se] += nu2[idx1] - nu[col[i.fi.fi]][idx2];
		}
	}
	
	R[cent] = 1;
	
	for(auto &i : vec[cent])
	{
		if(R[i])
			continue;
		
		f(i);
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(n + i);
		vec[n + i].push_back(all);
		vec[n + i].push_back(bll);
		vec[bll].push_back(n + i);
	}
	
	N = n;
	n += n - 1;
	
	dfs0(1, 0);
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	cin >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> siz[i];
		
		for(ll j = 0 ; j < siz[i] ; j++)
		{
			cin >> all >> bll;
			
			bll *= 2;
			a[i].push_back({all, bll});
			suf[i].push_back({0, 0});
		}
		
		pre[i].push_back(a[i][0]);
		
		for(ll j = 1 ; j < siz[i] ; j++)
			pre[i].push_back(merge(pre[i][j - 1], a[i][j]));
		
		suf[i][siz[i] - 1] = a[i][siz[i] - 1];
		
		for(ll j = siz[i] - 2 ; j >= 0 ; j--)
			suf[i][j] = merge(suf[i][j + 1], a[i][j]);
		
		if(siz[i] == 1)
		{
			ans[i] = N;
			continue;
		}
		
		for(ll j = 0 ; j < siz[i] ; j++)
		{
			if(j == 0)
			{
				qry.push_back({suf[i][j + 1], ++cc});
				Q[cc] = {i, 1};
			}
			
			else if(j == siz[i] - 1)
			{
				qry.push_back({pre[i][j - 1], ++cc});
				Q[cc] = {i, 1};
			}
			
			else
			{
				qry.push_back({merge(pre[i][j - 1], suf[i][j + 1]), ++cc});
				Q[cc] = {i, 1};
			}
			
			if(qry.back().fi.se == -1)
				qry.pop_back();
		}
		
		qry.push_back({pre[i][siz[i] - 1], ++cc});
		Q[cc] = {i, -(siz[i] - 1)};
		
		if(qry.back().fi.se == -1)
			qry.pop_back();
	}
	
	for(auto &i : qry)
		qry2[i.fi.fi].push_back(i);
	
	f(1);
	
	for(auto &i : qry)
		ans[Q[i.se].fi] += Q[i.se].se * qans[i.se];
	
	for(ll i = 1 ; i <= m ; i++)
		cout << ans[i] en;
	
	return 0;
}