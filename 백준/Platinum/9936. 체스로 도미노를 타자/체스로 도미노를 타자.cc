#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 1987654321
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, k;
ll a[1010][5];
ll dp[1010][1010][10];
ll ans = -INF;

int main(void)
{
	fastio
	
	cin >> n >> k;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j < 3 ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 0 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= k ; j++)
		{
			for(ll o = 0 ; o < 8 ; o++)
				dp[i][j][o] = -INF;
		}
	}
	
	dp[0][0][7] = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= k ; j++)
		{
			for(ll o = 0 ; o < 8 ; o++)
				dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][o]);
			
			if(j >= 1)
			{
				for(ll o = 0 ; o < 8 ; o++)
				{
					if(!(o & 1))
						dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][o] + a[i][0] + a[i - 1][0]);
					
					if(!(o & 2))
						dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][o] + a[i][1] + a[i - 1][1]);
					
					if(!(o & 4))
						dp[i][j][4] = max(dp[i][j][4], dp[i - 1][j - 1][o] + a[i][2] + a[i - 1][2]);
					
					if(!(o & 1) && !(o & 2) && j >= 2)
						dp[i][j][3] = max(dp[i][j][3], dp[i - 1][j - 2][o] + a[i][1] + a[i - 1][1] + a[i][0] + a[i - 1][0]);
					
					if(!(o & 1) && !(o & 4) && j >= 2)
						dp[i][j][5] = max(dp[i][j][5], dp[i - 1][j - 2][o] + a[i][2] + a[i - 1][2] + a[i][0] + a[i - 1][0]);
					
					if(!(o & 2) && !(o & 4) && j >= 2)
						dp[i][j][6] = max(dp[i][j][6], dp[i - 1][j - 2][o] + a[i][1] + a[i - 1][1] + a[i][2] + a[i - 1][2]);
				}
			}
			
			for(ll o = 0 ; o < 8 ; o++)
			{
				if(!(o & 1) && !(o & 2) && j >= 1)
					dp[i][j][o | 3] = max(dp[i][j][o | 3], dp[i][j - 1][o] + a[i][0] + a[i][1]);
				
				if(!(o & 2) && !(o & 4) && j >= 1)
					dp[i][j][o | 6] = max(dp[i][j][o | 6], dp[i][j - 1][o] + a[i][1] + a[i][2]);
			}
		}
	}
	
	for(ll i = 0 ; i <= n ; i++)
	{
		for(ll o = 0 ; o < 8 ; o++)
			ans = max(ans, dp[i][k][o]);
	}
	
	cout << ans;
	return 0;
}