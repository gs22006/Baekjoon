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
ll a[20010], bll;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		ll ans = 0;
		
		cin >> n >> m;
		
		for(ll i = 1 ; i <= n ; i++)
			cin >> a[i];
		
		sort(a + 1, a + 1 + n);
		
		for(ll i = 1 ; i <= m ; i++)
		{
			cin >> bll;
			
			ll l = 1, r = n;
			
			while(l <= r)
			{
				ll mid = (l + r) / 2;
				
				if(a[mid] <= bll)
					l = mid + 1;
				else
					r = mid - 1;
			}
			
			ans += n - r;
		}
		
		cout << ans en;
	}
	
	return 0;
}