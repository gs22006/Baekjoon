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

ll n, m;
ll all, bll, cll;
ll ans = MAX;

struct MinCostMaxFlow
{
	ll Vtx;
	ll flow[2010][2010];
	ll capa[2010][2010];
	ll cost[2010][2010];
	vector<ll> adj[2010];
	ll bfr[2010], dist[2010];
	ll inQ[2010];
	ll Srce, Snk;
	
	void init(ll U, ll V, ll W)
	{
		Vtx = U;
		Srce = V;
		Snk = W;
	}
	
	void add_edge(ll U, ll V, ll W, ll COST, ll DIR)
	{
		adj[U].push_back(V);
		adj[V].push_back(U);
		capa[U][V] += W;
		cost[U][V] = COST;
		cost[V][U] = -COST;
		
		if(!DIR)
			capa[V][U] += W;
	}
	
	pll MCMF(void)
	{
		ll ret = 0;
		ll ret2 = 0;
		
		while(1)
		{
			queue<ll> QQ;
			
			for(ll i = 1 ; i <= Vtx ; i++)
			{
				bfr[i] = -1;
				dist[i] = INF;
				inQ[i] = 0;
			}
			
			dist[Srce] = 0;
			inQ[Srce] = 1;
			QQ.push(Srce);
			
			while(!QQ.empty())
			{
				ll qqqq = QQ.front();
				QQ.pop();
				
				inQ[qqqq] = 0;
				
				for(auto &i : adj[qqqq])
				{
					if(dist[i] > dist[qqqq] + cost[qqqq][i] && (capa[qqqq][i] - flow[qqqq][i]) > 0)
					{
						dist[i] = dist[qqqq] + cost[qqqq][i];
						bfr[i] = qqqq;
						
						if(!inQ[i])
						{
							QQ.push(i);
							inQ[i] = 1;
						}
					}
				}
			}
			
			if(bfr[Snk] == -1)
				break;
			
			ll minini = INF;
			
			for(ll i = Snk ; i != Srce ; i = bfr[i])
				minini = min(minini, capa[bfr[i]][i] - flow[bfr[i]][i]);
			
			ret2 += minini;
			
			for(ll i = Snk ; i != Srce ; i = bfr[i])
			{
				ret += minini * cost[bfr[i]][i];
				flow[bfr[i]][i] += minini;
				flow[i][bfr[i]] -= minini;
			}
			
			if(ret2 == 2)
				ans = min(ans, ret);
		}
		
		return {ret2, ret};
	}
}mcmf;

int main(void)
{
	fastio
	
	while(cin >> n >> m)
	{
		for(ll i = 1 ; i <= m ; i++)
		{
			cin >> all >> bll >> cll;
			mcmf.add_edge(all + n, bll, 1, cll, 1);
		}
		
		for(ll i = 1 ; i <= n ; i++)
			mcmf.add_edge(i, i + n, 1, 0, 1);
		
		ans = MAX;
		
		mcmf.init(n * 2, n + 1, n);
		mcmf.MCMF();
		
		cout << ans en;
		
		for(ll i = 1 ; i <= n * 2 ; i++)
		{
			for(ll j = 1 ; j <= n * 2 ; j++)
				mcmf.flow[i][j] = mcmf.capa[i][j] = mcmf.cost[i][j] = 0;
			
			mcmf.adj[i].clear();
			mcmf.bfr[i] = mcmf.dist[i] = mcmf.inQ[i] = 0;
		}
	}
	
	return 0;
}