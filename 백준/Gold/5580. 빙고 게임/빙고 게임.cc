#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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

ll n, m, S;
ll dp1[110][3010];
ll dp2[110][3010];
ll ss = 100000;
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> m >> S;
	
	dp1[0][0] = 1;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		for(ll j = 0 ; j <= n * n ; j++)
		{
			for(ll k = 0 ; k <= S ; k++)
				dp2[j][k] = dp1[j][k];
		}
		
		for(ll j = 1 ; j <= n * n ; j++)
		{
			for(ll k = i ; k <= S ; k++)
				dp2[j][k] = (dp2[j][k] + dp1[j - 1][k - i]) % ss;
		}

		for(ll j = 0 ; j <= n * n ; j++)
		{
			for(ll k = 0 ; k <= S ; k++)
				dp1[j][k] = dp2[j][k];
		}
	}
	
	ans = (ans + dp2[n * n][S]) % ss;
	cout << ans;
	return 0;
}