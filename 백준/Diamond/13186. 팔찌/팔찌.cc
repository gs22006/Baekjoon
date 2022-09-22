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

ll n, m;
ll sqr[2000010];
ll inv[2000010];
ll ss = 1000000007;
ll gap[2000010], nu[2000010];
ll ans = 1;

int main(void)
{
	fastio
	
	cin >> n >> m;
	
	inv[1] = 1;
	sqr[1] = m;
	
	for(ll i = 2 ; i <= n * 2 ; i++)
	{
		sqr[i] = sqr[i - 1] * m % ss;
		inv[i] = (ss - ss / i) * inv[ss % i] % ss;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		gap[i] += i;
		
		for(ll j = i * 2 ; j <= n ; j += i)
			gap[j] -= gap[i];
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		ll siz = n / i;
		ll ans2 = 0;
		
		for(ll j = 1 ; j <= siz ; j++)
			ans2 = (ans2 + gap[j] % ss * inv[j] % ss) % ss;
		
		ans = (ans + sqr[i] * inv[i << 1] % ss * ans2 % ss) % ss;
	}
	
	for(ll i = 1 ; i <= n ; ++i)
	{
		if(i & 1)
			ans = (ans + i * sqr[(i + 1) >> 1] % ss * inv[i << 1] % ss) % ss;
		else
			ans = (ans + (i >> 1) * (sqr[i >> 1] + sqr[(i >> 1) + 1]) % ss * inv[i << 1] % ss) % ss;
	}
	
	cout << (ans < 0 ? ans + ss : ans);
	return 0;
}