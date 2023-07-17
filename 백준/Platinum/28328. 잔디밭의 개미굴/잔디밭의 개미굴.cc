#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fi first
#define se second

ll n;
ll all, bll;
vector<ll> vec[500010];
ll dp[500010][2];
ll dp2[500010];
ll maxx;
ll a[500010];
ll ans;
ll siz[500010];
ll R[500010];

void dfs(ll here, ll pa)
{
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
		
		dp[here][0] += max(dp[i][0], dp[i][1]);
		dp[here][1] += dp[i][0];
	}

	dp[here][1]++;
}

void dfs2(ll here, ll pa, ll Z, ll O)
{
	ll sum1 = 0, sum2 = 0;

	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		sum1 += max(dp[i][0], dp[i][1]);
		sum2 += dp[i][0];
	}

	dp2[here] = sum1 + max(Z, O);

	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		ll gap1 = sum1 - max(dp[i][0], dp[i][1]);
		ll gap2 = sum2 - dp[i][0] + 1;
		ll NZ = gap1 + max(Z, O);
		ll NO = Z + gap2;

		dfs2(i, here, NZ, NO);
	}
}

int main(void)
{
	scanf("%lld", &n);

	for(ll i = 1 ; i < n ; i++)
	{
		scanf("%lld %lld", &all, &bll);

		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}

	dfs(1, 0);
	dfs2(1, 0, 0, 0);

	maxx = max(dp[1][0], dp[1][1]);
	
	ll couu = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(dp2[i] != maxx)
			couu++;
	}
	
	ans = n * (n - 1) / 2;
	
	printf("%lld", ans - couu * (couu - 1) / 2);
	return 0;
}