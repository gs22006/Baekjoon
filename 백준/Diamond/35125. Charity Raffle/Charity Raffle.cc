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

ll n, K, m;
ll ss = 998244353;
ll fac[3000010], inv[3000010];

ll sqrmtp(ll X, ll Y)
{
	ll ret = 1;
	
	while(Y)
	{
		if(Y & 1)
			ret = ret * X % ss;
		
		X = X * X % ss;
		Y >>= 1;
	}
	
	return ret;
}

ll C(ll N, ll R)
{
	return fac[N] * inv[R] % ss * inv[N - R] % ss;
}

ll f(ll X, ll Y)
{
	ll ret = 0;
	
	for(ll i = 0 ; i <= n ; i++)
	{
		if((X + 1) * i > Y)
			break;
		
		ll gap = 0;
		
		gap = C(Y - (X + 1) * i + n - 1, Y - (X + 1) * i);
		gap = gap * C(n, i) % ss;
		
		if(i & 1)
			gap *= -1;
		
		ret = (ret + gap) % ss;
	}
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> n >> K >> m;
	
	fac[0] = 1;
	
	for(ll i = 1 ; i <= 3000000 ; i++)
		fac[i] = fac[i - 1] * i % ss;
	
	inv[3000000] = sqrmtp(fac[3000000], ss - 2);
	
	for(ll i = 2999999 ; i >= 0 ; i--)
		inv[i] = inv[i + 1] * (i + 1) % ss;
	
	ll ans = (f(m, K) - f(m - 1, K - 1)) % ss;
	
	cout << (ans + ss) % ss;
	return 0;
}