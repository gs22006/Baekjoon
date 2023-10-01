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
ll ans;
ll cou[200010][3];
ll sum[3];

ll dist(ll x1, ll y1, ll x2, ll y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n * 2 ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		
		if(a[i].fi < 1)
		{
			ans += 1 - a[i].fi;
			a[i].fi = 1;
		}
		
		else if(a[i].fi > n)
		{
			ans += a[i].fi - n;
			a[i].fi = n;
		}
		
		if(a[i].se < 1)
		{
			ans += 1 - a[i].se;
			a[i].se = 1;
		}
		
		else if(a[i].se > 2)
		{
			ans += a[i].se - 2;
			a[i].se = 2;
		}
		
		cou[a[i].fi][a[i].se]++;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		sum[1] += cou[i][1] - 1;
		sum[2] += cou[i][2] - 1;
		
		if(sum[1] > 0 && sum[2] < 0)
		{
			ll gap = min(sum[1], -sum[2]);
			
			ans += gap;
			sum[1] -= gap;
			sum[2] += gap;
		}
		
		else if(sum[2] > 0 && sum[1] < 0)
		{
			ll gap = min(sum[2], -sum[1]);
			
			ans += gap;
			sum[2] -= gap;
			sum[1] += gap;
		}
		
		ans += abs(sum[1]) + abs(sum[2]);
	}
	
	cout << ans;
	return 0;
}