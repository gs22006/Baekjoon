#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define fi first
#define se second

ll n, s, e;
ll dp[2010][2010][4];
ll ss = 1000000007;

int main(void)
{
	scanf("%lld %lld %lld", &n, &s, &e);
	
	if(s == 1 || e == 1)
		dp[1][1][1] = 1;
	else
		dp[1][1][0] = 1;
	
	for(ll i = 2 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= i ; j++)
		{
			for(ll k = 0 ; k <= 2 ; k++)
			{
				if(i == s || i == e)
				{
					if(j >= 2 && k >= 1)
						dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k - 1]) % ss;
					
					if(k >= 1)
						dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % ss;
				}
				
				else
				{
					if(j >= 2 && (j - k) >= 0)
						dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k] * (j - k) % ss) % ss;
					
					if(j + 1 <= i - 1)
						dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j + 1][k] * j % ss) % ss;
				}
			}
		}
	}
	
	printf("%lld", dp[n][1][2] % ss < 0 ? dp[n][1][2] % ss + ss : dp[n][1][2] % ss);
	return 0;
}