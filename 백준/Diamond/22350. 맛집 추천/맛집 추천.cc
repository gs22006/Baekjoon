#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

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

ll n, m;
ll all, bll, cll;
vector<ll> vec[100010], cvec[100010];
vector<pll> a[100010], sum[100010], sum2[100010];
ll R[100010];
ll cpa[100010];
ll siz[100010];
ll dep[100010], spa[100010][21];
vector< pair<pll, ll> > con[100010];
ll ans;
ll dp[100010];

void dfs2(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	spa[here][0] = pa;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs2(i, here);
	}
}

void dfs0(ll here, ll pa)
{
	siz[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		dfs0(i, here);
		siz[here] += siz[i];
	}
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

ll dist(ll X, ll Y)
{
	return dep[X] + dep[Y] - 2 * dep[LCA(X, Y)];
}

ll get_centroid(ll here, ll pa, ll SIZ)
{
	for(auto &i : vec[here])
	{
		if(i == pa || R[i])
			continue;
		
		if(siz[i] * 2 > SIZ)
			return get_centroid(i, here, SIZ);
	}
	
	return here;
}

ll frt = 0;

void f(ll here, ll pa)
{
	dfs0(here, 0);
	
	ll rt = get_centroid(here, 0, siz[here]);
	
	if(!frt)
		frt = rt;
	
	if(pa)
	{
		cpa[rt] = pa;
		cvec[pa].push_back(rt);
		cvec[rt].push_back(pa);
	}
	
	R[rt] = 1;
	
	for(auto &i : vec[rt])
	{
		if(R[i])
			continue;
		
		f(i, rt);
	}
}

void update(ll X, ll D, ll G)
{
	ll l = 0, r = (ll)sum[X].size() - 1;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		
		if(sum[X][mid].fi < D)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	if(l == (ll)sum[X].size() || sum[X][l].fi != D)
	{
		//cout << X sp << "push " << D sp << G en;
		sum[X].push_back({D, G});
		sort(sum[X].begin(), sum[X].end());
	}
	
	else
	{
		sum[X][l].se += G;
		//cout << X sp << sum[X][l].fi sp << "+" << sum[X][l].se en;
	}
}

ll query(ll X, ll D)
{
	ll l = 0, r = (ll)sum[X].size() - 1;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		
		if(sum[X][mid].fi < D)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	if(l == sum[X].size() || sum[X][l].fi != D)
		return 0;
	//cout << "FFF" << X sp << sum[X][l].fi sp << sum[X][l].se en;
	return sum[X][l].se;
}

void update2(ll X, ll D, ll G)
{
	ll l = 0, r = (ll)sum2[X].size() - 1;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		
		if(sum2[X][mid].fi < D)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	if(l == (ll)sum2[X].size() || sum2[X][l].fi != D)
	{
		//cout << X sp << "push2 " << D sp << G en;
		sum2[X].push_back({D, G});
		sort(sum2[X].begin(), sum2[X].end());
	}
	
	else
	{
		sum2[X][l].se += G;
		//cout << X sp << sum2[X][l].fi sp << "+2" << sum2[X][l].se en;
	}
}

ll query2(ll X, ll D)
{
	ll l = 0, r = (ll)sum2[X].size() - 1;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		
		if(sum2[X][mid].fi < D)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	if(l == sum2[X].size() || sum2[X][l].fi != D)
		return 0;
	//cout << "FFF2" << X sp << sum2[X][l].fi sp << sum2[X][l].se en;
	return sum2[X][l].se;
}

void dfs(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
	}
	
	ll sum1 = 0;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		sum1 += dp[i];
	}
	
	dp[here] = max(dp[here], sum1);
	
	for(auto &i : con[here])
	{
		ll U = i.fi.fi;
		ll D = i.fi.se;
		ll G = i.se;
		ll last = -1;
		
		D++;
		
		//cout << "NOW : " << U sp << D sp << G en;
		
		while(1)
		{
			ll DD = 0;
			
			DD = dist(i.fi.fi, U);
			
			G += query(U, D - DD);
			
			if(last != -1)
			{
				G -= query2(last, D - DD);
				//cout << "-qry : " << last sp << D - DD sp << query(last, D - DD) en;
			}
			
			//cout << "qry : " << U sp << D - DD sp << query(U, D - DD) en;
			
			if(U == frt)
				break;
			
			last = U;
			U = cpa[U];
		}
		
		dp[here] = max(dp[here], G);
	}
	
	ll now = here;
	
	while(1)
	{
		update(now, dist(here, now), dp[here]);
		
		if(cpa[now])
			update2(now, dist(cpa[now], here), dp[here]);
		
		//cout << "update : " << here sp << now sp << dist(here, now) sp << dp[here] en;
		//cout << "update2 : " << here sp << now sp << dist(cpa[now], here) sp << dp[here] en;
		
		if(now == frt)
			break;
		
		now = cpa[now];
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs2(1, 0);
	
	spa[1][0] = 1;
	
	for(ll i = 1 ; i <= 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		
		ll won = all, won2 = bll;
		
		a[all].push_back({bll, cll});
		
		for(ll j = 20 ; j >= 0 ; j--)
		{
			if((1LL << j) <= bll)
			{
				all = spa[all][j];
				bll -= (1LL << j);
			}
		}
		
		con[all].push_back({{won, won2}, cll});
	}
	
	f(1, 0);
	
	//for(ll i = 1 ; i <= n ; i++)
		//cout << "SAD" << i sp << cpa[i] en;
	
	dfs(1, 0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		//cout << dp[i] en;
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	return 0;
}