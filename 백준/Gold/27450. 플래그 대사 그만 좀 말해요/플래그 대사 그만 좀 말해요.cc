#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n, K;
pll a[500010];
queue<pll> q;
ll gap, hap;
ll ans;

int main(void)
{
	fastio
	
	cin >> n >> K;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].fi;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i].se;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll nam = max(0LL, a[i].se - a[i].fi - gap);
		ll hwe = (nam + K - 1) / K;
		
		q.push({i, hwe});
		gap += K * hwe;
		hap += hwe;
		gap -= hap;
		ans += hwe;
		
		while(!q.empty() && q.front().fi <= i - K + 1)
		{
			hap -= q.front().se;
			q.pop();
		}
	}
	
	cout << ans;
	return 0;
}