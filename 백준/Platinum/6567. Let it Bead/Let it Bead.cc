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

ll sqrmtp(ll X, ll Y)
{
	ll ret = 1;
	
	while(Y)
	{
		if(Y & 1)
			ret *= X;
		
		X *= X;
		Y >>= 1;
	}
	
	return ret;
}

int main(void)
{
	fastio
	
	while(1)
	{
		cin >> m >> n;
		
		if(!n && !m)
			break;
		
		ll ans = 0;
		
		for(ll i = 1 ; i <= n ; i++)
			ans += sqrmtp(m, __gcd(i, n));
		
		if(n & 1)
			ans += n * sqrmtp(m, (n + 1) / 2);
		else
			ans += n / 2 * (sqrmtp(m, n / 2 + 1) + sqrmtp(m, n / 2));
		
		ans /= (n * 2);
		cout << ans en;
	}
	
	return 0;
}