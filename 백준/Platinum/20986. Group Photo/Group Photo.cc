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
ll dp[5010];
ll w[5010];

struct fenwicktree
{
	ll bit[5010];
	
	void init(void)
	{
		for(ll i = 0 ; i <= n ; i++)
			bit[i] = 0;
	}
	
	void update(ll W, ll v)
	{
		if(W == 0)
			return;
		
		for(ll i = W ; i <= n ; i += (i & (-i)))
			bit[i] += v;
	}
	
	ll query(ll W)
	{
		ll ret = 0;
		
		for(ll i = W ; i > 0 ; i -= (i & (-i)))
			ret += bit[i];
		
		return ret;
	}
}BIT, BIT2;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		
		w[a[i]] = i;
		dp[i] = INF;
	}
	
	dp[0] = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		BIT.init();
		BIT2.init();
		
		for(ll j = 1 ; j < i ; j++)
			BIT.update(w[j], 1);
		
		ll sum = 0;
		
		for(ll j = i - 1 ; j >= 0 ; j--)
		{
			ll now = w[j + 1] + BIT.query(n) - BIT.query(w[j + 1] - 1);
			
			sum += now;
			dp[i] = min(dp[i], dp[j] + sum - (i + j + 1) * (i - j) / 2);
			
			BIT.update(w[j + 1], 1);
			BIT2.update(w[j + 1], 1);
			BIT.update(w[j], -1);
			sum -= BIT2.query(w[j]);
		}
	}
	
	cout << dp[n];
	return 0;
}