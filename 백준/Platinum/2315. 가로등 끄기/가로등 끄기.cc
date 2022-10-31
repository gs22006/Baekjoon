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
pair<ll, ll> a[1010];
ll dp[1010][1010][3];
ll nu[1010];
ll sum;

ll dist(ll X, ll Y)
{
	return abs(a[X].fi - a[Y].fi);
}

ll cost(ll X, ll Y)
{
	return sum - (nu[Y] - nu[X - 1]);
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		
		sum += a[i].se;
		nu[i] = nu[i - 1] + a[i].se;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			dp[i][j][0] = dp[i][j][1] = INF;
	}
	
	dp[m][m][0] = dp[m][m][1] = 0;
	
	for(ll L = 1 ; L < n ; L++)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			ll j = i + L;
			
			if(j > n)
				break;
			
			dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][0] + dist(i + 1, i) * cost(i + 1, j));
			dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] + dist(j, i) * cost(i + 1, j));
			dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][0] + dist(i, j) * cost(i, j - 1) + dist(j, i) * cost(i, j));
			dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][1] + dist(j - 1, j) * cost(i, j - 1) + dist(j, i) * cost(i, j));
			
			dp[i][j][1] = min(dp[i][j][1], dp[i + 1][j][0] + dist(i + 1, i) * cost(i + 1, j) + dist(i, j) * cost(i, j));
			dp[i][j][1] = min(dp[i][j][1], dp[i + 1][j][1] + dist(j, i) * cost(i + 1, j) + dist(i, j) * cost(i, j));
			dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + dist(i, j) * cost(i, j - 1));
			dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dist(j - 1, j) * cost(i, j - 1));
		}
	}
	
	cout << min(dp[1][n][0], dp[1][n][1]);
	return 0;
}