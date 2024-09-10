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

ll n;
ll a[510];
ll all;

struct Dinic
{
	ll Vtx, Srce, Snk;
	ll capa[510][510], flow[510][510];
	vector<ll> adj[510];
	ll level[510], work[510], chch[510];
	
	void init(ll AAA, ll BBB, ll CCC)
	{
		Vtx = AAA;
		Srce = BBB;
		Snk = CCC;
	}
	
	void add_edge(ll U, ll V, ll W, ll dir)
	{
		capa[U][V] += W;
		adj[U].push_back(V);
		adj[V].push_back(U);
		
		if(!dir)
			capa[V][U] += W;
	}
	
	ll BFS(void)
	{
		queue<ll> q;
		
		for(ll i = 1 ; i <= Vtx ; i++)
			level[i] = -1;
		
		level[Srce] = 0;
		q.push(Srce);
		
		while(!q.empty())
		{
			ll qq = q.front();
			q.pop();
			
			for(auto &i : adj[qq])
			{
				if(capa[qq][i] - flow[qq][i] > 0 && level[i] == -1)
				{
					level[i] = level[qq] + 1;
					q.push(i);
				}
			}
		}
		
		return level[Snk] != -1;
	}
	
	ll dfs(ll here, ll mini)
	{
		if(here == Snk)
			return mini;
		
		for(ll &i = work[here] ; i < (ll)adj[here].size() ; i++)
		{
		    ll nxt = adj[here][i];
		    
			if(level[here] + 1 == level[nxt] && capa[here][nxt] - flow[here][nxt] > 0)
			{
    			ll gap = dfs(nxt, min(mini, capa[here][nxt] - flow[here][nxt]));
    			
    			if(gap > 0)
    			{
    				flow[here][nxt] += gap;
    				flow[nxt][here] -= gap;
    				
    				return gap;
    			}
			}
		}
		
		return 0;
	}
	
	ll get_flow(void)
	{
		ll ret = 0;
		
		while(BFS())
		{
			for(ll i = 1 ; i <= Vtx ; i++)
				work[i] = 0;
			
			while(1)
			{
				ll gap = dfs(Srce, INF);
				
				if(!gap)
					break;
				
				ret += gap;
			}
		}
		
		return ret;
	}
	
	pair< vector<ll>, vector<ll> > get_cut(void)
	{
	    for(ll i = 1 ; i <= Vtx ; i++)
	        chch[i] = 0;
	    
	    queue<ll> q;
	    vector<ll> ret, ret2;
	    
	    chch[Srce] = 1;
	    q.push(Srce);
	    
	    while(!q.empty())
	    {
	        ll qq = q.front();
	        q.pop();
	        
	        for(auto &i : adj[qq])
	        {
	            if(flow[qq][i] < 0)
	                continue;
	            
	            if(!chch[i] && capa[qq][i] - flow[qq][i] > 0)
	            {
	                chch[i] = 1;
	                q.push(i);
	            }
	        }
	    }
	    
	    for(ll i = 2 ; i < Vtx ; i++)
	    {
	        if(chch[i])
	            ret.push_back(i - 1);
	        else
	            ret2.push_back(i - 1);
	    }
	    
	    return {ret, ret2};
	}
}mxfl;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	mxfl.init(n + 2, 1, n + 2);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i] == 1)
			mxfl.add_edge(1, i + 1, INF, 0);
		else if(a[i] == 2)
			mxfl.add_edge(i + 1, n + 2, INF, 0);
	}
	
	for(ll i = 2 ; i <= n + 1 ; i++)
	{
		for(ll j = 2 ; j <= n + 1 ; j++)
		{
			cin >> all;
			
			if(i < j)
				mxfl.add_edge(i, j, all, 0);
		}
	}
	
	cout << mxfl.get_flow() en;
	
	pair< vector<ll>, vector<ll> > ans = mxfl.get_cut();
	
	for(auto &i : ans.fi)
	    cout << i sp;
	
	cout en;
	
	for(auto &i : ans.se)
	    cout << i sp;
	
	cout en;
	return 0;
}