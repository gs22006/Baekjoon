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
 
ll n, m, K, T, P;
pair<pll, ll> a[20];
ll ans1, ans2;
 
int main(void)
{
	fastio
	
	cin >> n >> m >> K >> T >> P;
	
	assert(1 <= n && n <= 50);
	assert(1 <= m && m <= 50);
	assert(1 <= K && K <= 10);
	assert(1 <= T && T <= 1000000000);
	assert(1 <= P && P <= 1000000000);
	
	for(ll i = 1 ; i <= K ; i++)
	{
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
		
		assert(1 <= a[i].fi.fi && a[i].fi.fi <= n);
		assert(1 <= a[i].fi.se && a[i].fi.se <= m);
	}
	
	sort(a + 1, a + 1 + K);
	
	do
	{
		ll cou = 0;
		ll gaet = 1;
		
		for(ll i = 1 ; i < K ; i++)
		{
			cou += abs(a[i + 1].fi.fi - a[i].fi.fi) + abs(a[i + 1].fi.se - a[i].fi.se);
			
			if(cou > T)
				break;
			
			gaet++;
		}
		
		ans1 = max(ans1, gaet);
	}while(next_permutation(a + 1, a + 1 + K));
	
	for(ll i = 1 ; i <= n ; i++)
	{
		for(ll j = 1 ; j <= m ; j++)
		{
			ll cou = 0;
			
			for(ll k = 1 ; k <= K ; k++)
			{
				ll dist = abs(a[k].fi.fi - i) + abs(a[k].fi.se - j);
				
				if(P >= a[k].se * dist)
					cou++;
			}
			
			ans2 = max(ans2, cou);
		}
	}
	
	cout << ans1 sp << ans2 en;
	return 0;
}
