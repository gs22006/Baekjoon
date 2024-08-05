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

ll n;
ll a[5010];
ll t;
ll all;
ll dp[5010][5010];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll L = 1 ; L <= n ; L++)
	{
		for(ll R = n ; R > L ; R--)
		{
			dp[L][R] = max(dp[L][R + 1], dp[L - 1][R]);
			dp[L][R] = max(dp[L][R], dp[L - 1][R + 1] + (a[L] == a[R]));
		}
	}
	
	cin >> t;
	
	while(t--)
	{
		cin >> all;
		cout << n - 1 - 2 * dp[all - 1][all + 1] en;
	}
	
	return 0;
}