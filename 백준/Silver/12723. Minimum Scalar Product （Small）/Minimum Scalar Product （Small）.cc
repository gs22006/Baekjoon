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

ll t;
ll n;
ll a[110], b[110];
ll cc;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i];
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> b[i];
		
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		
		ll ans = 0;
		
		for(ll i = 1 ; i <= n ; i++)
			ans += a[i] * b[n + 1 - i];
		
		cout << "Case #" << ++cc << ": " << ans en;
	}
	
	return 0;
}