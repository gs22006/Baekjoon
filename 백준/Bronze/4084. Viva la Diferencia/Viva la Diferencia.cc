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

ll a, b, c, d;

int main(void)
{
	fastio
	
	while(1)
	{
		cin >> a >> b >> c >> d;
		
		if(a == 0)
			break;
		
		ll ans = 0;
		
		while(1)
		{
			if(a == b && b == c && c == d)
				break;
			
			ll ta, tb, tc, td;
			
			ta = abs(a - b);
			tb = abs(c - b);
			tc = abs(c - d);
			td = abs(a - d);
			
			a = ta, b = tb, c = tc, d = td;
			ans++;
		}
		
		cout << ans en;
	}
	
	return 0;
}