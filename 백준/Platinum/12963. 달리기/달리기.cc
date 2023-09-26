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

ll n, m;
pll edg[2010];
ll pa[2010], ra[2010];
ll thr[2010];
ll ss = 1000000007;
ll ans;

ll ffind(ll here)
{
	if(pa[here] == here)
		return here;
	
	return pa[here] = ffind(pa[here]);
}

void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
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
	
	cin >> n >> m;
	
	for(ll i = 0 ; i < m ; i++)
		cin >> edg[i].fi >> edg[i].se;
	
	for(ll i = 0 ; i < n ; i++)
		pa[i] = i;
	
	thr[0] = 1;
	
	for(ll i = 1 ; i < m ; i++)
		thr[i] = thr[i - 1] * 3 % ss;
	
	for(ll i = m - 1 ; i >= 0 ; i--)
	{
		ll U = edg[i].fi, V = edg[i].se;
		
		if(ffind(U) == ffind(V))
			continue;
		
		if(ffind(U) == ffind(0) && ffind(V) == ffind(n - 1))
			ans = (ans + thr[i]) % ss;
		else if(ffind(U) == ffind(n - 1) && ffind(V) == ffind(0))
			ans = (ans + thr[i]) % ss;
		else
			uunion(U, V);
	}
	
	cout << (ans % ss + ss) % ss;
	return 0;
}