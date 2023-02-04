#include <bits/stdc++.h>

using namespace std;
typedef int ll;

ll num[2010][2010];
vector<ll> vec[5000010], yuk[5000010];
stack<ll> stk;
ll chk[5000010];
ll scc[5000010];
ll cc;
ll cc2;

void dfs(ll here)
{
	chk[here] = 1;
	
	for(auto &i : vec[here])
	{
		if(chk[i])
			continue;
		
		dfs(i);
	}
	
	stk.push(here);
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

bool reversal(int N, int M, vector<string> P)
{
	for(ll i = 0 ; i < N ; i++)
	{
		for(ll j = 0 ; j < M ; j++)
			num[i][j] = ++cc2;
	}
	
	for(ll i = N ; i < N * 2 ; i++)
	{
		for(ll j = 0 ; j < M ; j++)
			num[i][j] = ++cc2;
	}
	
	for(ll i = 0 ; i < N ; i++)
	{
		for(ll j = 0 ; j < N ; j++)
		{
			if(P[i][j] == 'X')
			{
				vec[num[i][j % M]].push_back(num[j + N][i % M]);
				vec[num[i][j % M] + cc2].push_back(num[j + N][i % M] + cc2);
				vec[num[j + N][i % M]].push_back(num[i][j % M]);
				vec[num[j + N][i % M] + cc2].push_back(num[i][j % M] + cc2);
				yuk[num[i][j % M]].push_back(num[j + N][i % M]);
				yuk[num[i][j % M] + cc2].push_back(num[j + N][i % M] + cc2);
				yuk[num[j + N][i % M]].push_back(num[i][j % M]);
				yuk[num[j + N][i % M] + cc2].push_back(num[i][j % M] + cc2);
			}
			
			else
			{
				vec[num[i][j % M] + cc2].push_back(num[j + N][i % M]);
				vec[num[i][j % M]].push_back(num[j + N][i % M] + cc2);
				vec[num[j + N][i % M]].push_back(num[i][j % M] + cc2);
				vec[num[j + N][i % M] + cc2].push_back(num[i][j % M]);
				yuk[num[i][j % M] + cc2].push_back(num[j + N][i % M]);
				yuk[num[i][j % M]].push_back(num[j + N][i % M] + cc2);
				yuk[num[j + N][i % M]].push_back(num[i][j % M] + cc2);
				yuk[num[j + N][i % M] + cc2].push_back(num[i][j % M]);
			}
		}
	}
	
	for(ll i = 1 ; i <= cc2 * 2 ; i++)
	{
		if(!chk[i])
			dfs(i);
	}
	
	while(!stk.empty())
	{
		ll tp = stk.top();
		stk.pop();
		
		if(scc[tp])
			continue;
		
		cc++;
		dfs2(tp);
	}
	
	ll ans = 1;
	
	for(ll i = 1 ; i <= cc2 ; i++)
	{
		if(scc[i] == scc[i + cc2])
			ans = 0;
	}
	
	return ans;
}