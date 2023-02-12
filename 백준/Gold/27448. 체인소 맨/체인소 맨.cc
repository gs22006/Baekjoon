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

ll n, m, F;
char a[110][110];
ll ga[110][110], se[110][110];
ll dp[110][110], dp2[110][110];
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> m >> F;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(a[i][j] == '#' && a[i + 1][j] == '#')
				ga[i][j] = 0;
			else if(a[i][j] == '.' && a[i + 1][j] == '.')
				ga[i][j] = 2;
			else
				ga[i][j] = 1;
		}
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j < m ; j++)
		{
			if(a[i][j] == '#' && a[i][j + 1] == '#')
				se[i][j] = 0;
			else if(a[i][j] == '.' && a[i][j + 1] == '.')
				se[i][j] = 2;
			else
				se[i][j] = 1;
		}
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			if(ga[i][j] == 0)
				ans += dp[i][j - 1];
			
			else if(ga[i][j] == 1)
			{
				dp[i][j] = INF;
				
				ll ff = 0;
				ll ff2 = 0;
				
				for(ll k = j + 1 ; k <= m ; k++)
				{
					if(ga[i][k] == 0)
						ff = 1;
				}
				
				for(ll k = j - 1 ; k >= 1 ; k--)
				{
					if(ga[i][k] == 0)
						ff2 = 1;
				}
				
				for(ll k = j - 1 ; k >= 0 ; k--)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + j - k);
					
					if(!ff)
						dp[i][j] = min(dp[i][j], dp[i][k] + F);
					
					if(!ff2)
						dp[i][j] = min(dp[i][j], dp[i][k] + F);
					
					if(ga[i][k] == 0)
						break;
				}
			}
			
			else
			{
				dp[i][j] = INF;
				
				ll ff = 0;
				ll ff2 = 0;
				
				for(ll k = j + 1 ; k <= m ; k++)
				{
					if(ga[i][k] == 0)
						ff = 1;
				}
				
				for(ll k = j - 1 ; k >= 1 ; k--)
				{
					if(ga[i][k] == 0)
						ff2 = 1;
				}
				
				for(ll k = j - 1 ; k >= 0 ; k--)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + j - k);
					
					if(!ff)
						dp[i][j] = min(dp[i][j], dp[i][k] + F);
					
					if(!ff2)
						dp[i][j] = min(dp[i][j], dp[i][k] + F);
					
					if(ga[i][k] == 0)
						break;
				}
				
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			}
		}
		
		ans += dp[i][m];
	}
	
	for(ll j = 1 ; j < m ; j++)
	{
		for(ll i = 1 ; i <= n ; i++)
		{
			if(se[i][j] == 0)
				ans += dp2[i - 1][j];
			
			else if(se[i][j] == 1)
			{
				dp2[i][j] = INF;
				
				ll ff = 0;
				ll ff2 = 0;
				
				for(ll k = i + 1 ; k <= n ; k++)
				{
					if(se[k][j] == 0)
						ff = 1;
				}
				
				for(ll k = i - 1 ; k >= 1 ; k--)
				{
					if(se[k][j] == 0)
						ff2 = 1;
				}
				
				for(ll k = i - 1 ; k >= 0 ; k--)
				{
					dp2[i][j] = min(dp2[i][j], dp2[k][j] + i - k);
					
					if(!ff)
						dp2[i][j] = min(dp2[i][j], dp2[k][j] + F);
					
					if(!ff2)
						dp2[i][j] = min(dp2[i][j], dp2[k][j] + F);
					
					if(se[k][j] == 0)
						break;
				}
			}
			
			else
			{
				dp2[i][j] = INF;
				
				ll ff = 0;
				ll ff2 = 0;
				
				for(ll k = i + 1 ; k <= n ; k++)
				{
					if(se[k][j] == 0)
						ff = 1;
				}
				
				for(ll k = i - 1 ; k >= 1 ; k--)
				{
					if(se[k][j] == 0)
						ff2 = 1;
				}
				
				for(ll k = i - 1 ; k >= 0 ; k--)
				{
					dp2[i][j] = min(dp2[i][j], dp2[k][j] + i - k);
					
					if(!ff)
						dp2[i][j] = min(dp2[i][j], dp2[k][j] + F);
					
					if(!ff2)
						dp2[i][j] = min(dp2[i][j], dp2[k][j] + F);
					
					if(se[k][j] == 0)
						break;
				}
				
				dp2[i][j] = min(dp2[i][j], dp2[i - 1][j]);
			}
		}
		
		ans += dp2[n][j];
	}
	
	cout << ans;
	return 0;
}