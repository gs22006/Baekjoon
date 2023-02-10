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

struct MinCostMaxFlow
{
	ll Vtx;
	ll flow[3010][3010];
	ll capa[3010][3010];
	ll cost[3010][3010];
	vector<ll> adj[3010];
	ll bfr[3010], dist[3010];
	ll inQ[3010];
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
		}
		
		return {ret2, ret};
	}
	
	void GrphChk(void)
	{
		cout << "Number of Vertex : " << Vtx en;
		cout << "Source : " << Srce en;
		cout << "Sink : " << Snk en;
		
		for(ll i = 1 ; i <= Vtx ; i++)
		{
			for(auto &j : adj[i])
				cout << i sp << "-> " << j en;
		}
	}
}mcmf;

ll n, m;
ll a[110], b[110];
ll c[110][110];

int main(void)
{
	//fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		mcmf.add_edge(m + i, n + m + 2, a[i], 0, 1);
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> b[i];
		mcmf.add_edge(n + m + 1, i, b[i], 0, 1);
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			cin >> c[i][j];
			mcmf.add_edge(i, j + m, INF, c[i][j], 1);
		}
	}
	
	mcmf.init(n + m + 2, n + m + 1, n + m + 2);
	
	cout << mcmf.MCMF().se;
	return 0;
}