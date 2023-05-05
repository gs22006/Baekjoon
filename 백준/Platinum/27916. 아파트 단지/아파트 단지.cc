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

ll n, m, q;
ll a[300010];
ll all;
ll l, r;
ll dp[300010];

int main(void)
{
	fastio
	
	cin >> n >> m >> q;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	l = 0;
	r = 10000000000;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		
		for(ll i = 1 ; i <= n ; i++)
			dp[i] = 0;
		
		dp[0] = 1;
		ll sum = 0;
		ll p = 0;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			while(p < i && a[p + 1] < a[i] - mid)
			{
				sum -= dp[p];
				p++;
			}
			
			if(i - m >= 0)
				sum += dp[i - m];
			
			if(p <= i - m)
				dp[i] = (!!sum);
		}
		
		if(dp[n])
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	while(q--)
	{
		cin >> all;
		
		if(all >= l)
			cout << 1;
		else
			cout << 0;
	}
	
	return 0;
}