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

ll n, m;
pair<ll, pll> edg[1000010];
ll pa[100010], ra[100010];
ll ans, maxx;

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
	
	cin >> n >> m;
	
	for(ll i = 1 ; i <= m ; i++)
		cin >> edg[i].se.fi >> edg[i].se.se >> edg[i].fi;
	
	sort(edg + 1, edg + 1 + m);
	
	for(ll i = 1 ; i <= n ; i++)
		pa[i] = i;
	
	for(auto &i : edg)
	{
		if(ffind(i.se.fi) == ffind(i.se.se))
			continue;
		
		uunion(i.se.fi, i.se.se);
		ans += i.fi;
		maxx = max(maxx, i.fi);
	}
	
	cout << ans - maxx;
	return 0;
}