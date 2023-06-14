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

ll n, K;
ll a[2000010];
ll dp[2000010];
ll dp2[2000010];
ll OR, AND, XOR;

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		
		dp[a[i]]++;
		dp2[a[i] ^ ((1LL << 20) - 1)]++;
	}
	
	if(K == 0)
	{
		for(ll i = 0 ; i < (1LL << 20) ; i++)
			XOR += dp[i] * (dp[i] - 1) / 2;
	}
	
	else
	{
		for(ll i = 0 ; i < (1LL << 20) ; i++)
			XOR += dp[i] * dp[K ^ i];
		
		XOR /= 2;
	}
	
	for(ll i = 0 ; i < 20 ; i++)
	{
		for(ll j = 0 ; j < (1LL << 20) ; j++)
		{
			if(j & (1LL << i))
			{
				dp[j] += dp[j ^ (1LL << i)];
				dp2[j] += dp2[j ^ (1LL << i)];
			}
		}
	}
	
	for(ll i = 0 ; i < (1LL << 20) ; i++)
	{
		dp[i] = dp[i] * (dp[i] - 1) / 2;
		dp2[i] = dp2[i] * (dp2[i] - 1) / 2;
	}
	
	for(ll i = 0 ; i < (1LL << 20) ; i++)
	{
		if((i | K) != K)
			continue;
		
		ll gaet = 0;
		
		for(ll j = 0 ; j < 20 ; j++)
		{
			if(!(i & (1LL << j)) && (K & (1LL << j)))
				gaet++;
		}
		
		if(gaet & 1)
			OR -= dp[i];
		else
			OR += dp[i];
	}
	
	K ^= ((1LL << 20) - 1);
	
	for(ll i = 0 ; i < (1LL << 20) ; i++)
	{
		if((i | K) != K)
			continue;
		
		ll gaet = 0;
		
		for(ll j = 0 ; j < 20 ; j++)
		{
			if(!(i & (1LL << j)) && (K & (1LL << j)))
				gaet++;
		}
		
		if(gaet & 1)
			AND -= dp2[i];
		else
			AND += dp2[i];
	}
	
	cout << AND sp << OR sp << XOR;
	return 0;
}