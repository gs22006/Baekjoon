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

ll n;
ll a[60];
ll dp[60][500010];
ll sum;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	for(ll i = 0 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= sum ; j++)
			dp[i][j] = -INF;
	}
	
	dp[0][0] = 0;
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j <= sum ; j++)
		{
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			
			if(j + a[i + 1] <= sum)
				dp[i + 1][j + a[i + 1]] = max(dp[i + 1][j + a[i + 1]], dp[i][j] + a[i + 1]);
			
			if(abs(j - a[i + 1]) <= sum)
			{
				if(j - a[i + 1] >= 0)
					dp[i + 1][j - a[i + 1]] = max(dp[i + 1][j - a[i + 1]], dp[i][j]);
				
				if(j - a[i + 1] < 0)
					dp[i + 1][a[i + 1] - j] = max(dp[i + 1][a[i + 1] - j], dp[i][j] - j + a[i + 1]);
			}
		}
	}
	
	if(dp[n][0] == 0)
		cout << -1;
	else
		cout << dp[n][0];
	
	return 0;
}