#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll n, m, k, w;
ll all, bll, cll;
ll what;
ll chk[200010];
vector< pair<ll, pair<ll, ll> > > edg;
vector< pair< pair<ll, ll>, pair<ll, ll> > > vv;
ll l, r;
ll pa[200010], ra[200010];
ll ans = -1;

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

pair<ll, ll> solve(ll lambda2)
{
	ll ret1 = 0, ret2 = 0, ret3 = 0;
	
	vv.clear();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		pa[i] = i;
		ra[i] = 0;
	}
	
	for(auto &i : edg)
	{
		if(chk[i.se.fi] ^ chk[i.se.se])
			vv.push_back({{i.fi + lambda2, 0}, {i.se.fi, i.se.se}});
		else
			vv.push_back({{i.fi, 1}, {i.se.fi, i.se.se}});
	}
	
	sort(vv.begin(), vv.end());
	
	for(auto &i : vv)
	{
		if(ffind(i.se.fi) != ffind(i.se.se))
		{
			uunion(i.se.fi, i.se.se);
			ret1 += (chk[i.se.fi] ^ chk[i.se.se]);
			ret2 += i.fi.fi;
			ret3++;
		}
	}
	
	if(ret3 != n - 1)
		return {-1, -1};
	
	return {ret2, ret1};
}

pair<ll, ll> solve2(ll lambda2)
{
	ll ret1 = 0, ret2 = 0, ret3 = 0;
	
	vv.clear();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		pa[i] = i;
		ra[i] = 0;
	}
	
	for(auto &i : edg)
	{
		if(chk[i.se.fi] ^ chk[i.se.se])
			vv.push_back({{i.fi + lambda2, 1}, {i.se.fi, i.se.se}});
		else
			vv.push_back({{i.fi, 0}, {i.se.fi, i.se.se}});
	}
	
	sort(vv.begin(), vv.end());
	
	for(auto &i : vv)
	{
		if(ffind(i.se.fi) != ffind(i.se.se))
		{
			uunion(i.se.fi, i.se.se);
			ret1 += (chk[i.se.fi] ^ chk[i.se.se]);
			ret2 += i.fi.fi;
			ret3++;
		}
	}
	
	if(ret3 != n - 1)
		return {-1, -1};
	
	return {ret2, ret1};
}

int main(void)
{
	scanf("%lld %lld %lld %lld", &n, &m, &k, &w);
	
	for(ll i = 1 ; i <= k ; i++)
	{
		scanf("%lld", &all);
		chk[all] = 1;
	}
	
	for(ll i = 1 ; i <= m ; i++)
	{
		scanf("%lld %lld %lld", &all, &bll, &cll);
		
		edg.push_back({cll, {all, bll}});
		
		if(chk[all] ^ chk[bll])
			what++;
	}
	
	if(what < w || solve(0).se == -1)
	{
		printf("-1");
		return 0;
	}
	
	l = -100001;
	r = 100001;
	
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		pair<ll, ll> gap = solve(mid);
		
		if(gap.se < w)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	pair<ll, ll> why = solve(l);
	pair<ll, ll> whyyy = solve(r);
	
	if(solve2(l).se <= w && w <= why.se)
		printf("%lld", why.fi - l * w);
	else if(solve2(r).se <= w && w <= whyyy.se)
		printf("%lld", whyyy.fi - r * w);
	else
		printf("-1");
	
	return 0;
}