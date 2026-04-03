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
ll a[4010];
ll b[4010];
ll dp[4010][4010];

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i];
		
		for(ll i = 1 ; i <= m ; i++)
			cin >> b[i];
		
		for(ll i = 0 ; i <= m ; i++)
		{
			for(ll j = 0 ; j <= n ; j++)
				dp[i][j] = 0;
		}
		
		dp[0][0] = 1;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			ll now = 0;
			
			for(ll j = b[i] ; j <= n ; j++)
			{
				now |= dp[i - 1][j - b[i]];
				dp[i][j] = now;
			}
			
			for(ll j = 1 ; j <= n ; j++)
			{
				if(a[j] == b[i])
					dp[i][j] |= dp[i - 1][j - 1];
			}
		}
		
		if(dp[m][n])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}