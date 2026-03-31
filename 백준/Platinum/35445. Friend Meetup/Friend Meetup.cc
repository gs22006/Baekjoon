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
pair<pll, ll> a[200010];
pll b[200010];
ld ans;

void solve(void)
{
	ld l = 0, r = 1000000000;
	
	for(ll o = 0 ; o < 100 ; o++)
	{
		ld mid = (l + r) / 2.0;
		ld minn = INF, maxx = -INF;
		
		for(ll i = 1 ; i <= n ; i++)
		{
			minn = min(minn, b[i].fi + b[i].se * mid);
			maxx = max(maxx, b[i].fi - b[i].se * mid);
		}
		
		if(maxx >= minn)
			l = mid;
		else
			r = mid;
	}
	
	ans = max(ans, l);
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
	
	for(ll i = 1 ; i <= n ; i++)
		b[i] = {a[i].fi.fi + a[i].fi.se, a[i].se};
	
	solve();
	
	for(ll i = 1 ; i <= n ; i++)
		b[i] = {a[i].fi.fi - a[i].fi.se, a[i].se};
	
	solve();
	
	cout << ans;
	return 0;
}