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
ll a[2510];
ll b[2510];
ll dp[2510];
ll cost[2510][2510];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		ll sum = 0;
		
		for(ll j = i ; j < n ; j++)
		{
			cost[i][j] = sum + (!!b[j]);
			
			if(b[j])
			{
				if(b[j] < b[j + 1])
				{
					sum++;
					b[j + 1] -= b[j];
				}
				
				else
				{
					sum++;
					b[j] -= b[j + 1];
					b[j + 1] = 0;
					
					if(b[j])
						sum++;
				}
			}
		}
		
		cost[i][n] = sum + (!!b[n]);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		dp[i] = INF;
		
		for(ll j = 0 ; j < i ; j++)
			dp[i] = min(dp[i], dp[j] + cost[j + 1][i]);
	}
	
	cout << dp[n];
	return 0;
}