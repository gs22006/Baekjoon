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

ll t;
ll n;
ll all, bll;
vector<ll> vec[200010];
ll dp[200010];
ll ans;

void dfs(ll here, ll pa)
{
	ll minn = INF, maxx = -INF;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		dfs(i, here);
		minn = min(minn, dp[i] + 1);
		maxx = max(maxx, dp[i] + 1);
	}
	
	if(here != 1)
	{
		ll ff = 0;
		
		for(auto &i : vec[here])
		{
			if(i == pa)
				continue;
			
			if(dp[i] + 1 == minn)
			{
				if(!ff)
				{
					ff = 1;
					continue;
				}
			}
			
			ans = max(ans, dp[i] + 2);
		}
	}
	
	else
	{
		ll ff = 0;
		
		for(auto &i : vec[here])
		{
			if(i == pa)
				continue;
			
			if(dp[i] + 1 == maxx)
			{
				if(!ff)
				{
					ff = 1;
					continue;
				}
			}
			
			ans = max(ans, dp[i] + 2);
		}
	}
	
	if(minn != INF && here != 1)
		dp[here] = minn;
	else if(maxx != -INF && here == 1)
		dp[here] = maxx;
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			vec[i].clear();
			dp[i] = 0;
		}
		
		for(ll i = 1 ; i < n ; i++)
		{
			cin >> all >> bll;
			
			vec[all].push_back(bll);
			vec[bll].push_back(all);
		}
		
		ans = 0;
		
		dfs(1, 0);
		
		for(ll i = 1 ; i <= n ; i++)
			ans = max(ans, dp[i]);
		
		cout << ans en;
	}
	
	return 0;
}