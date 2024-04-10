#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
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
 
ll p, q, r;
ll dp[1000010][2];
ll ss = 1000000009;
ll ans = 0;
 
ll ja(ll X, ll Y)
{
	ll ret = 0;
	
	while(X)
	{
		ret++;
		X /= Y;
	}
	
	return ret;
}
 
int main(void)
{
	fastio
	
	cin >> p >> q >> r;
	
	if(ja(r, p) + 1 == q + 1)
	{
		ll R = r;
		
		while(R % p)
			R /= p;
		
		if(R == 1)
			ans++;
	}
	
	if(p == 2)
	{
		if(r == 0)
		{
			cout << 0;
			return 0;
		}
		
		if(ja(r, p) + 1 <= q)
			ans++;
		
		ans += max(0LL, q - ja(r - 1, p) - 1);
		
		cout << ans;
		return 0;
	}
	
	ll P = (p - 1) / 2;
	
	dp[0][0] = 1;
	dp[0][1] = 0;
	
	for(ll i = 1 ; i <= q + 1 ; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % ss * P % ss;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % ss * (p - 1 - P) % ss;
	}
	
	if(r == 0)
	{
		for(ll i = 1 ; i <= q ; i++)
			ans = (ans + dp[i][0]) % ss;
		
		ans = (ans + dp[q][1]) % ss;
		cout << (ans + ss) % ss;
		return 0;
	}
	
	ll L = ja(r, p) + 1;
	
	for(ll i = 0 ; i <= q - L ; i++)
		ans = (ans + dp[i][0]) % ss;
	
	L = ja(r - 1, p) + 1;
	
	for(ll i = 0 ; i <= q - L ; i++)
		ans = (ans + dp[i][1]) % ss;
	
	cout << (ans + ss) % ss;
	return 0;
}
