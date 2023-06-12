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
ll S[100010], T[100010];
ll p[20], q[20];
ll a[20][100010], b[20][100010];
ll cost[20][1000010];
ll gap[100010];
ll dp[1000010];
ll dp2[1000010];

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < m ; i++)
		cin >> S[i];
	
	for(ll i = 0 ; i < m ; i++)
		cin >> T[i];
	
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> p[i];
		
		for(ll j = 0 ; j < p[i] ; j++)
		{
			cin >> a[i][j];
			a[i][j]--;
		}
		
		cin >> q[i];
		
		for(ll j = 0 ; j < q[i] ; j++)
		{
			cin >> b[i][j];
			b[i][j]--;
		}
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < q[i] ; j++)
			gap[b[i][j]] |= (1LL << i);
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		ll sum = 0;
		
		for(ll j = 0 ; j < p[i] ; j++)
			sum += T[a[i][j]] - S[a[i][j]];
		
		for(ll j = 0 ; j < (1LL << n) ; j++)
			dp[j] = 0;
		
		for(ll j = 0 ; j < p[i] ; j++)
			dp[gap[a[i][j]]] += T[a[i][j]] - S[a[i][j]];
		
		for(ll j = 0 ; j < n ; j++)
		{
			for(ll k = 0 ; k < (1LL << n) ; k++)
			{
				if(k & (1LL << j))
					dp[k] += dp[k ^ (1LL << j)];
			}
		}
		
		for(ll j = 0 ; j < (1LL << n) ; j++)
			cost[i][((1LL << n) - 1) ^ j] = sum - dp[j];
	}
	
	for(ll i = 0 ; i < (1LL << n) ; i++)
	{
		for(ll j = 0 ; j < n ; j++)
		{
			if(i & (1LL << j))
				dp2[i] = max(dp2[i], dp2[i ^ (1LL << j)] + cost[j][i ^ (1LL << j)]);
		}
	}
	
	cout << dp2[(1LL << n) - 1];
	return 0;
}