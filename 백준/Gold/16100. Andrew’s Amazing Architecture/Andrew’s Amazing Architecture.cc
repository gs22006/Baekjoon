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
ll nu1[200010];
ll nu2[200010];
ll maxx[200010];
ll ans = INF;

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	for(ll i = 1 ; i <= n ; i++)
		b[i] = a[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(b[i] < b[i - 1])
			b[i] += (b[i - 1] - b[i] + a[i] - 1) / a[i] * a[i];
		
		nu1[i] = nu1[i - 1] + b[i];
		maxx[i] = max(maxx[i], b[i]);
	}
	
	for(ll i = 1 ; i <= n ; i++)
		b[i] = a[i];
	
	for(ll i = n ; i >= 1 ; i--)
	{
		if(b[i] < b[i + 1])
			b[i] += (b[i + 1] - b[i] + a[i] - 1) / a[i] * a[i];
		
		nu2[i] = nu2[i + 1] + b[i];
		maxx[i] = max(maxx[i], b[i]);
	}
	
	for(ll i = 1 ; i <= n ; i++)
		ans = min(ans, maxx[i] + nu1[i - 1] + nu2[i + 1]);
	
	cout << ans;
	return 0;
}