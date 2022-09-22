#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define fi first
#define se second

struct poi
{
	ll x, y;
	ll cost;
};

ll n;
poi a[1010];
ll w, m;
ll dp[1010][15][2510];
ll ans = MAX;

ll dist(ll X, ll Y)
{
	return abs(a[X].x - a[Y].x) + abs(a[X].y - a[Y].y);
}

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%lld %lld %lld", &a[i].x, &a[i].y, &a[i].cost);
	
	scanf("%lld", &w);
	scanf("%lld", &m);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= m ; j++)
		{
			for(ll k = 0 ; k <= n * 2 + 1 ; k++)
				dp[i][j][k] = MAX / 2;
		}
	}
	
	dp[1][0][0] = 0;
	
	for(ll j = 0 ; j <= m ; j++)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll k = 1 ; k <= n ; k++)
			{
				if(i == k)
					continue;
				
				if(dist(i, k) <= w)
					dp[k][j][n + 1 + i] = min(dp[k][j][n + 1 + i], dp[i][j][1]);
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll k = 2 ; k <= n + 1 ; k++)
			{
				if(i == k - 1)
					continue;
				
				dp[k - 1][j][0] = min(dp[k - 1][j][0], dp[i][j][k]);
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
			dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][0] + w * a[i].cost);
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll k = 2 ; k <= n + 1 ; k++)
			{
				if(k - 1 == i)
					continue;
				
				if(dist(i, k - 1) <= w)
					dp[i][j + 1][k] = min(dp[i][j + 1][k], dp[i][j][0] + dist(i, k - 1) * a[i].cost);
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll k = n + 2 ; k <= n * 2 + 1 ; k++)
			{
				if(k - n - 1 == i)
					continue;
				
				if(w - dist(k - n - 1, i) >= 0 && w - dist(k - n - 1, i) <= w)
					dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + dist(k - n - 1, i) * a[i].cost);
			}
		}
		
		for(ll i = 1 ; i <= n ; i++)
		{
			vector< pair<ll, ll> > vec;
			
			for(ll k = 1 ; k <= n ; k++)
			{
				if(i == k)
					continue;
				
				if(w - dist(i, k) >= 0)
				{
					vec.push_back(make_pair(w - dist(i, k), -(n + k + 1)));
					vec.push_back(make_pair(dist(i, k), k + 1));
				}
			}
			
			sort(vec.begin(), vec.end());
			ll minn = MAX / 2;
			
			for(ll k = 0 ; k < vec.size() ; k++)
			{
				if(vec[k].se < 0)
					minn = min(minn, dp[i][j][-vec[k].se] - vec[k].fi * a[i].cost);
				else
					dp[i][j + 1][vec[k].se] = min(dp[i][j + 1][vec[k].se], minn + vec[k].fi * a[i].cost);
			}
		}
	}
	
	for(ll j = 0 ; j <= m ; j++)
	{
		for(ll k = 0 ; k <= n * 2 + 1 ; k++)
			ans = min(ans, dp[2][j][k]);
	}
	
	if(ans > MAX / 4)
		printf("-1");
	else
		printf("%lld", ans);
	
	return 0;
}