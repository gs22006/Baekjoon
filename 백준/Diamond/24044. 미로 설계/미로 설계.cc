#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, m, k;
vector< pair<ll, ll> > edg;
ll all, bll;
vector<ll> vvec[500010], vec[500010];
ll num[500010], deg[500010], deg2[500010];
ll cou[500010];
queue<ll> q;
ll cc;
ll dp[500010];
ll won[500010];
vector< pair<ll, ll> > ans;

int main(void)
{
	scanf("%lld %lld %lld", &n, &m, &k);
	
	for(ll i = 1 ; i <= m ; i++)
	{
		scanf("%lld %lld", &all, &bll);
		
		edg.push_back({all, bll});
		vvec[all].push_back(bll);
		deg[bll]++;
	}
	
	q.push(1);
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		num[qq] = ++cc;
		won[cc] = qq;
		
		for(auto &i : vvec[qq])
		{
			deg[i]--;
			
			if(!deg[i])
				q.push(i);
		}
	}
	
	for(auto &i : edg)
	{
		vec[num[i.fi]].push_back(num[i.se]);
		deg2[num[i.se]]++;
	}
	
	for(ll i = 1 ; i <= 30 ; i++)
	{
		for(auto &j : vec[i])
		{
			if(j == i + 1)
				cou[i]++;
		}
	}
	
	for(ll i = 1 ; i <= 30 ; i++)
	{
		if(!cou[i])
		{
			vec[i].push_back(i + 1);
			vec[i].push_back(i + 1);
			deg2[i + 1] += 2;
			ans.push_back({won[i], won[i + 1]});
			ans.push_back({won[i], won[i + 1]});
		}
		
		else if(cou[i] == 1)
		{
			vec[i].push_back(i + 1);
			deg2[i + 1]++;
			ans.push_back({won[i], won[i + 1]});
		}
	}
	
	dp[1] = 1;
	q.push(1);
	
	while(!q.empty())
	{
		ll qq = q.front();
		q.pop();
		
		for(auto &i : vec[qq])
		{
			deg2[i]--;
			dp[i] += dp[qq];
			
			if(i > 30)
				dp[i] %= k;
			
			if(!deg2[i])
				q.push(i);
		}
	}
	
	ll gap = k - dp[n];
	
	for(ll i = 30 ; i >= 1 ; i--)
	{
		ll siz = gap / dp[i];
		
		while(siz--)
			ans.push_back({won[i], n});
		
		gap %= dp[i];
	}
	
	printf("%lld\n", (ll)ans.size());
	
	for(auto &i : ans)
		printf("%lld %lld\n", i.fi, i.se);
	
	return 0;
}