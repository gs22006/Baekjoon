#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll t;
ll n, W;
ll a[10010], b[10010];
ll dp[10010][5];

void init(void)
{
	for(ll i = 0 ; i <= n ; i++)
	{
		for(ll j = 0 ; j < 4 ; j++)
			dp[i][j] = INF;
	}
}

void calc_dp(void)
{
	for(ll i = 2 ; i <= n ; i++)
	{
		dp[i][0] = min(dp[i][0], dp[i - 1][3]);
		dp[i][1] = min(dp[i][1], dp[i - 1][3] + 1);
		
		if(a[i - 1] + a[i] <= W)
			dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);
		
		dp[i][2] = min(dp[i][2], dp[i - 1][3] + 1);
		
		if(b[i - 1] + b[i] <= W)
			dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);
		
		dp[i][3] = min(dp[i][3], dp[i - 1][3] + 2);
		
		if(a[i - 1] + a[i] <= W)
			dp[i][3] = min(dp[i][3], dp[i - 1][2] + 2);
		
		if(b[i - 1] + b[i] <= W)
			dp[i][3] = min(dp[i][3], dp[i - 1][1] + 2);
		
		if(a[i - 1] + a[i] <= W && b[i - 1] + b[i] <= W)
			dp[i][3] = min(dp[i][3], dp[i - 1][0] + 2);
		
		if(a[i] + b[i] <= W)
			dp[i][3] = min(dp[i][3], dp[i - 1][3] + 1);
		
		dp[i][1] = min(dp[i][1], dp[i][0] + 1);
		dp[i][2] = min(dp[i][2], dp[i][0] + 1);
		dp[i][3] = min(dp[i][3], dp[i][0] + 2);
		
		if(a[i] + b[i] <= W)
			dp[i][3] = min(dp[i][3], dp[i][0] + 1);
	}
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		ll ans = INF;
		
		cin >> n >> W;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i];
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> b[i];
		
		if(n == 1)
		{
			if(a[1] + b[1] <= W)
				cout << 1 en;
			else
				cout << 2 en;
			
			continue;
		}
		
		init();
		
		dp[1][0] = 0;
		dp[1][1] = 1;
		dp[1][2] = 1;
		
		if(a[1] + b[1] <= W)
			dp[1][3] = 1;
		else
			dp[1][3] = 2;
		
		calc_dp();
		ans = min(ans, dp[n][3]);
		
		if(a[1] + a[n] <= W)
		{
			init();
			
			dp[1][1] = 1;
			dp[1][3] = 2;
			
			calc_dp();
			ans = min(ans, dp[n][2]);
		}
		
		if(b[1] + b[n] <= W)
		{
			init();
			
			dp[1][2] = 1;
			dp[1][3] = 2;
			
			calc_dp();
			ans = min(ans, dp[n][1]);
		}
		
		if(a[1] + a[n] <= W && b[1] + b[n] <= W)
		{
			init();
			
			dp[1][3] = 2;
			
			calc_dp();
			ans = min(ans, dp[n][0]);
		}
		
		cout << ans en;
	}
	
	return 0;
}