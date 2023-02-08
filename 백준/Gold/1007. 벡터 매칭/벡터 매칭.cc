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

ll t;
ll n;
pll a[30];
ll b[30];

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		ld ans = INF;
		
		cin >> n;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i].fi >> a[i].se;
		
		for(ll i = 1 ; i <= n / 2 ; i++)
			b[i] = -1;
		
		for(ll i = n / 2 + 1 ; i <= n ; i++)
			b[i] = 1;
		
		do
		{
			ll X = 0, Y = 0;
			
			for(ll i = 1 ; i <= n ; i++)
			{
				X += a[i].fi * b[i];
				Y += a[i].se * b[i];
			}
			
			ans = min(ans, sqrt((ld)(X * X + Y * Y)));
		}while(next_permutation(b + 1, b + 1 + n));
		
		cout << ans en;
	}
	
	return 0;
}