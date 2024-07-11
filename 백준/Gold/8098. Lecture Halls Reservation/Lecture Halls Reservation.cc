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
pll a[30010];
ll dp[30010];
ll p;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		a[i].fi++, a[i].se++;
	}
	
	sort(a + 1, a + 1 + n);
	
	p = 1;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(p <= a[i].fi)
		{
			dp[p] = max(dp[p - 1], dp[p]);
			p++;
		}
		
		dp[a[i].se] = max(dp[a[i].se], dp[a[i].fi] + a[i].se - a[i].fi);
	}
	
	while(p < 30010)
	{
		dp[p] = max(dp[p - 1], dp[p]);
		p++;
	}
	
	cout << dp[30009];
	return 0;
}