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
ll n, m;
ll all, bll;
ll deg[5010];

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		for(ll i = 1 ; i <= n ; i++)
			deg[i] = 0;
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cin >> all >> bll;
			deg[all]++, deg[bll]++;
		}
		
		ll ans = n * (n - 1) * (n - 2) / 3;
		
		for(ll i = 1 ; i <= n ; i++)
			ans -= deg[i] * (n - deg[i] - 1);
		
		cout << ans / 2 en;
	}
	
	return 0;
}