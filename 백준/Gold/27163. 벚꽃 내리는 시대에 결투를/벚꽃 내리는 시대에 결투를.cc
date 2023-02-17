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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"

ll n, A, L;
pair<ll, ll> a[5010];
ll dp[5010][5010];
pair<ll, pair<ll, ll> > yuk[5010][5010];
ll ff = -1;

int main(void)
{
	fastio
	
	cin >> n >> A >> L;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi >> a[i].se;
	
	for(ll i = 0 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= L ; j++)
			dp[i][j] = -1;
	}
	
	dp[0][L] = A;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 0 ; j <= L ; j++)
		{
			if(a[i].se == -1)
			{
				if(dp[i - 1][j] != -1)
				{
					if(dp[i][j] < max(dp[i - 1][j] - a[i].fi, 0LL))
					{
						dp[i][j] = max(dp[i - 1][j] - a[i].fi, 0LL);
						yuk[i][j] = {1, {i - 1, j}};
					}
				}
			}
			
			if(dp[i - 1][j] != -1 && j - a[i].se > 0 && a[i].se != -1)
			{
				if(dp[i][j - a[i].se] < dp[i - 1][j])
				{
					dp[i][j - a[i].se] = dp[i - 1][j];
					yuk[i][j - a[i].se] = {2, {i - 1, j}};
				}
			}
			
			if(dp[i - 1][j] != -1 && dp[i - 1][j] >= a[i].fi && a[i].fi != -1)
			{
				if(dp[i][j] < dp[i - 1][j] - a[i].fi)
				{
					dp[i][j] = dp[i - 1][j] - a[i].fi;
					yuk[i][j] = {1, {i - 1, j}};
				}
			}
		}
	}
	
	for(ll i = 1 ; i <= L ; i++)
	{
		if(dp[n][i] != -1)
			ff = i;
	}
	
	if(ff == -1)
	{
		cout << "NO";
		return 0;
	}
	
	cout << "YES\n";
	
	pair<ll, ll> xy = {n, ff};
	vector<char> ans;
	
	while(1)
	{
		if(xy.fi == 0)
			break;
		
		if(yuk[xy.fi][xy.se].fi == 1)
			ans.push_back('A');
		else
			ans.push_back('L');
		
		xy = yuk[xy.fi][xy.se].se;
	}
	
	reverse(ans.begin(), ans.end());
	
	for(auto &i : ans)
		cout << i;
	
	return 0;
}