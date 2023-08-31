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

ll n, K, P;
ll a[2010], C[2010];
ll cost[2010][2010];
ll dp[2010][2010];

void dnc(ll s, ll e, ll l, ll r, ll cha)
{
	if(s > e)
		return;
	
	ll I = (s + e) >> 1;
	ll J = I - cha;
	ll gap = -INF, w = -2;
	ll siz = min(r, I - 2);
	
	for(ll i = l ; i <= siz ; i++)
	{
		ll I2 = i;
		ll J2 = I2 - cha + 1;
		ll k = I - i - 1;
		
		if(gap < dp[I2][J2] + cost[I - k + 1][I] + P)
		{
			gap = dp[I2][J2] + cost[I - k + 1][I] + P;
			w = I2;
		}
	}
	
	if(J)
		dp[I][J] = gap;
	
	else
	{
		dp[I][J] = 0;
		w = l;
	}
	
	dnc(s, I - 1, l, w, cha);
	dnc(I + 1, e, w, r, cha);
}

int main(void)
{
	fastio
	
	cin >> n >> K >> P;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> C[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i ; j <= n ; j++)
			cost[i][j] = cost[i][j - 1] + a[j] * C[j - i + 1];
	}
	
	for(ll i = 1 ; i <= n ; i++)
		dp[i][i] = cost[1][i] + P;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		dnc(i, n, i - 1, n, i);
		
		for(ll j = i ; j <= n ; j++)
		{
			ll I = j;
			ll J = I - i;
			
			if(I - 1 >= J)
				dp[I][J] = max(dp[I][J], dp[I - 1][J]);
		}
	}
	
	ll ans = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= K ; j++)
			ans = max(ans, dp[i][j]);
	}
	
	cout << ans;
	return 0;
}