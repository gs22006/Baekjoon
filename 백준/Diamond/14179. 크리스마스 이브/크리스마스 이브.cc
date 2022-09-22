#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, k;
pair<ll, ll> a[5010];
ll nu[5010][5010];
ll md[5010][5010];
ll dp[3][5010];
ll ans = MAX;
ll p;

void dnc(ll s, ll e, ll l, ll r, ll K)
{
	if(s > e)
		return;
	
	ll mid = (s + e) >> 1;
	ll w = -1;
	
	dp[K][mid] = INF;
	
	for(ll i = l ; i < mid && i <= r ; ++i)
	{
		ll mm = md[i][mid];
		ll gap = dp[1 - K][i] - nu[i][n] + nu[i][mm - 1] + nu[mid][mm] + nu[mid][n];
		
		if(gap < dp[K][mid])
		{
			dp[K][mid] = gap;
			w = i;
		}
	}
	
	dnc(s, mid - 1, l, w, K);
	dnc(mid + 1, e, w, r, K);
}

int main(void)
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> n >> k;
	
	for(ll i = 1 ; i <= n ; ++i)
		cin >> a[i].fi >> a[i].se;
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		for(ll j = 1 ; j <= n ; ++j)
			nu[i][j] = abs(a[j].fi - a[i].fi) * a[j].se;
		
		for(ll j = i + 1 ; j <= n ; ++j)
			nu[i][j] += nu[i][j - 1];
		
		for(ll j = i - 1 ; j >= 1 ; --j)
			nu[i][j] += nu[i][j + 1];
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		p = i;
		
		for(ll j = i + 1 ; j <= n ; ++j)
		{
			while((a[p].fi << 1) < a[i].fi + a[j].fi)
				p++;
			
			md[i][j] = p;
		}
	}
	
	for(ll i = 1 ; i <= n ; ++i)
		dp[1][i] = nu[i][n] + nu[i][1];
	
	for(ll i = 2 ; i <= k ; ++i)
		dnc(i - 1, n - k + i, i - 1, n - k + i - 1, i & 1);
	
	ll gap = (k & 1);
	
	for(ll i = k ; i <= n ; ++i)
		ans = min(ans, dp[gap][i]);
	
	cout << ans;
	return 0;
}