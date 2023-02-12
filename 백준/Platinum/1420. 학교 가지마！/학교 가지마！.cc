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
char a[110][110];
ll num[110][110], cc;
ll dx[10] = {-1, 1, 0, 0};
ll dy[10] = {0, 0, -1, 1};
pll K, H;

struct DinicAdjlist //Caution Same Edge
{
	ll Vtx;
	vector< pair<ll, pll> > adj[20010];
	vector<ll> flow, capa;
	ll work[20010], level[20010];
	ll Srce, Snk;
	ll Enum;
	
	void init(ll U, ll V, ll W)
	{
		Vtx = U;
		Srce = V;
		Snk = W;
	}
	
	void add_edge(ll U, ll V, ll W, ll DIR)
	{
		adj[U].push_back({V, {Enum, Enum + 1}});
		capa.push_back(W);
		flow.push_back(0);
		Enum++;
		
		adj[V].push_back({U, {Enum, Enum - 1}});
		capa.push_back(0);
		flow.push_back(0);
		Enum++;
		
		if(!DIR)
			capa.back() += W;
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
				if(level[i.fi] == -1 && (capa[i.se.fi] - flow[i.se.fi]) > 0)
				{
					QQ.push(i.fi);
					level[i.fi] = level[qqqq] + 1;
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
			pair<ll, pll> nxt = adj[here][i];
			
			if(level[nxt.fi] == level[here] + 1 && (capa[nxt.se.fi] - flow[nxt.se.fi]) > 0)
			{
				ll GAP = DFS(nxt.fi, min(minini, capa[nxt.se.fi] - flow[nxt.se.fi]));
				
				if(GAP > 0)
				{
					flow[nxt.se.fi] += GAP;
					flow[nxt.se.se] -= GAP;
					
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

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			num[i][j] = ++cc;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			mxfl.add_edge(num[i][j], num[i][j] + cc, 1, 1);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(a[i][j] == 'K')
				K = {i, j};
			else if(a[i][j] == 'H')
				H = {i, j};
			
			for(ll d = 0 ; d < 4 ; d++)
			{
				ll nx = i + dx[d];
				ll ny = j + dy[d];
				
				if(a[i][j] == 'K' && a[nx][ny] == 'H')
				{
					cout << -1;
					return 0;
				}
				
				if(nx <= 0 || ny <= 0 || nx > n || ny > m)
					continue;
				
				if(a[i][j] != '#' && a[nx][ny] != '#')
					mxfl.add_edge(num[i][j] + cc, num[nx][ny], 987654321, 1);
			}
		}
	}
	
	mxfl.init(cc * 2, num[K.fi][K.se] + cc, num[H.fi][H.se]);
	
	cout << mxfl.max_flow();
	return 0;
}