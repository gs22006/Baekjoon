#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n, m;
ll S, E;
ll T;
ll dp[3010][3010];
ll nu[3010][3010];
ll no[3010];
deque< pair<ll, ll> > dq[3010];
ll w;
ll ans = INF;

int main(void)
{
	fastio
	
	cin >> n >> m >> S >> E >> T;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> nu[i][j];
		
		for(ll j = 1 ; j <= m ; j++)
			nu[i][j] += nu[i][j - 1];
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> no[i];
		
		for(ll j = 1 ; j <= m ; j++)
			dp[i][j] = INF;
	}
	
	for(ll i = 1 ; i < m ; i++)
	{
		if(i - S >= 0)
		{
			vector< pair<ll, ll> > tmp;
			
			for(ll j = 1 ; j <= n ; j++)
				tmp.push_back({dp[j][i - S], j});
			
			sort(tmp.begin(), tmp.end());
			
			for(ll j = 1 ; j <= n ; j++)
			{
				for(ll k = 0 ; k < 3 ; k++)
				{
					if(tmp[k].se == j || tmp[k].se == no[j])
						continue;
					
					ll gap = dp[tmp[k].se][i - S] - nu[j][i - S] + T;
					
					while(!dq[j].empty() && dq[j].back().fi >= gap)
						dq[j].pop_back();
					
					dq[j].push_back({gap, i - S});
					break;
				}
			}
		}
		
		for(ll j = 1 ; j <= n ; j++)
		{
			while(!dq[j].empty() && dq[j].front().se < i - E)
				dq[j].pop_front();
			
			if(!dq[j].empty())
				dp[j][i] = dq[j].front().fi + nu[j][i];
		}
	}
	
	for(ll i = 0 ; i < m ; i++)
	{
		vector< pair<ll, ll> > tmp;
		
		for(ll j = 1 ; j <= n ; j++)
			tmp.push_back({dp[j][i], j});
		
		sort(tmp.begin(), tmp.end());
		
		for(ll j = 1 ; j <= n ; j++)
		{
			for(ll k = 0 ; k < 3 ; k++)
			{
				if(tmp[k].se == j || tmp[k].se == no[j])
					continue;
				
				ll gap = dp[tmp[k].se][i] - nu[j][i] + T;
				
				while(!dq[j].empty() && dq[j].back().fi >= gap)
					dq[j].pop_back();
				
				dq[j].push_back({gap, i});
				break;
			}
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		while(!dq[i].empty() && dq[i].front().se < m - E)
			dq[i].pop_front();
		
		if(!dq[i].empty())
			dp[i][m] = dq[i].front().fi + nu[i][m];
	}
	
	for(ll i = 1 ; i <= n ; i++)
		ans = min(ans, dp[i][m] - T);
	
	cout << ans;
	return 0;
}