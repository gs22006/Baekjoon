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

ll n;
ll a[300010];
pair<pll, ll> b[300010];
ll cc, cc2;
ll ans = MIN;

void dfs(ll here, ll dep)
{
	b[here].fi.se = dep;
	cc2 = max(cc2, dep);
	
	if((here << 1) <= n)
		dfs(here << 1, dep + 1);
	
	b[here].fi.fi = ++cc;
	
	if((here << 1 | 1) <= n)
		dfs(here << 1 | 1, dep + 1);
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		b[i].se = i;
	}
	
	dfs(1, 1);
	
	sort(b + 1, b + 1 + n);
	
	for(ll i = 1 ; i <= cc2 ; i++)
	{
		for(ll j = i ; j <= cc2 ; j++)
		{
			vector<ll> vec;
			
			for(ll k = 1 ; k <= n ; k++)
			{
				if(i <= b[k].fi.se && b[k].fi.se <= j)
					vec.push_back(a[b[k].se]);
			}
			
			ll minn = 0, hap = 0;
			ll maxx = MIN;
			
			for(ll k = 0 ; k < (ll)vec.size() ; k++)
			{
				hap += vec[k];
				maxx = max(maxx, hap - minn);
				minn = min(minn, hap);
			}
			
			ans = max(ans, maxx);
		}
	}
	
	cout << ans;
	return 0;
}