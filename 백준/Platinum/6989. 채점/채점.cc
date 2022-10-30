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

ll n;
ll a[210];
ll k;
bitset<1200000> dp[210];
ll cost[210][210];
ll nu[210];
ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		nu[i] = nu[i - 1] + a[i];
	}
	
	cin >> k;
	
	if(k > 1200000)
	{
		cout << k;
		return 0;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = i ; j <= n ; j++)
			cost[i][j] = cost[i][j - 1] + nu[j] - nu[i - 1];
	}
	
	dp[0].set(0, 1);
	dp[1].set(0, 1);
	dp[1].set(a[1], 1);
	
	for(ll i = 2 ; i <= n ; i++)
	{
		dp[i].set(cost[1][i], 1);
		
		for(ll j = i - 2 ; j >= 0 ; j--)
			dp[i] |= (dp[j] << cost[j + 2][i]);
		
		dp[i] |= dp[i - 1];
	}
	
	for(ll i = k ; ; i++)
	{
		if(!dp[n].test(i))
		{
			ans = i;
			break;
		}
	}
	
	cout << ans;
	return 0;
}