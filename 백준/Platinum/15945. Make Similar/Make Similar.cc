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
ll a[100010];
ll ans = MAX;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	ans = min(ans, a[n] - a[1]);
	
	if(a[1] * a[n] < 0)
	{
		cout << 0;
		return 0;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i])
			ans = min(ans, abs(a[i]));
	}
	
	cout << ans;
	return 0;
}