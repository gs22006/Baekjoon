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
char a[1010][1010];
ll b[1010][1010], c[1010][1010];
ll L[1010][1010], U[1010][1010];
ll dp[1010][1010];
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(a[i][j] == 'G')
				b[i][j] = 1;
			
			if(j >= 2 && a[i][j] == a[i][j - 1])
				c[i][j] = 1;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(j == 1 || b[i][j] != b[i][j - 1])
				L[i][j] = j;
			else
				L[i][j] = L[i][j - 1];
		}
	}
	
	for(ll j = 1 ; j <= m ; j++)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			if(c[i][j])
				U[i][j] = U[i - 1][j] + 1;
			else
				U[i][j] = 0;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
		dp[i][1] = 1;
	
	for(ll i = 1 ; i <= m ; i++)
		dp[1][i] = 1;
	
	for(ll i = 2 ; i <= n ; i++)
	{
		for(ll j = 2 ; j <= m ; j++)
			dp[i][j] = min(min(j - L[i][j] + 1, U[i - 1][j] + 1), dp[i - 1][j - 1] + 1);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			ans = max(ans, dp[i][j]);
	}
	
	cout << ans * ans;
	return 0;
}