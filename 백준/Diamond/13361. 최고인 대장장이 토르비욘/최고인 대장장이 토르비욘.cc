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
pll a[500010];
ll ans;
vector<ll> zip;
ll won[500010];
ll pa[500010], ra[500010];
vector<ll> vec[500010], vec2[500010];

ll ffind(ll here)
{
	if(here == pa[here])
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
		pa[X] = Y;
	else if(ra[Y] < ra[X])
		pa[Y] = X;
	
	else
	{
		pa[X] = Y;
		ra[Y]++;
	}
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i].fi >> a[i].se;
		
		zip.push_back(a[i].fi);
		zip.push_back(a[i].se);
		ans += a[i].fi + a[i].se;
	}
	
	compress(zip);
	
	for(ll i = 0 ; i < (ll)zip.size() ; i++)
		won[i + 1] = zip[i];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		a[i].fi = lower_bound(zip.begin(), zip.end(), a[i].fi) - zip.begin() + 1;
		a[i].se = lower_bound(zip.begin(), zip.end(), a[i].se) - zip.begin() + 1;
		
		vec2[a[i].fi].push_back(a[i].se);
		vec2[a[i].se].push_back(a[i].fi);
	}
	
	for(ll i = 1 ; i <= (ll)zip.size() ; i++)
		pa[i] = i;
	
	for(ll i = 1 ; i <= n ; i++)
		uunion(a[i].fi, a[i].se);
	
	for(ll i = 1 ; i <= (ll)zip.size() ; i++)
		vec[ffind(i)].push_back(i);
	
	for(ll i = 1 ; i <= (ll)zip.size() ; i++)
	{
		ll cou = 0;
		ll sum = 0, maxx = 0;
		
		for(auto &j : vec[i])
		{
			cou += (ll)vec2[j].size();
			sum += won[j];
			maxx = max(maxx, won[j]);
		}
		
		cou /= 2;
		
		if(cou == (ll)vec[i].size())
			ans -= sum;
		else
			ans -= (sum - maxx);
	}
	
	cout << ans;
	return 0;
}