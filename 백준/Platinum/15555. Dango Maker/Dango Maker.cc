#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll n, m;
char a[3010][3010];
vector<ll> vec[10010];
vector< pair<ll, ll> > rgw[10010];
ll dp[10010][4] = {0, };
ll ans;

int main(void)
{
	scanf("%lld %lld", &n, &m);
	
	for(ll i = 1 ; i <= n ; i++)
		scanf("%s", a[i] + 1);
	
	for(ll i = 2 ; i <= n + m ; i++)
	{
		for(ll j = 1 ; j <= i - 1 ; j++)
		{
			ll x = j;
			ll y = i - j;
			pair<ll, ll> tmp;
			
			if(x > n || y > m)
				continue;
			
			if(a[x][y] == 'G')
			{
				vec[i].push_back(j);
				
				if(a[x - 1][y] == 'R' && a[x + 1][y] == 'W')
					tmp.first = 1;
				if(a[x][y - 1] == 'R' && a[x][y + 1] == 'W')
					tmp.second = 1;
				
				rgw[i].push_back(tmp);
			}
		}
	}
	
	for(ll i = 2 ; i <= n + m ; i++)
	{
		ll maxx = 0;
		
		if(rgw[i].empty())
			continue;
		
		dp[0][0] = 0;
		dp[0][1] = rgw[i][0].first;
		dp[0][2] = rgw[i][0].second;
		
		maxx = max(rgw[i][0].first, rgw[i][0].second);
		
		for(ll j = 1 ; j < vec[i].size() ; j++)
		{
			if((vec[i][j] - 1LL) == vec[i][j - 1])
			{
				dp[j][0] = max(dp[j - 1][0], max(dp[j - 1][1], dp[j - 1][2]));
				dp[j][1] = max(dp[j - 1][0], dp[j - 1][1]) + rgw[i][j].first;
				dp[j][2] = max(dp[j - 1][0], dp[j - 1][2]) + rgw[i][j].second;
			}
			
			else
			{
				dp[j][0] = max(dp[j - 1][0], max(dp[j - 1][1], dp[j - 1][2]));
				dp[j][1] = max(dp[j - 1][0], max(dp[j - 1][1], dp[j - 1][2])) + rgw[i][j].first;
				dp[j][2] = max(dp[j - 1][0], max(dp[j - 1][1], dp[j - 1][2])) + rgw[i][j].second;
			}
			
			maxx = max(dp[j][0], max(dp[j][1], dp[j][2]));
		}
		
		ans += maxx;
	}
	
	printf("%lld", ans);
	return 0;
}