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

ll n, m, A, B;
ll all, bll, cll;
vector<pll> vec[2010];
ll K;
ll path[2010];
ll distA[2010], distB[2010];
vector<ll> vec2[2010];
ll chk[2010];
ll spa[2010][20];
ll dep[2010];
ll LC[2010];
ll w[2010];
ll adj[2010][2010];

void dijkstra(void)
{
	priority_queue<pll> pq;
	
	for(ll i = 1 ; i <= n ; i++)
		distA[i] = INF;
	
	distA[A] = 0;
	pq.push({0, A});
	
	while(!pq.empty())
	{
		pll qq = pq.top();
		pq.pop();
		
		for(auto &i : vec[qq.se])
		{
			if(distA[i.fi] > distA[qq.se] + i.se)
			{
				distA[i.fi] = distA[qq.se] + i.se;
				pq.push({-distA[i.fi], i.fi});
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		distB[i] = INF;
	
	distB[B] = 0;
	pq.push({0, B});
	
	while(!pq.empty())
	{
		pll qq = pq.top();
		pq.pop();
		
		for(auto &i : vec[qq.se])
		{
			if(distB[i.fi] > distB[qq.se] + i.se)
			{
				distB[i.fi] = distB[qq.se] + i.se;
				pq.push({-distB[i.fi], i.fi});
			}
		}
	}
}

void dfs(ll here)
{
	for(auto &i : vec[here])
	{
		if(chk[i.fi])
			continue;
		
		if(distA[here] + i.se == distA[i.fi])
		{
			chk[i.fi] = 1;
			vec2[here].push_back(i.fi);
			vec2[i.fi].push_back(here);
			dfs(i.fi);
		}
	}
}

void dfs0(ll here, ll pa)
{
	dep[here] = dep[pa] + 1;
	
	for(auto &i : vec2[here])
	{
		if(i == pa)
			continue;
		
		spa[i][0] = here;
		dfs0(i, here);
	}
}

ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	
	ll cha = dep[X] - dep[Y];
	
	for(ll i = 19 ; i >= 0 ; i--)
	{
		if(cha >= (1LL << i))
		{
			cha -= (1LL << i);
			X = spa[X][i];
		}
	}
	
	if(X == Y)
		return X;
	
	for(ll i = 19 ; i >= 0 ; i--)
	{
		if(spa[X][i] != spa[Y][i])
		{
			X = spa[X][i];
			Y = spa[Y][i];
		}
	}
	
	return spa[X][0];
}

struct lazysegtree
{
	ll seg[100010];
	ll lazy[100010];
	
	void init(ll no, ll s, ll e)
	{
		seg[no] = lazy[no] = INF;
		
		if(s == e)
			return;
		
		init(no << 1, s, (s + e) >> 1);
		init(no << 1 | 1, ((s + e) >> 1) + 1, e);
	}
	
	void prop(ll no, ll s, ll e)
	{
		if(lazy[no] == INF)
			return;
		
		seg[no] = min(seg[no], lazy[no]);
		
		if(s != e)
		{
			lazy[no << 1] = min(lazy[no << 1], lazy[no]);
			lazy[no << 1 | 1] = min(lazy[no << 1 | 1], lazy[no]);
		}
		
		lazy[no] = INF;
	}
	
	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			seg[no] = min(seg[no], v);
			
			if(s != e)
			{
				lazy[no << 1] = min(lazy[no << 1], v);
				lazy[no << 1 | 1] = min(lazy[no << 1 | 1], v);
			}
			
			return;
		}
		
		update(no << 1, s, (s + e) >> 1, l, r, v);
		update(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		seg[no] = min(seg[no << 1], seg[no << 1 | 1]);
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return INF;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return min(query(no << 1, s, (s + e) >> 1, l, r), query(no << 1 | 1, ((s + e) >> 1) + 1, e, l, r));
	}
}segt;

int main(void)
{
	fastio
	
	cin >> n >> m >> A >> B;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		
		vec[all].push_back({bll, cll});
		vec[bll].push_back({all, cll});
	}
	
	cin >> K;
	
	for(ll i = 1 ; i <= K ; i++)
	{
		cin >> path[i];
		
		chk[path[i]] = 1;
		w[path[i]] = i;
	}
	
	dijkstra();
	
	for(ll i = 2 ; i <= K ; i++)
	{
		vec2[path[i - 1]].push_back(path[i]);
		vec2[path[i]].push_back(path[i - 1]);
	}
	
	for(ll i = 1 ; i <= K ; i++)
		dfs(path[i]);
	
	dfs0(A, 0);
	
	for(ll i = 1 ; i < 20 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			spa[j][i] = spa[spa[j][i - 1]][i - 1];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(auto &j : vec2[i])
			adj[i][j] = 1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		LC[i] = LCA(i, B);
	
	segt.init(1, 1, K);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(auto &j : vec[i])
		{
			ll U = i, V = j.fi;
			
			if(adj[U][V])
				continue;
			
			U = w[LC[U]], V = w[LC[V]];
			
			if(!U || !V)
				continue;
			
			if(U > V)
				swap(U, V);
			
			if(U == V)
				continue;
			
			segt.update(1, 1, K, U, V - 1, distA[i] + j.se + distB[j.fi]);
		}
	}
	
	for(ll i = 1 ; i < K ; i++)
	{
		ll gap = segt.query(1, 1, K, i, i);
		
		if(gap == INF)
			cout << -1 en;
		else
			cout << gap en;
	}
	
	return 0;
}