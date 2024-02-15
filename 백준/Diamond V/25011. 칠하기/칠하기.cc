#include <bits/stdc++.h>

using namespace std;
typedef int ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define sp << " "
#define en << "\n"

ll n, m;
char a[1010][1010];
ll num[1010][1010];
ll cc;
vector<ll> vec[4000010], yuk[4000010];
stack<ll> ord;
ll chk[4000010], scc[4000010], cc2;
vector<ll> vec2[4000010];
ll deg[4000010];

void edge(ll X, char D1, ll Y, char D2)
{
	if(D1 == 'U')
		X += 0;
	else if(D1 == 'R')
		X += cc;
	else if(D1 == 'D')
		X += cc * 2;
	else
		X += cc * 3;
	
	if(D2 == 'U')
		Y += 0;
	else if(D2 == 'R')
		Y += cc;
	else if(D2 == 'D')
		Y += cc * 2;
	else
		Y += cc * 3;
	
	vec[X].push_back(Y);
	yuk[Y].push_back(X);
}

void dfs(ll here)
{
	chk[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(chk[i])
			continue;
		
		dfs(i);
	}
	
	ord.push(here);
}

void dfs2(ll here)
{
	scc[here] = cc2;
	
	for(auto &i : yuk[here])
	{
		if(scc[i])
			continue;
		
		dfs2(i);
	}
}

ll yellowblue(ll N, ll M, vector<string> V)
{
	n = N, m = M;
	
	for(ll i = 0 ; i < n ; ++i)
	{
		for(ll j = 0 ; j < m ; ++j)
			a[i + 1][j + 1] = V[i][j];
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		for(ll j = 1 ; j <= m ; ++j)
		{
			if(a[i][j] == '.')
				num[i][j] = ++cc;
		}
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		for(ll j = 1 ; j <= m ; ++j)
		{
			if(a[i][j] == '#')
				continue;
			
			if(j < m && a[i][j + 1] == '.')
				edge(num[i][j], 'R', num[i][j + 1], 'R');
			
			else
			{
				edge(num[i][j], 'R', num[i][j], 'L');
				edge(num[i][j], 'R', num[i][j], 'U');
				edge(num[i][j], 'R', num[i][j], 'D');
			}
			
			if(j > 1 && a[i][j - 1] == '.')
				edge(num[i][j], 'L', num[i][j - 1], 'L');
			
			else
			{
				edge(num[i][j], 'L', num[i][j], 'R');
				edge(num[i][j], 'L', num[i][j], 'U');
				edge(num[i][j], 'L', num[i][j], 'D');
			}
			
			if(i < n && a[i + 1][j] == '.')
				edge(num[i][j], 'D', num[i + 1][j], 'D');
			
			else
			{
				edge(num[i][j], 'D', num[i][j], 'L');
				edge(num[i][j], 'D', num[i][j], 'R');
				edge(num[i][j], 'D', num[i][j], 'U');
			}
			
			if(i > 1 && a[i - 1][j] == '.')
				edge(num[i][j], 'U', num[i - 1][j], 'U');
			
			else
			{
				edge(num[i][j], 'U', num[i][j], 'L');
				edge(num[i][j], 'U', num[i][j], 'R');
				edge(num[i][j], 'U', num[i][j], 'D');
			}
		}
	}
	
	for(ll i = 1 ; i <= cc * 4 ; ++i)
	{
		if(!chk[i])
			dfs(i);
	}
	
	while(!ord.empty())
	{
		ll tp = ord.top();
		ord.pop();
		
		if(!scc[tp])
		{
			cc2++;
			dfs2(tp);
		}
	}
	
	for(ll i = 1 ; i <= cc * 4 ; ++i)
	{
		for(auto &j : vec[i])
		{
			if(scc[i] == scc[j])
				continue;
			
			vec2[scc[i]].push_back(scc[j]);
			deg[scc[j]]++;
		}
	}
	
	queue<ll> q;
	ll maxx = 0;
	
	for(ll i = 1 ; i <= cc2 ; ++i)
	{
		if(!deg[i])
		{
			q.push(i);
			maxx = max(maxx, (ll)q.size());
		}
	}
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec2[qq])
		{
			deg[i]--;
			
			if(!deg[i])
			{
				q.push(i);
				maxx = max(maxx, (ll)q.size());
			}
		}
	}
	
	if(maxx >= 2)
		return 0;
	
	return 1;
}