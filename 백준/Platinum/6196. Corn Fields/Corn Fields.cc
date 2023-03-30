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

ll n, m;
ll a[20][20];
ll dp[410][5010];
ll ss = 100000000;
ll siz;
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
			cin >> a[i][j];
	}
	
	siz = (1LL << m);
	
	dp[0][0] = 1;
	
	for(ll i = 0 ; i < n * m ; i++)
	{
		ll X = i / m;
		ll Y = i % m;
		
		for(ll j = 0 ; j < siz ; j++)
		{
			if((!(j & (1LL << (m - 1))) || Y == 0) && !(j & 1) && a[X][Y])
				dp[i + 1][(j >> 1) | (1LL << (m - 1))] = (dp[i + 1][(j >> 1) | (1LL << (m - 1))] + dp[i][j]) % ss;
			
			dp[i + 1][j >> 1] = (dp[i + 1][j >> 1] + dp[i][j]) % ss;
		}
	}
	
	/*for(ll i = 0 ; i <= n * m ; i++)
	{
		cout << "..........." << i en;
		
		for(ll j = 0 ; j < siz ; j++)
		{
			for(ll k = 0 ; k < m ; k++)
				cout << !!(j & (1LL << k));
			
			cout sp << ": " << dp[i][j] en;
		}
	}*/
	
	for(ll i = 0 ; i < siz ; i++)
		ans = (ans + dp[n * m][i]) % ss;
	
	cout << ans;
	return 0;
}