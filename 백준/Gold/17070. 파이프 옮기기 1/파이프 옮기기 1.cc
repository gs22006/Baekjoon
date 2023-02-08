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

ll n;
ll a[20][20];
ll dp[20][20][5];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			cin >> a[i][j];
	}
	
	a[1][1] = a[1][2] = 1;
	dp[1][2][1] = 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			if(j < n && !a[i][j + 1])
				dp[i][j + 1][1] += dp[i][j][1] + dp[i][j][3];
			
			if(i < n && !a[i + 1][j])
				dp[i + 1][j][2] += dp[i][j][2] + dp[i][j][3];
			
			if(i < n && j < n && !a[i + 1][j] && !a[i][j + 1] && !a[i + 1][j + 1])
				dp[i + 1][j + 1][3] += dp[i][j][1] + dp[i][j][2] + dp[i][j][3];
		}
	}
	
	cout << dp[n][n][1] + dp[n][n][2] + dp[n][n][3];
	return 0;
}