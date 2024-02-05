#include "aliens.h"
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

ll n, m, k;
pll a[100010];
ll dp[100010], yuk[100010];
ll gyo[100010];

struct line
{
	ll A, B;
	ld S;
	ll I;
};

ld intersect(ll A1, ll B1, ll A2, ll B2)
{
	return (ld)(B2 - B1) / (ld)(A1 - A2);
}

struct CHT
{
	vector<line> lin;
	
	void init(void)
	{
		lin.clear();
	}
	
	void update(ll X, ll Y, ll I)
	{
		while(!lin.empty())
		{
			if(intersect(lin.back().A, lin.back().B, X, Y) < lin.back().S)
				lin.pop_back();
			else
				break;
		}
		
		if(lin.empty())
		{
			lin.push_back({X, Y, -INF, I});
			return;
		}
		
		lin.push_back({X, Y, intersect(lin.back().A, lin.back().B, X, Y), I});
	}
	
	pll query(ll X)
	{
		ll l = 0, r = (ll)lin.size() - 1;
		
		while(l <= r)
		{
			ll mid = (l + r) >> 1;
			
			if(lin[mid].S <= X)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		return {lin[r].A * X + lin[r].B, lin[r].I};
	}
}cht;

pll solve(ll lambda)
{
	for(ll i = 0 ; i <= n ; i++)
		dp[i] = yuk[i] = 0;
	
	cht.init();
	cht.update(-2 * (a[1].fi - 1), (a[1].fi - 1) * (a[1].fi - 1), 0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		pll qq = cht.query(a[i].se);
		dp[i] = qq.fi + a[i].se * a[i].se + lambda;
		yuk[i] = yuk[qq.se] + 1;
		
		if(i < n)
			cht.update(-2 * (a[i + 1].fi - 1), dp[i] + (a[i + 1].fi - 1) * (a[i + 1].fi - 1) - gyo[i], i);
	}
	
	return {dp[n], yuk[n]};
}

long long take_photos(int N, int M, int K, std::vector<int> R, std::vector<int> C)
{
	vector<pll> vec;
	
	n = N, m = M, k = K;
	
	for(ll i = 0 ; i < n ; i++)
		a[i + 1] = {R[i] + 1, C[i] + 1};
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].fi > a[i].se)
			swap(a[i].fi, a[i].se);
	}
	
	sort(a + 1, a + 1 + n);
	
	for(ll i = 2 ; i <= n ; i++)
	{
		if(a[i].fi != a[i - 1].fi)
			vec.push_back(a[i - 1]);
	}
	
	vec.push_back(a[n]);
	
	ll maxx = 0;
	n = 0;
	
	for(auto &i : vec)
	{
		if(i.se > maxx)
		{
			maxx = i.se;
			a[++n] = i;
		}
	}
	
	for(ll i = 1 ; i < n ; i++)
	{
		ll w1 = a[i + 1].fi, w2 = a[i].se;
		
		if(w2 < w1)
			gyo[i] = 0;
		else
			gyo[i] = (w2 - w1 + 1) * (w2 - w1 + 1);
	}
	
	ll ans = -INF;
	ll l = 0, r = m * m + 1;
	
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		pll gap = solve(mid);
		
		ans = max(ans, gap.fi - k * mid);
		
		if(gap.se <= k)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	return ans;
}