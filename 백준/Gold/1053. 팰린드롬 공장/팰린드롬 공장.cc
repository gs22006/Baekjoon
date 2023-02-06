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

char a[110];
ll dp[110][110];
ll ans = INF;
ll n;

ll solve(void)
{
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < n ; j++)
			dp[i][j] = INF;
	}
	
	for(ll i = 0 ; i < n ; i++)
		dp[i][i] = 0;
	
	for(ll i = 1 ; i < n ; i++)
	{
		if(a[i - 1] == a[i])
			dp[i - 1][i] = 0;
		else
			dp[i - 1][i] = 1;
	}
	
	for(ll L = 2 ; L < n ; L++)
	{
		for(ll i = 0 ; i < n ; i++)
		{
			ll j = i + L;
			
			if(j >= n)
				break;
			
			dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + 1);
			
			if(a[i] == a[j])
			{
				dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
				
				if(i + 2 <= j - 1)
				{
					dp[i][j] = min(dp[i][j], dp[i + 2][j - 1] + 1);
					dp[i][j] = min(dp[i][j], dp[i + 1][j - 2] + 1);
				}
			}
		}
	}
	
	return dp[0][n - 1];
}

int main(void)
{
	fastio
	
	cin >> a;
	
	n = strlen(a);
	
	ans = min(ans, solve());
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < n ; j++)
		{
			swap(a[i], a[j]);
			ans = min(ans, solve() + 1);
			swap(a[i], a[j]);
		}
	}
	
	cout << ans;
	return 0;
}