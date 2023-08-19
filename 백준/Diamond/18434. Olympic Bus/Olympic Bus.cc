#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3 / 100
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

struct gujo
{
	ll V, C, D, num;
};

ll n, m;
ll all, bll, cll, dll;
vector< pair<pll, pll> > edg;
vector<gujo> vec[210], yuk[210];
ll ans[50010];
ll dist[210][2];
ll dist2[50010][210][2];
ll bk[210][2], bk2[210][2];
ll chk[210], chk2[50010];
ll ans2 = INF, ans3;

void dijkstra(ll X)
{
	for(ll i = 1 ; i <= n ; i++)
		dist[i][0] = INF, bk[i][0] = bk2[i][0] = chk[i] = 0;
	
	dist[1][0] = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll minn = INF, w = -1;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(chk[j])
				continue;
			
			if(minn > dist[j][0])
			{
				minn = dist[j][0];
				w = j;
			}
		}
		
		if(w == -1)
			break;
		
		chk[w] = 1;
		
		for(auto &j : vec[w])
		{
			if(j.num == X)
				continue;
			
			if(dist[j.V][0] > dist[w][0] + j.C)
			{
				dist[j.V][0] = dist[w][0] + j.C;
				bk[j.V][0] = w;
				bk2[j.V][0] = j.num;
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		dist[i][1] = INF, bk[i][1] = bk2[i][1] = chk[i] = 0;
	
	dist[n][1] = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll minn = INF, w = -1;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			if(chk[j])
				continue;
			
			if(minn > dist[j][1])
			{
				minn = dist[j][1];
				w = j;
			}
		}
		
		if(w == -1)
			break;
		
		chk[w] = 1;
		
		for(auto &j : yuk[w])
		{
			if(j.num == X)
				continue;
			
			if(dist[j.V][1] > dist[w][1] + j.C)
			{
				dist[j.V][1] = dist[w][1] + j.C;
				bk[j.V][1] = w;
				bk2[j.V][1] = j.num;
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		dist2[X][i][0] = dist[i][0], dist2[X][i][1] = dist[i][1];
}

void solve(void)
{
	dijkstra(0);
	
	ans3 += dist2[0][n][0];
	
	vector<ll> path;
	
	for(ll i = n ; i > 0 ; i = bk[i][0])
		path.push_back(bk2[i][0]);
	
	for(ll i = 1 ; i <= m ; i++)
		chk2[i] = 0;
	
	for(auto &i : path)
	{
		dijkstra(i);
		chk2[i] = 1;
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(!chk2[i])
			ans[i] += min(dist2[0][n][0], dist2[0][edg[i - 1].fi.se][0] + dist2[0][edg[i - 1].fi.fi][1] + edg[i - 1].se.fi);
		else
			ans[i] += min(dist2[i][n][0], dist2[i][edg[i - 1].fi.se][0] + dist2[i][edg[i - 1].fi.fi][1] + edg[i - 1].se.fi);
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll >> dll;
		
		edg.push_back({{all, bll}, {cll, dll}});
		vec[all].push_back({bll, cll, dll, i});
		yuk[bll].push_back({all, cll, dll, i});
		ans[i] += dll;
	}
	
	solve();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		vec[i].clear();
		yuk[i].clear();
	}
	
	ll cc = 0;
	
	for(auto &i : edg)
	{
		if(i.fi.fi == 1)
			i.fi.fi = n;
		else if(i.fi.fi == n)
			i.fi.fi = 1;
		
		if(i.fi.se == 1)
			i.fi.se = n;
		else if(i.fi.se == n)
			i.fi.se = 1;
		
		cc++;
		vec[i.fi.fi].push_back({i.fi.se, i.se.fi, i.se.se, cc});
		yuk[i.fi.se].push_back({i.fi.fi, i.se.fi, i.se.se, cc});
	}
	
	solve();
	
	for(ll i = 1 ; i <= m ; i++)
		ans2 = min(ans2, ans[i]);
	
	ans2 = min(ans2, ans3);
	
	if(ans2 >= INF / 10)
		cout << -1;
	else
		cout << ans2;
	
	return 0;
}