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

ll a, b;

ll solve(ll X)
{
	ll ret = 0;
	
	for(ll i = 1 ; ; i <<= 1)
	{
		ll gaet = X + 1;
		ll ju = (i << 1);
		
		if(i > X + 1)
			break;
		
		ret += gaet / ju * i;
		gaet %= ju;
		ret += max(0LL, gaet - i);
	}
	
	return ret;
}

int main(void)
{
	fastio
	
	cin >> a >> b;
	cout << solve(b) - solve(a - 1);
	return 0;
}