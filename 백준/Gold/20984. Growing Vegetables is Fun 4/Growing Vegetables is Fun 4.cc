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
ll a[200010];
ll b[200010];
ll ans = INF;
ll sum1, sum2;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 2 ; i <= n ; i++)
		b[i - 1] = a[i - 1] - a[i];
	
	for(ll i = 1 ; i < n ; i++)
	{
		if(b[i] <= 0)
			sum2 += -b[i] + 1;
	}
	
	for(ll i = 0 ; i < n ; i++)
	{
		ans = min(ans, max(sum1, sum2));
		
		if(b[i + 1] >= 0)
			sum1 += b[i + 1] + 1;
		
		if(b[i + 1] <= 0)
			sum2 -= -b[i + 1] + 1;
	}
	
	cout << ans;
	return 0;
}