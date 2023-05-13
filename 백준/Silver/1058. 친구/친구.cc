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
char a[110][110];
ll dp[110][110];
ll maxx;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 0 ; i < n ; i++)
		cin >> a[i];
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < n ; j++)
		{
			if(a[i][j] == 'Y')
				dp[i][j] = 1;
			else
				dp[i][j] = INF;
		}
	}
	
	for(ll k = 0 ; k < n ; k++)
	{
		for(ll i = 0 ; i < n ; i++)
		{
			for(ll j = 0 ; j < n ; j++)
			{
				if(i == j)
					continue;
				
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		ll cou = 0;
		
		for(ll j = 0 ; j < n ; j++)
		{
			if(dp[i][j] <= 2)
				cou++;
		}
		
		maxx = max(maxx, cou);
	}
	
	cout << maxx;
	return 0;
}