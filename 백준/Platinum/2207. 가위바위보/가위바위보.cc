#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n, m;
ll all, bll;
vector<ll> vec[100010], yuk[100010];
ll chk[100010];
stack<ll> s;
ll scc[100010];
ll cc;

ll num(ll X)
{
	if(X < 0)
		X = -X + m;
	
	return X;
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
	
	s.push(here);
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
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all >> bll;
		
		vec[num(-all)].push_back(num(bll));
		yuk[num(bll)].push_back(num(-all));
	}
	
	for(ll i = 1 ; i <= m * 2 ; i++)
	{
		if(!chk[i])
			dfs(i);
	}
	
	while(!s.empty())
	{
		ll tp = s.top();
		s.pop();
		
		if(!scc[tp])
		{
			cc++;
			dfs2(tp);
		}
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		if(scc[i] == scc[i + m])
		{
			cout << "OTL";
			return 0;
		}
	}
	
	cout << "^_^";
	return 0;
}