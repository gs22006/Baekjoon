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
ll a[300010];
ll cou[10];
ll ans;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		cou[a[i] % 5]++;
	}
	
	ans += cou[1];
	ans += cou[2] * 2;
	
	ll gap = min(cou[3], cou[4]);
	
	ans += gap * 2;
	
	cou[3] -= gap;
	cou[4] -= gap;
	
	if(cou[3])
	{
		ans += cou[3] / 2;
		ans -= cou[3] % 2 * 2;
	}
	
	if(cou[4])
	{
		ans += cou[4] / 3 * 2;
		ans -= cou[4] % 3;
	}
	
	cout << ans en;
	return 0;
}