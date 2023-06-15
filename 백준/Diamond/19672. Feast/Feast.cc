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

ll n, K;
ll a[300010];
pll dp[300010][2];
ll ans;

void solve(ll lambda)
{
	for(ll i = 0 ; i <= n ; i++)
	{
		dp[i][0] = {0, 0};
		dp[i][1] = {-INF, 0};
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(dp[i - 1][0].fi == dp[i - 1][1].fi)
		{
			dp[i][0].fi = dp[i - 1][0].fi;
			dp[i][0].se = min(dp[i - 1][0].se, dp[i - 1][1].se);
		}
		
		else
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		
		dp[i][1] = {dp[i - 1][0].fi + a[i] * 2 - lambda, dp[i - 1][0].se + 1};
		
		if(dp[i - 1][1].fi + a[i] * 2 == dp[i][1].fi && dp[i - 1][1].se < dp[i][1].se)
			dp[i][1].se = dp[i - 1][1].se;
		else if(dp[i - 1][1].fi + a[i] * 2 > dp[i][1].fi)
			dp[i][1] = {dp[i - 1][1].fi + a[i] * 2, dp[i - 1][1].se};
	}
}

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	solve(0);
	
	pll gap;
	
	if(dp[n][0].fi == dp[n][1].fi)
	{
		gap.fi = dp[n][0].fi;
		gap.se = min(dp[n][0].se, dp[n][1].se);
	}
	
	else
		gap = max(dp[n][0], dp[n][1]);
	
	if(gap.se <= K)
	{
		cout << gap.fi / 2;
		return 0;
	}
	
	ll l = 0, r = 1000000000000;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		
		solve(mid);
		
		if(dp[n][0].fi == dp[n][1].fi)
		{
			gap.fi = dp[n][0].fi;
			gap.se = min(dp[n][0].se, dp[n][1].se);
		}
		
		else
			gap = max(dp[n][0], dp[n][1]);
		
		if(gap.se > K)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	solve(l);
	
	if(dp[n][0].fi == dp[n][1].fi)
	{
		gap.fi = dp[n][0].fi;
		gap.se = min(dp[n][0].se, dp[n][1].se);
	}
	
	else
		gap = max(dp[n][0], dp[n][1]);
	
	gap.fi += gap.se * l;
	gap.fi /= 2;
	
	cout << gap.fi;
	return 0;
}