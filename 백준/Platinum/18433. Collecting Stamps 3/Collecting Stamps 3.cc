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

ll n, L;
ll a[210], T[210];
vector<pll> dp[210][210][3];
ll ans;

ll dist(ll X, ll Y)
{
	if(X < Y)
		return a[Y] - a[X];
	
	return a[Y] - a[X] + L;
}

bool comp(pll X, pll Y)
{
	if(X.fi != Y.fi)
		return X.fi < Y.fi;
	
	return X.se > Y.se;
}

int main(void)
{
	fastio
	
	cin >> n >> L;
	
	n++;
	
	for(ll i = 2 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 2 ; i <= n ; i++)
		cin >> T[i];
	
	a[1] = 0, T[1] = INF;
	
	dp[1][1][0].push_back({0, 0});
	dp[1][1][1].push_back({0, 0});
	
	for(ll l = 0 ; l < n - 1 ; l++)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			ll j = (i + l - 1) % n + 1;
			
			sort(dp[i][j][0].begin(), dp[i][j][0].end(), comp);
			sort(dp[i][j][1].begin(), dp[i][j][1].end(), comp);
			
			for(ll k = 0 ; k < 2 ; k++)
			{
				vector<pll> tmp;
				ll last = -1;
				
				for(auto &o : dp[i][j][k])
				{
					if(last < o.se)
					{
						last = o.se;
						tmp.push_back(o);
					}
				}
				
				dp[i][j][k] = tmp;
			}
			
			for(auto &k : dp[i][j][0])
			{
				ll lf = (i - 1 <= 0) ? n : i - 1;
				ll tm = k.fi + dist(lf, i);
				
				if(tm <= T[lf])
					dp[lf][j][0].push_back({tm, k.se + 1});
				else
					dp[lf][j][0].push_back({tm, k.se});
				
				ll rg = (j + 1 > n) ? 1 : j + 1;
				tm = k.fi + dist(i, rg);
				
				if(tm <= T[rg])
					dp[i][rg][1].push_back({tm, k.se + 1});
				else
					dp[i][rg][1].push_back({tm, k.se});
			}
			
			for(auto &k : dp[i][j][1])
			{
				ll lf = (i - 1 <= 0) ? n : i - 1;
				ll tm = k.fi + dist(lf, j);
				
				if(tm <= T[lf])
					dp[lf][j][0].push_back({tm, k.se + 1});
				else
					dp[lf][j][0].push_back({tm, k.se});
				
				ll rg = (j + 1 > n) ? 1 : j + 1;
				tm = k.fi + dist(j, rg);
				
				if(tm <= T[rg])
					dp[i][rg][1].push_back({tm, k.se + 1});
				else
					dp[i][rg][1].push_back({tm, k.se});
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
		{
			for(auto &k : dp[i][j][0])
				ans = max(ans, k.se);
			
			for(auto &k : dp[i][j][1])
				ans = max(ans, k.se);
		}
	}
	
	cout << ans;
	return 0;
}