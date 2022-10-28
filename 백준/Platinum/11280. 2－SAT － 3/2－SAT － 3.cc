#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n, m;
ll all, bll;
vector<ll> vec[20010], yuk[20010];
vector<ll> vis;
ll chk[20010];
ll SCC[20010];
ll cc;

ll num(ll X)
{
	if(X < 0)
		return -X + n;
	
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
	
	vis.push_back(here);
}

void dfs2(ll here)
{
	SCC[here] = cc;
	
	for(auto &i : yuk[here])
	{
		if(SCC[i])
			continue;
		
		dfs2(i);
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll;
		
		vec[num(-all)].push_back(num(bll));
		vec[num(-bll)].push_back(num(all));
		yuk[num(bll)].push_back(num(-all));
		yuk[num(all)].push_back(num(-bll));
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[i])
			continue;
		
		dfs(i);
	}
	
	reverse(vis.begin(), vis.end());
	
	for(auto &i : vis)
	{
		if(SCC[i])
			continue;
		
		cc++;
		dfs2(i);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(SCC[num(i)] == SCC[num(-i)])
		{
			cout << 0;
			return 0;
		}
	}
	
	cout << 1;
	return 0;
}