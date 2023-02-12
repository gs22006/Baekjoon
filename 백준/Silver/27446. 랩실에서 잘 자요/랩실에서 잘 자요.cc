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

ll n, m;
ll all;
ll chk[110];
ll dp[110];

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all;
		chk[all] = 1;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		dp[i] = INF;
	
	dp[0] = 0;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(chk[i])
			dp[i] = min(dp[i], dp[i - 1]);
		
		for(ll j = 0 ; j < i ; j++)
			dp[i] = min(dp[i], dp[j] + 5 + (i - j) * 2);
	}
	
	cout << dp[n];
	return 0;
}