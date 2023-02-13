#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, m;
pll a[5010];
ll w;
ll dp[5010][5010][3];
ll ans;
ll nu[5010];

ll dist(ll X, ll Y)
{
	return abs(a[X].fi - a[Y].fi);
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	a[n + 1].fi = 0;
	a[n + 1].se = m;
	n++;
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].fi == 0)
		{
			w = i;
			break;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		nu[i] = nu[i - 1] + a[i].se;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			dp[i][j][0] = dp[i][j][1] = -INF;
	}
	
	dp[w][w][0] = dp[w][w][1] = m;
	
	for(ll L = 0 ; L < n ; L++)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			ll j = i + L;
			
			if(j > n)
				break;
			
			if(1 <= i - 1)
			{
				if(dp[i][j][0] - dist(i, i - 1) > 0)
					dp[i - 1][j][0] = max(dp[i - 1][j][0], dp[i][j][0] - dist(i, i - 1) + a[i - 1].se);
				
				if(dp[i][j][1] - dist(j, i - 1) > 0)
					dp[i - 1][j][0] = max(dp[i - 1][j][0], dp[i][j][1] - dist(j, i - 1) + a[i - 1].se);
			}
			
			if(j + 1 <= n)
			{
				if(dp[i][j][0] - dist(i, j + 1) > 0)
					dp[i][j + 1][1] = max(dp[i][j + 1][0], dp[i][j][0] - dist(i, j + 1) + a[j + 1].se);
				
				if(dp[i][j][1] - dist(j, j + 1) > 0)
					dp[i][j + 1][1] = max(dp[i][j + 1][0], dp[i][j][1] - dist(j, j + 1) + a[j + 1].se);
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i ; j <= n ; j++)
		{
			if(dp[i][j][0] >= 0)
				ans = max(ans, nu[j] - nu[i - 1]);
			
			if(dp[i][j][1] >= 0)
				ans = max(ans, nu[j] - nu[i - 1]);
		}
	}
	
	cout << ans;
	return 0;
}