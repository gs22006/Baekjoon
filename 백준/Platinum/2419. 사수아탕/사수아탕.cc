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
ll a[310];
ll ans[310][310];
ll dp[310][310][3];
ll w;
ll ans2 = -INF;

ll dist(ll X, ll Y)
{
	return abs(a[X] - a[Y]);
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	a[n + 1] = 0;
	n++;
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i] == 0)
		{
			w = i;
			break;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			ans[i][j] = -INF;
	}
	
	for(ll k = 1 ; k <= n ; k++)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = 1 ; j <= n ; j++)
				dp[i][j][0] = dp[i][j][1] = INF;
		}
		
		dp[w][w][0] = dp[w][w][1] = 0;
		
		for(ll L = 1 ; L < k ; L++)
		{
			for(ll i = 1 ; i <= n ; i++)
			{
				ll j = i + L;
				
				if(j > n)
					break;
				
				dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][0] + dist(i + 1, i) * (k - L));
				dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] + dist(j, i) * (k - L));
				dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][0] + dist(i, j) * (k - L) + dist(j, i) * (k - L - 1));
				dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][1] + dist(j - 1, j) * (k - L) + dist(j, i) * (k - L - 1));
				
				dp[i][j][1] = min(dp[i][j][1], dp[i + 1][j][0] + dist(i + 1, i) * (k - L) + dist(i, j) * (k - L - 1));
				dp[i][j][1] = min(dp[i][j][1], dp[i + 1][j][1] + dist(j, i) * (k - L) + dist(j, i) * (k - L - 1));
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + dist(i, j) * (k - L));
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dist(j - 1, j) * (k - L));
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = i ; j <= n ; j++)
				ans[i][j] = max(ans[i][j], (j - i) * m - min(dp[i][j][0], dp[i][j][1]));
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i ; j <= n ; j++)
			ans2 = max(ans2, ans[i][j]);
	}
	
	cout << ans2;
	return 0;
}