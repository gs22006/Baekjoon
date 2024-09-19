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

ll t;
ll n, m;
ll dp[2010][2010];

int main(void)
{
	fastio
	
	for(ll i = 0 ; i < 2010 ; i++)
		dp[0][i] = 1;
	
	for(ll i = 1 ; i <= 10 ; i++)
	{
		for(ll j = 1 ; j < 2010 ; j++)
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j / 2];
	}
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		cout << dp[n][m] en;
	}
	
	return 0;
}