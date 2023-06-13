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

ll n, m;
char a[21][2000010];
ll gap[2000010];
ll ss = 1000000007;
ll cost[2000010];
ll cou[2000010];
ll S[21][2000010];
ll dp[2000010];
ll ans;

void calc_cost(ll X)
{
	if(cost[X])
		return;
	
	ll tmp = 1;
	
	for(ll i = 0 ; i <= X ; i++)
	{
		cost[X] = (cost[X] + tmp) % ss;
		tmp = tmp * (X - i) % ss;
	}
}

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < m ; i++)
		cin >> a[i];
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
		{
			if(a[j][i] == 'H')
				gap[i] |= (1LL << j);
		}
		
		cou[gap[i]]++;
	}
	
	for(ll i = 0 ; i < (1LL << m) ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
		{
			if(i & (1LL << j))
				dp[i] = (dp[i] + S[j][i ^ (1LL << j)]) % ss;
		}
		
		calc_cost(cou[i]);
		
		dp[i] = (dp[i] + 1) % ss;
		dp[i] = dp[i] * (cost[cou[i]] - 1) % ss;
		
		S[0][i] = dp[i];
		
		for(ll j = 0 ; j < m ; j++)
		{
			if(j)
				S[j][i] = S[j - 1][i];
			
			if(i & (1LL << j))
				S[j][i] = (S[j][i] + S[j][i ^ (1LL << j)]) % ss;
		}
	}
	
	for(ll i = 0 ; i < (1LL << m) ; i++)
		ans = (ans + dp[i]) % ss;
	
	cout << ans;
	return 0;
}