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
ll a[8010];
ll nu[8010];
ll dp[8010][810];
ll ans = INF;

void dnc(ll s, ll e, ll l, ll r, ll j)
{
	ll mid = (s + e) >> 1;
	ll w = -1;
	ll L = l, R = min(r, mid);
	
	for(ll i = L ; i <= R ; i++)
	{
		if(dp[mid][j] > dp[i][j - 1] + (nu[mid] - nu[i]) * (mid - i))
		{
			dp[mid][j] = dp[i][j - 1] + (nu[mid] - nu[i]) * (mid - i);
			w = i;
		}
	}
	
	if(s >= e)
		return;
	
	dnc(s, mid - 1, l, w, j);
	dnc(mid + 1, e, w, r, j);
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		nu[i] = nu[i - 1] + a[i];
	}
	
	for(ll i = 0 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= m ; j++)
			dp[i][j] = INF;
	}
	
	dp[0][0] = 0;
	
	for(ll i = 1 ; i <= m ; i++)
		dnc(0, n, 0, n, i);
	
	for(ll i = 0 ; i <= m ; i++)
		ans = min(ans, dp[n][i]);
	
	cout << ans;
	return 0;
}