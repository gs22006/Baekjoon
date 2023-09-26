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

ll n, m;
ll all, bll;
vector<ll> vec[10010], yuk[10010];
vector<ll> vec2[10010];
ll dp[10010], siz[10010];
vector<ll> vv;
ll chk[10010];
ll deg[10010];
ll scc[10010];
ll S, T;
ll ans;
ll cc;

void dfs(ll here)
{
	chk[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(chk[i])
			continue;
		
		dfs(i);
	}
	
	vv.push_back(here);
}

void dfs2(ll here)
{
	scc[here] = cc;
	
	for(auto &i : yuk[here])
	{
		if(scc[i])
			continue;
		
		dfs2(i);
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m >> S >> T;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		yuk[bll].push_back(all);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!chk[i])
			dfs(i);
	}
	
	reverse(vv.begin(), vv.end());
	
	for(auto &i : vv)
	{
		if(scc[i])
			continue;
		
		cc++;
		dfs2(i);
	}
	
	S = scc[S];
	T = scc[T];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		siz[scc[i]]++;
		dp[scc[i]] = -INF;
		
		for(auto &j : vec[i])
		{
			if(scc[i] == scc[j])
				continue;
			
			vec2[scc[i]].push_back(scc[j]);
			deg[scc[j]]++;
		}
	}
	
	dp[S] = siz[S];
	
	queue<ll> q;
	
	for(ll i = 1 ; i <= cc ; i++)
	{
		if(!deg[i])
			q.push(i);
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec2[qq])
		{
			deg[i]--;
			dp[i] = max(dp[i], dp[qq] + siz[i]);
			
			if(!deg[i])
				q.push(i);
		}
	}
	
	ans = max(ans, dp[T]);
	
	cout << ans;
	return 0;
}