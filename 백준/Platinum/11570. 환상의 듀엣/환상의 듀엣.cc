#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll a[2010];
ll dp[2010][2010];
ll ans = 19876543210;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	for(ll i = 0 ; i < 2010 ; i++)
	{
		for(ll j = 0 ; j < 2010 ; j++)
			dp[i][j] = 19876543210;
	}
	
	dp[1][0] = 0;
	dp[0][1] = 0;
	
	for(ll i = 0 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= n ; j++)
		{
			if(i == j)
				continue;
			
			int ne = max(i, j) + 1;
			
			if(i == 0 || j == 0)
				a[0] = a[ne];
			
			dp[ne][j] = min(dp[ne][j], dp[i][j] + abs(a[ne] - a[i]));
			dp[i][ne] = min(dp[i][ne], dp[i][j] + abs(a[ne] - a[j]));
		}
	}
	
	for(ll i = 0 ; i < n ; i++)
		ans = min(ans, min(dp[i][n], dp[n][i]));
	
	printf("%lld", ans);
	return 0;
}