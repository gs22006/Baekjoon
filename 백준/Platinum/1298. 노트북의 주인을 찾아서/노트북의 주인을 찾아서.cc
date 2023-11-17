#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;

ll n, m;
ll all, bll;
vector<ll> vec[5010];
ll chk[5010];
ll np[5010];
ll ans;

ll dfs(ll here)
{
	for(ll i = 0 ; i < vec[here].size() ; i++)
	{
		if(chk[vec[here][i]])
			continue;
		
		chk[vec[here][i]] = 1;
		
		if(np[vec[here][i]] == 0 || dfs(np[vec[here][i]]))
		{
			np[vec[here][i]] = here;
			return 1;
		}
	}
	
	return 0;
}

int main(void)
{
	scanf("%lld %lld", &n, &m);
	
	for(ll i = 0 ; i < m ; i++)
	{
		scanf("%lld %lld", &all, &bll);
		vec[all].push_back(bll);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		memset(chk, 0, sizeof(chk));
		
		if(dfs(i))
			ans++;
	}
	
	printf("%lld", ans);
	return 0;
}