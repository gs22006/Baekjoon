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
pll a[200010];
ll b[200010];
ll nu1[200010], nu2[200010];
ll ans[200010];

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n + 1 ; i++)
	{
		cin >> a[i].fi;
		a[i].se = i;
	}
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> b[i];
	
	sort(a + 1, a + 2 + n);
	sort(b + 1, b + 1 + n);
	
	for(ll i = 1 ; i <= n ; i++)
		nu1[i] = max(nu1[i - 1], max(0LL, a[i].fi - b[i]));
	
	for(ll i = n ; i >= 1 ; i--)
		nu2[i] = max(nu2[i + 1], max(0LL, a[i + 1].fi - b[i]));
	
	for(ll i = 1 ; i <= n + 1 ; i++)
		ans[a[i].se] = max(nu1[i - 1], nu2[i]);
	
	for(ll i = 1 ; i <= n + 1 ; i++)
		cout << ans[i] sp;
	
	return 0;
}