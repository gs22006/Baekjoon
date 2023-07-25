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
 
ll n;
pll a[500010];
pll b[500010];
ll maxx = -INF, ans;
 
int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		
		b[i].fi = a[i].fi - a[i].se;
		b[i].se = -a[i].fi - a[i].se;
	}
	
	sort(b + 1, b + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(maxx < -b[i].se)
		{
			maxx = -b[i].se;
			ans++;
		}
	}
	
	cout << ans;
	return 0;
}