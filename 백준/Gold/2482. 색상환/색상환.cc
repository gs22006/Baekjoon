#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, k;
ll dp[1010][1010];
ll ss = 1000000003;
ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	cin >> k;
	
	if(k * 2 > n)
	{
		cout << 0;
		return 0;
	}
	
	dp[0][0] = 1;
	dp[1][0] = dp[1][1] = 1;
	
	for(ll i = 2 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= k ; j++)
		{
			dp[i][j] = dp[i - 1][j];
			
			if(i - 2 >= 0 && j - 1 >= 0)
				dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % ss;
		}
	}
	
	ans = dp[n - 1][k] + dp[n - 3][k - 1];
	ans = ans % ss < 0 ? ans % ss + ss : ans % ss;
	
	cout << ans;
	return 0;
}