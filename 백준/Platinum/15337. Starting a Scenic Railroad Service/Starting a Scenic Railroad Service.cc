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
pll a[500010], b[500010];
ll cc;
ll cou;
ll maxx;
ll ans;
ll nu1[100010], nu2[100010];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		
		nu1[a[i].fi]++;
		nu2[a[i].se]++;
		b[cc++] = {a[i].fi, 1};
		b[cc++] = {a[i].se, -1};
	}
	
	for(ll i = 1 ; i <= 100000 ; i++)
	{
		nu1[i] += nu1[i - 1];
		nu2[i] += nu2[i - 1];
	}
	
	sort(b, b + cc);
	
	for(ll i = 0 ; i < cc ; i++)
	{
		cou += b[i].se;
		maxx = max(maxx, cou);
	}
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
		ans = max(ans, n - nu2[a[i].fi] - (nu1[100000] - nu1[a[i].se - 1]));
	
	cout << ans sp << maxx;
	return 0;
}