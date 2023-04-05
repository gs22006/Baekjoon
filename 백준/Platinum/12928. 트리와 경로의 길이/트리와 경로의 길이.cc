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

ll n, s;
ll dp[110][1010];

int main(void)
{
	fastio
	
	cin >> n >> s;
	
	if(n <= 2)
	{
		cout << 0;
		return 0;
	}
	
	dp[2][0] = 1;
	
	for(ll i = 2 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= s ; j++)
		{
			ll nam = n - i;
			
			for(ll k = 1 ; k <= nam ; k++)
			{
				ll nxt = j + k * (k - 1) / 2;
				nxt += k;
				
				if(nxt <= s)
					dp[i + k][nxt] |= dp[i][j];
			}
		}
	}
	
	cout << dp[n][s];
	return 0;
}