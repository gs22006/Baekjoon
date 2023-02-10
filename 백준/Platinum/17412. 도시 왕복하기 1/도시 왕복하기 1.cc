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

struct Dinic
{
	ll Vtx;
	ll flow[3010][3010];
	ll capa[3010][3010];
	vector<ll> adj[3010];
	ll work[3010], level[3010];
	ll Srce, Snk;
	
	void init(ll U, ll V, ll W)
	{
		Vtx = U;
		Srce = V;
		Snk = W;
	}
	
	void add_edge(ll U, ll V, ll W, ll DIR)
	{
		adj[U].push_back(V);
		adj[V].push_back(U);
		capa[U][V] += W;
		
		if(!DIR)
			capa[V][U] += W;
	}
	
	ll BFS(void)
	{
		for(ll i = 1 ; i <= Vtx ; i++)
			level[i] = -1;
		
		queue<ll> QQ;
		
		QQ.push(Srce);
		level[Srce] = 0;
		
		while(!QQ.empty())
		{
			ll qqqq = QQ.front();
			QQ.pop();
			
			for(auto &i : adj[qqqq])
			{
				if(level[i] == -1 && (capa[qqqq][i] - flow[qqqq][i]) > 0)
				{
					QQ.push(i);
					level[i] = level[qqqq] + 1;
				}
			}
		}
		
		return level[Snk] != -1;
	}
	
	ll DFS(ll here, ll minini)
	{
		if(here == Snk)
			return minini;
		
		for(ll &i = work[here] ; i < (ll)adj[here].size() ; i++)
		{
			ll nxt = adj[here][i];
			
			if(level[nxt] == level[here] + 1 && (capa[here][nxt] - flow[here][nxt]) > 0)
			{
				ll GAP = DFS(nxt, min(minini, capa[here][nxt] - flow[here][nxt]));
				
				if(GAP > 0)
				{
					flow[here][nxt] += GAP;
					flow[nxt][here] -= GAP;
					
					return GAP;
				}
			}
		}
		
		return 0;
	}
	
	ll max_flow(void)
	{
		ll ret = 0;
		
		while(BFS())
		{
			for(ll i = 1 ; i <= Vtx ; i++)
				work[i] = 0;
			
			while(1)
			{
				ll FLOW = DFS(Srce, INF);
				
				if(!FLOW)
					break;
				
				ret += FLOW;
			}
		}
		
		return ret;
	}
}mxfl;

ll n, m;
ll all, bll;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		mxfl.add_edge(all, bll, 1, 1);
	}
	
	mxfl.init(n, 1, 2);
	
	cout << mxfl.max_flow();
	return 0;
}