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
ll a[500010];
ll pre[500010], suf[500010];
ll ans = INF;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 2 ; i <= n ; i += 2)
		pre[i] = pre[i - 2] + a[i] - a[i - 1];
	
	for(ll i = n ; i >= 2 ; i -= 2)
		suf[i] = suf[i + 2] + a[i] - a[i - 1];
	
	for(ll i = 1 ; i <= n - 2 ; i += 2)
		ans = min(ans, pre[i - 1] + suf[i + 4] + a[i + 2] - a[i]);
	
	cout << ans;
	return 0;
}