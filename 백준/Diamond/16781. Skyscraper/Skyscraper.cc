#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, L;
ll a[110];
ll dp[110][110][1010][3];
ll ss = 1000000007;

int main(void)
{
	scanf("%lld %lld", &n, &L);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld", &a[i]);
	
	sort(a + 1, a + 1 + n);
	
	dp[1][1][0][0] = 1;
	dp[1][1][0][1] = 2;
	dp[1][1][0][2] = 1;
	
	for(ll i = 2 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= i ; j++)
		{
			for(ll k = 0 ; k <= L ; k++)
			{
				for(ll l = 0 ; l <= 2 ; l++)
				{
					if(k - ((j - 1) * 2 - l) * (a[i] - a[i - 1]) >= 0 && (j - l) >= 0)
						dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j - 1][k - ((j - 1) * 2 - l) * (a[i] - a[i - 1])][l] * (j - l) % ss) % ss;
					
					if(k - ((j - 1) * 2 - (l - 1)) * (a[i] - a[i - 1]) >= 0 && (l - 1) >= 0)
						dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j - 1][k - ((j - 1) * 2 - (l - 1)) * (a[i] - a[i - 1])][l - 1] * (3 - l) % ss) % ss;
					
					if(k - (j * 2 - l) * (a[i] - a[i - 1]) >= 0)
						dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j][k - (j * 2 - l) * (a[i] - a[i - 1])][l] * (2 * j - l) % ss) % ss;
					
					if(k - (j * 2 - (l - 1)) * (a[i] - a[i - 1]) >= 0 && (l - 1) >= 0)
						dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j][k - (j * 2 - (l - 1)) * (a[i] - a[i - 1])][l - 1] * (3 - l) % ss) % ss;
					
					if(k - ((j + 1) * 2 - l) * (a[i] - a[i - 1]) >= 0)
						dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j + 1][k - ((j + 1) * 2 - l) * (a[i] - a[i - 1])][l] * j % ss) % ss;
				}
			}
		}
	}
	
	ll ans = 0;
	
	for(ll i = 0 ; i <= L ; i++)
		ans = (ans + dp[n][1][i][2]) % ss;
	
	printf("%lld", ans % ss < 0 ? ans % ss + ss : ans % ss);
	return 0;
}