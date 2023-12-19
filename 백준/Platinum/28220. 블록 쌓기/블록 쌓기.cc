#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll n, L, R;
ll a[110];
ll sum;
ll dp[101][101][10001];
ll nu[110];
ll ans = (1LL << 61);

int main(void)
{
	scanf("%lld %lld %lld", &n, &L, &R);

	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%lld", &a[i]);
		sum += a[i];
	}

	if(sum < L * n || sum > R * n)
	{
		printf("-1");
		return 0;
	}

	for(ll i = 1 ; i <= n ; i++)
		a[i] -= L;

	for(ll i = 1 ; i <= n ; i++)
		nu[i] = nu[i - 1] + a[i];
	
	for(ll i = 0 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= R - L ; j++)
		{
			for(ll k = 0 ; k <= 10000 ; k++)
				dp[i][j][k] = (1LL << 61);
		}
	}

	dp[0][0][0] = 0;

	for(ll i = 0 ; i <= R - L ; i++)
		dp[0][i][0] = 0;

	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= R - L ; j++)
		{
			for(ll k = 0 ; k <= 10000 ; k++)
			{
				dp[i][j][k] = (1LL << 61);

				if(k - j < 0)
					continue;
				
				dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - j] + abs(a[i] - k + nu[i - 1]));
			}
		}

		for(ll k = 0 ; k <= 10000 ; k++)
		{
			for(ll j = 1 ; j <= R - L ; j++)
				dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k]);
		}
	}

	for(ll i = 0 ; i <= R - L ; i++)
		ans = min(ans, dp[n][i][nu[n]]);
	
	printf("%lld", ans);
	return 0;
}