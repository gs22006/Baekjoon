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

ll n, m, K;
ll a[20010];
ll dp[20010];

int main(void)
{
	fastio
	
	cin >> n >> m >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
		dp[i] = INF;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll maxx = -INF, minn = INF;
		
		for(ll j = i ; j >= 1 ; j--)
		{
			maxx = max(maxx, a[j]);
			minn = min(minn, a[j]);
			
			if(i - j + 1 > m)
				break;
			
			dp[i] = min(dp[i], dp[j - 1] + (maxx - minn) * (i - j + 1) + K);
		}
	}
	
	cout << dp[n];
	return 0;
}