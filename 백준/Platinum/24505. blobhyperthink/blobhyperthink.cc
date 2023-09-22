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
ll a[100010];
ll ss = 1000000007;
ll dp[100010][12];

struct fenwicktree
{
	ll bit[100010];
	
	void update(ll w, ll v)
	{
		for(ll i = w ; i <= n ; i += (i & (-i)))
			bit[i] = (bit[i] + v) % ss;
	}
	
	ll query(ll X)
	{
		ll ret = 0;
		
		for(ll i = X ; i > 0 ; i -= (i & (-i)))
			ret = (ret + bit[i]) % ss;
		
		return ret;
	}
}BIT[12];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
		dp[i][1] = 1;
	
	for(ll i = 2 ; i <= 11 ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			dp[j][i] = BIT[i - 1].query(a[j] - 1);
			BIT[i - 1].update(a[j], dp[j][i - 1]);
		}
	}
	
	ll ans = 0;
	
	for(ll i = 1 ; i <= n ; i++)
		ans = (ans + dp[i][11]) % ss;
	
	cout << (ans % ss + ss) % ss;
	return 0;
}