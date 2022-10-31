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
ll a[60], b[60], c[60];
ll nu[1010][1010];
ll dp[1010][1010];
ll ans;

ll cost(ll x1, ll y1, ll x2, ll y2)
{
	return nu[x2][y2] - nu[x1 - 1][y2] - nu[x2][y1 - 1] + nu[x1 - 1][y1 - 1];
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		nu[a[i]][b[i]] += c[i];
	}
	
	for(ll i = 1 ; i < 1010 ; i++)
	{
		for(ll j = 1 ; j < 1010 ; j++)
			nu[i][j] += nu[i - 1][j] + nu[i][j - 1] - nu[i - 1][j - 1];
	}
	
	for(ll i = 0 ; i < 1010 ; i++)
	{
		for(ll j = 0 ; j < 1010 ; j++)
			dp[i][j] = -INF;
	}
	
	dp[1][1] = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i] == 1 || b[i] == 1)
			dp[1][1] += c[i];
	}
	
	for(ll i = 1 ; i <= 1000 ; i++)
	{
		for(ll j = 1 ; j <= 1000 ; j++)
		{
			if(dp[i][j] == -INF)
				continue;
			
			if(dp[i][j] >= 1)
			{
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1 + cost(i + 1, j + 1, 1000, j + 1));
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1 + cost(i + 1, j + 1, i + 1, 1000));
			}
		}
	}
	
	for(ll i = 1 ; i <= 1000 ; i++)
	{
		for(ll j = 1 ; j <= 1000 ; j++)
		{
			ll cou = 0;
			
			if(dp[i][j] == -INF)
				continue;
			
			for(ll k = 1 ; k <= n ; k++)
			{
				if(a[k] <= i || b[k] <= j)
					cou++;
			}
			
			ans = max(ans, cou);
		}
	}
	
	cout << ans;
	return 0;
}