#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll a[1010][1010];
ll b[1010][1010];
ll dp1[1010][1010][5];
ll dp2[1010][1010][5];
ll dp3[1010][1010][5];
ll dp4[1010][1010][5];
ll nu[1010][1010];
ll INF = 1000000000LL;

ll solve(void)
{
	ll ret = -INF;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll k = 0 ; k < 4 ; k++)
				dp1[i][j][k] = dp2[i][j][k] = dp3[i][j][k] = dp4[i][j][k] = -INF;
			
			nu[i][j] = 0;
		}
	}
	
	dp1[1][1][0] = dp1[1][1][3] = a[1][1];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(i - 1 >= 1)
				dp1[i][j][0] = max(dp1[i - 1][j][0], dp1[i - 1][j][3]) + a[i][j];
			
			if(j - 1 >= 1)
				dp1[i][j][3] = max(dp1[i][j - 1][0], dp1[i][j - 1][3]) + a[i][j];
		}
	}
	
	dp2[1][n][1] = dp2[1][n][0] = a[1][n];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = n ; j >= 1 ; j--)
		{
			if(i - 1 >= 1)
				dp2[i][j][0] = max(dp2[i - 1][j][0], dp2[i - 1][j][1]) + a[i][j];
			
			if(j + 1 <= n)
				dp2[i][j][1] = max(dp2[i][j + 1][0], dp2[i][j + 1][1]) + a[i][j];
		}
	}
	
	dp3[n][1][2] = dp3[n][1][3] = a[n][1];
	
	for(ll i = n ; i >= 1 ; i--)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(i + 1 <= n)
				dp3[i][j][2] = max(dp3[i + 1][j][2], dp3[i + 1][j][3]) + a[i][j];
			
			if(j - 1 >= 1)
				dp3[i][j][3] = max(dp3[i][j - 1][2], dp3[i][j - 1][3]) + a[i][j];
		}
	}
	
	dp4[n][n][1] = dp4[n][n][2] = a[n][n];
	
	for(ll i = n ; i >= 1 ; i--)
	{
		for(ll j = n ; j >= 1 ; j--)
		{
			if(j + 1 <= n)
				dp4[i][j][1] = max(dp4[i][j + 1][1], dp4[i][j + 1][2]) + a[i][j];
			
			if(i + 1 <= n)
				dp4[i][j][2] = max(dp4[i + 1][j][1], dp4[i + 1][j][2]) + a[i][j];
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			nu[i][j] = nu[i][j - 1] + a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll maxx = -INF;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			ll gap = dp2[i][j][0] + dp4[i][j][1];
			gap = max(gap, dp2[i][j][0] + dp4[i][j][2]);
			gap = max(gap, dp2[i][j][1] + dp4[i][j][2]);
			ll gap2 = dp1[i][j][0] + dp3[i][j][2];
			gap2 = max(gap2, dp1[i][j][0] + dp3[i][j][3]);
			gap2 = max(gap2, dp1[i][j][3] + dp3[i][j][2]);
			
			gap -= a[i][j];
			gap2 -= a[i][j];
			
			if(j != 1)
			{
				ret = max(ret, gap + nu[i][j - 1] + maxx);
				//printf("%lld ", gap + nu[i][j - 1] + maxx);
			}
			
			maxx = max(maxx, gap2 - nu[i][j]);
		}
		
		//printf("\n");
	}
	//printf("????%lld\n", ret);
	//printf("\n");
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			//printf("(%lld, %lld) ", dp1[i][j][0] + dp2[i][j][1] + dp3[i][j][3] + dp4[i][j][2], dp1[i][j][3] + dp2[i][j][0] + dp3[i][j][2] + dp4[i][j][1]);
			ret = max(ret, dp1[i][j][0] + dp2[i][j][1] + dp3[i][j][3] + dp4[i][j][2] - a[i][j] * 3);
			ret = max(ret, dp1[i][j][3] + dp2[i][j][0] + dp3[i][j][2] + dp4[i][j][1] - a[i][j] * 3);
		}
		//printf("\n");
	}
	
	//printf("????%lld\n", ret);
	return ret;
}

int max_item_sum (vector<vector<int> > V)
{
	n = (ll)V.size();
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < n ; j++)
			a[i + 1][j + 1] = V[i][j];
	}
	
	ll ans = solve();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[i][j] = a[j][i];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			a[i][j] = b[i][j];
	}
	
	ans = max(ans, solve());
	
	return (int)ans;
}