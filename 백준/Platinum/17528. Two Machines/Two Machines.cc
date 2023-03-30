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
ll a[310], b[310];
ll dp[63010];
ll tmp[63010];
ll ans = INF;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i] >> b[i];
	
	for(ll i = 0 ; i < 63010 ; i++)
		dp[i] = INF;
	
	dp[0] = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j < 63010 ; j++)
			tmp[j] = INF;
		
		for(ll j = 0 ; j < 63010 ; j++)
		{
			if(j >= a[i])
				tmp[j] = min(tmp[j], dp[j - a[i]]);
			
			tmp[j] = min(tmp[j], dp[j] + b[i]);
		}
		
		for(ll j = 0 ; j < 63010 ; j++)
			dp[j] = tmp[j];
	}
	
	for(ll i = 0 ; i < 63010 ; i++)
		ans = min(ans, max(i, dp[i]));
	
	cout << ans;
	return 0;
}